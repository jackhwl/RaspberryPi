/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

#include "Helper.h"
#include "Music.h"

#define BUZZER_PIN 8

Helper helper;
Music music(BUZZER_PIN);

const int resetTime = 3600;
unsigned long previousMillis = 0, previousMillis2 = 0;

void setup()
{
}

void loop()
{
  helper.displayTimer(previousMillis);

  unsigned long currentMillis = millis();

  if ((unsigned long)(currentMillis - previousMillis) / 1000 >= resetTime)
  {
    helper.display(1, " It's Tea Time! ");
    previousMillis = currentMillis;
    previousMillis2 = previousMillis;
    music.playMusic(2);
    helper.clearLCDLine(1);
  }

  if ((unsigned long)(currentMillis - previousMillis2) / 1000 >= resetTime / 2)
  {
    helper.display(1, "It's Coffee Time");
    previousMillis2 = currentMillis;
    music.playMusic(1);
    helper.clearLCDLine(1);
  }
}
