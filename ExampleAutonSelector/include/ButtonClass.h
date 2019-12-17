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


void insertText(std::string text, int width, int height, int xi, int yi, int Ftype, int Fsize, int penHue, std::string penHex){
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

  int x = xi - (vexDisplayStringWidthGet(string)/2);
  int y = yi + (vexDisplayStringHeightGet(string)/4);
  if(penHue != -1){
    Brain.Screen.setPenColor(penHue);
  }
  else{
    Brain.Screen.setPenColor(penHex.c_str());
  }
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
  std::string hex = "#353535";
  std::string text = "";
  int font = 0;
  int fontsize = 20;
  int penHue = -1;
  std::string penHex = "#FFFFFF";
  std::string outlinehex = "white";
  int outlinehue = -1;
  int thickness = 2;

  int xMin;
  int xMax;
  int yMin;
  int yMax;
  
  //_________________________________________________________________________
  //_________________________________________________________________________
  //constructors
  //_________________________________________________________________________
  //_________________________________________________________________________

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

  lcdButton(int x, int y, int wide, int tall, std::string chars, std::string colorHex, std::string outHex, int outThickness){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    width = wide;
    height = tall;
    text = chars;
    hex = colorHex;
    outlinehex = outHex;
    thickness = outThickness;
    draw();
  }

  lcdButton(int x, int y, int wide, int tall, std::string chars, int colorHue, std::string outHex, int outThickness){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    width = wide;
    height = tall;
    text = chars;
    hue = colorHue;
    hex = "using hue";
    outlinehex = outHex;
    thickness = outThickness;
    draw();
  }

  lcdButton(int x, int y, int wide, int tall, std::string chars, std::string colorHex, int outHue, int outThickness){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    width = wide;
    height = tall;
    text = chars;
    hex = colorHex;
    outlinehue = outHue;
    outlinehex = "using hue";
    thickness = outThickness;
    draw();
  }

  lcdButton(int x, int y, int wide, int tall, std::string chars, int colorHue, int outHue, int outThickness){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    width = wide;
    height = tall;
    text = chars;
    hue = colorHue;
    hex = "using hue";
    outlinehue = outHue;
    outlinehex = "using hue";
    thickness = outThickness;
    draw();
  }

//end intended helper view --------------------------------

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

  lcdButton(int x, int y, int wide, int tall, int colorHue){
    buttonId = nextId;
    nextId++;
    xPos = x;
    yPos = y;
    width = wide;
    height = tall;
    hue = colorHue;
    hex = "using hue";
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
    hex = "using hue";
    draw();
  }
  

  //_________________________________________________________________________
  //_________________________________________________________________________

  //Functions
  //_________________________________________________________________________
  //_________________________________________________________________________

  void setPenColor(std::string input){
    penHex = input;
    penHue = -1;
  }

  void setPenColor(int input){
    penHue = input;
    penHex = "using hue";
  }

  void setFont(int chosen){
    font = chosen;
  }

  void setFontSize(int chosen){
    fontsize = chosen;
  }

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
    width = wide;
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

  void setOutlineThickness(int thick){
    thickness = thick;
    draw();
  }

  void setOutlineColor(std::string colored){
    outlinehex = colored;
    outlinehue = -1;
  }

  void setOutlineColor(int colored){
    outlinehue = colored;
    outlinehex = "using hue";
  }

  void draw(){
    xMin = xPos - (width/2);
    xMax = xPos + (width/2);
    yMin = yPos - (height/2);
    yMax = yPos + (height/2);
    if(outlinehue != -1){
      Brain.Screen.setPenColor(outlinehue);
    }
    else{
      Brain.Screen.setPenColor(outlinehex.c_str());
    }

    Brain.Screen.setPenWidth(thickness);

    if(hue != -1){ //determine if using hue int or hex string
      Brain.Screen.drawRectangle(xPos - (width/2), yPos - (height/2), width, height, hue);
    }
    else{ //using hex
      const char *string = hex.c_str();
      Brain.Screen.drawRectangle(xPos - (width/2), yPos - (height/2), width, height, string);
    }

    insertText(text, width, height, xPos, yPos, font, fontsize, penHue, penHex);
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