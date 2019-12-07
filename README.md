# VEXcode Button Generator + template for the VEX V5 brain

**this is a WORK IN PROGRESS, expect the unexpected**

The VEXcode Button Generator consists of a class designed to automate the process of adding a button to the V5 Brain screen in VEXcode.  It is meant to help new users get started with the V5 system, not as a tool for advanced porgrammers.  It can, however, be a handy tool for quickly making autonomous selectors or control the robot from the brain itself.

___

### Capabilities:

In one line you can create a button with automatically centered text and press detection

Additionally, change button position, size, color, and text after initial creation.

WIP:
 - use custom images from SD card
 - redraw button automatically after parameter change
 - font and font size changes

### Limitations:
Press detection is limited to rectangular shapes, it cannot accurately detect presses for other shapes.

Cannot delete previously drawn buttons or automatically redraw a button - to display changes in a button the screen must be cleared and then be redrawn with button.draw(); while the press detection changes immediately after being updated.
