#pragma once

#include <WPILib.h>

class Xbox_Controller {
public:
	Xbox_Controller(int port);
	float getLeftJoystickX();
	float getLeftJoystickY();
	float getRightJoystickY();
	float getLeftTrigger();
	float getRightTrigger();
	int getPOVAngle();
private:
	Joystick joystick;
public:
	JoystickButton A, B, X, Y, LB, RB, BACK, START;
};

