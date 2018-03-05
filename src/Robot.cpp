#include "Commands/IntakeBox.hpp"
#include "Commands/GuillotineScore.hpp"
#include "Commands/PivotIntakeDown.hpp"
#include "Commands/PivotIntakeUp.hpp"
#include "Commands/IntakeGrab.hpp"
#include "Commands/IntakeRelease.hpp"
#include "Commands/GuillotineHold.hpp"
#include "Commands/GuillotineKick.hpp"
#include "Robot.hpp"
#include "UserInterface/UI.hpp"

void Robot::RobotInit() {
	Subsystems::compressor.Start();
	UserInterface::userInterface.controller.A.WhenPressed(new IntakeGrab());
	UserInterface::userInterface.controller.B.WhenPressed(new IntakeRelease());
	UserInterface::userInterface.controller.LB.WhenPressed(new GuillotineHold());
	UserInterface::userInterface.controller.RB.WhenPressed(new GuillotineKick());
	UserInterface::userInterface.controller.START.WhenPressed(new IntakeBox());
	camera = CameraServer::GetInstance()->StartAutomaticCapture();
	Subsystems::arduino.sendCommand("0001111");
}

void Robot::DisabledInit() {
	Subsystems::arduino.sendCommand("0001111");
}

void Robot::DisabledPeriodic() {
	SmartDashboard::PutBoolean("Lift Upper Switch", Subsystems::guillotine.getUpperSwitchValue());
	SmartDashboard::PutBoolean("Lift Lower Switch", Subsystems::guillotine.getLowerSwitchValue());
	SmartDashboard::PutBoolean("Intake Upper Switch", Subsystems::intake.getUpperSwitchValue());
	SmartDashboard::PutBoolean("Intake Lower Switch", Subsystems::intake.getLowerSwitchValue());
}

void Robot::AutonomousInit() {
	Subsystems::arduino.sendCommand("0005551");
	std::string gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	if (UserInterface::userInterface.launchpad.getMultiSwitchLeft()) {
		if (UserInterface::userInterface.launchpad.getSwitch1()) {
			leftAuto.setShouldScore(gameData[1], true);
		} else {
			leftAuto.setShouldScore(gameData[0], false);
		}
		leftAuto.Start();
	} else if (UserInterface::userInterface.launchpad.getMultiSwitchInactive()) {
		centerAuto.setSideToScore(gameData[0], true);
		centerAuto.Start();
	} else if (UserInterface::userInterface.launchpad.getMultiSwitchRight()) {
		if (UserInterface::userInterface.launchpad.getSwitch1()) {
			rightAuto.setShouldScore(gameData[1], true);
		} else {
			rightAuto.setShouldScore(gameData[0], false);
		}
		rightAuto.Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kRed) {
		Subsystems::arduino.sendCommand("0003331");
	} else {
		Subsystems::arduino.sendCommand("0002221");
	}
	leftAuto.Cancel();
	centerAuto.Cancel();
	rightAuto.Cancel();
}

void Robot::TeleopPeriodic() {
	Subsystems::guillotine.setLiftSpeed(0.0f);
	if (UserInterface::userInterface.controller.X.Get()) {
		Subsystems::intake.release();
		Subsystems::guillotine.setLiftSpeed(0.9f);
	} else if (UserInterface::userInterface.controller.Y.Get()) {
		Subsystems::guillotine.setLiftSpeed(-0.4f);
		if (Subsystems::guillotine.getLowerSwitchValue()) {
			Subsystems::guillotine.kick();
		}
	}
	Subsystems::intake.setArmsSpeed(0.0f);
	if (UserInterface::userInterface.controller.getLeftTrigger() > 0.1f) {
		Subsystems::intake.setArmsSpeed(0.5f);
	} else if (UserInterface::userInterface.controller.getRightTrigger() > 0.1f) {
		Subsystems::intake.setArmsSpeed(-1.0f);
	}
	Subsystems::intake.setPivotSpeed(0.0f);
	if (UserInterface::userInterface.controller.getLeftJoystickY() < -0.6f) {
		Subsystems::intake.setPivotSpeed(-UserInterface::userInterface.controller.getLeftJoystickY());
	} else if (UserInterface::userInterface.controller.getRightJoystickY() < -0.2f) {
		Subsystems::intake.setPivotSpeed(UserInterface::userInterface.controller.getRightJoystickY());
	}
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("Ultrasonic", Subsystems::intake.getUltrasonicDistance());
	SmartDashboard::PutBoolean("Lift Upper Switch", Subsystems::guillotine.getUpperSwitchValue());
	SmartDashboard::PutBoolean("Lift Lower Switch", Subsystems::guillotine.getLowerSwitchValue());
	SmartDashboard::PutBoolean("Intake Upper Switch", Subsystems::intake.getUpperSwitchValue());
	SmartDashboard::PutBoolean("Intake Lower Switch", Subsystems::intake.getLowerSwitchValue());
	SmartDashboard::PutNumber("Guillotine Position", Subsystems::guillotine.getLiftPosition());
}

START_ROBOT_CLASS(Robot);
