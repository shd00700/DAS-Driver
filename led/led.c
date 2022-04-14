#include <stdio.h>
#include "pico/stdlib.h"

int main()
{
    const uint led_pin3 = 20;

    const uint led_pin1 = 16;
    const uint led_pin2 = 19;
    // Initialize LED pin
    gpio_init(led_pin1);
    gpio_init(led_pin2);
    gpio_init(led_pin3);
    gpio_set_dir(led_pin1, GPIO_OUT);
    gpio_set_dir(led_pin2, GPIO_OUT);
    gpio_set_dir(led_pin3, GPIO_OUT);
    // Initialize chosen serial port
    stdio_init_all();

    // Loop forever
    while (true)
    {

        // Blink LED
        printf("Blinking!\r\n");
        gpio_put(led_pin1, true);
        gpio_put(led_pin2, true);
        gpio_put(led_pin3, true);
        sleep_ms(1000);
        gpio_put(led_pin1, false);
        gpio_put(led_pin2, false);
        gpio_put(led_pin3, false);
        sleep_ms(1000);
    }
}