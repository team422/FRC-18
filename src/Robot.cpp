#include "Commands/IntakeBox.hpp"
#include "Commands/GuillotineScore.hpp"
#include "Commands/PivotIntakeDown.hpp"
#include "Commands/PivotIntakeUp.hpp"
#include "Commands/IntakeGrab.hpp"
#include "Commands/IntakeRelease.hpp"
#include "Commands/GuillotineHold.hpp"
#include "Commands/GuillotineKick.hpp"
#include "Robot.hpp"

void Robot::RobotInit() {
	Subsystems::compressor.Start();
	Subsystems::userInterface.controller.A.WhenPressed(new IntakeGrab());
	Subsystems::userInterface.controller.B.WhenPressed(new IntakeRelease());
	Subsystems::userInterface.controller.LB.WhenPressed(new GuillotineHold());
	Subsystems::userInterface.controller.RB.WhenPressed(new GuillotineKick());
	Subsystems::userInterface.controller.START.WhenPressed(new IntakeBox());
	camera = CameraServer::GetInstance()->StartAutomaticCapture();
}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {

}

void Robot::AutonomousInit() {
	std::string gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	int position = 0; // Get position data from DS
	if (position == 0) {
		leftAuto.setShouldScore(true, true);
		leftAuto.Start();
	} else if (position == 1) {
		centerAuto.setSideToScore(gameData[0], 0, true);
		centerAuto.Start();
	} else if (position == 2) {
		rightAuto.setShouldScore(gameData[0] == 'R' ? true : false);
		rightAuto.Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	leftAuto.Cancel();
	centerAuto.Cancel();
	rightAuto.Cancel();
}

void Robot::TeleopPeriodic() {
	Subsystems::guillotine.stopLift();
	if (Subsystems::userInterface.controller.X.Get()) {
		Subsystems::guillotine.raiseLift();
	} else if (Subsystems::userInterface.controller.Y.Get()) {
		Subsystems::guillotine.lowerLift();
	}
	Subsystems::intake.stopArms();
	if (Subsystems::userInterface.controller.getLeftTrigger() > 0.1f) {
		Subsystems::intake.setArmsIn();
	} else if (Subsystems::userInterface.controller.getRightTrigger() > 0.1f) {
		Subsystems::intake.setArmsOut();
	}
	Subsystems::intake.setPivotSpeed(Subsystems::userInterface.controller.getLeftJoystickY());
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("Ultrasonic", Subsystems::intake.getUltrasonicDistance());
}

START_ROBOT_CLASS(Robot);
