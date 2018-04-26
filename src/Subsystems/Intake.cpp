#include "Intake.hpp"

Intake::Intake() :
	Subsystem("Intake"),
	grabber(Ports::INTAKE_FORWARD, Ports::INTAKE_REVERSE),
	pivot(Ports::INTAKE_PIVOT),
	leftArm(Ports::INTAKE_LEFT_ARM),
	rightArm(Ports::INTAKE_RIGHT_ARM),
	upperSwitch(Ports::INTAKE_UPPER_SWITCH),
	lowerSwitch(Ports::INTAKE_LOWER_SWITCH) {
		leftArm.SetInverted(true);
#ifndef COMP_BOT
		pivot.SetInverted(true);
#endif
}

/**
 * Sets the speed of the arm rollers on the intake
 * A positive speed moves the rollers inwards, and a negative speed
 * moves them outwards
 * @param speed The target roller speed
 */
void Intake::setArmsSpeed(double speed) {
	leftArm.Set(ControlMode::PercentOutput, speed);
	rightArm.Set(ControlMode::PercentOutput, speed);
}

/**
 * Sets the speed of the arm rollers individually.
 * A positive speed moves the rollers inwards, and a negative speed
 * moves them outwards.
 * @param left  The left side target speed
 * @param right The right side target speed
 */
void Intake::setArmsSpeed(double left, double right) {
	leftArm.Set(ControlMode::PercentOutput, left);
	rightArm.Set(ControlMode::PercentOutput, right);
}

/**
 * Causes the intake to grab
 */
void Intake::grab() {
	grabber.Set(DoubleSolenoid::Value::kForward);
}

/**
 * Causes the intake to release
 */
void Intake::release() {
	grabber.Set(DoubleSolenoid::Value::kReverse);
}

/**
 * Sets the intake pivot speed
 * A positive value will cause the intake to pivot up, and a negative
 * value will cause it to pivot down
 */
void Intake::setPivotSpeed(double speed) {
//	pivot.Set(ControlMode::PercentOutput, 0.0f);
//	if (speed > 0 && !getLowerSwitchValue()) {
//		pivot.Set(ControlMode::PercentOutput, speed);
//	} else if (speed < 0 && !getUpperSwitchValue()) {
//		pivot.Set(ControlMode::PercentOutput, speed);
//	}
	double target = 0.0d;
	if (speed > 0 && !getLowerSwitchValue()) {
		target = speed;
	} else if (speed < 0 && !getUpperSwitchValue()) {
		target = speed;
	}
	pivot.Set(ControlMode::PercentOutput, target);
}

/**
 * Gets whether the upper limit switch is active
 * @return A boolean representing whether the upper switch is active or not
 */
bool Intake::getUpperSwitchValue() {
	return !upperSwitch.Get();
}

/**
 * Gets whether the lower limit switch is active
 * @return A boolean representing whether the lower switch is active or not
 */
bool Intake::getLowerSwitchValue() {
	return !lowerSwitch.Get();
}

/**
 * Gets the output current in the left arm roller motor
 * @return The left arm motor's output current
 */
double Intake::getLeftArmCurrent() {
	return leftArm.GetOutputCurrent();
}

/**
 * Gets the output current in the right arm roller motor
 * @return The right arm motor's output current
 */
double Intake::getRightArmCurrent() {
	return rightArm.GetOutputCurrent();
}
