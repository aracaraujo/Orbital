//
// Created by Wade Withers on 3/6/24.
//

#ifndef ORBITAL_ACCELERATION_H
#define ORBITAL_ACCELERATION_H
#pragma once
#include "position.h"
#include "angle.h"
class TestAcceleration;
class Acceleration {
public:
    friend TestAcceleration;

    // Default Constructor.
    Acceleration() : verticalAcceleration(0.0), horizontalAcceleration(0.0) {}

    // Non-Default Constructor.
    Acceleration(double gravity, const Angle& angle) {
        /*this->verticalAcceleration = */calcVerticalAccelerationFromGravity(gravity, angle);
        /*this->horizontalAcceleration = */calcHorizontalAccelerationFromGravity(gravity, angle);
    }

    // Operators
    Acceleration & operator=(const Acceleration & rhs)
    {
        horizontalAcceleration = rhs.horizontalAcceleration;
        verticalAcceleration = rhs.verticalAcceleration;
        return *this;
    }

    // GETTERS
    double getVerticalAcceleration() const;
    double getHorizontalAcceleration() const;

    // SETTERS
    void setVerticalAcceleration(double verticalAcceleration);
    void setHorizontalAcceleration(double horizontalAcceleration);

    // Vertical acceleration from total gravity.
    void calcVerticalAccelerationFromGravity(double gravity, const Angle& angle);

    // Horizontal acceleration from total gravity.
    void calcHorizontalAccelerationFromGravity(double gravity, const Angle& angle);

private:
    double verticalAcceleration;
    double horizontalAcceleration;
};


#endif //ORBITAL_ACCELERATION_H
