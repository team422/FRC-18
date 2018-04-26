#include "TankDrive.hpp"

#include "../Subsystems/Subsystems.hpp"
#include "../UserInterface/UI.hpp"

/**
 * The main drive command - a Tank Drive
 */
TankDrive::TankDrive() :
	Command("TankDrive"),
	leftSpeed(0),
	rightSpeed(0) {
		Requires(&Subsystems::driveBase);
}

void TankDrive::Initialize() {

}

void TankDrive::Execute() {
	double left = UserInterface::userInterface.leftJoystick.GetY();
	double leftDifference = left - leftSpeed;
	if (leftDifference > MAX_CHANGE) {
		left = leftSpeed + MAX_CHANGE;
	} else if (leftDifference < -MAX_CHANGE) {
		left = leftSpeed - MAX_CHANGE;
	}
	double right = UserInterface::userInterface.rightJoystick.GetY();
	double rightDifference = right - rightSpeed;
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

