#ifndef ST7920_SPI_U8G2_HAL_H
#define ST7920_SPI_U8G2_HAL_H

// Reference: https://github.com/olikraus/u8g2/issues/1758

#include <u8g2.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"

// ADD THE INIT DISPLAY 
#define SPI_PORT spi0
#define PIN_CS 5
#define PIN_SCK 2
#define PIN_MOSI 3
#define SPI_SPEED 500 * 1000
#define PIN_RST 13

void st7920_writeReg_SPI(uint8_t aByte);
void st7920_writeData_SPI(uint8_t aByte);
uint8_t u8x8_gpio_and_delay_pico(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
uint8_t u8x8_byte_pico_hw_spi(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

#endif