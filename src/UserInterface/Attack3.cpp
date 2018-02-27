#include "Attack3.hpp"

Attack3::Attack3(uint32_t port) :
	joystick (new Joystick(port)),
	TRIGGER (new JoystickButton(joystick, 1)),
	BUTTON_2 (new JoystickButton(joystick, 2)),
	BUTTON_3 (new JoystickButton(joystick, 3)),
	BUTTON_4 (new JoystickButton(joystick, 4)),
	BUTTON_5 (new JoystickButton(joystick, 5)) {

}

float Attack3::GetX() {
	return joystick->GetX();
}

float Attack3::GetY() {
	return joystick->GetY();
}
