#include "PivotIntakeUp.hpp"
#include "../Subsystems/Subsystems.hpp"

PivotIntakeUp::PivotIntakeUp(float time) : Command(time), time(time) {
	Requires(&Subsystems::intake);
}

void PivotIntakeUp::Initialize() {

}

void PivotIntakeUp::Execute() {
	Subsystems::intake.pivotUp();
}

bool PivotIntakeUp::IsFinished() {
	if (time != 0.0f) {
		return IsTimedOut();
	} else {
		return Subsystems::intake.getLowerSwitchValue();
	}
}

void PivotIntakeUp::Interrupted() {
	Cancel();
}

void PivotIntakeUp::End() {
	Subsystems::intake.stopPivot();
}
