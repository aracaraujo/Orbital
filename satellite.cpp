//
// Created by Wade Withers on 3/28/24.
//

#include "satellite.h"
#include "uiDraw.h"
#include <vector>
#include "fragment.h"

/****************************
 * Sputnik
 ****************************/
void Sputnik::display(ogstream *gout) const {
    gout->drawSputnik(this->position, this->angle.getRadians());
}

void Sputnik::destroy(vector<Component*> &satellites) {
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI/2, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 0, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 11*M_PI/6, radius = 2));
}

/****************************
 * GPS
 ****************************/
void Gps::display(ogstream *gout) const {
    gout->drawGPS(this->position, this->angle.getRadians());
}

void Gps::destroy(vector<Component*> &satellites) {
    satellites.push_back(new GPSCenter(position, acceleration, velocity, angle, radius = 7));
//    satellites.push_back(new GPSLeft(position, acceleration, velocity, angle, radius = 8));
//    satellites.push_back(new GPSRight(position, acceleration, velocity, angle+=M_PI/2, radius = 8));
//    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 11*M_PI/6, radius = 2));
//    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 5*M_PI/6, radius = 2));
}

/****************************
 * Hubble
 ****************************/
void Hubble::display(ogstream *gout) const {
    gout->drawHubble(this->position, this->angle.getRadians());
}

void Hubble::destroy(vector<Component *> &satellites) {
    satellites.push_back(new HubbleTelescope(position, acceleration, velocity, angle = M_PI/2, radius = 10));
    satellites.push_back(new HubbleComputer(position, acceleration, velocity, angle = 0, radius = 7));
    satellites.push_back(new HubbleLeft(position, acceleration, velocity, angle = M_PI, radius = 8));
    satellites.push_back(new HubbleRight(position, acceleration, velocity, angle = 11*M_PI/6, radius = 8));
}

/****************************
 * Dragon
 ****************************/
void Dragon::display(ogstream *gout) const {
    gout->drawCrewDragon(this->position, this->angle.getRadians());
}

void Dragon::destroy(vector<Component *> &satellites) {
    satellites.push_back(new DragonCenter(position, acceleration, velocity, angle = M_PI/2, radius = 6));
    satellites.push_back(new DragonLeft(position, acceleration, velocity, angle = 0, radius = 6));
    satellites.push_back(new DragonRight(position, acceleration, velocity, angle = M_PI, radius = 6));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 11*M_PI/6, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 5*M_PI/6, radius = 2));
}

/****************************
 * Starlink
 ****************************/
void Starlink::display(ogstream *gout) const {
    gout->drawStarlink(this->position, this->angle.getRadians());
}

void Starlink::destroy(vector<Component *> &satellites) {
    satellites.push_back(new GPSCenter(position, acceleration, velocity, angle = M_PI/2, radius = 7));
    satellites.push_back(new GPSLeft(position, acceleration, velocity, angle = 0, radius = 8));
    satellites.push_back(new GPSRight(position, acceleration, velocity, angle = M_PI, radius = 8));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 11*M_PI/6, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 5*M_PI/6, radius = 2));
}

/****************************
 * GPS Parts
 ****************************/
 // GPS Center
void GPSCenter::display(ogstream *gout) const {
    gout->drawGPSCenter(this->position, this->angle.getRadians());
}

void GPSCenter::destroy(vector<Component *> &satellites) {
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI/2, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 0, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI, radius = 2));
}

// GPS left
void GPSLeft::display(ogstream *gout) const {
    gout->drawGPSLeft(this->position, this->angle.getRadians());
}

void GPSLeft::destroy(vector<Component *> &satellites) {
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI/2, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 0, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI, radius = 2));
}

// GPS Right
void GPSRight::display(ogstream *gout) const {
    gout->drawGPSRight(this->position, this->angle.getRadians());

}

void GPSRight::destroy(vector<Component *> &satellites) {
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI/2, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 0, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI, radius = 2));
}

/****************************
 * Hubble Parts
 ****************************/
 // Hubble Telescope
void HubbleTelescope::display(ogstream *gout) const {
     gout->drawHubbleTelescope(this->position, this->angle.getRadians());

}

void HubbleTelescope::destroy(vector<Component *> &satellites) {
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI/2, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 0, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI, radius = 2));
}

// Hubble Computer
void HubbleComputer::display(ogstream *gout) const {
    gout->drawHubbleComputer(this->position, this->angle.getRadians());

}

void HubbleComputer::destroy(vector<Component *> &satellites) {
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI/2, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 0, radius = 2));
}

// Hubble Left
void HubbleLeft::display(ogstream *gout) const {
    gout->drawHubbleLeft(this->position, this->angle.getRadians());

}

void HubbleLeft::destroy(vector<Component *> &satellites) {
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI/2, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 0, radius = 2));
}

// Hubble Right
void HubbleRight::display(ogstream *gout) const {
    gout->drawHubbleRight(this->position, this->angle.getRadians());

}

void HubbleRight::destroy(vector<Component *> &satellites) {
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI/2, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 0, radius = 2));
}

/****************************
 * Crew Dragon Parts
 ****************************/
// Dragon Center
void DragonCenter::display(ogstream *gout) const {
    gout->drawCrewDragonCenter(this->position, this->angle.getRadians());

}

void DragonCenter::destroy(vector<Component *> &satellites) {
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI/2, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 0, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 11*M_PI/6, radius = 2));
}

// Dragon Left
void DragonLeft::display(ogstream *gout) const {
    gout->drawCrewDragonLeft(this->position, this->angle.getRadians());

}

void DragonLeft::destroy(vector<Component *> &satellites) {
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI/2, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 0, radius = 2));
}

// Dragon Right
void DragonRight::display(ogstream *gout) const {
    gout->drawCrewDragonRight(this->position, this->angle.getRadians());

}

void DragonRight::destroy(vector<Component *> &satellites) {
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI/2, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 0, radius = 2));
}

/****************************
 * Starlink Parts
 ****************************/
 // Starlink Body
void StarlinkBody::display(ogstream *gout) const {
     gout->drawStarlinkBody(this->position, this->angle.getRadians());

}

void StarlinkBody::destroy(vector<Component *> &satellites) {
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI/2, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 0, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI, radius = 2));
}

// Starlink Array
void StarlinkArray::display(ogstream *gout) const {
    gout->drawStarlinkArray(this->position, this->angle.getRadians());
}

void StarlinkArray::destroy(vector<Component *> &satellites) {
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI/2, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = 0, radius = 2));
    satellites.push_back(new Fragment(position, acceleration, velocity, angle = M_PI, radius = 2));
}
