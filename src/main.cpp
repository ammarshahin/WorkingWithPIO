/**
 * @file main.cpp
 * @author Ammar Shahin (Ammar0Shahin@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/utils.hpp"
#include "../include/blutooth_module.hpp"
#include "../include/shift_registers.hpp"
#include "../include/user_input.hpp"

#define debug 0

void setup()
{
    Serial.begin(9600);

    shift_registers_init();
    user_input_init();
    blutooth_module_init();
}

void loop()
{
    blutooth_module_update();
    user_input_update();
    delay(1);
}