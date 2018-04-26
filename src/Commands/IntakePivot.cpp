#include "IntakePivot.hpp"

#include "../Subsystems/Subsystems.hpp"

IntakePivot::IntakePivot(Direction direction, bool useTimeoutOnly, double timeout) :
    Command("IntakePivot", timeout),
    direction(direction),
    useTimeoutOnly(useTimeoutOnly) {
        Requires(&Subsystems::intake);
}

void IntakePivot::Initialize() {

}

void IntakePivot::Execute() {
    if (direction == Direction::UP) {
        Subsystems::intake.setPivotSpeed(0.8d);
    } else {
        Subsystems::intake.setPivotSpeed(-0.25f);
    }
}

bool IntakePivot::IsFinished() {
    if (useTimeoutOnly) {
        return IsTimedOut();
    } else {
        if (direction == Direction::UP) {
            return Subsystems::intake.getLowerSwitchValue() || IsTimedOut();
        } else {
            return Subsystems::intake.getUpperSwitchValue() || IsTimedOut();
        }
    }
}

void IntakePivot::Interrupted() {
    Subsystems::intake.setPivotSpeed(0.0d);
}

void IntakePivot::End() {
    Subsystems::intake.setPivotSpeed(0.0d);
}