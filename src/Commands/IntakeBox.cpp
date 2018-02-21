#include "IntakeBox.hpp"
#include "PivotIntakeUp.hpp"
#include "GuillotineHold.hpp"
#include "GuillotineKick.hpp"

IntakeBox::IntakeBox() {
	AddSequential(new GuillotineKick());
	AddSequential(new PivotIntakeUp(0.0f));
	AddSequential(new PivotIntakeUp(0.05f));
	AddSequential(new GuillotineHold());
}

