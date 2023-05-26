# pico-u8g2-ST7920

This project utilises the [U8G2 library](https://github.com/olikraus/u8g2) and ST7920 GLCD display unit with the Raspberry Pico SDK.

Currently only SPI is supported.

#### Bonus:
To use the ported demo tests from the U8G2 library, simply change the main.cpp in the `add_executable` in the CMakeLists.txt to FPS.cpp or GFXtest.cpp:
```
add_executable(pico-u8g2-st7920 main.cpp
st7920_spi_u8g2_hal.cpp )
```
Then save the file and recompile!

### SPI connection:
|RASPBERRY PICO|ST7920
|---|---
|GP2|E (SCK)
|GP3|RW (MOSI)
|GP5|RS (CS)
|GP13|RST
|GND|PSB

## Requirements:
- ST7920 Display
- Raspberry Pico SDK 1.4
- Latest version of U8G2

## References:
- [Porting U8G2 to RP2040 SDK](https://github.com/olikraus/u8g2/issues/2159)
