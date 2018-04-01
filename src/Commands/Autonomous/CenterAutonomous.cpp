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
#include "../ArduinoControllerSendCommand.hpp"

CenterAutonomous::CenterAutonomous(char c) {
	AddSequential(new GuillotineHold());
	AddSequential(new IntakeGrab());
	if (c == 'L') {
		// Score on the left side on the front of the switch
		AddSequential(new DriveStraight(10.968, 0.5, true, 5));
		AddSequential(new Turn(-50, 0.7, 5));
		AddSequential(new DriveStraight(59.877, 0.5, true, 5));
		AddSequential(new Turn(50, 0.7, 5));
		AddSequential(new DriveStraight(50, 0.5, true, 2));
		AddSequential(new GuillotineKick());
		AddSequential(new PivotIntakeDown(0.3f));
		AddSequential(new WaitCommand(0.5f));
		AddSequential(new IntakeArmsOut());
		AddSequential(new WaitCommand(4));
		AddSequential(new IntakeArmsStop());
		AddSequential(new ArduinoControllerSendCommand());
	} else if (c == 'R') {
		// Score on the right side on the front of the switch
		AddSequential(new DriveStraight(10.968, 0.5, true, 5));
		AddSequential(new Turn(50, 0.7, 5));
		AddSequential(new DriveStraight(54.877, 0.5, true, 5));
		AddSequential(new Turn(-50, 0.7, 5));
		AddSequential(new DriveStraight(50, 0.5, true, 2));
		AddSequential(new GuillotineKick());
		AddSequential(new PivotIntakeDown(0.3f));
		AddSequential(new WaitCommand(0.5f));
		AddSequential(new IntakeArmsOut());
		AddSequential(new WaitCommand(4));
		AddSequential(new IntakeArmsStop());
		AddSequential(new ArduinoControllerSendCommand());
	}
}

