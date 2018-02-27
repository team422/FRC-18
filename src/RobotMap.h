#pragma once

#include <WPILib.h>

#define COMP_BOT

namespace Ports {

#ifndef COMP_BOT // Practice Bot
	// Motor IDs
	const int	LEFT_MASTER_MOTOR = 40,
				LEFT_FOLLOWER_1 = 44,
				LEFT_FOLLOWER_2 = 21,
				RIGHT_MASTER_MOTOR = 39,
				RIGHT_FOLLOWER_1 = 42,
				RIGHT_FOLLOWER_2 = 46,

				INTAKE_PIVOT = 16,
				INTAKE_LEFT_ARM = 35,
				INTAKE_RIGHT_ARM = 12,

				LIFT = 56;

	// DoubleSolenoid IDs
	const int	INTAKE_FORWARD = 5,
				INTAKE_REVERSE = 3,
				KICKER_FORWARD = 2,
				KICKER_REVERSE = 4;

	// Digital Input Ports
	const int	INTAKE_UPPER_SWITCH = 5,
				INTAKE_LOWER_SWITCH = 4,
				GUILLOTINE_UPPER_SWITCH = 2,
				GUILLOTINE_LOWER_SWITCH = 3;

#else	// Competition Bot
	// Motor IDs
	const int	LEFT_MASTER_MOTOR = 1,
				LEFT_FOLLOWER_1 = 2,
				LEFT_FOLLOWER_2 = 3,
				RIGHT_MASTER_MOTOR = 4,
				RIGHT_FOLLOWER_1 = 5,
				RIGHT_FOLLOWER_2 = 6,

				INTAKE_PIVOT = 43,
				INTAKE_LEFT_ARM = 9,
				INTAKE_RIGHT_ARM = 10,

				LIFT = 11;

	// DoubleSolenoid IDs
	const int	INTAKE_FORWARD = 5,
				INTAKE_REVERSE = 3,
				KICKER_FORWARD = 4,
				KICKER_REVERSE = 2;

	// Digital Input Ports
	const int	INTAKE_UPPER_SWITCH = 4,
				INTAKE_LOWER_SWITCH = 5,
				GUILLOTINE_UPPER_SWITCH = 2,
				GUILLOTINE_LOWER_SWITCH = 3;
#endif

	// Digital IO Ports
	const int	BEAM_BRAKE = 6;

	// Joystick IDs
	const int	XBOX_CONTROLLER = 0,
				LAUNCHPAD = 1,
				LEFT_JOYSTICK = 3,
				RIGHT_JOYSTICK = 2;

	const int INTAKE_ULTRASONIC = 3;
}
