#include "Launchpad.hpp"

/**
 * Represents a Launchpad.
 *
 * The port the launchpad is plugged into is configurable in the Driver Station.
 * @param port The port number which the Launchpad is plugged into
 */
Launchpad::Launchpad(int port) :
	joystick(port) {

}

/**
 * Gets whether the first switch is active
 * @return A boolean representing the state of the first switch
 */
bool Launchpad::getSwitch1() const {
	return joystick.GetRawButton(5);
}

/**
 * Gets whether the second switch is active
 * @return A boolean representing the state of the second switch
 */
bool Launchpad::getSwitch2() const {
	return joystick.GetRawButton(1);
}

/**
 * Gets whether the third swtich is active
 * @return A boolean representing the state of the third switch
 */
bool Launchpad::getSwitch3() const {
	return joystick.GetRawButton(6);
}

/**
 * Gets whether the fourth swtich is active
 * @return A boolean representing the state of the fourth switch
 */
bool Launchpad::getSwitch4() const {
	return joystick.GetRawButton(11);
}

/**
 * Gets true if the multi-switch is in the left position
 * @return A boolean denoting if the multi-switch is in the left position
 */
bool Launchpad::getMultiSwitchLeft() const {
	return joystick.GetRawButton(9);
}

/**
 * Returns true if the multi-switch is in the right position
 * @return A boolean denoting if the multi-switch is in the right position
 */
bool Launchpad::getMultiSwitchRight() const {
	return joystick.GetRawButton(12);
}

/**
 * Gets true if the multi-switch is in the center position
 * @return A boolean representing if the multi-switch is inactive
 */
bool Launchpad::getMultiSwitchInactive() const {
	return !getMultiSwitchLeft() && !getMultiSwitchRight();
}
