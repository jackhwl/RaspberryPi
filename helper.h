#include <LiquidCrystal.h>

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

void clearLCDLine(LiquidCrystal *l, int line)
{
    for (int n = 0; n < 16; n++)
    { // 20 indicates symbols in line. For 2x16 LCD write - 16
        l->setCursor(n, line);
        l->print(" ");
    }
}