#pragma once

namespace Numbers {

    bool inRange(double value, double target, double error) {
        return abs(value - target) < error;
    }

}
