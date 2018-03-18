#include "Guillotine.hpp"
#include "../RobotMap.h"

Guillotine::Guillotine() :
Subsystem("Guillotine"),
kicker(Ports::KICKER_FORWARD, Ports::KICKER_REVERSE),
lift(Ports::LIFT),
upperSwitch(Ports::GUILLOTINE_UPPER_SWITCH),
lowerSwitch(Ports::GUILLOTINE_LOWER_SWITCH) {

}

/**
 * Causes the guillotine to hold down
 */
void Guillotine::hold() {
	kicker.Set(DoubleSolenoid::Value::kForward);
}

/**
 * Causes the guillotine to kick
 */
void Guillotine::kick() {
	kicker.Set(DoubleSolenoid::Value::kReverse);
}

/**
 * Sets the lift to the given speed
 * A positive speed will cause the lift to rise, while a negative
 * speed will cause it to fall
 */
void Guillotine::setLiftSpeed(float speed) {
	lift.Set(ControlMode::PercentOutput, 0.0f);
	if (speed > 0) {
		lift.Set(ControlMode::PercentOutput, 0.3f);
	}
	if (speed > 0 && !getUpperSwitchValue()) {
		// If the lift can go up, let it
		lift.Set(ControlMode::PercentOutput, speed);
	} else if (speed < 0 && !getLowerSwitchValue()) {
		// If the lift can go down, let it
		lift.Set(ControlMode::PercentOutput, speed);
	}
}

/**
 * Returns whether the upper switch is active.
 * This occurs when the lift is fully raised
 */
bool Guillotine::getUpperSwitchValue() {
	return !upperSwitch.Get();
}

/**
 * Returns whether the lower switch is active.
 * This occurs when the lift is fully lowered
 */
bool Guillotine::getLowerSwitchValue() {
	return !lowerSwitch.Get();
}

int Guillotine::getLiftPosition() {
	return lift.GetSelectedSensorPosition(0);
}

void Guillotine::zeroLiftPosition() {
	lift.SetSelectedSensorPosition(0, 0, 1);
}
