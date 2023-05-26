# Generated Cmake Pico project file

# u8g2 on pico-sdk reference: https://github.com/olikraus/u8g2/issues/2159

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffunction-sections -fdata-sections -Wl,--gc-sections")

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "E:/pico-sdk")

set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(pico-u8g2-st7920 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(pico-u8g2-st7920 main.cpp
st7920_spi_u8g2_hal.cpp )

pico_set_program_name(pico-u8g2-st7920 "pico-u8g2-st7920")
pico_set_program_version(pico-u8g2-st7920 "0.1")

pico_enable_stdio_uart(pico-u8g2-st7920 0)
pico_enable_stdio_usb(pico-u8g2-st7920 1)

# Add the standard library to the build
target_link_libraries(pico-u8g2-st7920
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(pico-u8g2-st7920 PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
  u8g2/csrc
  u8g2/cppsrc
)

file(GLOB U8G2_SRC u8g2/csrc/*.c)
add_library(u8g2 ${U8G2_SRC})

target_link_options(pico-u8g2-st7920 PRIVATE -Xlinker --print-memory-usage)

# Add any user requested libraries
target_link_libraries(pico-u8g2-st7920
        hardware_pio
        hardware_spi
        u8g2
        )

pico_add_extra_outputs(pico-u8g2-st7920)

