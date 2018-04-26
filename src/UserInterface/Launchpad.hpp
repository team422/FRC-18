#pragma once

#include <WPILib.h>

class Launchpad {
public:
	Launchpad(int port);
	bool getSwitch1() const;
	bool getSwitch2() const;
	bool getSwitch3() const;
	bool getSwitch4() const;
	bool getMultiSwitchLeft() const;
	bool getMultiSwitchRight() const;
	bool getMultiSwitchInactive() const;
private:
	Joystick joystick;
};

