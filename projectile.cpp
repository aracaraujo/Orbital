//
// Created by Ara Cantanhede Araujo on 3/23/24.
//

#include "projectile.h"

void Projectile::move() {
    if (age == 70){
        kill();
    }else{
        updatePosition(this->position,this->velocity,this->acceleration,48);
        incrementAge();
    }
}
