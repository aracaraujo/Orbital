//
// Created by Ara Cantanhede Araujo on 3/21/24.
//

#ifndef ORBITAL_CHASER_H
#define ORBITAL_CHASER_H

#pragma once
#include "component.h"
#include "angle.h"

class Chaser : Component{

public:
    // Default constructor
    Chaser() { isSpacePress = false; };

    // Non-default constructor
    Chaser(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Component(pos,acc, vel, angle, radius) {};

    //+ rotate( Radians: double)
    void rotate(double radians) {
        this->angle+=radians;
    }

    void setLocation(double x, double y){
        this->position.setPixelsX(x);
        this->position.setPixelsY(y);
    }

    //+ thrust()
//    void thrust()
    //+ shoot( ) : Bullet

    // Virtual methods
    virtual void display(ogstream* gout) const override{
        gout->drawShip(this->position,this->angle.getRadians(),false);
    }

    virtual void move() const override{

    }
private:
    bool isSpacePress;
};


#endif //ORBITAL_CHASER_H
