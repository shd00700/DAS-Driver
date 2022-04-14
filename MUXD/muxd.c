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
const uint s5 = 20;
const uint s6 = 21;
const uint s7 = 22;
const uint s8 = 23;
const uint s9 = 20;
const uint s10 = 25;

int controlPin_I[] = {s1, s2, s3, s4};
int controlPin_Q[] = {s6, s7, s8, s9};

int Muxchannel[16][4] = {

    {0, 0, 0, 0},
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 1, 0},
    {1, 0, 1, 0},
    {0, 1, 1, 0},
    {1, 1, 1, 0},
    {0, 0, 0, 1},
    {1, 0, 0, 1},
    {0, 1, 0, 1},
    {1, 1, 0, 1},
    {0, 0, 1, 1},
    {1, 0, 1, 1},
    {0, 1, 1, 1},
    {1, 1, 1, 1}};

void muxI_init()
{
    gpio_init(s1);
    gpio_init(s2);
    gpio_init(s3);
    gpio_init(s4);
    gpio_init(s5);
    gpio_set_dir(s1, GPIO_OUT);
    gpio_set_dir(s2, GPIO_OUT);
    gpio_set_dir(s3, GPIO_OUT);
    gpio_set_dir(s4, GPIO_OUT);
    gpio_set_dir(s5, GPIO_OUT);
}

void muxQ_init()
{
    gpio_init(s6);
    gpio_init(s7);
    gpio_init(s8);
    gpio_init(s9);
    gpio_init(s10);
    gpio_set_dir(s6, GPIO_OUT);
    gpio_set_dir(s7, GPIO_OUT);
    gpio_set_dir(s8, GPIO_OUT);
    gpio_set_dir(s9, GPIO_OUT);
    gpio_set_dir(s10, GPIO_OUT);
}

void muxnum_I(int n)
{
    gpio_put(s5, 1);
    gpio_put(s10, 0);

    switch (n)
    {
    case 0:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_I[i], Muxchannel[n][i]);
        }
        break;

    case 1:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_I[i], Muxchannel[n][i]);
        }
        break;

    case 2:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_I[i], Muxchannel[n][i]);
        }
        break;

    case 3:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_I[i], Muxchannel[n][i]);
        }
        break;

    case 4:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_I[i], Muxchannel[n][i]);
        }
        break;

    case 5:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_I[i], Muxchannel[n][i]);
        }
        break;

    case 6:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_I[i], Muxchannel[n][i]);
        }
        break;

    case 7:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_I[i], Muxchannel[n][i]);
        }
        break;

    case 8:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_I[i], Muxchannel[n][i]);
        }
        break;

    case 9:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_I[i], Muxchannel[n][i]);
        }
        break;

    case 10:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_I[i], Muxchannel[n][i]);
        }
        break;
    case 11:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_I[i], Muxchannel[n][i]);
        }
        break;
    case 12:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_I[i], Muxchannel[n][i]);
        }
        break;
    case 13:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_I[i], Muxchannel[n][i]);
        }
        break;
    case 14:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_I[i], Muxchannel[n][i]);
        }
        break;

    case 15:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_I[i], Muxchannel[n][i]);
        }
        break;

    default:
        break;
    }
}

void muxnum_Q(int n)
{
    gpio_put(s10, 1);
    gpio_put(s5, 0);

    switch (n)
    {
    case 0:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_Q[i], Muxchannel[n][i]);
        }
        break;

    case 1:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_Q[i], Muxchannel[n][i]);
        }
        break;

    case 2:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_Q[i], Muxchannel[n][i]);
        }
        break;

    case 3:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_Q[i], Muxchannel[n][i]);
        }
        break;

    case 4:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_Q[i], Muxchannel[n][i]);
        }
        break;

    case 5:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_Q[i], Muxchannel[n][i]);
        }
        break;

    case 6:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_Q[i], Muxchannel[n][i]);
        }
        break;

    case 7:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_Q[i], Muxchannel[n][i]);
        }
        break;

    case 8:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_Q[i], Muxchannel[n][i]);
        }
        break;

    case 9:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_Q[i], Muxchannel[n][i]);
        }
        break;

    case 10:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_Q[i], Muxchannel[n][i]);
        }
        break;
    case 11:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_Q[i], Muxchannel[n][i]);
        }
        break;
    case 12:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_Q[i], Muxchannel[n][i]);
        }
        break;
    case 13:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_Q[i], Muxchannel[n][i]);
        }
        break;
    case 14:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_Q[i], Muxchannel[n][i]);
        }
        break;

    case 15:
        for (int i = 0; i < 4; i++)
        {
            gpio_put(controlPin_Q[i], Muxchannel[n][i]);
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

    muxI_init();
    muxQ_init();
    // UART Setup
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    uart_is_readable(UART_ID);

    muxnum_I(0);
    muxnum_Q(0);
    gpio_put(s5, 0);
    gpio_put(s10, 0);

    while (1)
    {
        // char ch[20];

        uint16_t ch = uart_getc(UART_ID);

        if (ch == '0')
        {
            muxnum_I(0);
            printf("I 0ch\n");
            continue;
        }

        if (ch == '1')
        {
            muxnum_I(1);
            printf("I 1ch\n");
            continue;
        }

        if (ch == '2')
        {
            muxnum_I(2);
            printf("I 2ch\n");
            continue;
        }

        if (ch == '3')
        {
            muxnum_I(3);
            printf("I 3ch\n");
            continue;
        }

        if (ch == '4')
        {
            muxnum_I(4);
            printf("I 4ch\n");
            continue;
        }

        if (ch == '5')
        {
            muxnum_I(5);
            printf("I 5ch\n");
            continue;
        }

        if (ch == '6')
        {
            muxnum_I(6);
            printf("I 6ch\n");
            continue;
        }

        if (ch == '7')
        {
            muxnum_I(7);
            printf("I 7ch\n");
            continue;
        }

        if (ch == '8')
        {
            muxnum_I(8);
            printf("I 8ch\n");
            continue;
        }

        if (ch == '9')
        {
            muxnum_I(9);
            printf("I 9ch\n");
            continue;
        }

        if (ch == 'a')
        {
            muxnum_I(10);
            printf("I 10ch\n");
            continue;
        }

        if (ch == 'b')
        {
            muxnum_I(11);
            printf("I 11ch\n");
            continue;
        }

        if (ch == 'c')
        {
            muxnum_I(12);
            printf("I 12ch\n");
            continue;
        }

        if (ch == 'd')
        {
            muxnum_I(13);
            printf("I 13ch\n");
            continue;
        }

        if (ch == 'e')
        {
            muxnum_I(14);
            printf("I 14ch\n");
            continue;
        }

        if (ch == 'f')
        {
            muxnum_I(15);
            printf("I 15ch\n");
            continue;
        }

        if (ch == ')')
        {
            muxnum_Q(0);
            printf("Q 0ch\n");
            continue;
        }

        if (ch == '!')
        {
            muxnum_Q(1);
            printf("Q 1ch\n");
            continue;
        }

        if (ch == '@')
        {
            muxnum_Q(2);
            printf("Q 2ch\n");
            continue;
        }

        if (ch == '#')
        {
            muxnum_Q(3);
            printf("Q 3ch\n");
            continue;
        }

        if (ch == '$')
        {
            muxnum_Q(4);
            printf("Q 4ch\n");
            continue;
        }

        if (ch == '%')
        {
            muxnum_Q(5);
            printf("Q 5ch\n");
            continue;
        }

        if (ch == '^')
        {
            muxnum_Q(6);
            printf("Q 6ch\n");
            continue;
        }

        if (ch == '&')
        {
            muxnum_Q(7);
            printf("Q 7ch\n");
            continue;
        }

        if (ch == '*')
        {
            muxnum_Q(8);
            printf("Q 8ch\n");
            continue;
        }

        if (ch == '(')
        {
            muxnum_Q(9);
            printf("Q 9ch\n");
            continue;
        }

        if (ch == 'A')
        {
            muxnum_Q(10);
            printf("Q 10ch\n");
            continue;
        }

        if (ch == 'B')
        {
            muxnum_Q(11);
            printf("Q 11ch\n");
            continue;
        }

        if (ch == 'C')
        {
            muxnum_Q(12);
            printf("Q 12ch\n");
            continue;
        }

        if (ch == 'D')
        {
            muxnum_Q(13);
            printf("Q 13ch\n");
            continue;
        }

        if (ch == 'E')
        {
            muxnum_Q(14);
            printf("Q 14ch\n");
            continue;
        }

        if (ch == 'F')
        {
            muxnum_Q(15);
            printf("Q 15ch\n");
            continue;
        }

        printf("BI");
        continue;
    }
    printf("BO");
    return 0;
}
