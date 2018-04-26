#include "PixyTest.hpp"

#include "../TurnAndTargetCube.hpp"
#include "../DriveAndTargetCube.hpp"
#include "../DriveStraight.hpp"
#include "../IntakeRelease.hpp"
#include "../IntakeSetArmSpeed.hpp"
#include "../IntakeBox.hpp"
#include "../IntakePivot.hpp"

PixyTest::PixyTest() {
//	AddSequential(new IntakePivot(Direction::DOWN, false, 1.5d));
	AddSequential(new IntakeRelease());
	AddSequential(new IntakeSetArmSpeed(0.4d));
//	AddSequential(new TurnAndTargetCube(0.2, Direction::LEFT, 20));
	AddSequential(new DriveAndTargetCube(0.3d, Direction::FORWARD, 20));
	AddSequential(new WaitCommand(0.5d));
	AddSequential(new IntakeSetArmSpeed(0.0d));
	AddSequential(new IntakeBox());
//    AddSequential(new DriveStraight(1000, 0.4, Direction::FORWARD, 100));
//	AddSequential(new WaitCommand(2));
//	AddSequential(new DriveStraight(1.5*12, 0.4, Direction::FORWARD, 3));
//	AddSequential(new WaitCommand(0.5));
//	AddSequential(new IntakeSetArmSpeed(0.0));
//	AddSequential(new IntakeBox());
}

