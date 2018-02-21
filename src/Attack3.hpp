#pragma once

#include <WPILib.h>

class Attack3 {
public:
	Attack3(uint32_t port);
	float GetX();
	float GetY();
private:
	Joystick * joystick;
public:
	Button * const TRIGGER;
	Button * const BUTTON_2;
	Button * const BUTTON_3;
	Button * const BUTTON_4;
	Button * const BUTTON_5;
};
