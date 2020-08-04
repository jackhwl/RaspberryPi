#include <LiquidCrystal.h>

void setTimeBuffer(char *buffer, unsigned long seconds, bool withHour)
{
    uint8_t hours, minutes, remainSeconds;
    hours = seconds / 3600;
    remainSeconds = seconds % 3600;
    minutes = remainSeconds / 60;
    if (withHour)
        sprintf(buffer, "%02u:%02u:%02u", hours, minutes, seconds % 60);
    else
        sprintf(buffer, "%02u:%02u", minutes, seconds % 60);
}
void setTimeLineBuffer(char *buffer, unsigned long previousMillis)
{
    uint8_t hours, minutes, seconds, remainSeconds, hours2, minutes2, seconds2, remainSeconds2;
    unsigned long currentMillis = millis();
    seconds = (currentMillis - previousMillis) / 1000;
    hours = seconds / 3600;
    remainSeconds = seconds % 3600;
    minutes = remainSeconds / 60;

    seconds2 = currentMillis / 1000;
    hours2 = seconds2 / 3600;
    remainSeconds2 = seconds2 % 3600;
    minutes2 = remainSeconds2 / 60;

    sprintf(buffer, "%02u:%02u   %02u:%02u:%02u", minutes, seconds % 60, hours2, minutes2, seconds2 % 60);
}

void displayTimer(LiquidCrystal *lcd, unsigned long previousMillis)
{
    char buffer[16];

    lcd->setCursor(0, 0);
    //lcd->print(millis());

    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    int hours, minutes, seconds, remainSeconds, hours2, minutes2, seconds2, remainSeconds2;
    unsigned long currentMillis = millis();
    seconds = (currentMillis - previousMillis) / 1000;
    hours = seconds / 3600;
    remainSeconds = seconds % 3600;
    minutes = remainSeconds / 60;

    seconds2 = currentMillis / 1000;
    hours2 = seconds2 / 3600;
    remainSeconds2 = seconds2 % 3600;
    minutes2 = remainSeconds2 / 60;
    lcd->print(millis() / 1000);
    lcd->print(" ");
    lcd->print(minutes);
    lcd->print(",");
    lcd->print(seconds % 60);
    lcd->print(" ");
    //lcd->print(hours2);
    //lcd->print(",");
    lcd->print(minutes2);
    lcd->print(",");
    lcd->print(seconds2 % 60);
    lcd->setCursor(0, 1);
    sprintf(buffer, "%02u:%02u   %02u:%02u:%02u", minutes, seconds % 60, hours2, minutes2, seconds2 % 60);
    lcd->write(buffer);

    //setTimeLineBuffer(buffer, previousMillis);
    //lcd->write(buffer);

    // unsigned long currentMillis = millis();
    // // print the number of seconds since rollover:
    // setTimeBuffer(buffer, (currentMillis - previousMillis) / 1000, false);
    // lcd->write(buffer);

    // //lcd.print((currentMillis - previousMillis)/1000);
    // lcd->setCursor(8, 1);

    // setTimeBuffer(bufferh, currentMillis / 1000, true);
    // lcd->write(bufferh);
}

void clearLCDLine(LiquidCrystal *lcd, int line)
{
    for (int n = 0; n < 16; n++)
    { // 20 indicates symbols in line. For 2x16 LCD write - 16
        lcd->setCursor(n, line);
        lcd->print(" ");
    }
}