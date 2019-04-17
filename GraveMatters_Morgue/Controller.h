#pragma once

#include "Repository.h"
#include <iostream>

class Controller
{
private:
	Repository profiles;
	Repository transferredProfiles;
	int modePermissions;//1 - Administrator, 0 - Assistant, -1 - uninitialized
	int indexNext;

public:
	Controller(Repository &profiles, Repository &transferred);
	int getMode() const;
	void changeMode(int mode);
	bool addController(MorgueProfile newProfile);
	bool updateController(MorgueProfile updatedProfile);
	bool removeController(std::string name);
	DynamicVector<MorgueProfile> getProfiles() const;
	MorgueProfile next();
	DynamicVector<MorgueProfile> getTransferredProfiles() const;
	bool save(std::string name);
	DynamicVector<MorgueProfile> filterProfilesByLocation(DynamicVector<MorgueProfile> profiles, std::string location);
	DynamicVector<MorgueProfile> filterProfilesByAge(DynamicVector<MorgueProfile> profiles, int ageLimit);
	~Controller();
};

