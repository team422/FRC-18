#include <Subsystems/Intake.hpp>

Intake::Intake() :
Subsystem("Intake"),
grabber(Ports::INTAKE_FORWARD, Ports::INTAKE_REVERSE),
pivot(Ports::INTAKE_PIVOT),
leftArm(Ports::INTAKE_LEFT_ARM),
rightArm(Ports::INTAKE_RIGHT_ARM),
upperSwitch(Ports::INTAKE_UPPER_SWITCH),
lowerSwitch(Ports::INTAKE_LOWER_SWITCH),
ultrasonic(Ports::INTAKE_ULTRASONIC),
isIntaking(false) {
	leftArm.SetInverted(true);
}

void Intake::stopArms() {
	leftArm.Set(ControlMode::PercentOutput, 0);
	rightArm.Set(ControlMode::PercentOutput, 0);
}

void Intake::setArmsIn() {
	leftArm.Set(ControlMode::PercentOutput, 0.4);
	rightArm.Set(ControlMode::PercentOutput, 0.4);
}

void Intake::setArmsOut() {
	leftArm.Set(ControlMode::PercentOutput, -0.4);
	rightArm.Set(ControlMode::PercentOutput, -0.4);
}

void Intake::grab() {
	grabber.Set(DoubleSolenoid::Value::kForward);
}

void Intake::release() {
	grabber.Set(DoubleSolenoid::Value::kReverse);
}

void Intake::stopPivot() {
	pivot.Set(ControlMode::PercentOutput, 0.0f);
}

void Intake::pivotUp() {
	stopPivot();
	if (!getLowerSwitchValue()) {
#ifndef COMP_BOT
		pivot.Set(ControlMode::PercentOutput, -0.85f);
#else
		pivot.Set(ControlMode::PercentOutput, 0.85f);
#endif
	}
}

void Intake::pivotDown() {
	stopPivot();
	if (!getUpperSwitchValue()) {
#ifndef COMP_BOT
		pivot.Set(ControlMode::PercentOutput, 0.85f);
#else
		pivot.Set(ControlMode::PercentOutput, -0.85f);
#endif
	}
}

void Intake::setPivotSpeed(float speed) {
	stopPivot();
	if (speed > 0) {
		if (!getLowerSwitchValue()) {
	#ifndef COMP_BOT
			pivot.Set(ControlMode::PercentOutput, speed);
	#else
			pivot.Set(ControlMode::PercentOutput, speed);
	#endif
		}
	} else {
		if (!getUpperSwitchValue()) {
	#ifndef COMP_BOT
			pivot.Set(ControlMode::PercentOutput, speed);
	#else
			pivot.Set(ControlMode::PercentOutput, speed);
	#endif
		}
	}
}

bool Intake::getUpperSwitchValue() {
	return !upperSwitch.Get();
}

bool Intake::getLowerSwitchValue() {
	return !lowerSwitch.Get();
}

float Intake::getLeftArmCurrent() {
	return leftArm.GetOutputCurrent();
}

float Intake::getRightArmCurrent() {
	return rightArm.GetOutputCurrent();
}

float Intake::getUltrasonicDistance() {
	return ultrasonic.GetAverageVoltage();
}
