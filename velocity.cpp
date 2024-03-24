//
// Created by Ara Cantanhede Araujo on 3/8/24.
//

#include "velocity.h"
#include "cmath"

void Velocity::updateVelocity(const Acceleration& acceleration, double time) {
    // Updating the vertical velocity.
    dy = dy + ( acceleration.getVerticalAcceleration() * time);
    // Updating the horizontal velocity.
    dx = dx + ( acceleration.getHorizontalAcceleration() * time);
}

Velocity::Velocity(double velocity, const Angle& angle) {
    this->dx = velocity * sin(angle.getRadians());
    this->dy = velocity * cos(angle.getRadians());
};

std::ostream& operator << (std::ostream& out, const Velocity& vel)
{
    out << "(" << vel.getHorizontalVelocity() << " horizontal , " << vel.getVerticalVelocity() << " vertical)";
    return out;
}