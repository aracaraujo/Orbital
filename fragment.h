//
// Created by Wade Withers on 3/29/24.
//

#ifndef ORBITAL_FRAGMENT_H
#define ORBITAL_FRAGMENT_H

#include "component.h"

class Fragment : public Component {
public:
    // Constructors
    Fragment();
    Fragment(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) :
            Component(pos, acc, vel, angle, radius){

        // because sine and cosine are expensive, we want to call them only once
        double cosA = cos(angle.getRadians());
        double sinA = sin(angle.getRadians());

        // start with our original point
        Position ptReturn(position);

        // find the new values
        ptReturn.addPixelsX(0.0 * cosA + 4.0 * sinA);
        ptReturn.addPixelsY(4.0 * cosA - 0.0 * sinA);
        setPosition(ptReturn);

        this->age = 0;
        this->limitAge = random(50,100);
    };

    int getAge() const { return age; }
    void setAge(int age) { this->age = age; }

    int getLimitAge() const { return age; }
    void setLimitAge(int age) { this->age = age; }

    // Age fragment by one.
    void incrementAge() { this->age++; }

    // Display
    void display(ogstream * gout) const override;

    void destroy(list<Component*>& satellites) {};

private:
    int age;
    int limitAge;
};


#endif //ORBITAL_FRAGMENT_H
