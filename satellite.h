//
// Created by Wade Withers on 3/28/24.
//

#ifndef ORBITAL_SATELLITE_H
#define ORBITAL_SATELLITE_H

#include "component.h"

/****************************
 * SATELLITE
 ****************************/
class Satellite : public Component {
public:
    // Default Cosntructor
    Satellite() {}

    // Non-default constructor
    Satellite(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Component(
            pos,
            acc,
            vel,
            angle,
            radius) {
    };

    // Destructor
    ~Satellite() {}

    // Destroy
//    virtual void destroy(std::vector<Component*>& satellites) = 0;

};

/****************************
 * SPUTNIK
 ****************************/
class Sputnik : public Satellite {
public:
    // Default Constructor
    Sputnik();

    // Non-default constructor
    Sputnik(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {
    };

    // Destructor
    ~Sputnik() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

/****************************
 * GPS
 ****************************/
class Gps : public Satellite {
public:
    // Default Constructor
    Gps();

    // Non-default constructor
    Gps(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {
    };

    // Destructor
    ~Gps() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

/****************************
 * HUBBLE
 ****************************/
class Hubble : public Satellite {
public:
    // Default Constructor
    Hubble();

    // Non-default constructor
    Hubble(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {
    };

    // Destructor
    ~Hubble() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

/****************************
 * DRAGON
 ****************************/
class Dragon : public Satellite {
public:
    // Default Constructor
    Dragon();

    // Non-default constructor
    Dragon(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {
    };

    // Destructor
    ~Dragon() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

/****************************
 * STARLINK
 ****************************/
class Starlink : public Satellite {
public:
    // Default Constructor
    Starlink();

    // Non-default constructor
    Starlink(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {
    };

    // Destructor
    ~Starlink() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

/****************************
 * PARTS
 * GPS CENTER
 ****************************/
class GPSCenter : public Satellite {
public:
    // Default Constructor
    GPSCenter();

    // Non-default constructor
    GPSCenter(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {

        double cosA = cos(angle.getRadians());
        double sinA = sin(angle.getRadians());

        // start with our original point
        Position ptReturn(pos);

        // find the new values
        ptReturn.addPixelsX(0.0 * cosA + 10.0 * sinA);
        ptReturn.addPixelsY(10.0 * cosA - 0.0 * sinA);
        setPosition(ptReturn);

    };

    // Destructor
    ~GPSCenter() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

/****************************
 * GPS Left
 ****************************/
class GPSLeft : public Satellite {
public:
    // Default Constructor
    GPSLeft();

    // Non-default constructor
    GPSLeft(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {

    };

    // Destructor
    ~GPSLeft() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

/****************************
 * GPS Right
 ****************************/
class GPSRight : public Satellite {
public:
    // Default Constructor
    GPSRight();

    // Non-default constructor
    GPSRight(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {
    };

    // Destructor
    ~GPSRight() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

/****************************
 * Hubble Telescope Main Part
 ****************************/
class HubbleTelescope : public Satellite {
public:
    // Default Constructor
    HubbleTelescope();

    // Non-default constructor
    HubbleTelescope(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {
    };

    // Destructor
    ~HubbleTelescope() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

/****************************
 * Hubble Computer
 ****************************/
class HubbleComputer : public Satellite {
public:
    // Default Constructor
    HubbleComputer();

    // Non-default constructor
    HubbleComputer(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {
    };

    // Destructor
    ~HubbleComputer() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

/****************************
 * Hubble Left
 ****************************/
class HubbleLeft : public Satellite {
public:
    // Default Constructor
    HubbleLeft();

    // Non-default constructor
    HubbleLeft(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {
    };

    // Destructor
    ~HubbleLeft() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

/****************************
 * Hubble Right
 ****************************/
class HubbleRight : public Satellite {
public:
    // Default Constructor
    HubbleRight();

    // Non-default constructor
    HubbleRight(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {
    };

    // Destructor
    ~HubbleRight() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

/****************************
 * Dragon Parts
 * Crew Dragon Center
 ****************************/
class DragonCenter : public Satellite {
public:
    // Default Constructor
    DragonCenter();

    // Non-default constructor
    DragonCenter(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {
    };

    // Destructor
    ~DragonCenter() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

/****************************
 * Crew Dragon Left
 ****************************/
class DragonLeft : public Satellite {
public:
    // Default Constructor
    DragonLeft();

    // Non-default constructor
    DragonLeft(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {
    };

    // Destructor
    ~DragonLeft() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

/****************************
 * Crew Dragon Right
 ****************************/
class DragonRight : public Satellite {
public:
    // Default Constructor
    DragonRight();

    // Non-default constructor
    DragonRight(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {
    };

    // Destructor
    ~DragonRight() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

/****************************
 * Starlink Parts
 * Starlink Body
 ****************************/
class StarlinkBody : public Satellite {
public:
    // Default Constructor
    StarlinkBody();

    // Non-default constructor
    StarlinkBody(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {
    };

    // Destructor
    ~StarlinkBody() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

/****************************
 * Starlink Array
 ****************************/
class StarlinkArray : public Satellite {
public:
    // Default Constructor
    StarlinkArray();

    // Non-default constructor
    StarlinkArray(Position pos, Acceleration acc, Velocity vel, Angle angle, double radius) : Satellite(
            pos,
            acc,
            vel,
            angle,
            radius) {
    };

    // Destructor
    ~StarlinkArray() {}

    // display
    void display(ogstream * gout) const override;

    // Destroy
    void destroy(list<Component*>& satellites) override;
};

#endif //ORBITAL_SATELLITE_H
