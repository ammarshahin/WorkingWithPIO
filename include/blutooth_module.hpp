/**
 * @file Blutooth_Module.hpp
 * @author Ammar Shahin (Ammar0Shahin@gmail.com)
 * @brief this file is used to control the led's through the Relays
 * @version 0.1
 * @date 2021-3-3
 * 
 * @copyright Copyright (c) 2021
 *
 * 
 */

#ifndef BLUTOOTH_MODULE_H__
#define BLUTOOTH_MODULE_H__

#include "utils.hpp"

void blutooth_module_init(void);
void blutooth_module_update(void);
uint8_t blutooth_module_data_get(void);
bool blutooth_module_isDataReceived(void);

#endif   //! BLUTOOTH_MODULE_H__