#include "GuillotineLower.hpp"
#include "../Subsystems/Subsystems.hpp"

GuillotineLower::GuillotineLower() {
	Requires(&Subsystems::guillotine);
}

void GuillotineLower::Initialize() {

}

void GuillotineLower::Execute() {
	Subsystems::guillotine.lowerLift();
}

bool GuillotineLower::IsFinished() {
	return Subsystems::guillotine.getLowerSwitchValue();
}

void GuillotineLower::Interrupted() {
	Subsystems::guillotine.stopLift();
}

void GuillotineLower::End() {
	Subsystems::guillotine.stopLift();
}
