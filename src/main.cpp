#include <Arduino.h>

#define SHIFT_DATA 2
#define SHIFT_CLK 4
#define SHIFT_ENABLE 3

static volatile uint32_t gu32_internalBuffer;

void setData(uint32_t data);
void clrData(void);
void outData(void);

void setup()
{
    gu32_internalBuffer = 0;

    Serial.begin(9600);

    digitalWrite(SHIFT_ENABLE, LOW);
    digitalWrite(SHIFT_DATA, LOW);
    digitalWrite(SHIFT_CLK, LOW);
    pinMode(SHIFT_DATA, OUTPUT);
    pinMode(SHIFT_CLK, OUTPUT);
    pinMode(SHIFT_ENABLE, OUTPUT);
}

void setData(uint32_t data)
{
    gu32_internalBuffer |= (1 << data);
    outData();
}

void clrData()
{
    gu32_internalBuffer = 0;
    outData();
}

void outData()
{
    shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, gu32_internalBuffer >> 16);
    shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, gu32_internalBuffer >> 8);
    shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, gu32_internalBuffer);
    digitalWrite(SHIFT_ENABLE, LOW);
    digitalWrite(SHIFT_ENABLE, HIGH);
    digitalWrite(SHIFT_ENABLE, LOW);
}

void loop()
{
    static uint32_t x = 0;

    setData(x);

    Serial.println(x);

    if (x >= 23)
    {
        x = 0;
        delay(1000);
        clrData();
    }
    else
    {
        x++;
    }

    delay(1000);
}