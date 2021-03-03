/**
 * @file shift_registers.hpp
 * @author Ammar Shahin (Ammar0Shahin@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SHIFT_REGISTERS_H__
#define SHIFT_REGISTERS_H__

#include "utils.hpp"

void shift_registers_init(void);
void shift_registers_set(uint32_t data);
void shift_registers_clear(void);
void shift_registers_out(void);

#endif   // !SHIFT_REGISTERS_H__