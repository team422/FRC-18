#include "Attack3.hpp"

/**
 * Represents a Logitech Attack 3 Joystick.
 *
 * The port the joystick is plugged into is configurable in the Driver Station. The joystick buttons are exposed as
 * JoystickButton objects, allowing access to methods such as WhenPressed() or WhileHeld();
 * @param port	The port number which the Attack 3 is plugged into
 */
Attack3::Attack3(int port) :
	joystick(port),
	TRIGGER(&joystick, 1),
	BUTTON_2(&joystick, 2),
	BUTTON_3(&joystick, 3),
	BUTTON_4(&joystick, 4),
	BUTTON_5(&joystick, 5) {

}

/**
 * Gets the value of the Attack 3's x-axis
 * @return The value of the x-axis
 */
double Attack3::GetX() const {
	return joystick.GetX();
}

/**
 * Gets the value of the Attack 3's y-axis
 * @return The value of the y-axis
 */
double Attack3::GetY() const {
	return joystick.GetY();
}
