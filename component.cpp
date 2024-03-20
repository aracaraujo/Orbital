//
// Created by Wade Withers on 3/19/24.
//

#include "component.h"

Position Component::getPosition() {
    return Position();
}

Acceleration Component::getAcceleration() {
    return Acceleration();
}

Velocity Component::getVelocity() {
    return Velocity();
}

Angle Component::getAngle() {
    return Angle();
}

double Component::getRadius() {
    return 0;
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

void Component::display(ogstream gout, double radius) {

}

void Component::move() {

}


