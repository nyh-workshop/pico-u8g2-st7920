#include <stdio.h>
#include <tusb.h>
#include <u8g2.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/pio.h"

#include "st7920_spi_u8g2_hal.h"

u8g2_t u8g2;

void draw_test_display()
{
    char hey[] = "Hello World!";
    u8g2_ClearBuffer(&u8g2);
    u8g2_ClearDisplay(&u8g2);
    u8g2_SetDrawColor(&u8g2, 1);
    u8g2_SetFont(&u8g2, u8g2_font_lubBI14_tr);
    u8g2_DrawStr(&u8g2, 0, 30, hey);
    u8g2_UpdateDisplay(&u8g2);
}

void display_sequence()
{
    u8g2_Setup_st7920_s_128x64_f(&u8g2, U8G2_R0, u8x8_byte_pico_hw_spi, u8x8_gpio_and_delay_pico);
    u8g2_InitDisplay(&u8g2);
    draw_test_display();
}

int main()
{
    stdio_init_all();

    stdio_filter_driver(&stdio_usb);
    while (!tud_cdc_connected())
        sleep_ms(100);
    printf("\nUSB Serial connected!\n");

    puts("Hello, world!");

    display_sequence();

    while(1)
    {
        sleep_ms(500);
    }

    return 0;
}
