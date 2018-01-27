#include "TankDrive.hpp"
#include "../Subsystems/Subsystems.hpp"
#include "../Subsystems/DriveBase.hpp"


TankDrive::TankDrive() {
	Requires(&Subsystems::driveBase);
}

void TankDrive::Initialize() {
	printf("/n/nTankDrive Intitialize Called/n/n");
}

void TankDrive::Execute() {
	printf("/n/nTankDrive Execute Called/n/n");
	Subsystems::driveBase.setMotors(Subsystems::userInterface.leftJoystick.GetY(),
				Subsystems::userInterface.rightJoystick.GetY());
}

bool TankDrive::IsFinished() {
	printf("/n/nTankDrive IsFinished Called/n/n");
	return false;
}

void TankDrive::Interrupted() {
	printf("/n/nTankDrive Interrupted Called/n/n");
	Subsystems::driveBase.setMotors(0,0);
}

void TankDrive::End() {
	printf("/n/nTankDrive End Called/n/n");
	Subsystems::driveBase.setMotors(0,0);
}

