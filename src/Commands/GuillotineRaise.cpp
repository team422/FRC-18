#include "GuillotineRaise.hpp"
#include "../Subsystems/Subsystems.hpp"

GuillotineRaise::GuillotineRaise() {
	Requires(&Subsystems::guillotine);
}

void GuillotineRaise::Initialize() {

}

void GuillotineRaise::Execute() {
	Subsystems::guillotine.raiseLift();
}

bool GuillotineRaise::IsFinished() {
	return Subsystems::guillotine.getUpperSwitchValue();
}

void GuillotineRaise::Interrupted() {
	Subsystems::guillotine.stopLift();
}

void GuillotineRaise::End() {
	Subsystems::guillotine.stopLift();
}
