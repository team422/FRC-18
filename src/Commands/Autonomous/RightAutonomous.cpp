#include "RightAutonomous.hpp"
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
#include "../../UserInterface/UI.hpp"

RightAutonomous::RightAutonomous(std::string gameData, bool scale) {
	AddSequential(new GuillotineHold());
	AddSequential(new IntakeGrab());
	if (gameData[1] == 'R' && scale) {
		AddSequential(new DriveStraight(260.975f, 0.9f, true, 8.0f));
		AddSequential(new Turn(-94, 0.7f, 3.0f));
		AddSequential(new IntakeRelease());
		AddParallel(new DriveStraight(8, 0.5f, false, 0.6f));
		AddSequential(new GuillotineRaise());
		AddSequential(new DriveStraight(18, 0.5f, true, 1.5f));
		AddSequential(new GuillotineKick());
		AddSequential(new ArduinoControllerSendCommand());
		AddSequential(new DriveStraight(16, 0.3f, false, 1.5f));
		AddParallel(new GuillotineLower());
		if (UserInterface::userInterface.launchpad.getSwitch4()) {
			AddSequential(new Turn(-65.0f, 0.7f, 1.0f));
			AddSequential(new DriveStraight(48.0f, 0.9f, true, 3.0f));
			AddSequential(new IntakeArmsIn());
			AddSequential(new DriveStraight(48.0f, 0.3f, true, 1.0f));
			AddSequential(new IntakeGrab());
			AddSequential(new WaitCommand(0.2f));
		}
	} else if (gameData[1] == 'L' && scale && !UserInterface::userInterface.launchpad.getSwitch2()) {
		// If switch 2 is up, disable this mode
		AddSequential(new DriveStraight(190.438, 0.9, true, 40));
		AddSequential(new Turn(-87.0f, 0.7, 40));
		AddSequential(new DriveStraight(140.625, 0.9, true, 40));
		AddSequential(new Turn(98.0f,0.7,40));
		AddParallel(new IntakeRelease());
		AddSequential(new GuillotineRaise());
		AddSequential(new DriveStraight(52.057, 0.5, true, 0.9f));
		AddSequential(new GuillotineKick());
		AddSequential(new ArduinoControllerSendCommand());
		AddSequential(new DriveStraight(16, 0.3f, false, 1.5f));
	} else if (gameData[0] == 'R') {
		// Right-side switch
		AddSequential(new DriveStraight(114.275f, 0.9f, true, 6.0f));
		AddSequential(new Turn(-90.0f, 0.7f, 3.0f));
		AddSequential(new DriveStraight(24.0f, 0.4f, true, 1.0f));
		AddSequential(new GuillotineKick());
		AddSequential(new PivotIntakeDown(0.2f));
		AddSequential(new IntakeArmsOut());
		AddSequential(new ArduinoControllerSendCommand());
		AddSequential(new WaitCommand(4));
		AddSequential(new IntakeArmsStop());
	} else {
		// Left-side switch
		AddSequential(new DriveStraight(187.53, 0.9f, true, 8.0f));
//		AddSequential(new Turn(-90.0f, 0.7f, 3.0f));
//		AddSequential(new DriveStraight(187.534, 0.9f, true, 1.5f));
//		AddSequential(new Turn(-90, 0.7f, 3.0f));
//		AddSequential(new DriveStraight(42.0f, 0.3f, true, 1.0f));
//		AddSequential(new GuillotineKick());
//		AddSequential(new PivotIntakeDown(0.1));
//		AddSequential(new IntakeArmsOut());
//		AddSequential(new ArduinoControllerSendCommand());
//		AddSequential(new WaitCommand(3));
//		AddSequential(new IntakeArmsStop());
	}
}
