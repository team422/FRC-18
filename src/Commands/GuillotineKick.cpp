#include "GuillotineKick.hpp"

#include "../Subsystems/Subsystems.hpp"

/**
 * Causes the guillotine to kick
 */
GuillotineKick::GuillotineKick() : Command("GuillotineKick") {
	Requires(&Subsystems::guillotine);
}

void GuillotineKick::Initialize() {

}

void GuillotineKick::Execute() {
	Subsystems::guillotine.kick();
}

bool GuillotineKick::IsFinished() {
	return true;
}

void GuillotineKick::Interrupted() {

}

void GuillotineKick::End() {

}

