#include "DriveStraightBeamBreak.hpp"
#include "../Subsystems/Subsystems.hpp"
#include "../Subsystems/DriveBase.hpp"
#include <cmath>

DriveStraightBeamBreak::DriveStraightBeamBreak(float speed, float timeout) :
Command(timeout),
speed(speed) {
	Requires(&Subsystems::driveBase);
}

void DriveStraightBeamBreak::Initialize() {
	Subsystems::driveBase.zeroEncoderPosition();
	Subsystems::driveBase.zeroGyroAngle();
}

void DriveStraightBeamBreak::Execute() {
	float correction = Subsystems::driveBase.getGyroAngle();
	correction *= 0.075;
	correction += 1.0;
	Subsystems::driveBase.setMotors(-speed, -speed * correction);
}

bool DriveStraightBeamBreak::IsFinished() {
	return Subsystems::driveBase.getBeamBrake();
}

void DriveStraightBeamBreak::Interrupted() {
	Subsystems::driveBase.setMotors(0,0);
	Cancel();
}

void DriveStraightBeamBreak::End() {
	Subsystems::driveBase.setMotors(0,0);
	Cancel();
}
