#include "PivotIntakeDown.hpp"
#include "../Subsystems/Subsystems.hpp"

PivotIntakeDown::PivotIntakeDown(float time) : Command(time), time(time) {
	Requires(&Subsystems::intake);
}

void PivotIntakeDown::Initialize() {

}

void PivotIntakeDown::Execute() {
	Subsystems::intake.setPivotSpeed(-0.4f);
}

bool PivotIntakeDown::IsFinished() {
	if (time != 0.0f) {
		return IsTimedOut();
	} else {
		return Subsystems::intake.getUpperSwitchValue();
	}
}

void PivotIntakeDown::Interrupted() {

}

void PivotIntakeDown::End() {
	Subsystems::intake.setPivotSpeed(0.0f);
}
