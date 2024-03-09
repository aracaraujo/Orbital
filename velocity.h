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
    Velocity(double dy, double dx) : dy(0.0), dx(0.0) {};

    // Operators overload
    Velocity& operator+=(const Velocity & rhs) {return *this;}
    Velocity& operator-=(const Velocity & rhs) {return *this;}

    // Getters
    double getVerticalVelocity() {return 0.0;};
    double getHorizontalVelocity() {return 0.0;};

    // Setters
    void setVerticalVelocity(double dy) {};
    void setHorizontalVelocity(double dx) {};

    void updateVelocity(double ddy, double ddx, double time) {};

private:
    double dy; // vertical
    double dx; // horizontal
};
