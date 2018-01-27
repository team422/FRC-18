#pragma once

#include <WPILib.h>

#define COMP_BOT

namespace Ports {

#ifndef COMP_BOT
	// Motor IDs
	const int	LEFT_MASTER_MOTOR = 40,
				LEFT_FOLLOWER_1 = 44,
				LEFT_FOLLOWER_2 = 21,
				RIGHT_MASTER_MOTOR = 39,
				RIGHT_FOLLOWER_1 = 42,
				RIGHT_FOLLOWER_2 = 46;

	// DoubleSolenoid IDs
	const int	INTAKE_FOWARD = 3,
				INTAKE_REVERSE = 4;
#else
	// Motor IDs
	const int	LEFT_MASTER_MOTOR = 1,
				LEFT_FOLLOWER_1 = 2,
				LEFT_FOLLOWER_2 = 3,
				RIGHT_MASTER_MOTOR = 4,
				RIGHT_FOLLOWER_1 = 5,
				RIGHT_FOLLOWER_2 = 6;

	// DoubleSolenoid IDs
	const int	INTAKE_FOWARD = 3,
				INTAKE_REVERSE = 4;
#endif

	// Joystick IDs
	const int	LEFT_JOYSTICK = 3,
				RIGHT_JOYSTICK = 2;
}
