#include "DriveStraightBeamBreak.hpp"

#include "../Subsystems/Subsystems.hpp"

/**
 * Drives the robot straight until the beam break sensor is triggered
 * @param speed		The speed to drive at
 * @param timeout	A timeout to stop the command, even if the beam break has not fired
 */
DriveStraightBeamBreak::DriveStraightBeamBreak(double speed, double timeout) :
	Command("DriveStraightBeamBreak", timeout),
	speed(speed) {
		Requires(&Subsystems::driveBase);
}

void DriveStraightBeamBreak::Initialize() {
	Subsystems::driveBase.zeroEncoderPosition();
	Subsystems::driveBase.zeroGyroAngle();
}

void DriveStraightBeamBreak::Execute() {
	double correction = Subsystems::driveBase.getGyroAngle();
	correction *= 0.075d;
	correction += 1.0d;
	Subsystems::driveBase.setMotors(-speed, -speed * correction);
}

bool DriveStraightBeamBreak::IsFinished() {
	return Subsystems::driveBase.getBeamBreak() || IsTimedOut();
}

void DriveStraightBeamBreak::Interrupted() {
	Subsystems::driveBase.setMotors(0.0d, 0.0d);
}

void DriveStraightBeamBreak::End() {
	Subsystems::driveBase.setMotors(0.0d, 0.0d);
}
