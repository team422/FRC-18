#include "GuillotineLower.hpp"

#include "../Subsystems/Subsystems.hpp"

/**
 * Lowers the guillotine until it has reached the bottom of the lift
 */
GuillotineLower::GuillotineLower() : Command("GuillotineLower") {
	Requires(&Subsystems::guillotine);
}

void GuillotineLower::Initialize() {

}

void GuillotineLower::Execute() {
	Subsystems::guillotine.setLiftSpeed(-0.4d);
}

bool GuillotineLower::IsFinished() {
	return Subsystems::guillotine.getLowerSwitchValue();
}

void GuillotineLower::Interrupted() {
	Subsystems::guillotine.setLiftSpeed(0.0d);
}

void GuillotineLower::End() {
	Subsystems::guillotine.setLiftSpeed(0.0d);
}
