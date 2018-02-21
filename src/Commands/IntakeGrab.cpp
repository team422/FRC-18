#include "IntakeGrab.hpp"
#include "../Subsystems/Subsystems.hpp"

IntakeGrab::IntakeGrab() {
	Requires(&Subsystems::intake);
}

void IntakeGrab::Initialize() {

}

void IntakeGrab::Execute() {
	Subsystems::intake.grab();
}

bool IntakeGrab::IsFinished() {
	return true;
}

void IntakeGrab::Interrupted() {

}

void IntakeGrab::End() {

}

