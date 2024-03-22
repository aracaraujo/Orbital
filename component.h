//
// Created by Wade Withers on 3/19/24.
//

#ifndef ORBITAL_COMPONENT_H
#define ORBITAL_COMPONENT_H

#include "position.h"
#include "acceleration.h"
#include "velocity.h"
#include "angle.h"
#include "uiDraw.h"

class Component {
public:
    // Default Constructor
    Component() {};

    // Non-default constructor
    Component(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) :
            position(pos),
            acceleration(acc),
            velocity(vel),
            angle(angle),
            radius(radius){};

    // GETTERS
    Position getPosition();
    Acceleration getAcceleration();
    Velocity getVelocity();
    Angle getAngle();
    double getRadius();

    // SETTERS
    void setPosition(Position position);
    void setAcceleration(Acceleration acceleration);
    void setVelocity(Velocity velocity);
    void setAngle(Angle angle);
    void setRadius(double radius);

    // Display
    virtual void display(ogstream * gout)    const = 0;

    // Move
    virtual void move()                     const = 0;

protected:
    Position position;
    Acceleration acceleration;
    Velocity velocity;
    Angle angle;
    double radius;
};


#endif //ORBITAL_COMPONENT_H
