/*
  Display.h - Library for button handling.
  Created by Piotr Duch, December 30, 2016.
*/

#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"

class Buttons
{
  public:
    Buttons();
    void init();
    bool buttonClicked( int );
    
  private:

    static const int numberOfButtons = 16;

    static const int latchPin = 40;
    static const int dataPin = 42;
    static const int clockPin = 41;

    static void refresh();
    static bool buttons[numberOfButtons];
    static int buttonPins[numberOfButtons];
    static int previousState1, previousState2;
    static volatile int buttonOldStates[numberOfButtons];
    static byte shiftIn(int myDataPin, int myClockPin); 
    
};

#endif
