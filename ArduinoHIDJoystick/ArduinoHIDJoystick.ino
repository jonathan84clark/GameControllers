/********************************************************************
* ARDUINO HID JOYSTICK
* DESC: The arduino HID joystick is an application that supports a device similar
* to an N64 controller.
* Author: Jonathan L Clark
* Date: 5/11/2022
********************************************************************/
#include <Joystick.h>

#define HAT_UP    5
#define HAT_LEFT  8
#define HAT_RIGHT 6
#define HAT_DN    7

#define C_UP A0
#define C_LEFT 15
#define C_RIGHT 3
#define C_DN 14

#define A_BTN 10
#define B_BTN 16

#define JOYSTICK_BTN 9
#define Z_BUTTON 2

#define L_BUTTON 4
#define R_BUTTON A1

#define JOYSTICK_X A3
#define JOYSTICK_Y A2

// Create the Joystick
Joystick_ Joystick;

int toggle = 0;
// Constant that maps the physical pin to the joystick button.
const int pinToButtonMap = 9;

void setup() {
  // Initialize Button Pins
  pinMode(pinToButtonMap, INPUT_PULLUP);

  // Initialize Joystick Library
  //Joystick.begin();
  //Joystick.setXAxisRange(-127, 127);
}

// Last state of the button
int lastButtonState = 0;

void loop()
{

   /*
  // Read pin values
  if (toggle == 0)
  {
     Joystick.setButton(1, 1);
     Joystick.setXAxis(50);
     toggle = 1;
  }
  else
  {
     Joystick.setButton(1, 0);
     Joystick.setXAxis(0);
     toggle = 0;
  }
  */

  delay(500);
}
