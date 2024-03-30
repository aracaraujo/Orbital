//
// Created by Ara Cantanhede Araujo on 3/23/24.
//

#include "projectile.h"

void Projectile::move() {
    this->acceleration = getGravity(this->position);
    this->velocity.updateVelocity(this->acceleration,48);
    updatePosition(this->position,this->velocity,this->acceleration,48);
}
