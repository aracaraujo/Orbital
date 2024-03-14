//
// Created by Wade Withers on 3/6/24.
//

#include "acceleration.h"
#include "cmath"


double Acceleration::getVerticalAcceleration() {
    return this->verticalAcceleration;
}

double Acceleration::getHorizontalAcceleration() {
    return this->horizontalAcceleration;
}

void Acceleration::setVerticalAcceleration(double verticalAcceleration) {
    this->verticalAcceleration = verticalAcceleration;
}

void Acceleration::setHorizontalAcceleration(double horizontalAcceleration) {
    this->horizontalAcceleration = horizontalAcceleration;
}

void Acceleration::calcVerticalAccelerationFromGravity(double gravity, double angle) {
    this->verticalAcceleration = gravity * cos(angle);
}

void Acceleration::calcHorizontalAccelerationFromGravity(double gravity, double angle) {
    this->horizontalAcceleration = gravity * sin(angle);
}
