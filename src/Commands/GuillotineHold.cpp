#include "GuillotineHold.hpp"

#include "../Subsystems/Subsystems.hpp"

/**
 * Causes the guillotine to hold
 */
GuillotineHold::GuillotineHold() : Command("GuillotineHold") {
	Requires(&Subsystems::guillotine);
}

void GuillotineHold::Initialize() {

}

void GuillotineHold::Execute() {
	Subsystems::guillotine.hold();
}

bool GuillotineHold::IsFinished() {
	return true;
}

void GuillotineHold::Interrupted() {

}

void GuillotineHold::End() {

}

