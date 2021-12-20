#include "AD56x4.h"
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "pico/bootrom.h"

static void AD56x4_SPI_writeMessage(uint8_t command, uint8_t address, uint16_t data);
static void AD56x4_Reset(uint8_t ResetRequest);
static void AD56x4_Reference(uint8_t ReferenceRequest);

#define UART_ID uart1
#define BAUD_RATE 115200
#define UART_TX_PIN 8
#define UART_RX_PIN 9

int main()
{
    AD56x4_SPI_init();
    uarta_init();

    while (1)
    {

        uint16_t uarta = uart_getc(UART_ID);
        // AD56x4_Voltage_Control(150);
        // AD56x4_Current_Control(10000);
        bool data = uart_is_readable(UART_ID);
        printf(data);
        sleep_ms(500);
    }
}

void uarta_init(void)
{
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    uart_is_readable(UART_ID);
}
/* Initial function */
void AD56x4_SPI_init(void)
{
    // Initialize CS pin high
    gpio_init(AD56x4_SPI_CS_PIN);
    gpio_set_dir(AD56x4_SPI_CS_PIN, GPIO_OUT);
    gpio_put(AD56x4_SPI_CS_PIN, 1);

    // Initialize SPI port at 12 MHz
    spi_init(AD56x4_SPI_GROUP, AD56x4_SPI_BAUDRATE_12MHZ);

    // Set SPI format
    spi_set_format(AD56x4_SPI_GROUP, AD56x4_SPI_TRANSFER_8BIT, AD56x4_SPI_POLARITY, AD56x4_SPI_PHASE, SPI_MSB_FIRST);

    // Initialize SPI pins
    gpio_set_function(AD56x4_SPI_SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(AD56x4_SPI_MOSI_PIN, GPIO_FUNC_SPI);
    gpio_set_function(AD56x4_SPI_MISO_PIN, GPIO_FUNC_SPI);

    AD56x4_Reset(AD56x4_RESET_REQUEST);

    AD56x4_Reference(AD56x4_REFERENCE_ON_REQUEST);

    return;
}

/**********************************************************************************************************/
/* Target_Current : 0 ~ 500 (Decimal)                                                                     */
/* physical : 0.00[V] ~ 5.00[V]                                                                           */
/**********************************************************************************************************/
void AD56x4_Voltage_Control(uint16_t Target_Voltage)
{
    uint16_t OutputValue;

    if (Target_Voltage > AD56x4_VOLTAGE_CTRL_MAX)
    {
        Target_Voltage = AD56x4_VOLTAGE_CTRL_MAX;
    }
    if (Target_Voltage <= AD56x4_VOLTAGE_CTRL_MIN)
    {
        Target_Voltage = AD56x4_VOLTAGE_CTRL_MIN;
    }

    OutputValue = (uint16_t)((uint32_t)Target_Voltage * AD56x4_RESOUTION / AD56x4_REFERENCE_VOLTAGE / 2);

    if (OutputValue > AD56x4_RESOUTION)
    {
        OutputValue = AD56x4_RESOUTION;
    }

    AD56x4_SPI_writeMessage(AD56x4_COMMAND_WRITE_UPDATE_DAC_CHANNEL, AD56x4_ADDRESS_DAC_B, OutputValue);

    return;
}

/**********************************************************************************************************/
/* Target_Current : 0 ~ 50000 (Decimal)                                                                   */
/* physical : 0.00[mA] ~ 500.00[mA]                                                                       */
/**********************************************************************************************************/
void AD56x4_Current_Control(uint16_t Target_Current)
{
    uint16_t OutputValue;

    if (Target_Current > AD56x4_CURRENT_CTRL_MAX)
    {
        Target_Current = AD56x4_CURRENT_CTRL_MAX;
    }
    if (Target_Current <= AD56x4_CURRENT_CTRL_MIN)
    {
        Target_Current = AD56x4_CURRENT_CTRL_MIN;
    }

    OutputValue = (uint16_t)((uint32_t)Target_Current * AD56x4_RESOUTION / AD56x4_REFERENCE_VOLTAGE / 2 / 100);

    if (OutputValue > AD56x4_RESOUTION)
    {
        OutputValue = AD56x4_RESOUTION;
    }

    AD56x4_SPI_writeMessage(AD56x4_COMMAND_WRITE_UPDATE_DAC_CHANNEL, AD56x4_ADDRESS_DAC_A, OutputValue);

    return;
}

static void AD56x4_Reset(uint8_t ResetRequest)
{
    AD56x4_SPI_writeMessage(AD56x4_COMMAND_RESET, 0, (uint16_t)ResetRequest);
    return;
}

static void AD56x4_Reference(uint8_t ReferenceRequest)
{
    AD56x4_SPI_writeMessage(AD56x4_COMMAND_REFERENCE_SETUP, 0, (uint16_t)ReferenceRequest);
    return;
}

static void AD56x4_SPI_writeMessage(uint8_t command, uint8_t address, uint16_t data)
{
    uint8_t outputdata;

    gpio_put(AD56x4_SPI_CS_PIN, AD56x4_SPI_START);

    outputdata = (uint8_t)(((command & 0x07) << 3) | (address & 0x07));
    spi_write_blocking(AD56x4_SPI_GROUP, &outputdata, 1); // transfer command and address
    outputdata = (uint8_t)((data & 0xFF00) >> 8);
    spi_write_blocking(AD56x4_SPI_GROUP, &outputdata, 1); // transfer data MSB 8bit
    outputdata = (uint8_t)(data & 0x00FF);
    spi_write_blocking(AD56x4_SPI_GROUP, &outputdata, 1); // transfer data LSB 8bit

    gpio_put(AD56x4_SPI_CS_PIN, AD56x4_SPI_STOP);

    return;
}