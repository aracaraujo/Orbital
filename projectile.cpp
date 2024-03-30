//
// Created by Ara Cantanhede Araujo on 3/23/24.
//

#include "projectile.h"

Projectile::Projectile(Position pos, Velocity vel, Angle angle, double radius) : Component(pos,Acceleration(), vel, angle, radius) {

// because sine and cosine are expensive, we want to call them only once
double cosA = cos(angle.getRadians());
double sinA = sin(angle.getRadians());

// start with our original point
Position ptReturn(pos);

// find the new values
ptReturn.addPixelsX(0.0 * cosA + 19.0 * sinA);
ptReturn.addPixelsY(19.0 * cosA - 0.0 * sinA);
setPosition(ptReturn);
this->age = 0;
};