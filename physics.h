//
// Created by Ara Cantanhede Araujo on 3/20/24.
//

#pragma once
#include "cmath"
#include "position.h"
#include "acceleration.h"
#include "velocity.h"
#include "angle.h"
#define GRAVITY 9.80665  // m/s2
#define EARTHRADIUS 6378000 // earth radius
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
static double earthRotation(){
    return -(2 * M_PI/ FRAMERATE ) * (DILATION/SECONDSPERDAY);
}

/*
 * GET ALTITUDE
 * This function will return the altitude from a given position
 * in relation to the earth.
 */
static double getAltitude(const Position& position){
    double distance = computeDistance(Position(),position);
    return distance - EARTHRADIUS;
}

/*
 * DIRECTION THAT GRAVITY PULL
 * This function will return the angle in which the gravity is pulling
 * a give object. It only needs the objects position to perform the
 * calculations.
 */
static Angle directionGravityPull(const Position& position){

    return Angle(atan2(-position.getMetersX(),-position.getMetersY()));
}

/*
 * GET GRAVITY
 * This function will return and acceleration value that is
 * the value of gravity to a given altitude from the earth.
 */
static Acceleration getGravity(const Position& position){

    double height = getAltitude(position);

    Angle direction;

    direction.setDxDy(-position.getMetersX(),-position.getMetersY());

    double tmp = EARTHRADIUS / (EARTHRADIUS + height);

    double gravity = GRAVITY * tmp * tmp;

    return Acceleration(gravity,direction);
}

/*
 * UPDATE POSITION
 * It will update a position from a given velocity and acceleration
 */
static Position& updatePosition(Position& pos, const Velocity& vel, const Acceleration& acc, double time){
    pos.addMetersX(vel.getHorizontalVelocity() * time + 0.5 * acc.getHorizontalAcceleration() * time * time);
    pos.addMetersY(vel.getVerticalVelocity() * time + 0.5 * acc.getVerticalAcceleration() * time *  time);
    return pos;
}


