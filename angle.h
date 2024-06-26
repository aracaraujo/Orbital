#pragma once

#include <iostream>
#include <istream>
#include <cassert>
#include <ostream>
#include <cmath>
#include <iomanip>

#define TWO_PI 6.28318530718

using namespace std;

/************************************
 * ANGLE
 ************************************/
class Angle
{

public:
    // Default constructor
    Angle() : radians(0.0) {}
    Angle(const Angle & rhs) : radians(rhs.radians) {}
    Angle(double radians) : radians(radians) {}

    // Getters
    double getDegrees() const
    {
        return convertToDegrees(radians);
    }
    double getRadians() const
    {
        return radians;
    }

    // Setters
    void setDegrees(double degrees)
    {
        radians = normalize(convertToRadians(degrees));
    }
    void setRadians(double radians)
    {
        this->radians = normalize(radians);
    }

    void rotate(double amount)
    {
        radians += amount;
        if(radians > M_PI)
            radians -= 2.0 * M_PI;
        if(radians < M_PI)
            radians += 2.0 * M_PI;
    }

    void setDxDy(double dx, double dy)
    {
        radians = atan2(dx,dy);
    }

    // Display
    void display(ostream & out) const
    {
        out.precision(1);
        out.setf(ios::fixed | ios::showpoint);
        out << getDegrees();
    }

    // Assignment Operator
    Angle & operator=(const Angle & rhs)
    {
        radians = rhs.radians;
        return *this;
    }

    Angle & operator=(double radians)
    {
        radians = radians;
        return *this;
    }

    Angle& operator+=(const double & rhs)
    {
        radians += rhs;
        return *this;
    }

    Angle& operator-=(const double & rhs)
    {
        radians -= rhs;
        return *this;
    }

    // Negative Operator
    Angle operator-() const
    {
        return Angle(convertToDegrees(radians) + 180);
    }

    // Equals Operator
    bool operator==(const Angle & rhs) const
    {
        return radians == rhs.radians;
    }

    // Not Equals Operator
    bool operator!=(const Angle & rhs) const
    {
        return radians != rhs.radians;
    }

    Angle & operator++()
    {
        radians += convertToRadians(1.0);
        radians = normalize(radians);
        return *this;
    }

    Angle operator++(int postfix)
    {
        Angle angleReturn(*this);
        radians += convertToRadians(1.0);
        radians = normalize(radians);
        return angleReturn;
    }

    Angle & operator--()
    {
        radians -= convertToRadians(1.0);
        radians = normalize(radians);
        return *this;
    }

    Angle operator--(int postfix)
    {
        Angle angleReturn(*this);
        radians -= convertToRadians(1.0);
        radians = normalize(radians);
        return angleReturn;
    }


private:
    // Convert functions
    double convertToDegrees(double newRadians) const
    {
//        cout << normalize(newRadians) / TWO_PI * 360.0 << endl;
        return normalize(newRadians) / TWO_PI * 360.0;
    }

    double convertToRadians(double degrees) const
    {
        return normalize(degrees / 360.0 * TWO_PI);
    }

    // Normalize
    double normalize(double radians) const
    {
        if (radians >= TWO_PI)
        {
            double multiples = floor(radians / TWO_PI);
            assert(radians - TWO_PI * multiples >= 0.0);
            assert(radians - TWO_PI * multiples <= TWO_PI);
            return radians - (TWO_PI * multiples);
        }
        else if (radians < 0.0)
        {
            double multiples = ceil(-radians / TWO_PI);
            assert(TWO_PI * multiples + radians >= 0.0);
            assert(TWO_PI * multiples + radians <= TWO_PI);
            return TWO_PI * multiples + radians;
        }

        assert(0.0 <= radians && radians <= TWO_PI);
        return radians;
    }

    double radians;
};
