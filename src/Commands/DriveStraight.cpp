#include "DriveStraight.hpp"
#include "../Subsystems/Subsystems.hpp"
#include "../Subsystems/DriveBase.hpp"
#include <cmath>

DriveStraight::DriveStraight(float inches, float speed, bool forward, float timeout) :
Command(timeout),
ticks(convertToTicks(inches)),
forward(forward),
speed(speed) {
	Requires(&Subsystems::driveBase);
}

void DriveStraight::Initialize() {
	Subsystems::driveBase.zeroEncoderPosition();
	Subsystems::driveBase.zeroGyroAngle();
}

void DriveStraight::Execute() {
	float correction = Subsystems::driveBase.getGyroAngle();
	correction *= 0.075;
	correction += 1.0;
	if (forward) {
		Subsystems::driveBase.setMotors(-speed, -speed * correction);
	} else {
		Subsystems::driveBase.setMotors(speed * correction, speed);
	}
}

bool DriveStraight::IsFinished() {
	int leftPosition = abs(Subsystems::driveBase.getLeftPosition());
	int rightPosition = abs(Subsystems::driveBase.getRightPosition());
	return (leftPosition > ticks) || (rightPosition > ticks) || IsTimedOut();
}

void DriveStraight::Interrupted() {
	Subsystems::driveBase.zeroEncoderPosition();
	Subsystems::driveBase.zeroGyroAngle();
	Subsystems::driveBase.setMotors(0,0);
}

void DriveStraight::End() {
	Subsystems::driveBase.zeroEncoderPosition();
	Subsystems::driveBase.zeroGyroAngle();
	Subsystems::driveBase.setMotors(0,0);
}

int DriveStraight::convertToTicks(float inches) {
	return(4096 / (6 * 3.1415926) * inches);
}
