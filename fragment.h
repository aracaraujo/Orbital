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
            Component(pos, acc, vel, angle, radius){};

    int getAge() const { return age; }
    void setAge(int age) { this->age = age; }

    // Age fragment by one.
    void incrementAge() { this->age++; }

    // Display
    void display(ogstream * gout) const override;

private:
    int age;
};


#endif //ORBITAL_FRAGMENT_H
