#include "GuillotineLower.hpp"
#include "../Subsystems/Subsystems.hpp"

GuillotineLower::GuillotineLower() {
	Requires(&Subsystems::guillotine);
}

void GuillotineLower::Initialize() {

}

void GuillotineLower::Execute() {
	Subsystems::guillotine.setLiftSpeed(-0.4f);
}

bool GuillotineLower::IsFinished() {
	return Subsystems::guillotine.getLowerSwitchValue();
}

void GuillotineLower::Interrupted() {
	Subsystems::guillotine.setLiftSpeed(0.0f);
}

void GuillotineLower::End() {
	Subsystems::guillotine.setLiftSpeed(0.0f);
}
