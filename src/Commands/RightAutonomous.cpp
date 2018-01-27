#include "Commands/RightAutonomous.hpp"

RightAutonomous::RightAutonomous() {
	AddSequential(new DriveStraight(14*12, 0.2, 10));
	AddSequential(new Turn(-90,.20,10));

}
