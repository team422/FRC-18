#include "IntakeBox.hpp"
#include "IntakeGrab.hpp"
#include "PivotIntakeUp.hpp"
#include "GuillotineHold.hpp"
#include "GuillotineKick.hpp"

IntakeBox::IntakeBox() {
	AddSequential(new IntakeGrab());
	AddSequential(new GuillotineKick());
	AddSequential(new PivotIntakeUp(false, 1.5f));
	AddSequential(new PivotIntakeUp(true, 0.05f));
	AddSequential(new GuillotineHold());
}

