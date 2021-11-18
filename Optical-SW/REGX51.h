#ifndef __REGX51_H__
#define __REGX51_H__

sfr p0 = 0x80;
sfr SP = 0x81;
sfr DPL = 0x82;
sfr DPH = 0x83;
sfr PCON = 0x87;
sfr TCON = 0x88;
sfr TMOD = 0x89;
sfr TL0 = 0x8A;
sfr TL1 = 0x8B;
sfr TH0 = 0x8C;
sfr TH1 = 0x8D;
sfr p1 = 0x90;
sfr SCON = 0x98;
sfr SBUF = 0x99;
sfr p2 = 0xA0;
sfr IE = 0xA8;
sfr p3 = 0xB0;
sfr IP = 0xB8;
sfr PSW = 0xD0;
sfr ACC = 0xE0;
sfr B = 0xF0;

/*---------------
 p0 Ó‹Í»–ˆÌ–Ô
----------------*/
sbit p0_0 = 0x80;
sbit p0_1 = 0x81;
sbit p0_2 = 0x82;
sbit p0_3 = 0x83;
sbit p0_4 = 0x84;
sbit p0_5 = 0x85;
sbit p0_6 = 0x86;
sbit p0_7 = 0x87;
/*---------------
 p1 Ó‹Í»–ˆÌ–Ô
----------------*/
sbit p1_0 = 0x90;
sbit p1_1 = 0x91;
sbit p1_2 = 0x92;
sbit p1_3 = 0x93;
sbit p1_4 = 0x94;
sbit p1_5 = 0x95;
sbit p1_6 = 0x96;
sbit p1_7 = 0x97;
/*---------------
 p2 Ó‹Í»–ˆÌ–Ô
----------------*/
sbit p2_0 = 0xA0;
sbit p2_1 = 0xA1;
sbit p2_2 = 0xA2;
sbit p2_3 = 0xA3;
sbit p2_4 = 0xA4;
sbit p2_5 = 0xA5;
sbit p2_6 = 0xA6;
sbit p2_7 = 0xA7;
/*---------------
 p3 Ó‹Í»–ˆÌ–Ô
----------------*/
sbit p3_0 = 0xB0;
sbit p3_1 = 0xB1;
sbit p3_2 = 0xB2;
sbit p3_3 = 0xB3;
sbit p3_4 = 0xB4;
sbit p3_5 = 0xB5;
sbit p3_6 = 0xB6;
sbit p3_7 = 0xB7;
sbit RXD = 0xB0;
sbit TXD = 0xB1;
sbit INT0 = 0xB2;
sbit INT1 = 0xB3;
sbit T0 = 0xB4;
sbit T1 = 0xB5;
sbit WR = 0xB6;
sbit RD = 0xB7;
/*---------------
 PCON Ó‹Í»–ˆÌ–Ô
----------------*/
#define IDL_ 0x01
#define STOP_ 0x02
#define PD_ 0x02
#define GF0_ 0x04
#define GF1_ 0x08
#define SMOD_ 0x80
/*---------------
 TCON Ó‹Í»–ˆÌ–Ô
----------------*/
sbit IT0 = 0x88;
sbit IE0 = 0x89;
sbit IT1 = 0x8A;
sbit IE1 = 0x8B;
sbit TR0 = 0x8C;
sbit TF0 = 0x8D;
sbit TR1 = 0x8E;
sbit TF1 = 0x8F;
/*---------------
 TMOD Ó‹Í»–ˆÌ–Ô
----------------*/
#define T0_M0_ 0x01
#define T0_M1_ 0x02
#define T0_CT_ 0x04
#define T0_GATE_ 0x08
#define T1_M0_ 0x10
#define T1_M1_ 0x20
#define T1_CT_ 0x40
#define T1_GATE_ 0x80
#define T1_MASK_ 0xF0
#define T0_MASK_ 0x0F
/*---------------
 SCON Ó‹Í»–ˆÌ–Ô
----------------*/
sbit RI = 0x98;
sbit TI = 0x99;
sbit RB8 = 0x9A;
sbit TB8 = 0x9B;
sbit REN = 0x9C;
sbit SM2 = 0x9D;
sbit SM1 = 0x9E;
sbit SM0 = 0x9F;
/*---------------
 IE Ó‹Í»–ˆÌ–Ô
----------------*/
sbit EX0 = 0xA8;
sbit ET0 = 0xA9;
sbit EX1 = 0xAA;
sbit ET1 = 0xAB;
sbit ES = 0xAC;
sbit ET2 = 0xAD;
sbit EA = 0xAF;
/*---------------
 IP Ó‹Í»–ˆÌ–Ô
----------------*/
sbit PX0 = 0xB8;
sbit PT0 = 0xB9;
sbit PX1 = 0xBA;
sbit PT1 = 0xBB;
sbit PS = 0xBC;
sbit PT2 = 0xBD;
/*---------------
 PSW Ó‹Í»–ˆÌ–Ô
----------------*/
sbit P = 0xD0;
sbit FL = 0xD1;
sbit OV = 0xD2;
sbit RS0 = 0xD3;
sbit RS1 = 0xD4;
sbit F0 = 0xD5;
sbit AC = 0xD6;
sbit CY = 0xD7;
/*---------------
ÒÈ?˙æ’·
Interrupt Address =(Number*8)+3 
----------------*/
#define IE0_VECTOR 0 /* 0X03 External Interrupt 0 */
#define TF0_VECTOR 1 /* 0X0B Timer 0 */
#define IE1_VECTOR 2 /* 0X13 External Interrupt 1 */
#define TF1_VECTOR 3 /* 0X1B Timer 1 */
#define SI0_VECTOR 4 /* 0X23 Serial port */
/*---------------
----------------*/
