//
// Created by Wade Withers on 3/9/24.
//

#ifndef ORBITAL_TESTACCELERATION_H
#define ORBITAL_TESTACCELERATION_H

#include "acceleration.h"
#include <cmath>
#include <cassert>

class TestAcceleration {
public:
    void run() {
        test_defaultConstructor();
        test_nonDefaultConstructor_gravitySeaLevelAngleZero();
        test_nonDefaultConstructor_gravitySeaLevelAngle90();
        test_nonDefaultConstructor_gravityGeoAngle30();
        test_setAccelerations();
        test_getAccelerations();
        test_calcVertAccelerationFromGravity_gravityGeoAngleZero();
        test_calcVertAccelerationFromGravity_gravityGeoAngle45();
        test_calcVertAccelerationFromGravity_gravitySeaLevelAngle30();
        test_calcHorizAccelerationFromGravity_gravityGeoAngle90();
        test_calcHorizAccelerationFromGravity_gravityGeoAngleNeg30();
        test_calcHorizAccelerationFromGravity_gravitySeaLevelAngleZero();
    }

private:
    // utility function because floating point numbers are approximations
    bool closeEnough(double value, double test, double tolerance) const
    {
        double difference = value - test;
        return (difference >= -tolerance) && (difference <= tolerance);
    }

    /*
     * Testing constructor
     */
    void test_defaultConstructor() {
        // Setup

        // Exercise
        Acceleration acceleration;

        // Verify
        assert(acceleration.verticalAcceleration == 0.0);
        assert(acceleration.horizontalAcceleration == 0.0);

        // Teardown
    }

    /*
     * Testing that constructor calculates accelerations correctly.
     */
    void test_nonDefaultConstructor_gravitySeaLevelAngleZero() {
        // Setup
        double gravity = 9.8067;
        double angle = 0.0;
        double tolerance = 0.01;

        // Exercise
        Acceleration acceleration(gravity, angle);

        // Verify
        assert(closeEnough(9.8067, acceleration.verticalAcceleration, tolerance));
        assert(closeEnough(0.0, acceleration.horizontalAcceleration, tolerance));

        // Teardown
    }

    /*
     * Testing that constructor calculates accelerations correctly.
     */
    void test_nonDefaultConstructor_gravitySeaLevelAngle90() {
        // Setup
        double gravity = 9.8067;
        double angle = M_PI/2;
        double tolerance = 0.01;

        // Exercise
        Acceleration acceleration(gravity, angle);

        // Verify
        assert(closeEnough(0.0, acceleration.verticalAcceleration, tolerance));
        assert(closeEnough(9.8067, acceleration.horizontalAcceleration, tolerance));

        // Teardown
    }

    /*
     * Testing that constructor calculates accelerations correctly.
    */
    void test_nonDefaultConstructor_gravityGeoAngle30() {
        // Setup
        double gravity = 0.2244;
        double angle = M_PI/6;
        double tolerance = 0.01;

        // Exercise
        Acceleration acceleration(gravity, angle);

        // Verify
        assert(closeEnough(0.1943, acceleration.verticalAcceleration, tolerance));
        assert(closeEnough(0.1122, acceleration.horizontalAcceleration, tolerance));

        // Teardown
    }

    /*
     * Testing setters.
     */
    void test_setAccelerations() {
        // Setup
        Acceleration a;

        // Exercise
        a.setVerticalAcceleration(1.0);
        a.setHorizontalAcceleration(1.0);

        // Verify
        assert(a.verticalAcceleration == 1.0);
        assert(a.horizontalAcceleration == 1.0);

        // Teardown
    }

    /*
     * Testing getters
     */
    void test_getAccelerations() {
        // Setup
        double gravity = 10.0;
        double angle = M_PI/4;
        Acceleration a(gravity, angle);
        double tolerance = 0.01;

        // Exercise
        double ddy = a.getVerticalAcceleration();
        double ddx = a.getHorizontalAcceleration();

        // Verify
        assert(closeEnough(7.0711, ddy, tolerance));
        assert(closeEnough(7.0711, ddx, tolerance));

        // Teardown
    }

    /*
     * Testing calculate Vertical acceleration when satellite is 35,786.0 km above earth.
     */
    void test_calcVertAccelerationFromGravity_gravityGeoAngleZero() {
        // Setup
        Acceleration a;
        double gravity = 0.2244;
        double angle = 0.0;
        double tolerance = 0.01;

        // Exercise
        a.calcVerticalAccelerationFromGravity(gravity, angle);

        // Verify
        assert(closeEnough(0.2244, a.verticalAcceleration, tolerance));
        assert(closeEnough(0.0, a.horizontalAcceleration, tolerance));

        // Teardown
    }

    /*
     * Testing calculate Vertical acceleration when satellite is 35,786.0 km above earth.
     */
    void test_calcVertAccelerationFromGravity_gravityGeoAngle45() {
        // Setup
        Acceleration a;
        double gravity = 0.2244;
        double angle = M_PI/4;
        double tolerance = 0.01;

        // Exercise
        a.calcVerticalAccelerationFromGravity(gravity, angle);

        // Verify
        assert(closeEnough(0.1587, a.verticalAcceleration, tolerance));
        assert(closeEnough(0.1587, a.horizontalAcceleration, tolerance));

        // Teardown
    }

    /*
     * Testing calculate Vertical acceleration when satellite is at sea level.
     */
    void test_calcVertAccelerationFromGravity_gravitySeaLevelAngle30() {
        // Setup
        Acceleration a;
        double gravity = 9.8067;
        double angle = M_PI/6;
        double tolerance = 0.01;

        // Exercise
        a.calcVerticalAccelerationFromGravity(gravity, angle);

        // Verify
        assert(closeEnough(8.4929, a.verticalAcceleration, tolerance));
        assert(closeEnough(4.9034, a.horizontalAcceleration, tolerance));

        // Teardown
    }

    /*
     * Testing calculate horizontal acceleration when satellite is 35,786.0 km above earth.
     */
    void test_calcHorizAccelerationFromGravity_gravityGeoAngle90() {
        // Setup
        Acceleration a;
        double gravity = 0.2244;
        double angle = M_PI/2;
        double tolerance = 0.01;

        // Exercise
        a.calcHorizontalAccelerationFromGravity(gravity, angle);

        // Verify
        assert(closeEnough(0.0, a.verticalAcceleration, tolerance));
        assert(closeEnough(0.2244, a.horizontalAcceleration, tolerance));

        // Teardown
    }

    /*
     * Testing calculate horizontal acceleration when satellite is 35,786.0 km above earth.
     */
    void test_calcHorizAccelerationFromGravity_gravityGeoAngleNeg30() {
        // Setup
        Acceleration a;
        double gravity = 0.2244;
        double angle = -M_PI/6;
        double tolerance = 0.01;

        // Exercise
        a.calcHorizontalAccelerationFromGravity(gravity, angle);

        // Verify
        assert(closeEnough(0.1943, a.verticalAcceleration, tolerance));
        assert(closeEnough(-0.1122, a.horizontalAcceleration, tolerance));

        // Teardown
    }

    /*
     * Testing calculate horizontal acceleration when satellite is at sea level.
     */
    void test_calcHorizAccelerationFromGravity_gravitySeaLevelAngleZero() {
        // Setup
        Acceleration a;
        double gravity = 9.8067;
        double angle = 0.0;
        double tolerance = 0.01;

        // Exercise
        a.calcHorizontalAccelerationFromGravity(gravity, angle);

        // Verify
        assert(closeEnough(9.8067, a.verticalAcceleration, tolerance));
        assert(closeEnough(0.0, a.horizontalAcceleration, tolerance));

        // Teardown
    }

};

#endif //ORBITAL_TESTACCELERATION_H
