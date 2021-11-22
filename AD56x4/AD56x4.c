#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/gpio.h"
#include "AD56x4.h"

static void AD56x4_SPI_writeMessage(uint8_t command, uint8_t address, uint16_t data);
static void AD56x4_Reset(uint8_t ResetRequest);
static void AD56x4_Reference(uint8_t ReferenceRequest);

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
    spi_set_format(AD56x4_SPI_GROUP, AD56x4_SPI_TRANSFER_16BIT, AD56x4_SPI_POLARITY, AD56x4_SPI_PHASE, SPI_MSB_FIRST);

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

    OutputValue = (uint16_t)((uint32_t)(Target_Current * AD56x4_RESOUTION / AD56x4_REFERENCE_VOLTAGE / 2 / 100));

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
    uint16_t outputdata;

    gpio_put(AD56x4_SPI_CS_PIN, AD56x4_SPI_START);

    outputdata = (command & 0x38) | (address & 0x07);
    spi_write_blocking(AD56x4_SPI_GROUP, &outputdata, 1);
    outputdata = data;
    spi_write_blocking(AD56x4_SPI_GROUP, &outputdata, 1);

    gpio_put(AD56x4_SPI_CS_PIN, AD56x4_SPI_STOP);

    return;
}