#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "AD56x4.h"

AD56X4Class AD56X4;

/* Commands the AD564X DAC whose Slave Select pin is SS_pin to
   set the values of the specified channel/s. The values are word
   with the 12/14/16-bit values the channels should be set at (last
   4 and 2 bits are ignored for 12-bit and 14-bit DACs). Either
   one channel can be set (or all channels set to the same value)
   with a channel byte that must be one of
   
   AD56X4_CHANNEL_A
   AD56X4_CHANNEL_B
   AD56X4_CHANNEL_C
   AD56X4_CHANNEL_D
   AD56X4_CHANNEL_ALL
   
   or separate values (as an array in D to A order or as four
   separate arguments) be set to each one. There are three ways
   they can be set, or set modes. They are
   
   AD56X4_SETMODE_INPUT          Set the channel/s's input register.
   AD56X4_SETMODE_INPUT_DAC      Set both the input and DAC
                                   registers for the channel/s.
   AD56X4_SETMODE_INPUT_DAC_ALL  Set channel/s's input register and
                                   then update all DAC registers
                                   from the input registers.
*/
void AD56X4Class::setChannel(int SS_pin, byte setMode, byte channel,
                             word value)
{
    // Don't do anything if we weren't given a valid setMode.
    if (setMode == AD56X4_SETMODE_INPUT || setMode == AD56X4_SETMODE_INPUT_DAC || setMode == AD56X4_SETMODE_INPUT_DAC_ALL)
        AD56X4.writeMessage(SS_pin, setMode, channel, value);
}
void AD56X4Class::setChannel(int SS_pin, byte setMode, word values[])
{
    // Don't do anything if we weren't given a valid setMode.
    if (setMode == AD56X4_SETMODE_INPUT || setMode == AD56X4_SETMODE_INPUT_DAC || setMode == AD56X4_SETMODE_INPUT_DAC_ALL)
    {
        // It luckily turns out that channels A through D are numbers
        // 0 through 3, which we will exploit in the for loop.
        for (int i = 3; i >= 0; i--)
            AD56X4.writeMessage(SS_pin, setMode, i, values[3 - i]);
    }
}
void AD56X4Class::setChannel(int SS_pin, byte setMode, word value_D,
                             word value_C, word value_B, word value_A)
{
    word values[] = {value_D, value_C, value_B, value_A};
    AD56X4.setChannel(SS_pin, setMode, values);
}

/* Commands the AD564X DAC whose Slave Select pin is SS_pin to
   update the output (DAC register) of the specified channel from
   its buffer (input register). The valid channel choices are
   
   AD56X4_CHANNEL_A
   AD56X4_CHANNEL_B
   AD56X4_CHANNEL_C
   AD56X4_CHANNEL_D
   AD56X4_CHANNEL_ALL
*/
void AD56X4Class::updateChannel(int SS_pin, byte channel)
{
    AD56X4.writeMessage(SS_pin, AD56X4_COMMAND_UPDATE_DAC_REGISTER,
                        channel, 0);
}

/* Commands the AD564X DAC whose Slave Select pin is SS_pin to set
   the given power mode for the specified channels. The power modes
   are
   
   AD56X4_POWERMODE_NORMAL             normal operation (power up)
   AD56X4_POWERMODE_POWERDOWN_1K       connected to ground by 1k
   AD56X4_POWERMODE_POWERDOWN_100K     connected to ground by 100k
   AD56X4_POWERMODE_POWERDOWN_TRISTATE power down in tristate.
   
   A power mode can be applied to a set of channels specified by
   a channel mask (bits 3 through 0 correspond to channels D
   through A), a boolean array (in channel D through A order), or
   four boolean arguments. Or, an array of power modes can be
   applied to each channel (in D through A order).
*/
void AD56X4Class::powerUpDown(int SS_pin, byte powerMode,
                              byte channelMask)
{
    AD56X4.writeMessage(SS_pin, AD56X4_COMMAND_POWER_UPDOWN, 0,
                        (word)((B00110000 & powerMode) | (B00001111 & channelMask)));
}
void AD56X4Class::powerUpDown(int SS_pin, byte powerMode,
                              boolean channels[])
{
    AD56X4.powerUpDown(SS_pin, powerMode,
                       AD56X4.makeChannelMask(channels));
}
void AD56X4Class::powerUpDown(int SS_pin, byte powerMode,
                              boolean channel_D, boolean channel_C,
                              boolean channel_B, boolean channel_A)
{
    AD56X4.powerUpDown(SS_pin, powerMode,
                       AD56X4.makeChannelMask(channel_D, channel_C,
                                              channel_B, channel_A));
}
void AD56X4Class::powerUpDown(int SS_pin, byte powerModes[])
{
    // Go through each channel making a mask for just that channel
    // and apply the given power mode.

    byte channelMask = 1;
    for (int i = 0; i < 4; i++)
    {
        AD56X4.powerUpDown(SS_pin, powerModes[i], channelMask);
        channelMask = channelMask << 1;
    }
}

/* Commands the AD56X4 DAC whose Slave Select pin is SS_pin to
   reset. The DAC (output) and input (buffer) registers are set
   to zero, and if doing a full reset, the channels are all
   powered up, the external reference is used (internal turned off
   if present), and all channels set so that writing to the input
   register does not auto update the DAC register (output).
*/
void AD56X4Class::reset(int SS_pin, boolean fullReset)
{
    AD56X4.writeMessage(SS_pin, AD56X4_COMMAND_RESET, 0, (word)fullReset);
}

/* Commands the AD564X DAC whose Slave Select pin is SS_pin which
   channels are to have their DAC register (output) updated
   immediately when the input register (buffer) is set. True is
   for auto update and false is for not. It can either be given
   as a channel mask (bits 3 through 0 correspond to channels D
   through A), a boolean array (in channel D through A order), or
   four boolean arguments.
*/
void AD56X4Class::setInputMode(int SS_pin, byte channelMask)
{
    AD56X4.writeMessage(SS_pin, AD56X4_COMMAND_SET_LDAC, 0,
                        (word)channelMask);
}
void AD56X4Class::setInputMode(int SS_pin, boolean channels[])
{
    AD56X4.setInputMode(SS_pin, AD56X4.makeChannelMask(channels));
}
void AD56X4Class::setInputMode(int SS_pin, boolean channel_D,
                               boolean channel_C, boolean channel_B,
                               boolean channel_A)
{
    AD56X4.setInputMode(SS_pin,
                        AD56X4.makeChannelMask(channel_D, channel_C,
                                               channel_B, channel_A));
}

/* Commands the AD564X DAC whose Slave Select pin is SS_pin whether
   to use the internal voltage reference or not (use external).
   Should only be used with chips having an internal reference,
   which are the ones whose name ends in an R.
*/
void AD56X4Class::useInternalReference(int SS_pin, boolean yesno)
{
    AD56X4.writeMessage(SS_pin, AD56X4_COMMAND_REFERENCE_ONOFF, 0,
                        (word)yesno);
}

/* Create channel masks (word with bits 3 through 0 corresponding
   to channels D through A) from an array of booleans for each
   channel (D to A order) or from 4 argument booleans, one for each
   channel.
*/
word AD56X4Class::makeChannelMask(boolean channels[])
{
    return (word)((byte(channels[0]) << 3) | (byte(channels[1]) << 2) | (byte(channels[2]) << 1) | byte(channels[3]));
}
word AD56X4Class::makeChannelMask(boolean channel_D,
                                  boolean channel_C,
                                  boolean channel_B,
                                  boolean channel_A)
{
    return (word)((byte(channel_D) << 3) | (byte(channel_C) << 2) | (byte(channel_B) << 1) | byte(channel_A));
}

/* Writes a 24 bit message to the AD56X4 DAC whose Slave Select
   pin is SS_pin. The message is composed of a command instructing
   the chip what to do, an address telling it which channel/s to
   operate on, and a 2-byte unsigned integer data which could be
   the value to set a channel register to or other control data for
   other commands.
*/
void AD56X4Class::writeMessage(int SS_pin, byte command,
                               byte address, word data)
{

    // Set the SPI mode to SPI_MODE1 and the bit order to MSB first.

    SPI.setDataMode(SPI_MODE1);
    SPI.setBitOrder(MSBFIRST);

    // The clock speed doesn't matter too much as the chip can go up
    // to 50 MHz while the arduino can only go up 8 MHz, so we will
    // leave it.

    // Set the Slave Select pin to low so that the DAC knows to
    // listen for a command.

    digitalWrite(SS_pin, LOW);

    // The first byte is composed of two bits of nothing, then
    // the command bits, and then the address bits. Masks are
    // used for each set of bits and then the fields are OR'ed
    // together.

    SPI.transfer((command & B00111000) | (address & B00000111));

    // Send the data word. Must be sent byte by byte, MSB first.

    SPI.transfer(highByte(data));
    SPI.transfer(lowByte(data));

    // Set the Slave Select pin back to high since we are done
    // sending the command.

    digitalWrite(SS_pin, HIGH);
}