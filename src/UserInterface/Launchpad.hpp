#pragma once

#include <WPILib.h>

class Launchpad {
public:
	Launchpad(int port);
	bool getSwitch1();
	bool getSwitch2();
	bool getSwitch3();
	bool getSwitch4();
	bool getMultiSwitchLeft();
	bool getMultiSwitchRight();
	bool getMultiSwitchInactive();
private:
	Joystick joystick;
};

