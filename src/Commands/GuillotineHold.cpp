#include "GuillotineHold.hpp"
#include "../Subsystems/Subsystems.hpp"

GuillotineHold::GuillotineHold() {
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

