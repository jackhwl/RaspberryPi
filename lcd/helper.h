#ifndef MY_HELPER_H
#define MY_HELPER_H

#include <Arduino.h>
#include <LiquidCrystal.h>

class Helper
{

private:
    byte pin;

public:
    Helper(byte pin);
    void init();
    //void setTimeBuffer(char *buffer, unsigned long seconds, bool withHour);
    //void displayTimer();
    void displayTimer(LiquidCrystal *lcd, unsigned long previousMillis);
    void clearLCDLine(LiquidCrystal *lcd, int line);
};

#endif