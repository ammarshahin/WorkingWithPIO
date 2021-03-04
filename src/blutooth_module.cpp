/**
 * @file Blutooth_Module.cpp
 * @author Ammar Shahin (Ammar0Shahin@gmail.com)
 * @brief this file is used to control the led's through the Relays
 * @version 0.1
 * @date 2021-3-3
 * 
 * @copyright Copyright (c) 2021
 *
 * 
 */

#include "../include/blutooth_module.hpp"

#define MAX_BUFFER_SIZE (10u)

typedef struct
{
    uint32_t read_data;
    uint8_t Buffer[MAX_BUFFER_SIZE];
    uint8_t rx_internal_counter;
} bluetooth_comm_t;

static bluetooth_comm_t gx_internalBuffer;
static bool gb_dataReceived_flag;

static uint32_t atoi(char *str);

void blutooth_module_init(void)
{
    uint8_t u8_index = 0;
    for (u8_index = 0; u8_index < MAX_BUFFER_SIZE; u8_index++)
    {
        gx_internalBuffer.Buffer[u8_index] = 0;
    }
    gx_internalBuffer.rx_internal_counter = 0;
    gb_dataReceived_flag = false;

    // TODO: uart_init
}

void blutooth_module_update(void)
{
    uint8_t data_received = 0;
    static uint8_t u8_internalTimeout = 0;

    // check if the data is received
    if (0)   // TODO: (UART_RECV_COMPLETE_FLAG_CHECK())
    {
        u8_internalTimeout = 0;
        // TODO: UART_DATA_GET(data_received);
        gx_internalBuffer.Buffer[gx_internalBuffer.rx_internal_counter] = data_received;
        gx_internalBuffer.rx_internal_counter++;
        if (gx_internalBuffer.rx_internal_counter == MAX_BUFFER_SIZE)
        {
            gx_internalBuffer.rx_internal_counter = 0;
        }
    }

    if (gx_internalBuffer.rx_internal_counter > 0)
    {
        if ((u8_internalTimeout > 49))
        {
            gx_internalBuffer.Buffer[gx_internalBuffer.rx_internal_counter] = '\0';
            gx_internalBuffer.read_data = atoi((char *)gx_internalBuffer.Buffer);
            gx_internalBuffer.rx_internal_counter = 0;
            u8_internalTimeout = 0;
            gb_dataReceived_flag = true;
        }
        else
        {
            u8_internalTimeout++;
        }
    }
}

uint8_t blutooth_module_data_get(void)
{
    gb_dataReceived_flag = false;
    return gx_internalBuffer.read_data;
}

bool blutooth_module_dataReceivedFlag_get(void)
{
    return gb_dataReceived_flag;
}

static uint32_t atoi(char *str)
{
    uint32_t res = 0;
    uint8_t i = 0;

    for (i = 0; str[i] != '\0'; ++i)
    {
        res = res * 10 + (str[i] - '0');
    }

    return res;
}