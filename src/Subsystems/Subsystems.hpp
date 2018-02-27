#pragma once

#include "Intake.hpp"
#include "DriveBase.hpp"
#include "Guillotine.hpp"
#include "ArduinoController.hpp"
#include "../RobotMap.h"

namespace Subsystems {
	extern DriveBase driveBase;
	extern Compressor compressor;
	extern Intake intake;
	extern Guillotine guillotine;
	extern ArduinoController arduino;
}
