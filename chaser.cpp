//
// Created by Ara Cantanhede Araujo on 3/21/24.
//

#include "chaser.h"

void Chaser::move(){
    this->acceleration = getGravity(this->position);
    this->velocity.updateVelocity(this->acceleration,48);
    updatePosition(this->position,this->velocity,this->acceleration,48);
}

void Chaser::thrust(double acceleration) {
    Acceleration thrustAcceleration(acceleration, this->angle.getRadians());
    this->velocity.updateVelocity(thrustAcceleration,48);
    updatePosition(this->position,this->velocity,this->acceleration,48);
}
