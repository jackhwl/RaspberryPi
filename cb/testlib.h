#ifndef TESTLIB_H
#define TESTLIB_H

#include "Arduino.h"

class testLib
{

public:
    void begin(int interruptPin);
    void classInterruptHandler(void);
};

#endif