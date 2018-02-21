#include "Subsystems.hpp"

DriveBase Subsystems::driveBase;
UI Subsystems::userInterface(Ports::LEFT_JOYSTICK, Ports::RIGHT_JOYSTICK, Ports::XBOX_CONTROLLER);
Compressor Subsystems::compressor;
Intake Subsystems::intake;
Guillotine Subsystems::guillotine;
ArduinoController Subsystems::arduinoController;
