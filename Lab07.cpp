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
#include "projectile.h"
#include "star.h"
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

      createStars();

      angleEarth = 0.0;
   }

    void createStars() {

        for(auto & i : stars){
            Star star;
            star.setLocationInPixels(ptUpperRight.getPixelsX() * random(-0.5,0.5),ptUpperRight.getPixelsX() * random(-0.5,0.5));
            unsigned char phase = random(0,255);
            star.setPhase(phase);
            i = star;
        }
    }

    void display(){
        for (Component* comp : components) {
            comp->display(gout);
        }
   }

    void move(){

       ship.move();

       for (Component*& comp : components) {
            comp->move();
       }

        for (auto it = components.begin(); it != components.end(); ++it){
            // add loop to check for collision between the components

            // Check collision with the earth
            if (computeDistance(Position(0.0,0.0),(*it)->getPosition()) < ((*it)->getRadius() + RADIUS )){
                (*it)->kill();
                cout << "Collision with the earth" << endl;
            }

            // Check collision with the ship
            if (computeDistance(ship.getPosition(),(*it)->getPosition()) < ((*it)->getRadius() + ship.getRadius())){
                (*it)->kill();
                cout << "Collision with the ship" << endl;
            }
        }

        // Check ship collision with earth
        // We need to decide what will happen in this situation.
        if (computeDistance(ship.getPosition(),Position(0.0,0.0)) < (ship.getRadius() + RADIUS )){
            ship.kill();
            cout << "Collision with the ship" << endl;
        }

        // Removing dead components from the list.
        for (auto it= components.begin(); it != components.end();){
            if((*it)->isDead()){
                delete *it;
                it = components.erase(it);
            }else{
                ++it;
            }
        }

   }

   Chaser ship;
   Star stars[200];
   Position ptUpperRight;
   ogstream * gout;
   vector<Component*> components;

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
   if (pUI->isSpace())
   {
       if(pDemo->components.size() < 5){
           pDemo->components.push_back(new Projectile(pDemo->ship.shoot()));
       }

   }

   //
   // perform all the game logic
   //

   // rotate the earth
   pDemo->angleEarth += earthRotation();

   pDemo->ship.move();

   pDemo->move();

   // draw everything
   Position pt;

   // draw a single star
   for (Star& star : pDemo->stars){
       star.incrementPhase();
       pDemo->gout->drawStar(star.getPosition(), star.getPhase());
   }

   pDemo->display();


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
