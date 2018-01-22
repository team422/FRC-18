#include "Turn.hpp"
#include "../Subsystems/Subsystems.hpp"
#include "../Subsystems/DriveBase.hpp"

Turn::Turn(int degrees, float speed, float timeout) :
degrees(degrees),
speed(speed),
timeout(timeout) {
	Requires(&Subsystems::driveBase);
}

void Turn::Initialize() {
	Subsystems::driveBase.zeroGyroAngle();
	Subsystems::driveBase.zeroEncoderPosition();
}

void Turn::Execute() {
	// (+,-) = Turn Left (Turning left goes in the negative direction)
	// (-,+) = Turn Right (Turning right goes in the positive direction)
	if(degrees > 0) {
		Subsystems::driveBase.setMotors(-speed,speed);
	} else {
		Subsystems::driveBase.setMotors(speed,-speed);
	}
}

bool Turn::IsFinished() {
	float angle = Subsystems::driveBase.getGyroAngle();
	float time = TimeSinceInitialized();
	if(degrees > 0) {
		return(angle > degrees) || (time > timeout);
	}else{
		return(angle < degrees) || (time > timeout);
	}
}

void Turn::Interrupted() {
	Subsystems::driveBase.setMotors(0,0);
}

void Turn::End() {
	Subsystems::driveBase.setMotors(0,0);
	printf("\n\n\nTurn has ended!\n\n\n");
}
