//
// Created by Ara Cantanhede Araujo on 3/8/24.
//

#pragma once

#include "velocity.h"
#include <cassert>

class TestVelocity
{
public:
    void run()
    {
        defaultConstructor();
        nonDefaultConstructor();
        getVelocities();
        setVelocities();
        plusOperator();
        negativeOperator();
//        updateVelocityTwoPositive();
//        updateVelocityDyPositiveDxZero();
//        updateVelocityDyZeroDxPositive();
//        updateVelocityBothNegative();
    }

private:
    // utility function because floating point numbers are approximations
    bool closeEnough(double value, double test, double tolerence) const
    {
        double difference = value - test;
        return (difference >= -tolerence) && (difference <= tolerence);
    }

    void defaultConstructor() const
    {
        // Setup
        // Exercise
        Velocity velocity;
        // verify
        assert(velocity.dy == 0.0);
        assert(velocity.dx == 0.0);
        // Teardown
    }

    void nonDefaultConstructor() const
    {
        // Setup
        double tolerance = 0.01;
        // Exercise
        Velocity velocity(200.0,250.0);
        // verify
        assert(closeEnough(velocity.dy,200.0,tolerance));
        assert(closeEnough(velocity.dx,250.0,tolerance));
        // Teardown
    }

    void getVelocities() const
    {
        // Setup
        double tolerance = 0.01;
        // Exercise
        Velocity velocity(200.0,250.0);
        // verify
        assert(closeEnough(velocity.getVerticalVelocity(),200.0,tolerance));
        assert(closeEnough(velocity.getHorizontalVelocity(),250.0,tolerance));
        // Teardown

    }

    /*
     * Testing setters.
     */
    void setVelocities() const
    {
        // Setup
        // Exercise
        Velocity velocity;
        velocity.setVerticalVelocity(200.0);
        velocity.setHorizontalVelocity(250.0);
        // verify
        assert(velocity.dy == 200.0);
        assert(velocity.dx == 250.0);
        // Teardown
    }

    void plusOperator() const
    {
        // Setup
        Velocity velocityOne;
        Velocity velocityTwo(200.0,250.0);
        // Exercise
        velocityOne += velocityTwo;
        // verify
        assert(velocityOne.dy == 200.0);
        assert(velocityOne.dx == 250.0);
        // Teardown
    }

    void negativeOperator() const
    {
        // Setup
        Velocity velocityOne;
        Velocity velocityTwo(200.0,250.0);
        // Exercise
        velocityOne -= velocityTwo;
        // verify
        assert(velocityOne.dy == -200.0);
        assert(velocityOne.dx == -250.0);
        // Teardown
    }

//    void updateVelocityTwoPositive() const
//    {
//        // Setup
//        Velocity velocity(10.0,15.0);
//        // Exercise
//        velocity.updateVelocity(5,5,48); // We are using 48 sec because that is the time in each frame of the orbital
//        // verify
//        assert(velocity.dy == 250.0);
//        assert(velocity.dx == 255.0);
//        // Teardown
//    }
//
//    void updateVelocityDyPositiveDxZero() const
//    {
//        // Setup
//        Velocity velocity(10.0,15.0);
//        // Exercise
//        velocity.updateVelocity(5,0,48); // We are using 48 sec because that is the time in each frame of the orbital
//        // verify
//        assert(velocity.dy == 250.0);
//        assert(velocity.dx == 15.0);
//        // Teardown
//    }
//
//    void updateVelocityDyZeroDxPositive() const
//    {
//        // Setup
//        Velocity velocity(10.0,15.0);
//        // Exercise
//        velocity.updateVelocity(0,5,48); // We are using 48 sec because that is the time in each frame of the orbital
//        // verify
//        assert(velocity.dy == 10.0);
//        assert(velocity.dx == 255.0);
//        // Teardown
//    }
//
//    void updateVelocityBothNegative() const
//    {
//        // Setup
//        Velocity velocity(10.0,15.0);
//        // Exercise
//        velocity.updateVelocity(-2,-2,48); // We are using 48 sec because that is the time in each frame of the orbital
//        // verify
//        assert(velocity.dy == -86.0);
//        assert(velocity.dx == -81.0);
//        // Teardown
//    }

};
