#include <Commands/DriveStraightBeamBreak.hpp>
#include "CenterAutonomous.hpp"
#include "../DriveStraight.hpp"
#include "../GuillotineHold.hpp"
#include "../GuillotineKick.hpp"
#include "../IntakeGrab.hpp"
#include "../PivotIntakeDown.hpp"
#include "../PivotIntakeUp.hpp"
#include "../IntakeArmsOut.hpp"
#include "../IntakeArmsStop.hpp"
#include "../Turn.hpp"

CenterAutonomous::CenterAutonomous() {

}

/**
 * c		the side to go to ('L' or 'R')
 * mode		the part of the switch to go to
 * 				0 = front
 * 				1 = side
 * score	should the robot score
 */
void CenterAutonomous::setSideToScore(char c, int mode, bool score) {
	AddSequential(new GuillotineHold());
	AddSequential(new IntakeGrab());
	if (c == 'L' && mode == 0 && score) {
		// Score on the left side on the front of the switch
		AddSequential(new DriveStraight(10.968, 0.5, true, 5));
		AddSequential(new Turn(-50, 0.7, 5));
		AddSequential(new DriveStraight(60.877, 0.5, true, 5));
		AddSequential(new Turn(50, 0.7, 5));
		AddSequential(new DriveStraightBeamBreak(0.3, 5));
		AddSequential(new DriveStraight(1, 0.3, true, 5));
		AddSequential(new GuillotineKick());
		AddSequential(new PivotIntakeDown(0.1f));
		AddSequential(new IntakeArmsOut());
		AddSequential(new WaitCommand(1));
		AddSequential(new IntakeArmsStop());
		AddSequential(new PivotIntakeUp(true, 0.2f));
		AddSequential(new DriveStraight(50, 0.5, false, 5));
		AddSequential(new Turn(90, 0.7, 2));
	} else if (c == 'R' && mode == 0 && score) {
		// Score on the right side on the front of the switch
		AddSequential(new DriveStraight(10.968, 0.5, true, 5));
		AddSequential(new Turn(50, 0.7, 5));
		AddSequential(new DriveStraight(60.877, 0.5, true, 5));
		AddSequential(new Turn(-50, 0.7, 5));
		AddSequential(new DriveStraightBeamBreak(0.3, 5));
		AddSequential(new DriveStraight(1, 0.3, true, 5));
		AddSequential(new GuillotineKick());
		AddSequential(new PivotIntakeDown(0.1f));
		AddSequential(new IntakeArmsOut());
		AddSequential(new WaitCommand(1));
		AddSequential(new IntakeArmsStop());
		AddSequential(new PivotIntakeUp(true, 0.2f));
		AddSequential(new DriveStraight(50, 0.5, false, 5));
		AddSequential(new Turn(-90, 0.7, 2));
//	} else if (c == 'L' && mode == 1 && score) {
//		// Score on the left side on the side of the switch
//		AddSequential(new DriveStraight(10.968, 0.5, 40));
//		AddSequential(new Turn(-50, 0.35, 40));
//		AddSequential(new DriveStraight(143.285, 0.5, 40));
//		AddSequential(new Turn(50, 0.35, 40));
//		AddSequential(new DriveStraight(17.122, 0.5, 40));
//		AddSequential(new Turn(90, 0.35, 40));
//		AddSequential(new DriveStraightBeamBrake(0.3, 20));
//	} else if (c == 'R' && mode == 1 && score) {
//		// Score on the right side on the side of the switch
//		AddSequential(new DriveStraight(10.968, 0.5, 40));
//		AddSequential(new Turn(50, 0.35, 40));
//		AddSequential(new DriveStraight(143.285, 0.5, 40));
//		AddSequential(new Turn(-50, 0.35, 40));
//		AddSequential(new DriveStraight(17.122, 0.5, 40));
//		AddSequential(new Turn(-90, 0.35, 40));
//		AddSequential(new DriveStraightBeamBrake(0.3, 20));
//	} else if (c == 'L' && mode == 0 && !score) {
//		// Move to the left front of the switch
//		AddSequential(new DriveStraight(10.968, 0.5, 40));
//		AddSequential(new Turn(-50, 0.7, 40));
//		AddSequential(new DriveStraight(60.877, 0.5, 40));
//		AddSequential(new Turn(50, 0.7, 40));
//		AddSequential(new DriveStraightBeamBrake(0.3, 20));
//		AddSequential(new DriveStraight(1, 0.3, 10));
//	} else if (c == 'R' && mode == 0 && !score) {
//		// Move to the right front of the switch
//		AddSequential(new DriveStraight(10.968, 0.5, 40));
//		AddSequential(new Turn(50, 0.7, 40));
//		AddSequential(new DriveStraight(60.877, 0.5, 40));
//		AddSequential(new Turn(-50, 0.7, 40));
//		AddSequential(new DriveStraightBeamBrake(0.3, 20));
//		AddSequential(new DriveStraight(1, 0.3, 10));
//	} else if (c == 'L' && mode == 1 && !score) {
//		// Move to the left side of the switch
//		AddSequential(new DriveStraight(10.968, 0.5, 40));
//		AddSequential(new Turn(-50, 0.35, 40));
//		AddSequential(new DriveStraight(143.285, 0.5, 40));
//		AddSequential(new Turn(50, 0.35, 40));
//		AddSequential(new DriveStraight(17.122, 0.5, 40));
//		AddSequential(new Turn(90, 0.35, 40));
//		AddSequential(new DriveStraightBeamBrake(0.3, 20));
//	} else if (c == 'R' && mode == 1 && !score) {
//		// Move to the right side of the switch
//		AddSequential(new DriveStraight(10.968, 0.5, 40));
//		AddSequential(new Turn(50, 0.35, 40));
//		AddSequential(new DriveStraight(143.285, 0.5, 40));
//		AddSequential(new Turn(-50, 0.35, 40));
//		AddSequential(new DriveStraight(17.122, 0.5, 40));
//		AddSequential(new Turn(-90, 0.35, 40));
//		AddSequential(new DriveStraightBeamBrake(0.3, 20));
	}
}

