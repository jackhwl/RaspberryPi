#include "Helper.h"

Helper::Helper(byte pin)
{
    // Use 'this->' to make the difference between the
    // 'pin' attribute of the class and the
    // local variable 'pin' created from the parameter.
    this->pin = pin;
    init();
}

void Helper::init()
{
    // lcd.begin(16, 2);

    // pinMode(pin, OUTPUT);
}

void setTimeBuffer(char *buffer, unsigned long seconds, bool withHour)
{
    uint8_t hours, minutes;
    uint16_t remainSeconds;
    hours = seconds / 3600;
    remainSeconds = seconds % 3600;
    minutes = remainSeconds / 60;
    if (withHour)
        sprintf(buffer, "%02u:%02u:%02u", hours, minutes, seconds % 60);
    else
        sprintf(buffer, "%02u:%02u", minutes, seconds % 60);
}

// void setTimeLineBuffer(char *buffer, unsigned long previousMillis)
// {
//     uint8_t hours, minutes, seconds, hours2, minutes2, seconds2;
//     uint16_t remainSeconds, remainSeconds2;
//     unsigned long currentMillis = millis();
//     seconds = (currentMillis - previousMillis) / 1000;
//     hours = seconds / 3600;
//     remainSeconds = seconds % 3600;
//     minutes = remainSeconds / 60;

//     seconds2 = currentMillis / 1000;
//     hours2 = seconds2 / 3600;
//     remainSeconds2 = seconds2 % 3600;
//     minutes2 = remainSeconds2 / 60;

//     sprintf(buffer, "%02u:%02u   %02u:%02u:%02u", minutes, seconds % 60, hours2, minutes2, seconds2 % 60);
// }
// void Helper::init()
// {
//     const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//     LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// }

void Helper::displayTimer(LiquidCrystal *lcd, unsigned long previousMillis)
{
    char buffer[8];
    unsigned long currentMillis = millis();

    lcd->setCursor(0, 0);
    lcd->print("Hello viGlobal!");

    lcd->setCursor(0, 1);
    // print the number of seconds since rollover:
    setTimeBuffer(buffer, (currentMillis - previousMillis) / 1000, false);
    lcd->write(buffer);

    lcd->setCursor(8, 1);
    setTimeBuffer(buffer, currentMillis / 1000, true);
    lcd->write(buffer);
}

void Helper::clearLCDLine(LiquidCrystal *lcd, int line)
{
    for (int n = 0; n < 16; n++)
    { // 20 indicates symbols in line. For 2x16 LCD write - 16
        lcd->setCursor(n, line);
        lcd->print(" ");
    }
}