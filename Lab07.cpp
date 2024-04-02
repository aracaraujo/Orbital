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
#include "satellite.h"
#include "fragment.h"
#include <list>
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

      // Adding satellites
      components.push_back(new Sputnik(Position(-36515095.13,21082000.0),Acceleration(),Velocity(2050.0,2684.68),Angle(),4));
      components.push_back(new Gps(Position(0.0, 26560000.0), Acceleration(), Velocity(-3880.0, 0.0), Angle(M_PI/2), 12.0));
      components.push_back(new Gps(Position(23001634.72, 13280000.0), Acceleration(), Velocity(-1940.0, 3360.18), Angle(M_PI/2), 12.0));
      components.push_back(new Gps(Position(23001634.72, -13280000.0), Acceleration(), Velocity(1940.0, 3360.18), Angle(M_PI/2), 12.0));
      components.push_back(new Gps(Position(0.0, -26560000.0), Acceleration(), Velocity(3880.0, 0.0), Angle(M_PI/2), 12.0));
      components.push_back(new Gps(Position(-23001634.72, -13280000.0), Acceleration(), Velocity(1940.0, -3360.18), Angle(M_PI/2), 12.0));
      components.push_back(new Gps(Position(-23001634.72, 13280000.0), Acceleration(), Velocity(-1940.0, -3360.18), Angle(M_PI/2), 12.0));
      components.push_back(new Hubble(Position(0.0, -42164000.0), Acceleration(), Velocity(3100.0, 0.0), Angle(M_PI/2), 10.0));
      components.push_back(new Dragon(Position(0.0, 8000000.0), Acceleration(), Velocity(-7900.0, 0.0), Angle(M_PI/2), 7.0));
      components.push_back(new Starlink(Position(0.0, -13020000.0), Acceleration(), Velocity(5800.0, 0.0), Angle(M_PI/2), 6.0));
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
        // Draw stars.
        for (Star& star : stars){
            star.incrementPhase();
            gout->drawStar(star.getPosition(), star.getPhase());
            }
        // Draw other components.
        for (Component* comp : components) {
            comp->display(gout);
        }
   }

    void move(){
       list <Component*> :: iterator  it;
       list <Component*> :: iterator  it2;

       ship.move(48);

       for (Component*& comp : components) {
           comp->move(48);
       }

       for (it = components.begin(); it != components.end(); ++it){
            // add loop to check for collision between the components
           for ((it2 = it)++; it2 != components.end(); ++it2){
               if (!(*it)->isDead() && !(*it2)->isDead()){
                   // Distance is divided by 128k, so we have the value in pixels since the radius are in pixel.
                   if (computeDistance((*it)->getPosition(),(*it2)->getPosition())/128000 < ((*it)->getRadius() + (*it2)->getRadius() )){
                       (*it)->kill();
                       (*it2)->kill();
                   }
               }
           }
            // Check collision with the earth
            if (computeDistance(Position(0.0,0.0),(*it)->getPosition()) < ((*it)->getRadius() + EARTHRADIUS )){
                (*it)->kill();
            }

            // Check collision with the ship
            // Distance is divided by 128k, so we have the value in pixels since the radius are in pixel.
            if (computeDistance(ship.getPosition(),(*it)->getPosition())/128000 < ((*it)->getRadius() + ship.getRadius())){
                (*it)->kill();
            }

            // Check projectile's and fragment's age.
            // When it hits 70 it will kill it if not it will just increment.
            if (Projectile* projectile = dynamic_cast<Projectile*>(*it)){
                if(projectile->getAge() == 70){
                    projectile->kill();
                }else{
                    projectile->incrementAge();
                }
            }

           if (Fragment* fragment = dynamic_cast<Fragment*>(*it)){
               if(fragment->getAge() == 70){
                   fragment->kill();
               }else{
                   fragment->incrementAge();
               }
           }

        }

        // Check ship collision with earth
        // We need to decide what will happen in this situation.
        if (computeDistance(ship.getPosition(),Position(0.0,0.0)) < (ship.getRadius() + EARTHRADIUS )){
            ship.kill();
        }

        // Removing dead components from the list.
        for (auto it= components.begin(); it != components.end();){
            if((*it)->isDead()){
//                if (Satellite* satellite = dynamic_cast<Satellite*>(*it)){
//                    satellite->destroy(components);
//                }
                (*it)->destroy(components);
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
   list<Component*> components;
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
       pDemo->components.push_back(new Projectile(pDemo->ship.shoot()));
   }
   //
   // perform all the game logic
   //

   // rotate the earth
   pDemo->angleEarth += earthRotation();

   pDemo->move();

   // draw everything
   Position pt;

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
