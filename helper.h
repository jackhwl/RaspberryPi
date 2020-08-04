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

void displayTimer(LiquidCrystal *lcd, unsigned long previousMillis)
{
    char buffer[8];
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd->setCursor(0, 1);
    unsigned long currentMillis = millis();
    // print the number of seconds since rollover:
    setTimeBuffer(buffer, (currentMillis - previousMillis) / 1000, false);
    lcd->write(buffer);

    //lcd.print((currentMillis - previousMillis)/1000);
    lcd->setCursor(8, 1);

    setTimeBuffer(buffer, currentMillis / 1000, true);
    lcd->write(buffer);
}

void clearLCDLine(LiquidCrystal *lcd, int line)
{
    for (int n = 0; n < 16; n++)
    { // 20 indicates symbols in line. For 2x16 LCD write - 16
        lcd->setCursor(n, line);
        lcd->print(" ");
    }
}