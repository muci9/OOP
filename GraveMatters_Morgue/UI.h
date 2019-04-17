#pragma once

#include "Controller.h"

class UI
{
private:
	Controller controller;

public:
	UI(Controller &newController): controller{newController} {}
	void userInterface();
	~UI();
	void displayProfiles(DynamicVector<MorgueProfile> profiles);
};

