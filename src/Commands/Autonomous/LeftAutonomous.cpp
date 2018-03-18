#include "LeftAutonomous.hpp"
#include "../DriveStraightBeamBreak.hpp"
#include "../DriveStraight.hpp"
#include "../GuillotineHold.hpp"
#include "../GuillotineKick.hpp"
#include "../GuillotineRaise.hpp"
#include "../GuillotineLower.hpp"
#include "../IntakeGrab.hpp"
#include "../IntakeRelease.hpp"
#include "../PivotIntakeDown.hpp"
#include "../IntakeArmsIn.hpp"
#include "../IntakeArmsOut.hpp"
#include "../IntakeArmsStop.hpp"
#include "../IntakeBox.hpp"
#include "../Turn.hpp"
#include "../ArduinoControllerSendCommand.hpp"

LeftAutonomous::LeftAutonomous() {

}

void LeftAutonomous::setShouldScore(std::string gameData, bool scale) {
	AddSequential(new GuillotineHold());
	AddSequential(new IntakeGrab());
	if (gameData[1] == 'L' && scale) {
		AddSequential(new DriveStraight(165.145, 0.5, true, 40));
		AddSequential(new Turn(30.3, 0.7, 40));
		AddSequential(new DriveStraight(59.0, 0.5, true, 40));
		AddSequential(new IntakeRelease());
		AddSequential(new GuillotineRaise());
		AddSequential(new Turn(-30.3, 0.7, 40));
		AddSequential(new WaitCommand(0.5));
		AddSequential(new DriveStraight(12, 0.3, true, 1.5f));
		AddSequential(new GuillotineKick());
		AddSequential(new WaitCommand(1));
		AddSequential(new DriveStraight(16, 0.3, false, 1.5f));
	} else if (gameData[0] == 'L') {
		AddSequential(new DriveStraight(132.275, 0.5, true, 6.0f));
		AddSequential(new Turn(90.0, 0.7, 3.0f));
		AddSequential(new DriveStraight(20, 0.3, true, 1.5));
		AddSequential(new GuillotineKick());
		AddSequential(new PivotIntakeDown(0.2f));
		AddSequential(new IntakeArmsOut());
		AddSequential(new WaitCommand(4));
		AddSequential(new IntakeArmsStop());
	} else {
		AddSequential(new DriveStraight(236.529, 0.5, true, 10.0));
		AddSequential(new Turn(90, 0.7, 10.0));
		AddSequential(new DriveStraight(141.534, 0.7, true, 10.0));
		AddSequential(new Turn(90, 0.7, 10.0));
		AddSequential(new DriveStraight(18, 0.3, true, 10.0));
		AddSequential(new DriveStraightBeamBreak(0.3, 2.0));
		AddSequential(new DriveStraight(1, 0.3, true, 10.0));
		AddSequential(new GuillotineKick());
		AddSequential(new PivotIntakeDown(0.2));
		AddSequential(new WaitCommand(1));
		AddSequential(new IntakeArmsOut());
		AddSequential(new WaitCommand(3));
		AddSequential(new IntakeArmsStop());
	}
	AddSequential(new ArduinoControllerSendCommand());
}
