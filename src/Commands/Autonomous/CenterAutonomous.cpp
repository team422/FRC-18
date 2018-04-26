#include "CenterAutonomous.hpp"

#include "../ArduinoControllerSendCommand.hpp"
#include "../DriveStraight.hpp"
#include "../DriveStraightBeamBreak.hpp"
#include "../GuillotineHold.hpp"
#include "../GuillotineKick.hpp"
#include "../IntakeBox.hpp"
#include "../IntakeGrab.hpp"
#include "../IntakePivot.hpp"
#include "../IntakeRelease.hpp"
#include "../IntakeSetArmSpeed.hpp"
#include "../Turn.hpp"

CenterAutonomous::CenterAutonomous(char c) {
	AddSequential(new GuillotineHold());
	AddSequential(new IntakeGrab());
	if (c == 'L') {
		// Score on the left side on the front of the switch
		AddSequential(new DriveStraight(10.968, 0.5, Direction::FORWARD, 2.0d));
		AddSequential(new Turn(-50, 0.7, 5));
		AddSequential(new DriveStraight(54.877, 0.9, Direction::FORWARD, 5));
		AddSequential(new Turn(50, 0.7, 5));
		AddSequential(new DriveStraight(50, 0.9, Direction::FORWARD, 1.0d));
		AddSequential(new GuillotineKick());
		AddSequential(new IntakePivot(Direction::DOWN, false, 0.3f));
		AddSequential(new WaitCommand(0.5f));
		AddSequential(new IntakeSetArmSpeed(-0.4d));
		AddSequential(new ArduinoControllerSendCommand());
		AddSequential(new WaitCommand(1));
		AddSequential(new IntakeSetArmSpeed(0.0d));
		// Two Cube


		AddSequential(new IntakePivot(Direction::UP, false, 1.0d));
		AddSequential(new DriveStraight(10.968, 0.5, Direction::REVERSE, 2.0d));
		AddSequential(new Turn(133.567, 0.7, 2));
		AddSequential(new DriveStraight(42.704d, 0.9d, Direction::FORWARD, 2.0d));
		AddSequential(new Turn(-133.567, 0.7, 2));
		AddSequential(new IntakePivot(Direction::DOWN, true, 0.5));
		AddSequential(new IntakeRelease());
		AddSequential(new IntakeSetArmSpeed(0.8));
		AddSequential(new DriveStraight(50, 0.5, Direction::FORWARD, 1.0d));
//		AddSequential(new WaitCommand(0.5d));
//		AddSequential(new IntakeSetArmSpeed(0));
//		AddSequential(new IntakeBox());
//		AddSequential(new DriveStraight(15, 0.9, Direction::REVERSE, 2));
//		AddSequential(new Turn(-46.433, 0.7, 2));
//		AddSequential(new DriveStraight(82.704, 0.9, true, 2));
//		AddSequential(new Turn(46.433, 0.7, 2));
//		AddSequential(new DriveStraightBeamBreak(0.9, 3));
//		AddSequential(new GuillotineKick());
//		AddSequential(new IntakePivot(Direction::DOWN, true, 0.5));
//		AddSequential(new WaitCommand(0.5f));
//		AddSequential(new IntakeSetArmSpeed(-0.4));
//		AddSequential(new WaitCommand(1));
//		AddSequential(new IntakeSetArmSpeed(0));
//		AddSequential(new ArduinoControllerSendCommand());
	} else if (c == 'R') {
		// Score on the right side on the front of the switch
		AddSequential(new DriveStraight(10.968, 0.5, Direction::FORWARD, 2.0d));
		AddSequential(new Turn(50, 0.7, 5));
		AddSequential(new DriveStraight(49.877, 0.9, Direction::FORWARD, 5));
		AddSequential(new Turn(-50, 0.7, 5));
//		AddSequential(new DriveStraight(50, 0.9, Direction::FORWARD, 1.0d));
        AddSequential(new DriveStraightBeamBreak(0.9d, 1.0d));
		AddSequential(new GuillotineKick());
		AddSequential(new IntakePivot(Direction::DOWN, false, 0.3f));
		AddSequential(new WaitCommand(0.5f));
		AddSequential(new IntakeSetArmSpeed(-0.4d));
		AddSequential(new ArduinoControllerSendCommand());
		AddSequential(new WaitCommand(2));
		AddSequential(new IntakeSetArmSpeed(0.0d));
	}
}

