#include "IntakeArmsIn.hpp"
#include "../Subsystems/Subsystems.hpp"

IntakeArmsIn::IntakeArmsIn() {
	Requires(&Subsystems::intake);
}

void IntakeArmsIn::Initialize() {

}

void IntakeArmsIn::Execute() {
	Subsystems::intake.setArmsIn();
}

bool IntakeArmsIn::IsFinished() {
	return true;
}

void IntakeArmsIn::Interrupted() {

}

void IntakeArmsIn::End() {

}

