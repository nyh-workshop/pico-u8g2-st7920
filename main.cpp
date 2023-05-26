#include <stdio.h>
#include <tusb.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/pio.h"

#include "st7920_spi_u8g2_hal.h"

U8G2_ST7920_128X64_1_HW_SPI_CUSTOM u8g2(U8G2_R0);

void draw_test_display()
{
    u8g2.clearBuffer();
    u8g2.clearDisplay();
    u8g2.setDrawColor(1);
    u8g2.setFont(u8g2_font_lubBI14_tr);
    u8g2.drawStr(0, 30, "Hello World!");
    u8g2.updateDisplay();
}

int main()
{
    stdio_init_all();

    stdio_filter_driver(&stdio_usb);
    while (!tud_cdc_connected())
        sleep_ms(100);
    printf("\nUSB Serial connected!\n");

    puts("Hello, world!");

    u8g2.begin();

    draw_test_display();

    while(1)
    {
        sleep_ms(500);
    }

    return 0;
}
