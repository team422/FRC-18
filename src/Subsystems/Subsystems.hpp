#pragma once

#include "Intake.hpp"
#include "DriveBase.hpp"
#include "Guillotine.hpp"
#include "../UI.hpp"
#include "../RobotMap.h"
#include "ArduinoController.hpp"

namespace Subsystems {
	extern DriveBase driveBase;
	extern UI userInterface;
	extern Compressor compressor;
	extern Intake intake;
	extern Guillotine guillotine;
	extern ArduinoController arduinoController;
}
