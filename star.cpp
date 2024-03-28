#include "star.h"
#include "position.h"


Star::Star(){
    this->position = Position(0.0,0.0);
}

// Non-default constructor.
Star::Star(Position position, int phase){
    this->position = position;
    this->phase = phase;
}

// Set position.
void Star::setPosition(Position newPosition){
    this->position = newPosition;
}

// Get Position.
Position Star::getPosition(){
    return this->position;
}

// Set phase.
void Star::setPhase(unsigned char newPhase){
    this->phase = newPhase;
}

// Get Position.
unsigned char Star::getPhase(){
    return this->phase;
}

void Star::incrementPhase(){
    this->phase = getPhase() + 1;
}

void Star::setLocationInPixels(double x, double y){
    this->position.setPixelsX(x);
    this->position.setPixelsY(y);
}