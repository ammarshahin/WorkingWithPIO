/**
 * @file UTILS.hpp
 * @author Ammar Shahin (Ammar0Shahin@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <Arduino.h>

//Common Macros
#define CONTROL_BIT(reg, index, command) ((command) == (0) ? (CLR_BIT(reg, index)) : (SET_BIT(reg, index)))
#define WCONTROL_BIT(wreg, index, command) ((command) == (0) ? (WCLR_BIT(wreg, index)) : (WSET_BIT(wreg, index)))

#define SET_BIT(reg, index) (reg |= (1 << index))
#define CLR_BIT(reg, index) (reg &= (~(1 << index)))
#define GET_BIT(reg, index) ((reg >> index) & 0X01)

#define TOG_BIT(reg, index) (reg ^= (1 << index))
#define GET_LOW_NIBBLE(reg) (reg & 0x0F)
#define PUT_LOW_NIBBLE(reg, val) (reg = (reg & 0xF0) | (val))
#define GET_HIGH_THREE_BITS(reg) (reg >> 5)
#define PUT_HIGH_THREE_BITS(reg, val) (reg = (reg & 0x1F) | (val << 5))

#endif
