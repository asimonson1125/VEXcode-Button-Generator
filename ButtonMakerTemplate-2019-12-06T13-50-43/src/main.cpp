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
  while(true){
    //insert your code here
  }


//Here's an example of the button generator's use.  Have at it.
/*
  //create the buttons with shorter constructor (center x, center y, width, height, text, color)
  lcdButton Greg(250,100,100,50,"I am Greg", "#FF2525"); 
  lcdButton Josh(100,100,100,75,"I am Josh", "#2525FF");
  //create cooldowns so you have time to lift your finger
  int GregCooldown = 0;
  int JoshCooldown = 0;
  while(1){
    if(Greg.pressing() && GregCooldown < 1){ //check if greg is being pressed
      Brain.Screen.print("Greg Has Been Pressed.");
      GregCooldown = 100; //set cooldown
    }
    if(Josh.pressing() && JoshCooldown < 1){ //check if Josh is being pressed
      Brain.Screen.print("Josh Has Been Pressed.");
      JoshCooldown = 100; //set cooldown
    }
    task::sleep(10);
    GregCooldown--; //cool down cooldown
    JoshCooldown--;
  }*/
  
}
