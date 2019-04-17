#pragma once
#include <string>

class MorgueProfile
{
private:
	std::string name;
	std::string origin;
	int age;
	std::string photo;

public:
	MorgueProfile();
	MorgueProfile(std::string name, std::string origin, int age, std::string photo);
	std::string getName() const;
	void setName(std::string newName);
	std::string getOrigin() const;
	void setOrigin(std::string newOrigin);
	std::string getPhoto() const;
	void setPhoto(std::string newPhoto);
	int getAge() const;
	void setAge(unsigned int newAge);
	bool operator==(MorgueProfile otherProfile);
	bool operator==(std::string name);
	std::string toString() const;
	~MorgueProfile();
};

