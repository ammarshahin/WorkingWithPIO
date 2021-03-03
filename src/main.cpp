#include <Arduino.h>

#define SHIFT_DATA 2
#define SHIFT_CLK 4
#define SHIFT_ENABLE 3
#define SET_BIT(reg, index) (reg |= (1 >> index))

static volatile uint32_t gu32_internalBuffer;

void setData(uint32_t data);
void clrData();

// the setup function runs once when you press reset or power the board
void setup()
{
    gu32_internalBuffer = 0;

    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);

    pinMode(SHIFT_DATA, OUTPUT);
    pinMode(SHIFT_CLK, OUTPUT);
    pinMode(SHIFT_ENABLE, OUTPUT);
    digitalWrite(SHIFT_ENABLE, LOW);
    digitalWrite(SHIFT_DATA, LOW);
    digitalWrite(SHIFT_CLK, LOW);
}

void setData(uint32_t data)
{
    SET_BIT(gu32_internalBuffer, data);
    shiftOut(SHIFT_DATA, SHIFT_CLK, LSBFIRST, gu32_internalBuffer >> 16);
    shiftOut(SHIFT_DATA, SHIFT_CLK, LSBFIRST, gu32_internalBuffer >> 8);
    shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, gu32_internalBuffer);
    digitalWrite(SHIFT_ENABLE, LOW);
    digitalWrite(SHIFT_ENABLE, HIGH);
    digitalWrite(SHIFT_ENABLE, LOW);
}

void clrData()
{
    gu32_internalBuffer = 0;
    shiftOut(SHIFT_DATA, SHIFT_CLK, LSBFIRST, gu32_internalBuffer >> 16);
    shiftOut(SHIFT_DATA, SHIFT_CLK, LSBFIRST, gu32_internalBuffer >> 8);
    shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, gu32_internalBuffer);
    digitalWrite(SHIFT_ENABLE, LOW);
    digitalWrite(SHIFT_ENABLE, HIGH);
    digitalWrite(SHIFT_ENABLE, LOW);
}

// the loop function runs over and over again forever
void loop()
{
    static uint32_t x = 0;
    setData(x);
    if (x >= 7)
    {
        x = 0;
        clrData();
    }
    else
    {
        x++;
    }

    Serial.println(x);
    delay(1000);   // wait for a second
}