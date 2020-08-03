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
#include <LiquidCrystal.h>
#include "music.h"

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int resetTime = 3600;
unsigned long previousMillis = 0;

// change this to whichever pin you want to use
int buzzer = 8;

#define ELEMENTSIZE(x) (sizeof(x) / sizeof(x[0]))
char buffer[8];

void setTimeBuffer(char *buffer, unsigned long seconds, bool withHour)
{
  uint8_t hours, minutes;
  minutes = seconds / 60;
  hours = minutes / 60;
  if (withHour)
    sprintf(buffer, "%02u:%02u:%02u", hours, minutes % 60, seconds % 60);
  else
    sprintf(buffer, "%02u:%02u", minutes, seconds % 60);
}

void clearLCDLine(int line)
{
  for (int n = 0; n < 16; n++)
  { // 20 indicates symbols in line. For 2x16 LCD write - 16
    lcd.setCursor(n, line);
    lcd.print(" ");
  }
}

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello viGlobal!");

  pinMode(buzzer, OUTPUT);
}

void loop()
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  unsigned long currentMillis = millis();
  // print the number of seconds since rollover:
  setTimeBuffer(buffer, (currentMillis - previousMillis) / 1000, false);
  lcd.write(buffer);
  //lcd.print((currentMillis - previousMillis)/1000);
  lcd.setCursor(8, 1);

  setTimeBuffer(buffer, currentMillis / 1000, true);
  lcd.write(buffer);

  if ((unsigned long)(currentMillis - previousMillis) / 1000 >= resetTime)
  {
    previousMillis = currentMillis;
    lcd.setCursor(0, 1);
    lcd.print(" It's Tea Time! ");
    playTheTone(melody_Nokia, ELEMENTSIZE(melody_Nokia), 180);
    //playTheTone(melody_HappyBirthDay, ELEMENTSIZE(melody_HappyBirthDay), 140);
    clearLCDLine(1);
  }
}
