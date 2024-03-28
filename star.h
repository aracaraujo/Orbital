#pragma once

#include "position.h"

class Star
{
public:
    // Default constructor.
    Star();

    // Non-default constructor.
    Star(Position position, int phase);

    // Set position.
    void setPosition(Position position);

    // Get Position.
    Position getPosition();

    // Set phase.
    void setPhase(unsigned char newPhase);

    // Get Position.
    unsigned char  getPhase();

    // Increment phase;
    void incrementPhase();

    void setLocationInPixels(double x, double y);

private:
    Position position;

    unsigned char phase;
};
