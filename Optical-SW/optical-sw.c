/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/uart.h"
#include "pico/bootrom.h"

#define UART_ID uart1
#define BAUD_RATE 115200
#define LED_PIN 25

#define UART_TX_PIN 8
#define UART_RX_PIN 9

const uint sw1 = 16;
const uint sw2 = 17;
const uint sw3 = 18;

void swnum(int n)
{
    gpio_init(sw1);
    gpio_init(sw2);
    gpio_init(sw3);
    gpio_set_dir(sw1, GPIO_OUT);
    gpio_set_dir(sw2, GPIO_OUT);
    gpio_set_dir(sw3, GPIO_OUT);

    switch (n)
    {
    case 0:

        gpio_put(sw1, 1);
        gpio_put(sw2, 0);
        gpio_put(sw3, 0);

        break;

    case 1:

        gpio_put(sw1, 1);
        gpio_put(sw2, 0);
        gpio_put(sw3, 0);

        break;

    case 2:

        gpio_put(sw1, 0);
        gpio_put(sw2, 1);
        gpio_put(sw3, 0);

        break;
    case 3:
        gpio_put(sw1, 0);
        gpio_put(sw2, 0);
        gpio_put(sw3, 1);
        break;
    case 4:

        gpio_put(sw1, 0);
        gpio_put(sw2, 0);
        gpio_put(sw3, 0);
        break;

    case 5:

        break;

    default:
        break;
    }
}
int main()
{
    stdio_init_all();
    sleep_ms(3000);

    char s1[10];
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // UART Setup
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    uart_is_readable(UART_ID);

    swnum(0);

    while (1)
    {
        // char ch[20];

        uint16_t ch = uart_getc(UART_ID);

        if (ch == '1')
        {
            swnum(1);
            printf("1ch\n");
            continue;
        }

        if (ch == '2')
        {
            swnum(2);
            printf("2ch\n");
            continue;
        }

        if (ch == '3')
        {
            swnum(3);
            printf("3ch\n");
            continue;
        }
        if (ch == '4')
        {
            swnum(4);
            printf("4ch\n");
            continue;
        }
        if (ch == '5')
        {
            swnum(5);
            printf("5ch\n");
            continue;
        }
        if (ch == '5')
        {
            swnum(5);
            printf("5ch\n");
            continue;
        }
        if (ch == '5')
        {
            swnum(5);
            printf("5ch\n");
            continue;
        }
        if (ch == '5')
        {
            swnum(5);
            printf("5ch\n");
            continue;
        }
        if (ch == '5')
        {
            swnum(5);
            printf("5ch\n");
            continue;
        }
        if (ch == '5')
        {
            swnum(5);
            printf("5ch\n");
            continue;
        }
        if (ch == '5')
        {
            swnum(5);
            printf("5ch\n");
            continue;
        }
        if (ch == '5')
        {
            swnum(5);
            printf("5ch\n");
            continue;
        }
        if (ch == '5')
        {
            swnum(5);
            printf("5ch\n");
            continue;
        }
        if (ch == '5')
        {
            swnum(5);
            printf("5ch\n");
            continue;
        }
        if (ch == '5')
        {
            swnum(5);
            printf("5ch\n");
            continue;
        }
        if (ch == '5')
        {
            swnum(5);
            printf("5ch\n");
            continue;
        }
        if (ch == '5')
        {
            swnum(5);
            printf("5ch\n");
            continue;
        }
        if (ch == '5')
        {
            swnum(5);
            printf("5ch\n");
            continue;
        }
        printf("BI");
        continue;
        // swnum(1);
        // sleep_ms(3000);
        // swnum(2);
        // sleep_ms(3000);
        // swnum(3);
        // sleep_ms(3000);s
        // swnum(4);
        // sleep_ms(3000);
    }
    printf("BO");
    return 0;
}
