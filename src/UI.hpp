#pragma once

#include <WPILib.h>

class UI {
public:
	UI(int left, int right);
	frc::Joystick leftJoystick, rightJoystick;
};
