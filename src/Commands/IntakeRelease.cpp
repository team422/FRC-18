#include "IntakeRelease.hpp"
#include "../Subsystems/Subsystems.hpp"

IntakeRelease::IntakeRelease() {
	Requires(&Subsystems::intake);
}

void IntakeRelease::Initialize() {

}

void IntakeRelease::Execute() {
	Subsystems::intake.release();
}

bool IntakeRelease::IsFinished() {
	return true;
}

void IntakeRelease::Interrupted() {

}

void IntakeRelease::End() {

}

