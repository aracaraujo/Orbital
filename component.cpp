//
// Created by Wade Withers on 3/19/24.
//

#include "component.h"

Position Component::getPosition() {
    return this->position;
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

bool Component::isDead() {
    return dead;
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

void Component::kill() {
    this->dead = true;
}

void Component::move(int time) {
    this->acceleration = getGravity(this->position);
    this->velocity.updateVelocity(this->acceleration,time);
    updatePosition(this->position,this->velocity,this->acceleration,time);
}


