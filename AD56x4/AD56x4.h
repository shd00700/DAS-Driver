#include "pico.h"
#include "hardware/spi.h"
#include "hardware/gpio.h"
/********************** SPI Configuration **********************/
#define AD56x4_SPI_GROUP (spi0)

#define AD56x4_SPI_BAUDRATE_48MHZ (48000000)
#define AD56x4_SPI_BAUDRATE_36MHZ (36000000)
#define AD56x4_SPI_BAUDRATE_24MHZ (24000000)
#define AD56x4_SPI_BAUDRATE_12MHZ (12000000)

#define AD56x4_SPI_CS_PIN (21)
#define AD56x4_SPI_SCK_PIN (22)
#define AD56x4_SPI_MOSI_PIN (20)
#define AD56x4_SPI_MISO_PIN (23)

#define AD56x4_SPI_TRANSFER_8BIT (8)
#define AD56x4_SPI_TRANSFER_16BIT (16)
#define AD56x4_SPI_POLARITY (0)
#define AD56x4_SPI_PHASE (1)

#define AD56x4_SPI_START (0)
#define AD56x4_SPI_STOP (1)
/**************************************************************/
/********************** AD56x4 COMMAND **********************/
#define AD56x4_COMMAND_WRITE_REGISTER (0)
#define AD56x4_COMMAND_UPDATE_DAC_REGISTER (1)
#define AD56x4_COMMAND_WRITE_REGISTER_ALL (2)
#define AD56x4_COMMAND_WRITE_UPDATE_DAC_CHANNEL (3)
#define AD56x4_COMMAND_POWER_DOWN_DAC (4)
#define AD56x4_COMMAND_RESET (5)
#define AD56x4_COMMAND_LDAC_SETUP_REGISTER (6)
#define AD56x4_COMMAND_REFERENCE_SETUP (7)
/************************************************************/
/********************** AD56x4 ADDRESS **********************/
#define AD56x4_ADDRESS_DAC_A (0)
#define AD56x4_ADDRESS_DAC_B (1)
#define AD56x4_ADDRESS_DAC_C (2)
#define AD56x4_ADDRESS_DAC_D (3)
#define AD56x4_ADDRESS_DAC_ALL (7)
/************************************************************/
#define AD56x4_REFERENCE_VOLTAGE (250)
#define AD56x4_RESOUTION (65535)
#define AD56x4_VOLTAGE_CTRL_MAX (500)
#define AD56x4_VOLTAGE_CTRL_MIN (0)
/************************************************************/
#define AD56x4_CURRENT_CTRL_MAX (50000)
#define AD56x4_CURRENT_CTRL_MIN (0)

#define AD56x4_RESET_REQUEST (1)
#define AD56x4_REFERENCE_ON_REQUEST (1)

extern void AD56x4_SPI_init(void);
extern void AD56x4_Voltage_Control(uint16_t Target_Voltage);
extern void AD56x4_Current_Control(uint16_t Target_Current);