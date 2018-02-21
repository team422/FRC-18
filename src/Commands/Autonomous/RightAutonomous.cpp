#include <Commands/DriveStraightBeamBreak.hpp>
#include "RightAutonomous.hpp"
#include "../DriveStraight.hpp"
#include "../GuillotineHold.hpp"
#include "../GuillotineKick.hpp"
#include "../IntakeGrab.hpp"
#include "../PivotIntakeDown.hpp"
#include "../IntakeArmsOut.hpp"
#include "../IntakeArmsStop.hpp"
#include "../Turn.hpp"

RightAutonomous::RightAutonomous() {

}

void RightAutonomous::setShouldScore(bool shouldScore) {
	AddSequential(new GuillotineHold());
	AddSequential(new IntakeGrab());
	if (shouldScore) {
		AddSequential(new DriveStraight(140.275, 0.5, true, 10.0));
		AddSequential(new Turn(-90.0, 0.7, 8.0));
		AddSequential(new DriveStraightBeamBreak(0.3, 5.0));
		AddSequential(new DriveStraight(1, 0.3, true, 1));
		AddSequential(new GuillotineKick());
		AddSequential(new PivotIntakeDown(0.1f));
		AddSequential(new IntakeArmsOut());
		AddSequential(new WaitCommand(4));
		AddSequential(new IntakeArmsStop());
	} else {
		AddSequential(new DriveStraight(180.0, 0.3, true, 10.0));
	}
}
