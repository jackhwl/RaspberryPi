#include "testlib.h"

const int pin = 2;
testLib myLib; // object instance

void writePinStateToSerial(const int state)
{
    Serial.print("Pin ");
    Serial.print(pin, DEC);
    Serial.print(" state is: ");
    Serial.println(state ? "HIGH" : "LOW");
}

void setup()
{
    Serial.begin(115200);

    myLib.begin(pin);
    myLib.setCallback(writePinStateToSerial);
}

void loop()
{
    // nothing here
}