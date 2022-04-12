#include "pico/stdlib.h"
#include "muxd.h"

#define UART_ID uart1
#define BAUD_RATE 115200
#define LED_PIN 25

#define UART_TX_PIN 8
#define UART_RX_PIN 9

const uint s1 = 16;
const uint s2 = 17;
const uint s3 = 18;
const uint s4 = 19;

int controlPin[] = {s1, s2, s3, s4};

int Muxchannel[16][4] = {
    // s0, s1, s2, s3     channel
    {0, 0, 0, 0}, // 0
    {1, 0, 0, 0}, // 1
    {0, 1, 0, 0}, // 2
    {1, 1, 0, 0}, // 3
    {0, 0, 1, 0}, // 4
    {1, 0, 1, 0}, // 5
    {0, 1, 1, 0}, // 6
    {1, 1, 1, 0}, // 7
    {0, 0, 0, 1}, // 8
    {1, 0, 0, 1}, // 9
    {0, 1, 0, 1}, // 10
    {1, 1, 0, 1}, // 11
    {0, 0, 1, 1}, // 12
    {1, 0, 1, 1}, // 13
    {0, 1, 1, 1}, // 14
    {1, 1, 1, 1}  // 15
};

void muxnum(int n)
{
    gpio_init(s1);
    gpio_init(s2);
    gpio_init(s3);
    gpio_init(s4);
    gpio_set_dir(s1, GPIO_OUT);
    gpio_set_dir(s2, GPIO_OUT);
    gpio_set_dir(s3, GPIO_OUT);
    gpio_set_dir(s4, GPIO_OUT);

    switch (n)
    {
    case 0:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin[i], Muxchannel[n][i]);
        }
        break;

    case 1:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin[i], Muxchannel[n][i]);
        }
        break;

    case 2:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin[i], Muxchannel[n][i]);
        }
        break;

    case 3:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin[i], Muxchannel[n][i]);
        }
        break;

    case 4:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin[i], Muxchannel[n][i]);
        }
        break;

    case 5:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin[i], Muxchannel[n][i]);
        }
        break;

    case 6:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin[i], Muxchannel[n][i]);
        }
        break;

    case 7:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin[i], Muxchannel[n][i]);
        }
        break;

    case 8:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin[i], Muxchannel[n][i]);
        }
        break;

    case 9:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin[i], Muxchannel[n][i]);
        }
        break;

    case 10:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin[i], Muxchannel[n][i]);
        }
        break;

    default:
        break;
    }
}

int main()
{

    stdio_init_all();
    sleep_ms(3000);

    // UART Setup
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    uart_is_readable(UART_ID);

    muxnum(0);

    while (1)
    {
        // char ch[20];

        uint16_t ch = uart_getc(UART_ID);

        if (ch == '0')
        {
            muxnum(0);
            printf("1ch\n");
            continue;
        }

        if (ch == '1')
        {
            muxnum(1);
            printf("2ch\n");
            continue;
        }

        if (ch == '2')
        {
            muxnum(2);
            printf("2ch\n");
            continue;
        }

        if (ch == '3')
        {
            muxnum(3);
            printf("2ch\n");
            continue;
        }

        if (ch == '4')
        {
            muxnum(4);
            printf("2ch\n");
            continue;
        }

        if (ch == '5')
        {
            muxnum(5);
            printf("2ch\n");
            continue;
        }

        if (ch == '6')
        {
            muxnum(6);
            printf("2ch\n");
            continue;
        }

        if (ch == '7')
        {
            muxnum(7);
            printf("2ch\n");
            continue;
        }

        if (ch == '8')
        {
            muxnum(8);
            printf("2ch\n");
            continue;
        }

        if (ch == '9')
        {
            muxnum(9);
            printf("2ch\n");
            continue;
        }

        if (ch == '10')
        {
            muxnum(10);
            printf("2ch\n");
            continue;
        }

        printf("BI");
        continue;
    }
    printf("BO");
    return 0;
}
