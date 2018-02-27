#include "Turn.hpp"
#include "../Subsystems/Subsystems.hpp"
#include "../Subsystems/DriveBase.hpp"

Turn::Turn(int degrees, float speed, float timeout) :
Command(timeout),
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
	float angle = Subsystems::driveBase.getGyroAngle();
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
}

void Turn::End() {
	Subsystems::driveBase.setMotors(0,0);
}
