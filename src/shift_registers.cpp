/**
 * @file shift_registers.cpp
 * @author Ammar Shahin (Ammar0Shahin@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "../include/shift_registers.hpp"

#define debug 1

const uint8_t SHIFT_DATA_PIN = 2, SHIFT_ENABLE_PIN = 3, SHIFT_CLK_PIN = 4;
static volatile uint32_t gu32_internalBuffer;

void shift_registers_init(void)
{
    gu32_internalBuffer = 0;

    digitalWrite(SHIFT_ENABLE_PIN, LOW);
    digitalWrite(SHIFT_DATA_PIN, LOW);
    digitalWrite(SHIFT_CLK_PIN, LOW);

    pinMode(SHIFT_DATA_PIN, OUTPUT);
    pinMode(SHIFT_CLK_PIN, OUTPUT);
    pinMode(SHIFT_ENABLE_PIN, OUTPUT);
}

void shift_registers_set(uint8_t data)
{
    gu32_internalBuffer |= (static_cast<uint32_t>(1) << data);
    shift_registers_out();

#if debug
    Serial.println(data);
    Serial.println(gu32_internalBuffer);
#endif
}

void shift_registers_clear()
{
    gu32_internalBuffer = 0;
    shift_registers_out();
}

void shift_registers_out()
{
    shiftOut(SHIFT_DATA_PIN, SHIFT_CLK_PIN, MSBFIRST, static_cast<uint8_t>(gu32_internalBuffer >> 16));
    shiftOut(SHIFT_DATA_PIN, SHIFT_CLK_PIN, MSBFIRST, static_cast<uint8_t>(gu32_internalBuffer >> 8));
    shiftOut(SHIFT_DATA_PIN, SHIFT_CLK_PIN, MSBFIRST, static_cast<uint8_t>(gu32_internalBuffer >> 0));

    digitalWrite(SHIFT_ENABLE_PIN, LOW);
    digitalWrite(SHIFT_ENABLE_PIN, HIGH);
    digitalWrite(SHIFT_ENABLE_PIN, LOW);
}
