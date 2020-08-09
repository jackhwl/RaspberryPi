#ifndef MY_HELPER_H
#define MY_HELPER_H

#include <Arduino.h>
#include <LiquidCrystal.h>

class Helper
{
private:
    LiquidCrystal lcd;

public:
    Helper();
    void init();
    void displayTimer(unsigned long previousMillis);
    void display(byte line, String str);
    void clearLCDLine(byte line);
};

#endif