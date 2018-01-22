#include "DriveStraight.hpp"
#include "../Subsystems/Subsystems.hpp"
#include "../Subsystems/DriveBase.hpp"

DriveStraight::DriveStraight(float inches) : ticks(convertToTicks(inches)) {
	Requires(&Subsystems::driveBase);
}

void DriveStraight::Initialize() {
	Subsystems::driveBase.zeroEncoderPosition();
	Subsystems::driveBase.zeroGyroAngle();
}

void DriveStraight::Execute() {
	Subsystems::driveBase.setMotors(-0.2,-0.2);
}

bool DriveStraight::IsFinished() {
	int leftPosition = Subsystems::driveBase.getLeftPosition();
	int rightPosition = Subsystems::driveBase.getRightPosition();
	return(leftPosition > ticks) || (rightPosition > ticks);
}

void DriveStraight::Interrupted() {
	Subsystems::driveBase.setMotors(0,0);
}

void DriveStraight::End() {
	Subsystems::driveBase.setMotors(0,0);
}

int DriveStraight::convertToTicks(float inches) {
	return(4096/(6*3.1415926)*inches);
}
