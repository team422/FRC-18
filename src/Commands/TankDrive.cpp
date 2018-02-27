#include "TankDrive.hpp"
#include "../Subsystems/Subsystems.hpp"
#include "../UserInterface/UI.hpp"
#include "../Subsystems/DriveBase.hpp"

#include <cmath>

TankDrive::TankDrive() :
leftSpeed(0),
rightSpeed(0) {
	Requires(&Subsystems::driveBase);
}

void TankDrive::Initialize() {

}

void TankDrive::Execute() {
	float left = UserInterface::userInterface.leftJoystick.GetY();
	float leftDifference = left - leftSpeed;
	if (leftDifference > MAX_CHANGE) {
		left = leftSpeed + MAX_CHANGE;
	} else if (leftDifference < -MAX_CHANGE) {
		left = leftSpeed - MAX_CHANGE;
	}
	float right = UserInterface::userInterface.rightJoystick.GetY();
	float rightDifference = right - rightSpeed;
	if (rightDifference > MAX_CHANGE) {
		right = rightSpeed + MAX_CHANGE;
	} else if (rightDifference < -MAX_CHANGE) {
		right = rightSpeed - MAX_CHANGE;
	}
	leftSpeed = left;
	rightSpeed = right;
	Subsystems::driveBase.setMotors(left, right);
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

