/*
  Display.h - Library for displaying digits on 
	      seven-segment disply.
  Created by Piotr Duch, December 30, 2016.
*/

#include "Arduino.h"
#include <DueTimer.h>
#include "Buttons.h"

Buttons::Buttons()
{
}

bool Buttons::buttons[numberOfButtons] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
int Buttons::previousState1 = 255;

int Buttons::previousState2 = 255;

void Buttons::init()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, INPUT);

  Timer.getAvailable().attachInterrupt(refresh).start(25000); 
}

void Buttons::refresh()
{
  digitalWrite(latchPin,1);
  //set it to 1 to collect parallel data, wait
  //delayMicroseconds(20);
  //set it to 0 to transmit data serially  
  digitalWrite(latchPin,0);

  //while the shift register is in serial mode
  //collect each shift register into a byte
  //the register attached to the chip comes in first
  byte switchVar1 = shiftIn(dataPin, clockPin);
  byte switchVar2 = shiftIn(dataPin, clockPin);

  for ( int i = 0; i < 8; ++i )
  {
    int previous = previousState1 & (1 << i);
    int current = switchVar1 & (1 << i);

    if (current == 0 && previous != current)
      buttons[ i ] = true;
    else
      buttons[ i ] = false;
  }

  for ( int i = 0; i < 8; ++i )
  {
    int previous = previousState2 & (1 << i);
    int current = switchVar2 & (1 << i);

    if (current == 0 && previous != current)
      buttons[ i + 8] = true;
    else
      buttons[ i + 8 ] = false;
  }
  
  previousState1 = switchVar1;
  previousState2 = switchVar2;
    
}

bool Buttons::buttonClicked( int id )
{
  if ( id >= numberOfButtons )
    return false;
  
  return buttons[ id ];
}

byte Buttons::shiftIn(int myDataPin, int myClockPin) 
{
  int i;
  int temp = 0;
  int pinState;
  byte myDataIn = 0;

  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, INPUT);

//we will be holding the clock pin high 8 times (0,..,7) at the
//end of each time through the for loop

//at the begining of each loop when we set the clock low, it will
//be doing the necessary low to high drop to cause the shift
//register's DataPin to change state based on the value
//of the next bit in its serial information flow.
//The register transmits the information about the pins from pin 7 to pin 0
//so that is why our function counts down
  for (i=7; i>=0; i--)
  {
    digitalWrite(myClockPin, 0);
    delayMicroseconds(2);
    temp = digitalRead(myDataPin);
    if (temp) {
      pinState = 1;
      //set the bit to 0 no matter what
      myDataIn = myDataIn | (1 << i);
    }
    else {
      //turn it off -- only necessary for debuging
     //print statement since myDataIn starts as 0
      pinState = 0;
    }

    //Debuging print statements
    //Serial.print(pinState);
    //Serial.print("     ");
    //Serial.println (dataIn, BIN);

    digitalWrite(myClockPin, 1);

  }
  //debuging print statements whitespace
  //Serial.println();
  //Serial.println(myDataIn, BIN);
  return myDataIn;
}
