/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Andrew Simonson (Team 96807B)                             */
/*    Created:      Fri Dec 06 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "ButtonClass.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  lcdButton Greg(200,200,50,500,"to victory!");

  lcdButton Josh(100,100,75,75,"yeet!");

  int GregCooldown = 0;
  int JoshCooldown = 0;

  while(1){
    if(Greg.pressing() && GregCooldown < 1){
      Brain.Screen.print("EY!");
      GregCooldown = 100;
    }
    if(Josh.pressing() && JoshCooldown < 1){
      Brain.Screen.print("ok boomer");
      JoshCooldown = 100;
    }
    task::sleep(10);
    GregCooldown--;
    JoshCooldown--;
  }
  
}
