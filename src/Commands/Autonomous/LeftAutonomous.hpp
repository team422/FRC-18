#pragma once

#include "../Util/CommandBatch.hpp"

class LeftAutonomous : public CommandBatch {
public:
	LeftAutonomous(std::string gameData, bool scale);
};
