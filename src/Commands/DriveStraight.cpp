#include "DriveStraight.hpp"

#include "../Subsystems/Subsystems.hpp"

/**
 * Routine to drive the robot straight for the given number of ticks
 * @param inches  The inches to drive straight (this is automatically converted to encoder ticks)
 * @param speed   The speed to travel at
 * @param forward True if the robot should move forward, false if the robot should move in reverse
 * @param timeout A timeout, the command stops if this time passes without completing
 */
DriveStraight::DriveStraight(double inches, double speed, Direction direction, double timeout) :
	Command("DriveStraight", timeout),
	ticks(convertToTicks(inches)),
    direction(direction),
	speed(speed) {
		Requires(&Subsystems::driveBase);
}

void DriveStraight::Initialize() {
	Subsystems::driveBase.zeroEncoderPosition();
	Subsystems::driveBase.zeroGyroAngle();
}

void DriveStraight::Execute() {
	double correction = Subsystems::driveBase.getGyroAngle();
	correction *= 0.075d;
	correction += 1.0d;
	if (direction == Direction::FORWARD) {
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
	Subsystems::driveBase.setMotors(0.0d, 0.0d);
}

void DriveStraight::End() {
	Subsystems::driveBase.zeroEncoderPosition();
	Subsystems::driveBase.zeroGyroAngle();
	Subsystems::driveBase.setMotors(0.0d, 0.0d);
}

int DriveStraight::convertToTicks(double inches) {
	return (int) (4096 / (6 * 3.1415926) * inches);
}
