/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       simonand                                                  */
/*    Created:      Mon Dec 09 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "ButtonClass.h"

using namespace vex;


int xplace = 70;
int ColorChosen = 1;

lcdButton redButton(123, 22, 230, 35, "RED", "#252525");
lcdButton blueButton(480-123, 22, 230, 35, "BLUE", "#252525");

lcdButton confirm(300,150,100,60, "CONFIRM","#14c40e");
lcdButton none(xplace,90,120,40, "None", "#252525");

lcdButton redrun(xplace,135,120,40, "RedRun", "#FF2525");//, color(255, 33, 33));
lcdButton red4(xplace,180,120,40, "Red4", "#FF2525");//, color(255, 33, 33));
lcdButton bluerun(1000,135,120,40, "BlueRun", "#2525FF"); //figure out color scheme
lcdButton blue4(1000,180,120,40, "Blue4", "#2525FF");


void drawTonomous(){
  Brain.Screen.clearScreen("black");
  Brain.Screen.setPenColor(white);
  Brain.Screen.setPenWidth(2);
  Brain.Screen.drawLine(0,60,500,60);
  redButton.draw();
  blueButton.draw();
  confirm.draw();
  none.draw();
  redrun.draw();
  red4.draw();
  bluerun.draw();
  blue4.draw();

}

int main() {
    vexcodeInit();
int aselection = -1;
bool unconfirmed = true;

  Brain.Screen.clearScreen("black");
  drawTonomous();

  //use coordinate presser for exact spacing

  while(unconfirmed){
    if(Brain.Screen.pressing()){
      if(redButton.pressing()){
        ColorChosen = 1;
        redrun.moveTo(xplace,redrun.yPos);
        red4.moveTo(xplace,red4.yPos);
        bluerun.moveTo(1000,bluerun.yPos);
        blue4.moveTo(1000,blue4.yPos);
        drawTonomous();
      }
      else if (blueButton.pressing()){
        ColorChosen = 2;
        redrun.moveTo(1000,redrun.yPos);
        red4.moveTo(1000,red4.yPos);
        bluerun.moveTo(xplace,bluerun.yPos);
        blue4.moveTo(xplace,blue4.yPos);
        drawTonomous();
      }
      else if (ColorChosen == 1){
        if(redrun.pressing()){
          aselection = 1;
          drawTonomous();
        }
        else if (red4.pressing()){
          aselection = 3;
          drawTonomous();
        }
      }
      else if (ColorChosen == 2){
        if(bluerun.pressing()){
          aselection = 2;
          drawTonomous();
        }
        else if (blue4.pressing()){
          aselection = 4;
          drawTonomous();
        }
      }
      if (none.pressing()){
        aselection = 0;
        drawTonomous();
      }
    }


    if(aselection >-1){  
      switch(aselection){
        case 0: Brain.Screen.printAt(200, 200, "none");
          break;
        case 1: Brain.Screen.printAt(200, 200, "Red Run");
          break;
        case 2: Brain.Screen.printAt(200, 200, "Blue Run");
         break;
        case 3: Brain.Screen.printAt(200, 200, "Red 4");
         break;
        case 4: Brain.Screen.printAt(200, 200, "Blue 4");
          break;
      }
      if(confirm.pressing()){
        unconfirmed = false;
      }
    }
    this_thread::sleep_for(50);
  }
  Brain.Screen.clearScreen();
  
  

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}
