#include "Turn.hpp"

#include "../Subsystems/Subsystems.hpp"

/**
 * Represents a turn that the robot may perform
 * @param degrees The degrees to turn, positive is rotate clockwise, negative is counterclockwise
 * @param speed   The speed to turn with
 * @param timeout A timeout to stop after
 */
Turn::Turn(double degrees, double speed, double timeout) :
	Command("Turn", timeout),
	degrees(degrees),
	speed(speed),
	isCorrecting(false) {
		Requires(&Subsystems::driveBase);
}

void Turn::Initialize() {
	Subsystems::driveBase.zeroGyroAngle();
	Subsystems::driveBase.zeroEncoderPosition();
}

void Turn::Execute() {
	if ((degrees > 0) && !isCorrecting) {
		// Turning to the right
		Subsystems::driveBase.setMotors(-speed, speed);
	} else if ((degrees < 0) && !isCorrecting) {
		// Turning to the left
		Subsystems::driveBase.setMotors(speed, -speed);
	} else if (degrees > 0) {
		// Turned to the right, but correcting to the left
		Subsystems::driveBase.setMotors(speed / 2, -speed / 2);
	} else {
		// Turned to the left, but correcting to the right
		Subsystems::driveBase.setMotors(-speed / 2, speed / 2);
	}
}

bool Turn::IsFinished() {
	double angle = Subsystems::driveBase.getGyroAngle();
	if (degrees > 0) {
		// Turning to the right
		if (!isCorrecting) {
			if (angle > degrees) {
				isCorrecting = true;
			}
			return IsTimedOut();
		}
		return (angle < degrees) || IsTimedOut();
	} else {
		// Turning to the left
		if (!isCorrecting) {
			if (angle < degrees) {
				isCorrecting = true;
			}
			return IsTimedOut();
		}
		return (angle > degrees) || IsTimedOut();
	}
}

void Turn::Interrupted() {
	Subsystems::driveBase.setMotors(0,0);
	Subsystems::driveBase.zeroEncoderPosition();
	Subsystems::driveBase.zeroGyroAngle();
}

void Turn::End() {
	Subsystems::driveBase.setMotors(0,0);
	Subsystems::driveBase.zeroEncoderPosition();
	Subsystems::driveBase.zeroGyroAngle();
}
