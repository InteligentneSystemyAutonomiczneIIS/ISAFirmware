#include <ISADefinitions.h>
#include <ISALiquidCrystal.h>

ISALiquidCrystal lcd;

void setup(){
	//LCD
	lcd.begin();
	lcd.print("ISA IIS!");

	for(int i = 0; i < 8; i++)
		pinMode(LEDS[i], OUTPUT);


}

void loop(){
	//LED
	for(int i = 0; i < 8; i++)
		digitalWrite(LEDS[i], HIGH);

  delay(100);

  for(int i = 0; i < 8; i++)
		digitalWrite(LEDS[i], LOW);

  delay(100);
	

}
