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

#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include <vector>
#include "cmath"
#include "chaser.h"
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
      ptUpperRight(ptUpperRight),
      ship(Position(),Acceleration(),Velocity(0.0,-2.0),Angle(M_PI/2),10.0),
      gout(new ogstream(Position()))
   {
      ship.setLocationInPixels(-450,450);

      ptStar = createStars();

      angleEarth = 0.0;
      phaseStar = 0;

   }

    vector<Position> createStars() const{
        vector<Position> stars;

        while(stars.size() < 200){
            Position star;
            star.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5,0.5));
            star.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5,0.5));
            stars.push_back(star);
        }
        return stars;
    }

   Chaser ship;
   vector<Position> ptStar;
   Position ptUpperRight;
   ogstream * gout;

   unsigned char phaseStar;

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

   // accept input
   pDemo->ship.setIsSpacePress(false);
   if (pUI->isDown()){
       pDemo->ship.setIsSpacePress(true);
       pDemo->ship.thrust(2.0);
   }
   if (pUI->isLeft())
   {
       pDemo->ship.rotate(-0.1);
   }
   if (pUI->isRight())
   {
       pDemo->ship.rotate(0.1);
   }

   //
   // perform all the game logic
   //

   // rotate the earth
   pDemo->angleEarth += earthRotation();

   pDemo->ship.move();

   // draw everything
   Position pt;
   pDemo->phaseStar++;

   // draw a single star
   for (Position star : pDemo->ptStar){
       pDemo->gout->drawStar(star, pDemo->phaseStar);
   }

   // draw the earth
   pt.setMeters(0.0, 0.0);
   pDemo->gout->drawEarth(pt, pDemo->angleEarth);
   pDemo->ship.display(pDemo->gout);
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
