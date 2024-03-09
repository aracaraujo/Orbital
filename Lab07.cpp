/*************************************************************
 * 1. Name:
 *      Ara Araujo & Wade Withers
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "test.h"
#include <vector>
#include "cmath"
#define GRAVITY 9.80665  // m/s2
#define RADIUS 6378000 // earth radius
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
      ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptSputnik.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptSputnik.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptStarlink.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptStarlink.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptCrewDragon.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptCrewDragon.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptGPS.setPixelsX(0);
      ptGPS.setPixelsY(330);

      ptStar = createStars();

      angleShip = 0.0;
      angleEarth = 0.0;
      phaseStar = 0;

      ptGPSVelocityX = -3100.0;
      ptGPSVelocityY = 0;
   }

    vector<Position> createStars(){
        vector<Position> stars;

        while(stars.size() < 50){
            Position star;
            star.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5,0.5));
            star.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5,0.5));
            // Checking that the position is not on the ground.
            stars.push_back(star);
        }
        return stars;
    }

    double earthRotation(){

       return -(2 * M_PI/ 30 ) * (1440.0/86400.0);
   }

   double getGravity(double height){
       return GRAVITY * ((RADIUS/(RADIUS + height)) * (RADIUS/(RADIUS + height)));
   }

   double distanceFromEarth(Position satellite){
       double distances = (satellite.getMetersX() * satellite.getMetersX()) + (satellite.getMetersY() * satellite.getMetersY());
       return sqrt((distances-RADIUS));
   }

   double directionGravityPull(Position satellite){
       return atan2(0-satellite.getMetersX(),0-satellite.getMetersY());
   }

   double horizontalAcceleration(double acceleration, Position satellite){
       return acceleration * sin(directionGravityPull(satellite));
   }

    double verticalAcceleration(double acceleration, Position satellite){
        return acceleration * cos(directionGravityPull(satellite));
    }

    double velocityFromAcceleration(double initialVelocity, double acceleration, double time){
       return initialVelocity + (acceleration * time);
   }

   double calculateDistance(double initialDistance, double velocity, double time, double acceleration){
       return initialDistance + (velocity * time) + ((acceleration * (time*time))/2);
   }

   Position ptHubble;
   Position ptSputnik;
   Position ptStarlink;
   Position ptCrewDragon;
   Position ptShip;
   Position ptGPS;
   vector<Position> ptStar;
   Position ptUpperRight;
   double ptGPSVelocityX;
   double ptGPSVelocityY;

   unsigned char phaseStar;

   double angleShip;
   double angleEarth;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // accept input
   //

   // move by a little
   if (pUI->isUp())
      pDemo->ptShip.addPixelsY(1.0);
   if (pUI->isDown())
      pDemo->ptShip.addPixelsY(-1.0);
   if (pUI->isLeft())
      pDemo->ptShip.addPixelsX(-1.0);
   if (pUI->isRight())
      pDemo->ptShip.addPixelsX(1.0);


   //
   // perform all the game logic
   //

   // rotate the earth
   pDemo->angleEarth += pDemo->earthRotation();

   pDemo->phaseStar++;

   double height = pDemo->distanceFromEarth(pDemo->ptGPS);
   double gravity = pDemo->getGravity(height);
   pDemo->angleShip += 0.01;

   double horizontalAcceleration = pDemo->horizontalAcceleration(gravity,pDemo->ptGPS);
   double verticalAcceleration = pDemo->verticalAcceleration(gravity,pDemo->ptGPS);

   pDemo->ptGPSVelocityX = pDemo->velocityFromAcceleration(pDemo->ptGPSVelocityX,horizontalAcceleration,48);
   pDemo->ptGPSVelocityY = pDemo->velocityFromAcceleration(pDemo->ptGPSVelocityY,verticalAcceleration,48);

   pDemo->ptGPS.setMetersX(pDemo->calculateDistance(pDemo->ptGPS.getMetersX(),pDemo->ptGPSVelocityX,48,horizontalAcceleration));
   pDemo->ptGPS.setMetersY(pDemo->calculateDistance(pDemo->ptGPS.getMetersY(),pDemo->ptGPSVelocityY,48,verticalAcceleration));

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
//   gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
//   gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
//   gout.drawSputnik   (pDemo->ptSputnik,    pDemo->angleShip);
//   gout.drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
//   gout.drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
   gout.drawGPS       (pDemo->ptGPS,        pDemo->angleShip);

//    draw parts
//   pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
//   gout.drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
//   pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
//   gout.drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
//   pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20); *
//   pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20); *
//   gout.drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
//   pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
//   gout.drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set

   // draw fragments
//   pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
//   gout.drawFragment(pt, pDemo->angleShip);
//   pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
//   gout.drawFragment(pt, pDemo->angleShip);

   // draw a single star
   for (Position star : pDemo->ptStar){
       gout.drawStar(star, pDemo->phaseStar);
   }

   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   testRunner();
   cout << "All tests passed!" << endl;

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
