#include "UI.hpp"
#include "../RobotMap.h"

/**
 * Single instance of the user interface
 */
UI UserInterface::userInterface(Ports::LEFT_JOYSTICK, Ports::RIGHT_JOYSTICK, Ports::XBOX_CONTROLLER, Ports::LAUNCHPAD);

/**
 * Represents one set of all of the Driver Station's joysticks and controllers
 * @param left          the left joystick port number
 * @param right         the right joystick port number
 * @param xboxPort      the xbox controller port number
 * @param launchpadPort the launchpad port number
 */
UI::UI(int left, int right, int xboxPort, int launchpadPort) :
    leftJoystick(left),
    rightJoystick(right),
    controller(xboxPort),
    launchpad(launchpadPort) {

}
