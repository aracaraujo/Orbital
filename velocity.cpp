//
// Created by Ara Cantanhede Araujo on 3/8/24.
//

#include "velocity.h"

void Velocity::updateVelocity(const Acceleration& acceleration, double time) {
    // Updating the vertical velocity.
    dy = dy + ( acceleration.getVerticalAcceleration() * time);
    // Updating the horizontal velocity.
    dx = dx + ( acceleration.getHorizontalAcceleration() * time);
};