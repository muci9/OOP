#include "Repository.h"



Repository::Repository()
{
}

bool Repository::add(MorgueProfile newProfile)
{
	if (this->victimProfiles.getPositionElement(newProfile) != -1)
		return false;
	this->victimProfiles.addElement(newProfile);
	return true;
}

bool Repository::remove(std::string name)
{
	for (int index = 0; index < this->victimProfiles.getSize(); index++)
		if (this->victimProfiles.getElement(index) == name)
		{
			this->victimProfiles.removeElement(index);
			return true;
		}
	return false;
}

bool Repository::remove(int index)
{
	if (index < 0 || index > this->victimProfiles.getSize())
		return false;
	this->victimProfiles.removeElement(index);
	return true;
}

bool Repository::update(MorgueProfile updatedProfile)
{
	for (int index = 0;index < this->victimProfiles.getSize();index++)
		if (this->victimProfiles.getElement(index) == updatedProfile.getName())
		{
			this->victimProfiles.updateElement(updatedProfile, index);
			return true;
		}
	return false;
}
DynamicVector<MorgueProfile> Repository::getProfiles() const
{
	return this->victimProfiles;
}

int Repository::findProfile(std::string name) const
{
	int index;

	for (index = 0; index < this->victimProfiles.getSize(); index++)
	{
		MorgueProfile profile = this->getProfiles().getElement(index);
		if (profile.getName() == name)
			return index;
	}
	return -1;
}

Repository::~Repository()
{
}
