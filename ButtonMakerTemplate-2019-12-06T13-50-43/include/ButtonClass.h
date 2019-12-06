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
  int x;
  int y;
  const char *string = text.c_str();
  x = xi - (vexDisplayStringWidthGet(string)/2);
  y = yi + (vexDisplayStringHeightGet(string)/4);
  Brain.Screen.printAt(x, y, string);
}



int nextId = 0;

class lcdButton {
  public:
  int xPos;
  int yPos;
  int width;
  int height;
  int buttonId;
  std::string text;
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
    xPos = 20;
    yPos = 20;
    width = 20;
    height = 20;
    buttonId = nextId;
    nextId++;
    text = ("BUTTON!!");
    Brain.Screen.drawRectangle(xPos - (width/2), yPos - (height/2), width, height);
    insertText(text, width, height, xPos, yPos);
    xMin = xPos - (width/2);
    xMax = xPos + (width/2);
    yMin = yPos - (height/2);
    yMax = yPos + (height/2);
  }

  lcdButton(int x, int y){
    xPos = x;
    yPos = y;
    width = 20;
    height = 20;
    text = ("BUTTON!!");
    Brain.Screen.drawRectangle(xPos - (width/2), yPos - (height/2), width, height);
    insertText(text, width, height, xPos, yPos);
    xMin = xPos - (width/2);
    xMax = xPos + (width/2);
    yMin = yPos - (height/2);
    yMax = yPos + (height/2);
  }

  lcdButton(int x , int y, int tall){
    xPos = x;
    yPos = y;
    width = tall;
    height = tall;
    text = ("BUTTON!!");
    Brain.Screen.drawRectangle(xPos - (width/2), yPos - (height/2), width, height);
    insertText(text, width, height, xPos, yPos);
    xMin = xPos - (width/2);
    xMax = xPos + (width/2);
    yMin = yPos - (height/2);
    yMax = yPos + (height/2);
  }

  lcdButton(int x, int y, std::string chars){
    xPos = x;
    yPos = y;
    width = 20;
    height = 20;
    text = chars;
    Brain.Screen.drawRectangle(xPos - (width/2), yPos - (height/2), width, height);
    insertText(text, width, height, xPos, yPos);
    xMin = xPos - (width/2);
    xMax = xPos + (width/2);
    yMin = yPos - (height/2);
    yMax = yPos + (height/2);
  }

  lcdButton(int x, int y, int tall, std::string chars){
    xPos = x;
    yPos = y;
    width = tall;
    height = tall;
    text = chars;
    Brain.Screen.drawRectangle(xPos - (width/2), yPos - (height/2), width, height);
    insertText(text, width, height, xPos, yPos);
    xMin = xPos - (width/2);
    xMax = xPos + (width/2);
    yMin = yPos - (height/2);
    yMax = yPos + (height/2);
  }

  lcdButton(int x, int y, int tall, int wide, std::string chars){
    xPos = x;
    yPos = y;
    width = wide;
    height = tall;
    text = chars;
    Brain.Screen.drawRectangle(xPos - (width/2), yPos - (height/2), width, height);
    insertText(text, width, height, xPos, yPos);
    xMin = xPos - (width/2);
    xMax = xPos + (width/2);
    yMin = yPos - (height/2);
    yMax = yPos + (height/2);
  }

  //_________________________________________________________________________
  //_________________________________________________________________________

  //Functions
  //_________________________________________________________________________
  //_________________________________________________________________________

  void moveTo(int x, int y){
    this->xPos = x;
    this->yPos = y;
  }

  void setText(std::string chars){
    this->text = chars;
  }

  void setSize(int tall, int width){
    this->height = tall;
    this->width = width;
  }

  bool pressing(){
    if(Brain.Screen.pressing() && Brain.Screen.xPosition() < xMax && Brain.Screen.xPosition() > xMin && Brain.Screen.yPosition() < yMax && Brain.Screen.yPosition() > yMin){
      return true;
    }
    else{
      return false;
    }
  }
};