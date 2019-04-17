#include "UI.h"
#include <sstream>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

UI::~UI()
{
}

void UI::displayProfiles(DynamicVector<MorgueProfile> profiles)
{
	for (int index = 0; index < profiles.getSize(); index++)
		std::cout << profiles.getElement(index).toString() << std::endl;
}
// trim from start (in place)
static inline void ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
		std::not1(std::ptr_fun<int, int>(std::isspace))));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(),
		std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
	ltrim(s);
	rtrim(s);
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s) {
	ltrim(s);
	return s;
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s) {
	rtrim(s);
	return s;
}

// trim from both ends (copying)
static inline std::string trim_copy(std::string s) {
	trim(s);
	return s;
}

void UI::userInterface()
{
	std::string word;
	int index;
	bool thereIsInput = false;
	while (true)
	{
		index = 0;
		int cnt = 0;
		DynamicVector<std::string> inputWords{ 20 };
		std::string input;
		std::getline(std::cin, input);
		std::istringstream inputStream(input);
		while (std::getline(inputStream, word, ','))
		{
			inputWords.addElement(word);
			thereIsInput = true;
		}
		if (!thereIsInput)
			std::cout << "No input.\n";
		else
		{
			inputWords.updateElement(trim_copy(inputWords.getElement(index)), index);
			if (inputWords.getSize() == 1 && inputWords.getElement(index).find("mode") == 0)
			{
				std::istringstream newStream(inputWords.getElement(0));
				while (std::getline(newStream, word, ' '))
				{
					if (word != "" && word != " ")
					{
						inputWords.addElement(word);
						++cnt;
					}
				}
				index += 2;
				int mode;
				mode = -1;
				try
				{
					if (cnt == 2)
					{
						if (inputWords.getElement(index) == "A")
							mode = 1;
						else if (inputWords.getElement(index) == "B")
							mode = 0;
						this->controller.changeMode(mode);
					}
					else
						std::cout << "Mode command invalid!\n";
				}
				catch (std::exception e)
				{
					std::cout << e.what() << std::endl;
				}
			}
			else if (inputWords.getSize() == 4 && inputWords.getElement(index).find("add") == 0)
			{
				inputWords.updateElement(inputWords.getElement(index).erase(0, 3), index);
				try {
					for (int i = 0; i < inputWords.getSize(); i++)
					{
						inputWords.updateElement(trim_copy(inputWords.getElement(i)), i);
					}
					MorgueProfile newProfile{ inputWords.getElement(index), inputWords.getElement(index + 1), std::stoi(inputWords.getElement(index + 2)), inputWords.getElement(index + 3) };
					if (this->controller.addController(newProfile) == true)
						std::cout << "Profile added successfully!\n";
					else
						std::cout << "Adding profile failed!\n";
				}
				catch (std::exception e) {
					std::cout << e.what() << "\n";
				}
			}
			else if (inputWords.getSize() == 4 && inputWords.getElement(index).find("update") == 0)
			{
				inputWords.updateElement(inputWords.getElement(index).erase(0, 6), index);
				try {
					for (int i = 0; i < inputWords.getSize(); i++)
					{
						inputWords.updateElement(trim_copy(inputWords.getElement(i)), i);
					}
					MorgueProfile newProfile{ inputWords.getElement(index), inputWords.getElement(index + 1), std::stoi(inputWords.getElement(index + 2)), inputWords.getElement(index + 3) };
					if (this->controller.updateController(newProfile) == true)
						std::cout << "Profile updated successfully!\n";
					else
						std::cout << "Updating profile failed!\n";
				}
				catch (std::exception e) {
					std::cout << e.what() << "\n";
				}

			}
			else if (inputWords.getSize() == 1 && inputWords.getElement(index).find("delete") == 0)
			{
				inputWords.updateElement(inputWords.getElement(index).erase(0, 6), index);
				try {
					inputWords.updateElement(trim_copy(inputWords.getElement(index)), index);
					if (this->controller.removeController(inputWords.getElement(index)) == true)
						std::cout << "Profile deleted successfully!\n";
					else
						std::cout << "Deleting profile failed!\n";
				}
				catch (std::exception e) {
					std::cout << e.what() << "\n";
				}
			}
			else if (inputWords.getSize() == 1 && inputWords.getElement(index) == "list")
			{
				DynamicVector<MorgueProfile> profiles = this->controller.getProfiles();
				if (this->controller.getMode() == 1)
					this->displayProfiles(profiles);
				else
					std::cout << "Only administrators can use the list command.\n";
			}
			else if (inputWords.getSize() == 1 && inputWords.getElement(index) == "next")
			{
				try {
					std::cout << this->controller.next().toString() << "\n";
				}
				catch (std::exception e)
				{
					std::cout << e.what() << "\n";
				}
			}
			else if (inputWords.getSize() == 1 && inputWords.getElement(index).find("save") == 0)
			{
				inputWords.updateElement(inputWords.getElement(index).erase(0, 5), index);
				try {
					inputWords.updateElement(trim_copy(inputWords.getElement(index)), index);
					std::string name = inputWords.getElement(index);
					if (this->controller.save(name) == true)
						std::cout << "Profile transferred!\n";
					else
					{
						if (name == "")
							std::cout << "Invalid name. Use 'save <name>'.\n";
						else std::cout << "Profile was not transferred!\n";
					}
				}
				catch (std::exception e)
				{
					std::cout << e.what() << "\n";
				}
			}
			else if ((inputWords.getSize() >= 1 || inputWords.getSize() <= 2) && inputWords.getElement(index).find("list") == 0)
			{
				DynamicVector<MorgueProfile> filteredProfiles;
				int ageLimit;

				inputWords.updateElement(inputWords.getElement(index).erase(0, 4), index);
				inputWords.updateElement(trim_copy(inputWords.getElement(index)), index);
				try {
					if (inputWords.getSize() == 2)
					{
						filteredProfiles = this->controller.filterProfilesByLocation(this->controller.getProfiles(), inputWords.getElement(index));
						index++;
					}
					ageLimit = std::stoi(inputWords.getElement(index));
					if (filteredProfiles.getSize() == 0)
						filteredProfiles = this->controller.filterProfilesByAge(this->controller.getProfiles(), ageLimit);
					else
						filteredProfiles = this->controller.filterProfilesByAge(filteredProfiles, ageLimit);
					this->displayProfiles(filteredProfiles);
				}
				catch (std::exception e)
				{
					std::cout << e.what() << "\n";
				}

			}
			else if (inputWords.getSize() == 1 && inputWords.getElement(index) == "mylist")
			{
				try {
					this->displayProfiles(this->controller.getTransferredProfiles());
				}
				catch (std::exception e)
				{
					std::cout << e.what() << "\n";
				}
			}
			else if (inputWords.getSize() == 1 && inputWords.getElement(index) == "exit")
				break;
			else
				std::cout << "Invalid command.\n";
		}
	}
}