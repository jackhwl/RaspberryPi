#include "testlib.h"

// Outside of class
testLib *pointerToClass; // declare a pointer to testLib class

static void outsideInterruptHandler(void)
{                                            // define global handler
    pointerToClass->classInterruptHandler(); // calls class member handler
}

// Class members
void testLib::begin(int interruptPin)
{
    pinMode(interruptPin, INPUT);

    pointerToClass = this; // assign current instance to pointer (IMPORTANT!!!)
    attachInterrupt(digitalPinToInterrupt(interruptPin), outsideInterruptHandler, CHANGE);
}

void testLib::classInterruptHandler(void)
{
    // TO DO: call the... callback function
}