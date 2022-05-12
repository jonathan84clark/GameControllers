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
int lastButtonStates[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int buttonPins[] = {A_BTN, B_BTN, JOYSTICK_BTN, Z_BUTTON, L_BUTTON, R_BUTTON, C_UP, C_LEFT, C_RIGHT, C_DN};
void setup() {
  Serial.begin(9600);
  // Initialize Button Pins
  pinMode(HAT_UP, INPUT_PULLUP);
  pinMode(HAT_LEFT, INPUT_PULLUP);
  pinMode(HAT_RIGHT, INPUT_PULLUP);
  pinMode(HAT_DN, INPUT_PULLUP);

  pinMode(C_UP, INPUT_PULLUP);
  pinMode(C_LEFT, INPUT_PULLUP);
  pinMode(C_RIGHT, INPUT_PULLUP);
  pinMode(C_DN, INPUT_PULLUP);

  pinMode(A_BTN, INPUT_PULLUP);
  pinMode(B_BTN, INPUT_PULLUP);
  pinMode(JOYSTICK_BTN, INPUT_PULLUP);
  pinMode(Z_BUTTON, INPUT_PULLUP);

  pinMode(L_BUTTON, INPUT_PULLUP);
  pinMode(R_BUTTON, INPUT_PULLUP);

  pinMode(JOYSTICK_X, INPUT);
  pinMode(JOYSTICK_Y, INPUT);

  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(-127, 127);
  Joystick.setYAxisRange(-127, 127);
}

// Last state of the button
int lastButtonState = 0;

int CalculateJoystickValue(int pin)
{
   int output = 0;
   float joystickValue = (float)analogRead(pin) / 1024.0;
   joystickValue = (joystickValue * 254.0f) - 127.0;
   output = (int)joystickValue;

   return output;
}
void loop()
{

  // Joysticks
  int joystickYValue = CalculateJoystickValue(JOYSTICK_Y);
  joystickYValue *= -1;
  Joystick.setYAxis(joystickYValue);
  
  int joystickXValue = CalculateJoystickValue(JOYSTICK_X);
  Joystick.setXAxis(joystickXValue);

  // Hat Switches
  if (!digitalRead(HAT_UP))
  {
     Joystick.setHatSwitch(0, 0);
  }
  else if (!digitalRead(HAT_RIGHT))
  {
     Joystick.setHatSwitch(0, 90);
  }
  else if (!digitalRead(HAT_DN))
  {
     Joystick.setHatSwitch(0, 180);
  }
  else if (!digitalRead(HAT_LEFT))
  {
     Joystick.setHatSwitch(0, 270);
  }
  else
  {
     Joystick.setHatSwitch(0, -1);
  }

  // Iterate through all buttons
  for (int i = 0; i < 10; i++)
  {
      int buttonState = digitalRead(buttonPins[i]);
      if (buttonState == 1)
      {
         buttonState = 0;
      }
      else
      {
         buttonState = 1;
      }
      if (buttonState != lastButtonStates[i])
      {
          Joystick.setButton(i, buttonState);
          lastButtonStates[i] = buttonState;
      }
  }

  delay(50);
}
