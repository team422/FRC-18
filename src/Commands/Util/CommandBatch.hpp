#pragma once

#include <WPILib.h>

class CommandBatch : public frc::CommandGroup {
public:
	CommandBatch();
	virtual ~CommandBatch();
	void AddSequential(Command *command);
	void AddSequential(Command *command, double timeout);
	void AddParallel(Command *command);
	void AddParallel(Command *command, double timeout);
private:
	std::vector<Command*> commands;
};

