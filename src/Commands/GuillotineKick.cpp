#include "GuillotineKick.hpp"
#include "../Subsystems/Subsystems.hpp"

GuillotineKick::GuillotineKick() {
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

