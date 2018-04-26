#include "Xbox_Controller.hpp"

/**
 * Represents an Xbox Controller.
 *
 * The port the controller is plugged into is configurable in the Driver Station. The joystick buttons are exposed as
 * JoystickButton objects, allowing access to methods such as WhenPressed() or WhileHeld();
 * @param port The port number which the Launchpad is plugged into
 */
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

/**
 * Gets the value of the controller's left joystick x-axis
 * @return The value of the left joystick x-axis
 */
double Xbox_Controller::getLeftJoystickX() const {
	return joystick.GetRawAxis(0);
}

/**
 * Gets the value of the controller's left joystick y-axis
 * @return The value of the left joystick y-axis
 */
double Xbox_Controller::getLeftJoystickY() const {
	return joystick.GetRawAxis(1);
}

/**
 * Gets the value of the controller's right joystick x-axis
 * @return The value of the right joystick x-axis
 */
double Xbox_Controller::getRightJoystickX() const {
	return joystick.GetRawAxis(4);
}

/**
 * Gets the value of the controller's right joystick y-axis
 * @return The value of the right joystick y-axis
 */
double Xbox_Controller::getRightJoystickY() const {
	return joystick.GetRawAxis(5);
}

/**
 * Gets the value of the controller's left trigger
 * @return The value of the left trigger
 */
double Xbox_Controller::getLeftTrigger() const {
	return joystick.GetRawAxis(2);
}

/**
 * Gets the value of the controller's right trigger
 * @return The value of the right trigger
 */
double Xbox_Controller::getRightTrigger() const {
	return joystick.GetRawAxis(3);
}

/**
 * Gets the angle of the POV
 * @return An int representing the angle of the POV
 */
int Xbox_Controller::getPOVAngle() const {
	return joystick.GetPOV(0);
}

