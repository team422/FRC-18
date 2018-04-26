#include "TurnAndTargetCube.hpp"

#include "../Subsystems/Subsystems.hpp"
#include "../Util/Numbers.hpp"
#include <networktables/NetworkTableInstance.h>

TurnAndTargetCube::TurnAndTargetCube(double speed, Direction defaultDirection, double timeout) :
	Command("Turn", timeout),
	speed(speed),
	defaultDirection(defaultDirection),
	done(false) {
		Requires(&Subsystems::driveBase);
}

void TurnAndTargetCube::Initialize() {
	pixyTable = nt::NetworkTableInstance::GetDefault().GetTable("pixy");
}

void TurnAndTargetCube::Execute() {
	double centerX = pixyTable->GetNumber("blockX", 160);
	if (!Numbers::inRange(centerX, 160, 35)) {
		if (centerX < 160) {
			Subsystems::driveBase.setMotors(0.3d, -0.3d);
		} else {
			Subsystems::driveBase.setMotors(-0.3d, 0.3d);
		}
	} else {
		Subsystems::driveBase.setMotors(0.0d, 0.0d);
		done = true;
	}
}

bool TurnAndTargetCube::IsFinished() {
	return done;
}

void TurnAndTargetCube::Interrupted() {
	Subsystems::driveBase.setMotors(0,0);
}

void TurnAndTargetCube::End() {
	Subsystems::driveBase.setMotors(0,0);
	Subsystems::driveBase.zeroGyroAngle();
}
