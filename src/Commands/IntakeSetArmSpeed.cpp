#include "IntakeSetArmSpeed.hpp"

#include "../Subsystems/Subsystems.hpp"

/**
 * Sets the intake rollers to the given speed
 *
 * A positive speed moves the rollers inward, and a negative rolls them outward
 * @param speed The speed to set the rollers to
 */
IntakeSetArmSpeed::IntakeSetArmSpeed(double speed) : speed(speed) {

}

void IntakeSetArmSpeed::Initialize() {
    Subsystems::intake.setArmsSpeed(speed);
}

void IntakeSetArmSpeed::Execute() {

}

bool IntakeSetArmSpeed::IsFinished() {
    return true;
}

void IntakeSetArmSpeed::Interrupted() {

}

void IntakeSetArmSpeed::End() {

}
