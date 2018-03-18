#include "GuillotineRaise.hpp"
#include "../Subsystems/Subsystems.hpp"

GuillotineRaise::GuillotineRaise() {
	Requires(&Subsystems::guillotine);
}

void GuillotineRaise::Initialize() {

}

void GuillotineRaise::Execute() {
	Subsystems::guillotine.setLiftSpeed(0.9f);
}

bool GuillotineRaise::IsFinished() {
	return Subsystems::guillotine.getUpperSwitchValue();
}

void GuillotineRaise::Interrupted() {
	Subsystems::guillotine.setLiftSpeed(0.0f);
}

void GuillotineRaise::End() {
	Subsystems::guillotine.setLiftSpeed(0.3f);
}
