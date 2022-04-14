cmake_minimum_required(VERSION 3.12)

# Include build functions from Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)


project(pico_examples C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()

###
#set(PICO_EXAMPLE_URL_BASE "https://github.com/raspberrypi/pico-examples/tree/HEAD")
#macro(example_auto_set_url TARGET)
#    file(RELATIVE_PATH URL_REL_PATH "${PICO_EXAMPLES_PATH}" "${CMAKE_CURRENT_LIST_DIR}")
#    pico_set_program_url(${TARGET} "${PICO_EXAMPLE_URL_BASE}/${URL_REL_PATH}")
#endmacro()
###

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        )

# Hardware-specific examples in subdirectories:
add_subdirectory(led)
#add_subdirectory(MUXD)
add_subdirectory(Optical-SW)
add_subdirectory(SLDD)

# Enable usb output, disable uart output
# pico_enable_stdio_usb(Optical-SW 1)
# pico_enable_stdio_uart(Optical-SW 1)
pico_enable_stdio_usb(Optical-SW 1)
pico_enable_stdio_uart(Optical-SW 1)