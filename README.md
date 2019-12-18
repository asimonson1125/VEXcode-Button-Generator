# VEXcode Button Generator + template for the VEX V5 brain

The VEXcode Button Generator consists of a class designed to automate the process of adding a button to the V5 Brain screen in VEXcode.  It is meant to help new users get started with the V5 system, not as a tool for advanced porgrammers.  It can, however, be a handy tool for quickly making autonomous selectors or control the robot from the brain itself.
With it you can create a button with automatically centered text and press detection in one line and change button attributes on the fly.

___

**To add to currently existing project:** download the ButtonClass.h file itself and add ```#include "ButtonClass.h"``` to files that it will be used in.

**To download the template:** download the ButtonMakerTemplate folder and open the contained .v5code file

___


### Button attributes:
 - centered position in coordinate plane
 - button color
 - button dimensions
 - button color in hue (int) or hex (string, ie "#FFFFFF").
 - outline color in hue (int) or hex (string, ie "#FFFFFF").
 - outline thickness
 - text inside button
 - text font
 - text size
 - text color
 - ~~use custom images from SD card~~ *decided this capability is beyond the scope of the project, which is intended to be a basic button generator for newer teams.  Sorry to anyone who was looking forward to that.*


### How to Use:
To create a button all you have to do is call one of the following constructors:

```
lcdButton buttonName(int x, int y, int width, int height, string text, string color in Hex OR int color in Hue, string outline in Hex OR int outline in Hue, int outline Thickness);

lcdButton buttonName(int x, int y, int width, int height, string color in Hex);

lcdButton buttonName(int x, int y, int width, int height, string text, string color in Hex);
```

___

**Example:**

This line draws button 'redButton' with center at (120,22), width of 230px, height of 35px, and text that says `RED`.  The button itself is grey and it has a red outline with thickness of 2px.

`lcdButton redButton(120, 22, 230, 35, "RED", "#252525","#FF2525",2);`


___
**Functions**

Functions are how you can change button properties, redraw buttons, and check if the button is pressing.
More often than not you'll only need a few of these or any given project, but all of them are available.

`buttonName.pressing()` returns true if the button is currently being pressed.

`buttonName.draw()` redraws the visual of the button.


`buttonName.setPenColor(string or int)` sets the text color to input hue (if int) or hex (if string).

`buttonName.setFont(int)` sets the font to input, 0 = mono, 1 = prop, 2 = cjk.

`buttonName.setFontSize(int)` sets the font size to input (ie for mono30, input = 30).

`buttonName.moveTo(int x, int y)` moves the button to the x/y coordinates input (reminder x and y are centered on the button).

`buttonName.setText(string)` sets the text inside of the button to the input.

`buttonName.setSize(int width, int height)` sets how wide and how tall the button is.

`buttonName.setColor(int or string)` sets the color of the button to input.  int sets hue, string sets hex.

`buttonName.setOutlineThickness(int)` sets the thickness in pixels of the button outline.

`buttonName.setOutlineColor(int or string)` sets the color of the outline to the input.  int sets hue, string sets hex.

`insertText(string text, int button width, int button height, int xCenter, int yCenter, int Font type, int Font size, int text hue, string text hex)` a background function used to center the text inside of a button.  Can be used to center text to a specific point if you choose to use it.

If you want to use hue it doesn't matter what you set hex to.

If you want to use hex, set hue to -1.

Font types are 0 for mono, 1 for prop, and 2 for cjk.

___

**Example:**

Using the example previously, let's move the button  and change the text color to a shade of red.
```
redButton.moveTo(200,150); //moves the button to (200,150) on coordinate plane
redButton.setPenColor("#FF2525"); //sets the color to hex #FF2525
Brain.Screen.clearScreen("black"); //clear the screen of any duplicate drawings (see the program limitation listed below)
redButton.draw(); //draw the button with its new conditions
```

___
**Any non-specified variables default to the following:**

x = 100

y = 100

width = 20

height = 20

hue = -1 (hue is ideally not used, instead the default is to use hex.)

hex = "#353535"

text = ""

font = 0

font size = 20

text hue = -1 (hue is ideally not used, instead the default is to use hex.)

text hex = "#FFFFFF"

outline hex = "white"

outline hue = -1 (hue is ideally not used, instead the default is to use hex.)

outline thickness = 2

___
### Notable Limitation:
Cannot delete previously drawn buttons or automatically redraw a button.  This is due to the screen's inability to identify objects.  Any deletion of objects would hae to clear the entire screen.
The new button will automatically be drawn and the button detection will move to the new coordinates, but the previous button will still be drawn on the screen.
