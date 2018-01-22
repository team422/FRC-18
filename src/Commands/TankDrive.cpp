#include "TankDrive.hpp"
#include "../Subsystems/Subsystems.hpp"
#include "../Subsystems/DriveBase.hpp"


TankDrive::TankDrive() {
	Requires(&Subsystems::driveBase);
}

void TankDrive::Initialize() {}

void TankDrive::Execute() {
	Subsystems::driveBase.setMotors(Subsystems::userInterface.leftJoystick.GetY(),
				Subsystems::userInterface.rightJoystick.GetY());
}

bool TankDrive::IsFinished() {
	return false;
}

void TankDrive::Interrupted() {
	Subsystems::driveBase.setMotors(0,0);
}

void TankDrive::End() {
	Subsystems::driveBase.setMotors(0,0);
}

