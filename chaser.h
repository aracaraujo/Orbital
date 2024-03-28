//
// Created by Ara Cantanhede Araujo on 3/21/24.
//

#ifndef ORBITAL_CHASER_H
#define ORBITAL_CHASER_H

#pragma once
#include "component.h"
#include "angle.h"
#include "physics.h"
#include "acceleration.h"
#include "projectile.h"

class Chaser : public Component{

public:
    // Default constructor
    Chaser() { isSpacePress = false; };

    // Non-default constructor
    Chaser(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Component(pos,acc, vel, angle, radius) {
        isSpacePress = false;
    };

    // Rotate
    void rotate(double radians) {
        this->angle+=radians;
    }

    void setLocationInPixels(double x, double y){
        this->position.setPixelsX(x);
        this->position.setPixelsY(y);
    }

    // Thrust
    void thrust(double acceleration);

    // Shoot
    Projectile shoot();

    // Virtual methods
    void display(ogstream* gout) const override{
        gout->drawShip(this->position,this->angle.getRadians(),isSpacePress);
    }

   void move() override;

    bool getIsSpacePress() const{ return isSpacePress; };

    void setIsSpacePress(bool pressed) { this->isSpacePress = pressed; };

private:
    bool isSpacePress;
};


#endif //ORBITAL_CHASER_H
