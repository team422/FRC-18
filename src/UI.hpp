#pragma once

#include <WPILib.h>
#include "Attack3.hpp"
#include "Xbox_Controller.hpp"

class UI {
public:
	UI(int left, int right, int xboxPort);
	Attack3 leftJoystick, rightJoystick;
	Xbox_Controller controller;
};
