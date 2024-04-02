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
#include "physics.h"
#include <list>

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
            radius(radius),
            dead(false){};

    // GETTERS
    Position getPosition();
    Acceleration getAcceleration();
    Velocity getVelocity();
    Angle getAngle();
    double getRadius();
    bool isDead();

    // SETTERS
    void setPosition(Position position);
    void setAcceleration(Acceleration acceleration);
    void setVelocity(Velocity velocity);
    void setAngle(Angle angle);
    void setRadius(double radius);
    void kill();

    // Display
    virtual void display(ogstream * gout)    const = 0;

    // Destroy
    virtual void destroy(list<Component*>& satellites) = 0;

    // Move
    void move(int time);

protected:
    Position position;
    Acceleration acceleration;
    Velocity velocity;
    Angle angle;
    double radius;
    bool dead;
};


#endif //ORBITAL_COMPONENT_H
