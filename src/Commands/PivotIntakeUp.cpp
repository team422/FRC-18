#include "PivotIntakeUp.hpp"
#include "../Subsystems/Subsystems.hpp"

PivotIntakeUp::PivotIntakeUp(bool forTimeOnly, float time) : Command(time), forTimeOnly(forTimeOnly), time(time) {
	Requires(&Subsystems::intake);
}

void PivotIntakeUp::Initialize() {

}

void PivotIntakeUp::Execute() {
	Subsystems::intake.setPivotSpeed(0.6f);
}

bool PivotIntakeUp::IsFinished() {
	if (forTimeOnly) {
		return IsTimedOut();
	} else {
		return Subsystems::intake.getLowerSwitchValue() || IsTimedOut();
	}
}

void PivotIntakeUp::Interrupted() {

}

void PivotIntakeUp::End() {
	Subsystems::intake.setPivotSpeed(0.0f);
}
