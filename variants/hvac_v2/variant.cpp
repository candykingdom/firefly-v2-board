/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * + Pin number + Gemma Board pin  |  PIN   | Label/Name      | Comments (* is
 * for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Digital Low      |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 0          | D0               |  PA04  | D0/A2/SDA/TX    | EIC/EXTINT[4]
 * ADC/AIN[4]  AC/AIN[0] PTC/Y[2]  SERCOM0/PAD[0]                  *TCC0/WO[0]
 * | 1          | D1               |  PA02  | D1/A0/VOUT      | EIC/EXTINT[2]
 * ADC/AIN[0] *DAC/VOUT  PTC/Y[0] | 2          | D2               |  PA05  |
 * D2/A1/SCL/RX    | EIC/EXTINT[5]  ADC/AIN[5]  AC/AIN[1] PTC/Y[5]
 * SERCOM0/PAD[1]                  *TCC0/WO[1] | 3          | Dotstar Data     |
 * PA00  |                 | | 4          | DotStar Clock    |  PA01  | |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | USB              |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 5          |                  |  PA28  | USB_HOST_ENABLE | EIC/EXTINT[8]
 * | 6          |                  |  PA24  | USB_NEGATIVE    | *USB/DM
 * | 7          |                  |  PA25  | USB_POSITIVE    | *USB/DP
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Analog Pins      |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 8          | A0               |  PA02  | D1/A0/VOUT      | EIC/EXTINT[2]
 * *ADC/AIN[0]  DAC/VOUT  PTC/Y[0] | 9          | A1               |  PA05  |
 * D2/A1/SCL/RX    | EIC/EXTINT[5] *ADC/AIN[5]  AC/AIN[1] PTC/Y[5]
 * SERCOM0/PAD[1]                  TCC0/WO[1] | 10         | A2               |
 * PA04  | D0/A2/SDA/TX    | EIC/EXTINT[4] *ADC/AIN[4]  AC/AIN[0] PTC/Y[2]
 * SERCOM0/PAD[0]                  TCC0/WO[0]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | SWD              |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 11         |                  |  PA30  | SWD Clock       |
 * | 12         |                  |  PA31  | SWD Data        |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Digital High     |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 13         | 13               |  PA23  | LED             | EIC/EXTINT[7]
 * PTC/X[11] *SERCOM3/PAD[1] SERCOM5/PAD[1] TC4/WO[1] TCC0/WO[5] | 14         |
 * 14               |  PA10  | RXLED           | EIC/EXTINT[10] ADC/AIN[18]
 * PTC/X[2] *SERCOM0/PAD[2]                  TCC0/WO[2]  TCC1/WO[0] | 15 | 15 |
 * PA11  | TXLED           | EIC/EXTINT[11] ADC/AIN[19]           PTC/X[3]
 * *SERCOM0/PAD[3]  SERCOM2/PAD[3]  TCC0/WO[3]  TCC1/WO[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */

#include "variant.h"

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[] = {
    // 0: USB-D-
    {PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM,
     NOT_ON_TIMER, EXTERNAL_INT_NONE}, // USB/DM - GPIO #6

    // 1: USB-D+
    {PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM,
     NOT_ON_TIMER, EXTERNAL_INT_NONE}, // USB/DP - GPIO #7

    // 2: Neopixel control
    {PORTA, 7, PIO_DIGITAL, (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM,
     NOT_ON_TIMER, EXTERNAL_INT_NONE},

    // 3: Analog in VBATT voltage divider
    {PORTA, 4, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM,
     NOT_ON_TIMER, EXTERNAL_INT_NONE},

    // 4: Analog in MODE control
    {PORTA, 5, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM,
     NOT_ON_TIMER, EXTERNAL_INT_NONE},

    // 5: Analog in SPEED control
    {PORTA, 6, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM,
     NOT_ON_TIMER, EXTERNAL_INT_NONE},

    // 6: FAN signal
    {PORTA, 8, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER,
     EXTERNAL_INT_NONE},

    // 7: PUMP signal
    {PORTA, 9, PIO_DIGITAL, (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER,
     EXTERNAL_INT_NONE},

    // 8: Fan PWM
    {PORTA, 10, PIO_PWM, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM1_CH0, NOT_ON_TIMER, EXTERNAL_INT_10},

    // 9: NAP button
    {PORTA, 11, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER,
     EXTERNAL_INT_NONE},

    // 10: AUX button
    {PORTA, 14, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER,
     EXTERNAL_INT_NONE},

    // 11: Internal TEMP
    {PORTA, 15, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER,
     EXTERNAL_INT_NONE},

    // 12: External TEMP
    {PORTA, 16, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER,
     EXTERNAL_INT_NONE},

    // 13: Float switch
    {PORTA, 17, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER,
     EXTERNAL_INT_NONE},
};

const void *g_apTCInstances[TCC_INST_NUM + TC_INST_NUM] = {TCC0, TCC1, TCC2,
                                                           TC3,  TC4,  TC5};

// Multi-serial objects instantiation
SERCOM sercom0(SERCOM0);
SERCOM sercom1(SERCOM1);
SERCOM sercom2(SERCOM2);
SERCOM sercom3(SERCOM3);

// Uart Serial1( &sercom0, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX,
// PAD_SERIAL1_TX ) ;

/*void SERCOM0_Handler()
{
  Serial1.IrqHandler();
}*/
