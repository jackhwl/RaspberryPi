#ifndef MY_HELPER_H
#define MY_HELPER_H

#include <Arduino.h>
#include <LiquidCrystal.h>

class Helper
{

private:
    byte pin;
    LiquidCrystal lcd;

public:
    Helper();
    void init();
    void displayTimer(unsigned long previousMillis);
    //void clearLCDLine(LiquidCrystal *lcd, int line);
};

#endif