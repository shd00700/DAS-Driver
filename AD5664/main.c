#include <stdio.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "AD56x4.h"

#define PIN_MISO 10
#define PIN_CS 8
#define PIN_SCK 7
#define PIN_MOSI 6
#define SPI_PORT spi0

int AD56X4_SS_pin = 10;

// Define the sine wave frequencies for each channel in Hz, the
// initial phases in degrees, the offsets, and the amplitudes.

float frequencies[] = {1e1, 1e1, 1e1, 1e1};
float phases[] = {0, 90, 180, 270};
float offsets[] = {32768, 32768, 32768, 32768};
float amplitudes[] = {32600, 32600, 32600, 32600};

AD56X4_CHANNEL_A
