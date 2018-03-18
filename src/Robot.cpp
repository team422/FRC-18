#include "Commands/IntakeBox.hpp"
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
	Subsystems::guillotine.zeroLiftPosition();
}

void Robot::DisabledInit() {
	Subsystems::arduino.sendCommand("0001111");
}

void Robot::DisabledPeriodic() {
	printDataToSmartDashboard();
}

void Robot::AutonomousInit() {
	Subsystems::arduino.sendCommand("0005551");
	std::string gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	if (UserInterface::userInterface.launchpad.getMultiSwitchLeft()) {
		leftAuto.setShouldScore(gameData, UserInterface::userInterface.launchpad.getSwitch1());
		leftAuto.Start();
	} else if (UserInterface::userInterface.launchpad.getMultiSwitchInactive()) {
		centerAuto.setSideToScore(gameData[0]);
		centerAuto.Start();
	} else if (UserInterface::userInterface.launchpad.getMultiSwitchRight()) {
		rightAuto.setShouldScore(gameData, UserInterface::userInterface.launchpad.getSwitch1());
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
		Subsystems::guillotine.setLiftSpeed(1.0f);
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
		Subsystems::intake.setArmsSpeed(-0.9f);
	}
	Subsystems::intake.setPivotSpeed(0.0f);
	if (UserInterface::userInterface.controller.getLeftJoystickY() < -0.6f) {
		Subsystems::intake.setPivotSpeed(-UserInterface::userInterface.controller.getLeftJoystickY());
	} else if (UserInterface::userInterface.controller.getRightJoystickY() < -0.2f) {
		Subsystems::intake.setPivotSpeed(UserInterface::userInterface.controller.getRightJoystickY());
	}
	Scheduler::GetInstance()->Run();
	printDataToSmartDashboard();
}

void Robot::printDataToSmartDashboard() {
	SmartDashboard::PutNumber("Ultrasonic", Subsystems::intake.getUltrasonicDistance());
	SmartDashboard::PutBoolean("Lift Upper Switch", Subsystems::guillotine.getUpperSwitchValue());
	SmartDashboard::PutBoolean("Lift Lower Switch", Subsystems::guillotine.getLowerSwitchValue());
	SmartDashboard::PutBoolean("Intake Upper Switch", Subsystems::intake.getUpperSwitchValue());
	SmartDashboard::PutBoolean("Intake Lower Switch", Subsystems::intake.getLowerSwitchValue());
	SmartDashboard::PutNumber("Guillotine Position", Subsystems::guillotine.getLiftPosition());
	SmartDashboard::PutNumber("Left Encoder", Subsystems::driveBase.getLeftPosition());
	SmartDashboard::PutNumber("Right Encoder", Subsystems::driveBase.getRightPosition());
	SmartDashboard::PutNumber("Left Arm Current", Subsystems::intake.getLeftArmCurrent());
	SmartDashboard::PutNumber("Right Arm Current", Subsystems::intake.getRightArmCurrent());
	SmartDashboard::PutNumber("Xbox POV", UserInterface::userInterface.controller.getPOVAngle());
}

START_ROBOT_CLASS(Robot);
