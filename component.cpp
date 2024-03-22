//
// Created by Wade Withers on 3/19/24.
//

#include "component.h"

Position Component::getPosition() {
    return position;
}

Acceleration Component::getAcceleration() {
    return acceleration;
}

Velocity Component::getVelocity() {
    return velocity;
}

Angle Component::getAngle() {
    return angle;
}

double Component::getRadius() {
    return radius;
}

void Component::setPosition(Position position) {
    this->position = position;
}

void Component::setAcceleration(Acceleration acceleration) {
    this->acceleration = acceleration;
}

void Component::setVelocity(Velocity velocity) {
    this->velocity = velocity;
}

void Component::setAngle(Angle angle) {
    this->angle = angle;
}

void Component::setRadius(double radius) {
    this->radius = radius;
}


