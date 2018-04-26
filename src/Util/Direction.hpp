#pragma once

/**
 * Directions for various commands that are multi-directional
 *
 * These are to make it easier to read some of the functions. As opposed to taking a parameter that is a boolean
 * for one direction, the command can take in one of the directions from this enum
 */
enum class Direction {
    FORWARD,
    REVERSE,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

