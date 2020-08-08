#define LED_1_PIN 9

class Led
{
private:
    byte pin;

public:
    Led(byte pin)
    {
        // Use 'this->' to make the difference between the
        // 'pin' attribute of the class and the
        // local variable 'pin' created from the parameter.
        this->pin = pin;
        init();
    }

    void init()
    {
        pinMode(pin, OUTPUT);
        // Always try to avoid duplicate code.
        // Instead of writing digitalWrite(pin, LOW) here,
        // call the function off() which already does that
        off();
    }

    void on()
    {
        digitalWrite(pin, HIGH);
    }

    void off()
    {
        digitalWrite(pin, LOW);
    }
}; // don't forget the semicolon at the end of the class

Led led1(LED_1_PIN);

void setup() {}

void loop()
{
    led1.on();
    delay(500);
    led1.off();
    delay(500);
}