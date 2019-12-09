/*
 *_________________________________________________________________________
 *
 *
 * LCD Button Maker for VEX Robotics V5 brain
 *
 * By: Andrew Simonson from Team 96807B
 *
 *_________________________________________________________________________
*/

#include "vex.h"


void insertText(std::string text, int width, int height, int xi, int yi, int Ftype, int Fsize){
  int x;
  int y;
  const char *string = text.c_str();
  switch(Ftype){
    case 0: switch(Fsize){
      case 12: Brain.Screen.setFont(mono12);
        break;
      case 15: Brain.Screen.setFont(mono15);
        break;
      case 20: Brain.Screen.setFont(mono20);
        break;
      case 30: Brain.Screen.setFont(mono30);
        break;
      case 40: Brain.Screen.setFont(mono40);
        break;
    };
    break;

    case 1: switch(Fsize){
      case 20: Brain.Screen.setFont(prop20);
        break;
      case 30: Brain.Screen.setFont(prop30);
        break;
      case 40: Brain.Screen.setFont(prop40);
        break;
      case 60: Brain.Screen.setFont(prop60);
        break;
    };
    break;

    case 2: switch(Fsize){
      //case 15: Brain.Screen.setFont(cjk16);
      break;
    };
    break;
  }
//WHAT IS MONOXL I DID NOT SIGN UP FOR THIS

  x = xi - (vexDisplayStringWidthGet(string)/2);
  y = yi + (vexDisplayStringHeightGet(string)/4);
  Brain.Screen.printAt(x, y, string);
}



int nextId = 0;

class lcdButton {
  public:
  int buttonId;

  int xPos = 100;
  int yPos = 100;
  int width = 20;
  int height = 20;
  int hue = 0;
  int font = 0;
  int fontsize = 10;
  std::string text = "";

  int xMin;
  int xMax;
  int yMin;
  int yMax;
  
  //_________________________________________________________________________
  //_________________________________________________________________________
  //constructors
  //_________________________________________________________________________
  //_________________________________________________________________________

  lcdButton(){
    buttonId = nextId;
    nextId++;
    draw();
  }

  lcdButton(int x, int y){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    draw();
  }

  lcdButton(int x, int y, int wide, int tall, std::string chars){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    width = wide;
    height = tall;
    text = chars;
    draw();
  }

  lcdButton(int x, int y, int wide, int tall, int colorHue){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    width = wide;
    height = tall;
    hue = colorHue;
    draw();

  }

  lcdButton(int x, int y, int wide, int tall, std::string chars, int colorHue){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    width = wide;
    height = tall;
    text = chars;
    hue = colorHue;
    draw();
  }
  
  //hide the ones below by the master constructor, damn it thicc.
  lcdButton(int x, int y, std::string chars){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    text = chars;
    draw();
  }

  lcdButton(int x, int y, int wide, std::string chars){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    width = wide;
    height = wide;
    text = chars;
    draw();
  }
  
  lcdButton(int x , int y, int wide){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    width = wide;
    height = wide;
    draw();
  }
  

  //_________________________________________________________________________
  //_________________________________________________________________________

  //Functions
  //_________________________________________________________________________
  //_________________________________________________________________________

  void moveTo(int x, int y){
    xPos = x;
    yPos = y;
    draw();
  }

  void setText(std::string chars){
    text = chars;
    draw();
  }

  void setSize(int wide, int tall){
    height = tall;
    width = width;
    draw();
  }

  void setColor(int colorHue){
    hue = colorHue;
    draw();
  }

  void setFont(int chosen){
    font = chosen;
  }

  void setFontSize(int chosen){
    fontsize = chosen;
  }

  void draw(){
    xMin = xPos - (width/2);
    xMax = xPos + (width/2);
    yMin = yPos - (height/2);
    yMax = yPos + (height/2);
    Brain.Screen.drawRectangle(xPos - (width/2), yPos - (height/2), width, height, hue);
    insertText(text, width, height, xPos, yPos, font, fontsize);
  }

//________________________________________________________________________________________________

  bool pressing(){
    if(Brain.Screen.pressing() && Brain.Screen.xPosition() < xMax && Brain.Screen.xPosition() > xMin && Brain.Screen.yPosition() < yMax && Brain.Screen.yPosition() > yMin){
      return true;
    }
    else{
      return false;
    }
  }
};
