#include "Xbox_Controller.hpp"

Xbox_Controller::Xbox_Controller(int port) :
joystick(port),
A(&joystick, 1),
B(&joystick, 2),
X(&joystick, 3),
Y(&joystick, 4),
LB(&joystick, 5),
RB(&joystick, 6),
BACK(&joystick, 7),
START(&joystick, 8) {

}

float Xbox_Controller::getLeftJoystickX() {
	return joystick.GetRawAxis(0);
}

float Xbox_Controller::getLeftJoystickY() {
	return joystick.GetRawAxis(1);
}

float Xbox_Controller::getRightJoystickY() {
	return joystick.GetRawAxis(5);
}

float Xbox_Controller::getLeftTrigger() {
	return joystick.GetRawAxis(2);
}

float Xbox_Controller::getRightTrigger() {
	return joystick.GetRawAxis(3);
}

int Xbox_Controller::getPOVAngle() {
	return joystick.GetPOV(0);
}

