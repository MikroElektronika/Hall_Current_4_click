/*
Example for HallCurrent4 Click

    Date          : nov 2018.
    Author        : Katarina Perendic

Test configuration FT90x :
    
    MCU                : FT900
    Dev. Board         : EasyFT90x v7 
    FT90x Compiler ver : v2.3.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Initializations driver init
- Application Task - (code snippet) - Reads Current value in mA and logs this data to USBUART every 1 sec.

*/

#include "Click_HallCurrent4_types.h"
#include "Click_HallCurrent4_config.h"

void systemInit()
{
    mikrobus_i2cInit( _MIKROBUS1, &_HALLCURRENT4_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART, 9600 );
    mikrobus_logWrite(" --- System Init --- ", _LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
    hallcurrent4_i2cDriverInit( (T_HALLCURRENT4_P)&_MIKROBUS1_GPIO, (T_HALLCURRENT4_P)&_MIKROBUS1_I2C, _HALLCURRENT4_DEVICE_SLAVE_ADDRESS );
}

void applicationTask()
{
    char demoText[ 50 ];
    float Current;

    Current = hallcurrent4_getCurrent();

    mikrobus_logWrite(" Current value: ", _LOG_TEXT);
    FloatToStr(Current, demoText);
    mikrobus_logWrite(demoText, _LOG_TEXT);
    mikrobus_logWrite(" mA", _LOG_LINE);
    
    mikrobus_logWrite(" ------------------------- ", _LOG_LINE );
    Delay_ms( 1000 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}