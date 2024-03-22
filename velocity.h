//
// Created by Ara Cantanhede Araujo on 3/8/24.
//

#pragma once

#include "acceleration.h"

class TestVelocity;

class Velocity{
    friend TestVelocity;
public:

    // Constructors
    Velocity() : dy(0.0), dx(0.0) {};
    Velocity(double dx, double dy) : dx(dx), dy(dy) {};

    // Operators overload
    Velocity& operator+=(const Velocity & rhs)
    {
        this->dy += rhs.dy;
        this->dx += rhs.dx;
        return *this;
    }
    Velocity& operator-=(const Velocity & rhs)
    {
        this->dy -= rhs.dy;
        this->dx -= rhs.dx;
        return *this;
    }
    // Getters
    double getVerticalVelocity() const {return this->dy;};
    double getHorizontalVelocity() const {return this->dx;};

    // Setters
    void setVerticalVelocity(double dy)
    {
        this->dy = dy;
    };
    void setHorizontalVelocity(double dx)
    {
        this->dx = dx;
    };

    void updateVelocity(const Acceleration& acceleration, double time);

private:
    double dy; // vertical
    double dx; // horizontal
};
