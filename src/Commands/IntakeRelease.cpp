#include "IntakeRelease.hpp"
#include "../Subsystems/Subsystems.hpp"

/**
 * Causes the intake to release
 */
IntakeRelease::IntakeRelease() : Command("IntakeRelease") {
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

