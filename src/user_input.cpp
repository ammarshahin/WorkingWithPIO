/**
 * @file user_input.cpp
 * @author Ammar Shahin (Ammar0Shahin@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/user_input.hpp"
#include "../include/blutooth_module.hpp"
#include "../include/shift_registers.hpp"

#define debug 1
const uint8_t ALL_LOADS_OFF_COMMAND = 255u;
const uint8_t MAX_NUMBER_OF_LOADS = 24u;

void user_input_init(void)
{
    //
}

void user_input_update(void)
{
    static uint32_t u32_internal_timer = 0;
    u32_internal_timer++;
    if (u32_internal_timer >= 1000)
    {
        u32_internal_timer = 0;
#if debug
        static uint32_t x = 0;
        shift_registers_set(x);
        Serial.println(x);
        if (x >= (MAX_NUMBER_OF_LOADS - 1))
        {
            x = 0;
            shift_registers_clear();
        }
        else
        {
            x++;
        }
#else
        if (blutooth_module_dataReceivedFlag_get() == true)
        {
            uint8_t u8_received_date = blutooth_module_data_get();
            if (u8_received_date == ALL_LOADS_OFF_COMMAND)
            {
                shift_registers_clear();
            }
            else if (u8_received_date < MAX_NUMBER_OF_LOADS)
            {
                shift_registers_set(static_cast<uint32_t>(u8_received_date));
            }
            else
            {
                // Do nothing >> ignore
            }
            // leds_blinking_flag_set();
        }
#endif
    }
}
