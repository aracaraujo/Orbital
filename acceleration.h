//
// Created by Wade Withers on 3/6/24.
//

#ifndef ORBITAL_ACCELERATION_H
#define ORBITAL_ACCELERATION_H

#include "position.h"
class TestAcceleration;
class Acceleration {
public:
    friend TestAcceleration;

    // Default Constructor.
    Acceleration() : verticalAcceleration(0.0), horizontalAcceleration(0.0) {}

    // Non-Default Constructor.
    Acceleration(double gravity, double angle) {
    }

    // GETTERS
    double getVerticalAcceleration();
    double getHorizontalAcceleration();

    // SETTERS
    void setVerticalAcceleration(double verticalAcceleration);
    void setHorizontalAcceleration(double horizontalAcceleration);

    // Vertical acceleration from total gravity.
    void calcVerticalAccelerationFromGravity(double gravity, double angle);

    // Horizontal acceleration from total gravity.
    void calcHorizontalAccelerationFromGravity(double gravity, double angle);

private:
    double verticalAcceleration;
    double horizontalAcceleration;
};


#endif //ORBITAL_ACCELERATION_H
