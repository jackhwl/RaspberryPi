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

// include the library code:
// #include <LiquidCrystal.h>
#include "music.h"
#include "Helper.h"

#define BUZZER_PIN 8
Helper helper;

// change this to whichever pin you want to use
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int resetTime = 16;
unsigned long previousMillis = 0, previousMillis2 = 0;

#define ELEMENTSIZE(x) (sizeof(x) / sizeof(x[0]))

void setup()
{
  // set up the LCD's number of columns and rows:
  //lcd.begin(16, 2);

  pinMode(BUZZER_PIN, OUTPUT);
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
    // lcd.setCursor(0, 1);
    // lcd.print(" It's Tea Time! ");
    // playTheTone(melody_HappyBirthDay, ELEMENTSIZE(melody_HappyBirthDay), 140, buzzer);
    delay(1000);
    helper.clearLCDLine(1);
  }

  if ((unsigned long)(currentMillis - previousMillis2) / 1000 >= resetTime / 2)
  {
    helper.display(1, "It's Coffee Time");
    previousMillis2 = currentMillis;
    //   lcd.setCursor(0, 1);
    //   previousMillis2 = currentMillis;
    //   lcd.print("It's Coffee Time");
    //   playTheTone(melody_Nokia, ELEMENTSIZE(melody_Nokia), 180, buzzer);
    delay(1000);
    helper.clearLCDLine(1);
  }
}
