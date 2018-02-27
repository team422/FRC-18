#include "Launchpad.hpp"

Launchpad::Launchpad(int port) :
joystick(port) {

}

bool Launchpad::getSwitch1() {
	return joystick.GetRawButton(5);
}

bool Launchpad::getSwitch2() {
	return joystick.GetRawButton(1);
}

bool Launchpad::getSwitch3() {
	return joystick.GetRawButton(6);
}

bool Launchpad::getSwitch4() {
	return joystick.GetRawButton(11);
}

bool Launchpad::getMultiSwitchLeft() {
	return joystick.GetRawButton(9);
}

bool Launchpad::getMultiSwitchRight() {
	return joystick.GetRawButton(12);
}

bool Launchpad::getMultiSwitchInactive() {
	return !getMultiSwitchLeft() && !getMultiSwitchRight();
}
