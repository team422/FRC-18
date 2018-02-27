#pragma once

#include <WPILib.h>
#include "Attack3.hpp"
#include "Xbox_Controller.hpp"
#include "Launchpad.hpp"

class UI;

namespace UserInterface {
	extern UI userInterface;
}

class UI {
public:
	UI(int left, int right, int xboxPort, int launchpadPort);
	Attack3 leftJoystick, rightJoystick;
	Xbox_Controller controller;
	Launchpad launchpad;
};
