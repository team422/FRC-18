#include "GuillotineRaise.hpp"

#include "../Subsystems/Subsystems.hpp"

/**
 * Raises the guillotine until it has reached the top of the lift
 */
GuillotineRaise::GuillotineRaise() : Command("GuillotineRaise") {
	Requires(&Subsystems::guillotine);
}

void GuillotineRaise::Initialize() {

}

void GuillotineRaise::Execute() {
	Subsystems::guillotine.setLiftSpeed(0.9d);
}

bool GuillotineRaise::IsFinished() {
	return Subsystems::guillotine.getUpperSwitchValue();
}

void GuillotineRaise::Interrupted() {
	Subsystems::guillotine.setLiftSpeed(0.0d);
}

void GuillotineRaise::End() {
	Subsystems::guillotine.setLiftSpeed(0.3d);
}
