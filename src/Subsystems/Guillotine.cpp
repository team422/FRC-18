#include "Guillotine.hpp"
#include "../RobotMap.h"

Guillotine::Guillotine() :
Subsystem("Guillotine"),
kicker(Ports::KICKER_FORWARD, Ports::KICKER_REVERSE),
lift(Ports::LIFT),
upperSwitch(Ports::GUILLOTINE_UPPER_SWITCH),
lowerSwitch(Ports::GUILLOTINE_LOWER_SWITCH) {

}

Guillotine::~Guillotine() {

}

void Guillotine::hold() {
	kicker.Set(DoubleSolenoid::Value::kForward);
}

void Guillotine::kick() {
	kicker.Set(DoubleSolenoid::Value::kReverse);
}

void Guillotine::raiseLift() {
	if (!getUpperSwitchValue()) {
		lift.Set(ControlMode::PercentOutput, 0.9f);
	} else {
		stopLift();
	}
}

void Guillotine::lowerLift() {
	if (!getLowerSwitchValue()) {
		lift.Set(ControlMode::PercentOutput, -0.4f);
	} else {
		stopLift();
	}
}

void Guillotine::stopLift() {
	lift.Set(ControlMode::PercentOutput, 0.0f);
}

bool Guillotine::getUpperSwitchValue() {
	return !upperSwitch.Get();
}

bool Guillotine::getLowerSwitchValue() {
	return !lowerSwitch.Get();
}
