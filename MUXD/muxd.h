#include "pico.h"
#ifndef muxd_h
#define muxd_h

extern int _g_channel_truth_table[16][4];

void mux_channel(int channel);

#endif