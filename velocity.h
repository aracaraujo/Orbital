//
// Created by Ara Cantanhede Araujo on 3/8/24.
//

#pragma once

class TestVelocity;

class Velocity{
    friend TestVelocity;
public:

    // Constructors
    Velocity() : dy(0.0), dx(0.0) {};
    Velocity(double dy, double dx) : dy(dy), dx(dx) {};

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
    double getVerticalVelocity() {return this->dy;};
    double getHorizontalVelocity() {return this->dx;};

    // Setters
    void setVerticalVelocity(double dy)
    {
        this->dy = dy;
    };
    void setHorizontalVelocity(double dx)
    {
        this->dx = dx;
    };

    void updateVelocity(double ddy, double ddx, double time) {};

private:
    double dy; // vertical
    double dx; // horizontal
};
