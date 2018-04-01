#pragma once

#include <WPILib.h>

class Attack3 {
public:
	Attack3(uint32_t port);
	float GetX();
	float GetY();
private:
	Joystick joystick;
public:
	const JoystickButton TRIGGER;
	const JoystickButton BUTTON_2;
	const JoystickButton BUTTON_3;
	const JoystickButton BUTTON_4;
	const JoystickButton BUTTON_5;
};
