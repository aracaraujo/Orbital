//
// Created by Wade Withers on 3/6/24.
//

#include "acceleration.h"
#include "cmath"

/*************************
 * GETTERS
 *************************/
double Acceleration::getVerticalAcceleration() const {
    return this->verticalAcceleration;
}

double Acceleration::getHorizontalAcceleration() const {
    return this->horizontalAcceleration;
}

/*************************
 * SETTERS
 *************************/
void Acceleration::setVerticalAcceleration(double verticalAcceleration) {
    this->verticalAcceleration = verticalAcceleration;
}

void Acceleration::setHorizontalAcceleration(double horizontalAcceleration) {
    this->horizontalAcceleration = horizontalAcceleration;
}

/*************************
 * VERTICAL ACCELERATION FROM TOTAL GRAVITY
 * Calculates the vertical acceleration from total acceleration at the given angle.
 *************************/
void Acceleration::calcVerticalAccelerationFromGravity(double gravity, const Angle& angle) {
    this->verticalAcceleration = gravity * cos(angle.getRadians());
}

/*************************
 * HORIZONTAL ACCELERATION FROM TOTAL GRAVITY
 * Calculates the horizontal acceleration from total acceleration at the given angle.
 *************************/
void Acceleration::calcHorizontalAccelerationFromGravity(double gravity, const Angle& angle) {
    this->horizontalAcceleration = gravity * sin(angle.getRadians());
}
