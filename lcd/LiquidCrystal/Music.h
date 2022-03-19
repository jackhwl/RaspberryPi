#ifndef MY_MUSIC_H
#define MY_MUSIC_H

#include <Arduino.h>

class Music
{
private:
    byte pin;

public:
    Music(byte pin);
    void init();
    void playMusic(byte index);
};

#endif