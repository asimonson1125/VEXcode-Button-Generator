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


void insertText(std::string text, int width, int height, int xi, int yi){
  const char *string = text.c_str();
  int x = xi - (vexDisplayStringWidthGet(string)/2);
  int y = yi + (vexDisplayStringHeightGet(string)/4);
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
  int hue = -1;
  std::string hex = "#707070";
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

  lcdButton(int x , int y, int tall){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    width = tall;
    height = tall;
    draw();
  }

  lcdButton(int x, int y, std::string chars){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    text = chars;
    draw();
  }

  lcdButton(int x, int y, int tall, std::string chars){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    width = tall;
    height = tall;
    text = chars;
    draw();
  }

  /*lcdButton(int x, int y, int wide, int tall, std::string chars){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    width = wide;
    height = tall;
    text = chars;
    draw();
  }*/

  //string assumes color, not text

  lcdButton(int x, int y, int wide, int tall, std::string colorHex){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    width = wide;
    height = tall;
    hex = colorHex;
    draw();

  }

  lcdButton(int x, int y, int wide, int tall, std::string chars, std::string colorHex){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    width = wide;
    height = tall;
    text = chars;
    hex = colorHex;
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

  void setSize(int tall, int width){
    height = tall;
    width = width;
    draw();
  }

  void setColor(int colorHue){
    hex = "using hue";
    hue = colorHue;
    draw();
  }

  void setColor(std::string colorHex){
    hue = -1;
    hex = colorHex;
    draw();
  }

  void draw(){
    xMin = xPos - (width/2);
    xMax = xPos + (width/2);
    yMin = yPos - (height/2);
    yMax = yPos + (height/2);
    if(hue != -1){ //determine if using hue int or hex string
      Brain.Screen.drawRectangle(xPos - (width/2), yPos - (height/2), width, height, hue);
    }
    else{ //using hex
      const char *string = hex.c_str();
      Brain.Screen.drawRectangle(xPos - (width/2), yPos - (height/2), width, height, string);
    }
    insertText(text, width, height, xPos, yPos);
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
