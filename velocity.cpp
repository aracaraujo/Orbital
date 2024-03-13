//
// Created by Ara Cantanhede Araujo on 3/8/24.
//

#include "velocity.h"

void Velocity::updateVelocity(double ddy, double ddx, double time) {
    // Updating the vertical velocity.
    dy = dy + (ddy * time);
    // Updating the horizontal velocity.
    dx = dx + (ddx * time);
};