#include "MorgueProfile.h"



MorgueProfile::MorgueProfile()
{

}
MorgueProfile::MorgueProfile(std::string name, std::string origin, int age, std::string photo)
{
	this->name = name;
	this->origin = origin;
	this->age = age;
	this->photo = photo;
}

std::string MorgueProfile::getName() const
{
	return this->name;
}

std::string MorgueProfile::getOrigin() const
{
	return this->origin;
}

std::string MorgueProfile::getPhoto() const
{
	return this->photo;
}

int MorgueProfile::getAge() const
{
	return this->age;
}

void MorgueProfile::setName(std::string newName)
{
	this->name = newName;
}

void MorgueProfile::setOrigin(std::string newOrigin)
{
	this->origin = newOrigin;
}

void MorgueProfile::setPhoto(std::string newPhoto)
{
	this->photo = newPhoto;
}

void MorgueProfile::setAge(unsigned int newAge)
{
	this->age = newAge;
}

bool MorgueProfile::operator==(MorgueProfile otherProfile)
{
	if (this->name == otherProfile.name && this->origin == otherProfile.origin && this->age == otherProfile.age)
		return true;
	return false;
}

bool MorgueProfile::operator==(std::string name)
{
	if (this->name == name)
		return true;
	return false;
}

std::string MorgueProfile::toString() const
{
	std::string profileString;

	profileString = this->name + " " + this->origin + " " + std::to_string(this->age) + " " + this->photo;
	return profileString;
}

MorgueProfile::~MorgueProfile()
{
}
