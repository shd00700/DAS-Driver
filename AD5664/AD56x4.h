#ifndef AD56x4_h
#define AD56x4_h

#include <stdio.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "AD56x4.h"

/* For the various defined values, they are chosen so that they
   are exactly the values that need to be put into the SPI
   message. This makes it a lot easier to construct the message.
*/

#define AD56X4_COMMAND_WRITE_INPUT_REGISTER B00000000
#define AD56X4_COMMAND_UPDATE_DAC_REGISTER B00001000
#define AD56X4_COMMAND_WRITE_INPUT_REGISTER_UPDATE_ALL B00010000
#define AD56X4_COMMAND_WRITE_UPDATE_CHANNEL B00011000
#define AD56X4_COMMAND_POWER_UPDOWN B00100000
#define AD56X4_COMMAND_RESET B00101000
#define AD56X4_COMMAND_SET_LDAC B00110000
#define AD56X4_COMMAND_REFERENCE_ONOFF B00111000

#define AD56X4_CHANNEL_A B00000000
#define AD56X4_CHANNEL_B B00000001
#define AD56X4_CHANNEL_C B00000010
#define AD56X4_CHANNEL_D B00000011
#define AD56X4_CHANNEL_ALL B00000111

#define AD56X4_SETMODE_INPUT AD56X4_COMMAND_WRITE_INPUT_REGISTER
#define AD56X4_SETMODE_INPUT_DAC AD56X4_COMMAND_WRITE_UPDATE_CHANNEL
#define AD56X4_SETMODE_INPUT_DAC_ALL AD56X4_COMMAND_WRITE_INPUT_REGISTER_UPDATE_ALL

#define AD56X4_POWERMODE_NORMAL B00000000
#define AD56X4_POWERMODE_POWERDOWN_1K B00010000
#define AD56X4_POWERMODE_POWERDOWN_100K B00100000
#define AD56X4_POWERMODE_TRISTATE B00110000

class AD56X4Class
{

public:
    static void setChannel(int SS_pin, byte setMode, byte channel,
                           word value);
    static void setChannel(int SS_pin, byte setMode, word values[]);
    static void setChannel(int SS_pin, byte setMode, word value_D,
                           word value_C, word value_B, word value_A);

    static void updateChannel(int SS_pin, byte channel);

    static void powerUpDown(int SS_pin, byte powerMode,
                            boolean channels[]);
    static void powerUpDown(int SS_pin, byte powerMode,
                            boolean channel_D, boolean channel_C,
                            boolean channel_B, boolean channel_A);
    static void powerUpDown(int SS_pin, byte powerModes[]);

    static void reset(int SS_pin, boolean fullReset);

    static void setInputMode(int SS_pin, boolean channels[]);
    static void setInputMode(int SS_pin, boolean channel_D,
                             boolean channel_C, boolean channel_B,
                             boolean channel_A);

    static void useInternalReference(int SS_pin, boolean yesno);

private:
    inline static void powerUpDown(int SS_pin, byte powerMode,
                                   byte channelMask);

    inline static void setInputMode(int SS_pin, byte channelMask);

    static word makeChannelMask(boolean channels[]);
    static word makeChannelMask(boolean channel_D, boolean channel_C,
                                boolean channel_B, boolean channel_A);

    static void writeMessage(int SS_pin, byte command, byte address,
                             word data);
};

extern AD56X4Class AD56X4;

#endif