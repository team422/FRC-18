#pragma once

#include <WPILib.h>

class Attack3 {
public:
	Attack3(int port);
	double GetX() const;
	double GetY() const;
private:
	Joystick joystick;
public:
	JoystickButton	TRIGGER,
					BUTTON_2,
					BUTTON_3,
					BUTTON_4,
					BUTTON_5;
};
