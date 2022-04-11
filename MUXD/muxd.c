#include "pico/stdlib.h"
#include "muxd.h"

int _g_channel_truth_table[16][4] = {
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

void mux_channel(int channel)
{
    // mux A
    HAL_GPIO_WritePin(GPIOC, MUXA_S0_Pin, _g_channel_truth_table[channel][0]);
    HAL_GPIO_WritePin(GPIOC, MUXA_S1_Pin, _g_channel_truth_table[channel][1]);
    HAL_GPIO_WritePin(GPIOC, MUXA_S2_Pin, _g_channel_truth_table[channel][2]);
    HAL_GPIO_WritePin(GPIOC, MUXA_S3_Pin, _g_channel_truth_table[channel][3]);
    // mux B
    HAL_GPIO_WritePin(GPIOC, MUXB_S0_Pin, _g_channel_truth_table[channel][0]);
    HAL_GPIO_WritePin(GPIOC, MUXB_S1_Pin, _g_channel_truth_table[channel][1]);
    HAL_GPIO_WritePin(GPIOC, MUXB_S2_Pin, _g_channel_truth_table[channel][2]);
    HAL_GPIO_WritePin(GPIOC, MUXB_S3_Pin, _g_channel_truth_table[channel][3]);
    HAL_Delay(1);
}