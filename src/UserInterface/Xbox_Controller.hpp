#pragma once

#include <WPILib.h>

class Xbox_Controller {
public:
	Xbox_Controller(int port);
	double getLeftJoystickX() const;
	double getLeftJoystickY() const;
	double getRightJoystickX() const;
	double getRightJoystickY() const;
	double getLeftTrigger() const;
	double getRightTrigger() const;
	int getPOVAngle() const;
private:
	Joystick joystick;
public:
	JoystickButton A, B, X, Y, LB, RB, BACK, START;
};

