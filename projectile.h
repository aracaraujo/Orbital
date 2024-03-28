//
// Created by Ara Cantanhede Araujo on 3/23/24.
//

#ifndef ORBITAL_PROJECTILE_H
#define ORBITAL_PROJECTILE_H

#pragma once
#include "component.h"
#include "physics.h"

class Projectile : public Component{

public:
    // Default constructor
    Projectile() {};

    // Non-default constructor
    Projectile(Position pos, Velocity vel, Angle angle, double radius) : Component(pos,Acceleration(), vel, angle, radius) {

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

    Projectile(const Projectile & proj) : Component(proj.position,Acceleration(), proj.velocity, proj.angle, proj.radius) {

        // because sine and cosine are expensive, we want to call them only once
        double cosA = cos(angle.getRadians());
        double sinA = sin(angle.getRadians());

        // start with our original point
        Position ptReturn(proj.position);

        // find the new values
        ptReturn.addPixelsX(0.0 * cosA + 19.0 * sinA);
        ptReturn.addPixelsY(19.0 * cosA - 0.0 * sinA);
        setPosition(ptReturn);
        this->age = 0;
    };

    // GETTERS
    int getAge() const { return age; };

    // SETTERS
    void setAge(int newAge) { age = newAge; };

    void incrementAge() { age++; };

    // Virtual methods
    void display(ogstream* gout) const override{
        gout->drawProjectile(this->position);
    }

    void setLocationInPixels(double x, double y){
        this->position.setPixelsX(x);
        this->position.setPixelsY(y);
    }

    void move() override;

private:
    int age;
};


#endif //ORBITAL_PROJECTILE_H
