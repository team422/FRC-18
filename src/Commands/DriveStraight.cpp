#include "DriveStraight.hpp"
#include "../Subsystems/Subsystems.hpp"
#include "../Subsystems/DriveBase.hpp"

DriveStraight::DriveStraight(float inches, float speed, float timeout) :
ticks(convertToTicks(inches)),
speed(speed),
timeout(timeout) {
	Requires(&Subsystems::driveBase);
}

void DriveStraight::Initialize() {
	printf("/n/nDriveStraight Intitialize Called/n/n");
	Subsystems::driveBase.zeroEncoderPosition();
	Subsystems::driveBase.zeroGyroAngle();
}

void DriveStraight::Execute() {
	printf("/n/nDriveStraight Execute Called/n/n");
	Subsystems::driveBase.setMotors(-speed,-speed);
}

bool DriveStraight::IsFinished() {
	printf("/n/nDriveStraight IsFinished Called/n/n");
	float time = TimeSinceInitialized();
	int leftPosition = Subsystems::driveBase.getLeftPosition();
	int rightPosition = Subsystems::driveBase.getRightPosition();
	return(leftPosition > ticks) || (rightPosition > ticks) || (time > timeout);
}

void DriveStraight::Interrupted() {
	printf("/n/nDriveStraight Interrupted Called/n/n");
	Subsystems::driveBase.setMotors(0,0);
}

void DriveStraight::End() {
	printf("/n/nDriveStraight End Called/n/n");
	Subsystems::driveBase.setMotors(0,0);
}

int DriveStraight::convertToTicks(float inches) {
	return(4096/(6*3.1415926)*inches);
}
