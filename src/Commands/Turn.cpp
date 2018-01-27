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
	printf("/n/nTurn Intitialize Called/n/n");
	Subsystems::driveBase.zeroGyroAngle();
	Subsystems::driveBase.zeroEncoderPosition();
}

void Turn::Execute() {
	printf("/n/nTurn Execute Called/n/n");
	// (+,-) = Turn Left (Turning left goes in the negative direction)
	// (-,+) = Turn Right (Turning right goes in the positive direction)
	if(degrees > 0) {
		Subsystems::driveBase.setMotors(-speed,speed);
	} else {
		Subsystems::driveBase.setMotors(speed,-speed);
	}
}

bool Turn::IsFinished() {
	printf("/n/nTurn IsFinished Called/n/n");
	float angle = Subsystems::driveBase.getGyroAngle();
	float time = TimeSinceInitialized();
	if(degrees > 0) {
		return(angle > degrees) || (time > timeout);
	}else{
		return(angle < degrees) || (time > timeout);
	}
}

void Turn::Interrupted() {
	printf("/n/nTurn Interrupted Called/n/n");
	Subsystems::driveBase.setMotors(0,0);
}

void Turn::End() {
	printf("\n\nTurn End Called\n\n");
	Subsystems::driveBase.setMotors(0,0);
}
