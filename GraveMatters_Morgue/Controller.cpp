#include "Controller.h"


Controller::Controller(Repository &profiles, Repository &transferredProfiles)
{
	this->profiles = profiles;
	this->transferredProfiles = transferredProfiles;
	this->modePermissions = -1;
	this->indexNext = -1;
}

bool checkProfile(MorgueProfile profile)
{
	if (profile.getAge() < 0 || profile.getName() == "" || profile.getOrigin() == "" || profile.getPhoto() == "")
		return false;
	return true;
}

int Controller::getMode() const
{
	return this->modePermissions;
}

void Controller::changeMode(int mode)
{
	this->modePermissions = mode;
}

bool Controller::addController(MorgueProfile newProfile)
{
	if (checkProfile(newProfile) == false)
		throw std::exception("Invalid profile.");
	try 
	{
		if (this->modePermissions == 1)
			return this->profiles.add(newProfile);
		throw std::exception("Invalid mode for adding.");
	}
	catch (std::exception e)
	{
		//std::cout << e.what() << std::endl;
		return false;
	}
}

bool Controller::updateController(MorgueProfile updatedProfile)
{
	if (checkProfile(updatedProfile) == false)
		throw std::exception("Invalid profile.");
	try
	{
		if (this->modePermissions == 1)
			return this->profiles.update(updatedProfile);
		throw std::exception("Invalid mode for updating.");
	}
	catch (std::exception e)
	{
		//std::cout << e.what() << std::endl;
		return false;
	}
}

bool Controller::removeController(std::string name)
{
	try
	{
		if (this->modePermissions == 1)
			return this->profiles.remove(name);
		throw std::exception("Invalid mode for deleting.");
	}
	catch (std::exception e)
	{
		//std::cout << e.what() << std::endl;
		return false;
	}
}

DynamicVector<MorgueProfile> Controller::getProfiles() const
{
	return this->profiles.getProfiles();
}

MorgueProfile Controller::next()
{
	MorgueProfile toReturn;

	if (this->modePermissions != 0)
		throw std::exception("Only assistants can use the next command.");
	this->indexNext += 1;
	if (this->indexNext >= this->getProfiles().getSize() || this->indexNext < 0)
		this->indexNext = 0;
	toReturn = getProfiles().getElement(this->indexNext);
	return toReturn;
}

DynamicVector<MorgueProfile> Controller::getTransferredProfiles() const
{
	if (this->modePermissions != 0)
		throw std::exception("Only assistants can use the mylist command.");
	return this->transferredProfiles.getProfiles();
}

bool Controller::save(std::string name)
{
	int indexProfile;

	if (this->modePermissions != 0)
		throw std::exception("Only assistants can use the save command.");
	indexProfile = this->profiles.findProfile(name);
	if (indexProfile != -1)
	{
		this->indexNext -= 1;
		this->transferredProfiles.add(this->getProfiles().getElement(indexProfile));
		this->profiles.remove(indexProfile);
		return true;
	}
	return false;
}

DynamicVector<MorgueProfile> Controller::filterProfilesByLocation(DynamicVector<MorgueProfile> profiles, std::string location)
{
	DynamicVector<MorgueProfile> filterdProfiles;
	int index;
	
	if (this->modePermissions != 0)
		throw std::exception("Only the assistant can filter profiles.");
	for (index = 0; index < profiles.getSize(); index++)
	{
		if (profiles.getElement(index).getOrigin() == location)
			filterdProfiles.addElement(profiles.getElement(index));
	}
	return filterdProfiles;
}

DynamicVector<MorgueProfile> Controller::filterProfilesByAge(DynamicVector<MorgueProfile> profiles, int ageLimit)
{
	DynamicVector<MorgueProfile> filteredProfiles;
	int index;

	if (this->modePermissions != 0)
		throw std::exception("Only the assistant can filter profiles.");
	for (index = 0; index < profiles.getSize(); index++)
	{
		if (profiles.getElement(index).getAge() <= ageLimit)
			filteredProfiles.addElement(profiles.getElement(index));
	}
	return filteredProfiles;
}

Controller::~Controller()
{
}
