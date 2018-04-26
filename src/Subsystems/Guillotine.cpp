#include "Guillotine.hpp"
#include "../RobotMap.h"

/**
 * Represents one instance of the Guillotine subsystems
 *
 * Includes all motor controllers and any sensors attached to them
 */
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
 * Sets the lift to the given speed.
 * A positive speed will cause the lift to rise, while a negative
 * speed will cause it to fall
 * @param speed The speed to set the lift to
 */
void Guillotine::setLiftSpeed(double speed) {
	// Set the speed to zero to start, if it should be something else, it will be set later
	double target = 0.0d;
	if (speed > 0) {
		target = 0.3d;
	}
	if (speed > 0 && !getUpperSwitchValue()) {
		// If the lift can go up, let it
		target = speed;
	} else if (speed < 0 && !getLowerSwitchValue()) {
		// If the lift can go down, let it
		target = speed;
	}
	lift.Set(ControlMode::PercentOutput, target);
}

/**
 * Gets whether the upper switch is active.
 * This occurs when the lift is fully raised
 * @return A boolean representing the state of the upper switch
 */
bool Guillotine::getUpperSwitchValue() {
	return !upperSwitch.Get();
}

/**
 * Gets whether the lower switch is active.
 * This occurs when the lift is fully lowered
 * @return A boolean representing the state of the lower switch
 */
bool Guillotine::getLowerSwitchValue() {
	return !lowerSwitch.Get();
}

/**
 * Gets the position of the lift from the encoder
 * @return The position of the lift
 */
int Guillotine::getLiftPosition() {
	return abs(lift.GetSelectedSensorPosition(0));
}

/**
 * Sets the lift position to zero.
 * This should only be done when the lift is fully lowered
 */
void Guillotine::zeroLiftPosition() {
	lift.SetSelectedSensorPosition(0, 0, 10);
	lift.GetSensorCollection().SetQuadraturePosition(0, 10);
}
