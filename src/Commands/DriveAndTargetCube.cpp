#include "DriveAndTargetCube.hpp"

#include "../Subsystems/Subsystems.hpp"
#include <networktables/NetworkTableInstance.h>

DriveAndTargetCube::DriveAndTargetCube(double speed, Direction direction, double timeout) :
	Command("DriveAndTargetCube", timeout),
	speed(speed),
	direction(direction) {
    	Requires(&Subsystems::driveBase);
}

void DriveAndTargetCube::Initialize() {
	pixyTable = nt::NetworkTableInstance::GetDefault().GetTable("pixy");
	Subsystems::driveBase.zeroEncoderPosition();
	Subsystems::driveBase.zeroGyroAngle();
}

void DriveAndTargetCube::Execute() {
	// Get the value, normalize and scale it
	double correction = (160.0d - pixyTable->GetNumber("blockX", 160)) / 5.0d;
    correction *= 0.075d;
    correction += 1.0d;
    if (direction == Direction::FORWARD) {
        Subsystems::driveBase.setMotors(-speed, -speed * correction);
    } else {
        Subsystems::driveBase.setMotors(speed * correction, speed);
    }
    if (pixyTable->GetNumber("blockArea", 200*160) > (200*160)) {
    	Subsystems::intake.setArmsSpeed(0.8d);
    }
}

bool DriveAndTargetCube::IsFinished() {
//	if((pixyTable->GetNumber("blockArea", 32000) >= (130*200)) || pixyTable->GetNumber("blockArea", 32000) <= (100)) {
//		return true;
//	} else {
//		return false;
//	}
	return Subsystems::driveBase.getBeamBreak() || IsTimedOut();
}

void DriveAndTargetCube::Interrupted() {

}

void DriveAndTargetCube::End() {

}
