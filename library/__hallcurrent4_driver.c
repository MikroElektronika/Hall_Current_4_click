/*
    __hallcurrent4_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__hallcurrent4_driver.h"
#include "__hallcurrent4_hal.c"

/* ------------------------------------------------------------------- MACROS */

const uint8_t _HALLCURRENT4_DEVICE_SLAVE_ADDRESS = 0x4D;

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __HALLCURRENT4_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __HALLCURRENT4_DRV_SPI__

void hallcurrent4_spiDriverInit(T_HALLCURRENT4_P gpioObj, T_HALLCURRENT4_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __HALLCURRENT4_DRV_I2C__

void hallcurrent4_i2cDriverInit(T_HALLCURRENT4_P gpioObj, T_HALLCURRENT4_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __HALLCURRENT4_DRV_UART__

void hallcurrent4_uartDriverInit(T_HALLCURRENT4_P gpioObj, T_HALLCURRENT4_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

uint16_t hallcurrent4_readData()
{
    uint8_t command;
    uint8_t readReg[ 2 ];
    uint16_t rData;
    
    command = 0x00;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, &command, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readReg, 2, END_MODE_STOP);
    
    rData = readReg[ 0 ];
    rData <<= 8;
    rData |= readReg[ 1 ];
    rData = rData & 0x0FFF;
    
    return rData;
}

float hallcurrent4_getCurrent()
{
    float current;
    float voltage;
    uint16_t sensorValue;
    uint8_t _polarity = 1;

    sensorValue = hallcurrent4_readData();

    if(sensorValue < 1869)
    {
        sensorValue = 1869 - sensorValue;
        _polarity = 1;
    }
    else
    {
        sensorValue -= 1869;
        _polarity = 0;
    }
    
    voltage = (sensorValue / 4095.0) * 3350; // Vref 3V3
    current  = (voltage / 200) * 1000;  // Sensitivity 200mV/A
    
    if(_polarity == 1)
    {
        current = - current;
    }
    return current;
}

/* -------------------------------------------------------------------------- */
/*
  __hallcurrent4_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */