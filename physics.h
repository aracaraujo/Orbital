//
// Created by Ara Cantanhede Araujo on 3/20/24.
//

#include "cmath"
#include "position.h"
#include "acceleration.h"
#include "angle.h"
#define GRAVITY 9.80665  // m/s2
#define RADIUS 6378000 // earth radius
#define FRAMERATE  30
#define SECONDSPERDAY 86400.0
#define DILATION 1440.0

using namespace std;


/*
 *  Earth Rotation
 *  This function will return a double value that represents a
 *  radians of how much the earth will rotate each frame.
 *  It can be easily adapted in case the frame rate changes.
 */
double earthRotation(){
    return -(2 * M_PI/ FRAMERATE ) * (DILATION/SECONDSPERDAY);
}

/*
 * GET ALTITUDE
 * This function will return the altitude from a given position
 * in relation to the earth.
 */
double getAltitude(const Position& position){
    double distances = (position.getMetersX() * position.getMetersX()) + (position.getMetersY() * position.getMetersY());
    return sqrt((distances-RADIUS));
}

/*
 * DIRECTION THAT GRAVITY PULL
 * This function will return the angle in which the gravity is pulling
 * a give object. It only needs the objects position to perform the
 * calculations.
 */
Angle directionGravityPull(const Position& position){

    return Angle(atan2(-position.getMetersX(),-position.getMetersY()));
}

/*
 * GET GRAVITY
 * This function will return and acceleration value that is
 * the value of gravity to a given altitude from the earth.
 */
Acceleration getGravity(const Position& position){

    double height = getAltitude(position);

    double gravity = GRAVITY * ((RADIUS/(RADIUS + height)) * (RADIUS/(RADIUS + height)));

    Angle direction = directionGravityPull(position);

    return Acceleration(gravity,direction);
}


