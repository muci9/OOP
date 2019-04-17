#pragma once

#include "DynamicVector.h"
#include "MorgueProfile.h"

class Repository
{
private:
	DynamicVector<MorgueProfile> victimProfiles{ 2 };

public:
	Repository();
	bool add(MorgueProfile newProfile);
	bool remove(std::string name);
	bool remove(int index);
	bool update(MorgueProfile updatedProfile);
	DynamicVector<MorgueProfile> getProfiles() const;
	int findProfile(std::string name) const;
	~Repository();
};

