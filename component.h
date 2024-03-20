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
    Component() {}

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
    virtual void display(ogstream gout, double radius);

    // Move
    virtual void move();

protected:
    Position position;
    Acceleration acceleration;
    Velocity velocity;
    Angle angle;
    double radius;
};


#endif //ORBITAL_COMPONENT_H
