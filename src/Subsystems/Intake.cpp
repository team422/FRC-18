#include <Subsystems/Intake.hpp>

Intake::Intake() :
Subsystem("Intake"),
grabber(Ports::INTAKE_FORWARD, Ports::INTAKE_REVERSE),
pivot(Ports::INTAKE_PIVOT),
leftArm(Ports::INTAKE_LEFT_ARM),
rightArm(Ports::INTAKE_RIGHT_ARM),
upperSwitch(Ports::INTAKE_UPPER_SWITCH),
lowerSwitch(Ports::INTAKE_LOWER_SWITCH),
ultrasonic(Ports::INTAKE_ULTRASONIC) {
	leftArm.SetInverted(true);
#ifndef COMP_BOT
	pivot.SetInverted(true);
#endif
}

/**
 * Sets the speed of the arm rollers on the intake
 * A positive speed moves the rollers inwards, and a negative speed
 * moves them outwards
 */
void Intake::setArmsSpeed(float speed) {
	leftArm.Set(ControlMode::PercentOutput, speed);
	rightArm.Set(ControlMode::PercentOutput, speed);
}

void Intake::setArmsSpeed(float left, float right) {
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
void Intake::setPivotSpeed(float speed) {
	pivot.Set(ControlMode::PercentOutput, 0.0f);
	if (speed > 0 && !getLowerSwitchValue()) {
		pivot.Set(ControlMode::PercentOutput, speed);
	} else if (speed < 0 && !getUpperSwitchValue()) {
		pivot.Set(ControlMode::PercentOutput, speed);
	}
}

/**
 * Returns whether the upper limit switch is active
 */
bool Intake::getUpperSwitchValue() {
	return !upperSwitch.Get();
}

/**
 * Returns whether the lower limit switch is active
 */
bool Intake::getLowerSwitchValue() {
	return !lowerSwitch.Get();
}

/**
 * Returns the output current in the left arm roller motor
 */
float Intake::getLeftArmCurrent() {
	return leftArm.GetOutputCurrent();
}

/**
 * Returns the output current in the right arm roller motor
 */
float Intake::getRightArmCurrent() {
	return rightArm.GetOutputCurrent();
}

float Intake::getUltrasonicDistance() {
	return ultrasonic.GetAverageVoltage();
}
