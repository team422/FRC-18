#include "Attack3.hpp"

Attack3::Attack3(uint32_t port) :
	joystick(port),
	TRIGGER(&joystick, 1),
	BUTTON_2(&joystick, 2),
	BUTTON_3(&joystick, 3),
	BUTTON_4(&joystick, 4),
	BUTTON_5(&joystick, 5) {

}

float Attack3::GetX() {
	return joystick.GetX();
}

float Attack3::GetY() {
	return joystick.GetY();
}
