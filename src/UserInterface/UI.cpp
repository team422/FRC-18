#include "UI.hpp"
#include "../RobotMap.h"

UI UserInterface::userInterface(Ports::LEFT_JOYSTICK, Ports::RIGHT_JOYSTICK, Ports::XBOX_CONTROLLER, Ports::LAUNCHPAD);

UI::UI(int left, int right, int xboxPort, int launchpadPort) :
leftJoystick(left),
rightJoystick(right),
controller(xboxPort),
launchpad(launchpadPort) {

}
