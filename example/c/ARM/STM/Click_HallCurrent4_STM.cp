#line 1 "D:/Clicks_git/H/Hall_Current_4_Click/SW/example/c/ARM/STM/Click_HallCurrent4_STM.c"
#line 1 "d:/clicks_git/h/hall_current_4_click/sw/example/c/arm/stm/click_hallcurrent4_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/h/hall_current_4_click/sw/example/c/arm/stm/click_hallcurrent4_config.h"
#line 1 "d:/clicks_git/h/hall_current_4_click/sw/example/c/arm/stm/click_hallcurrent4_types.h"
#line 19 "d:/clicks_git/h/hall_current_4_click/sw/example/c/arm/stm/click_hallcurrent4_config.h"
const uint32_t _HALLCURRENT4_I2C_CFG[ 1 ] =
{
 100000
};
#line 28 "D:/Clicks_git/H/Hall_Current_4_Click/SW/example/c/ARM/STM/Click_HallCurrent4_STM.c"
void systemInit()
{
 mikrobus_i2cInit( _MIKROBUS1, &_HALLCURRENT4_I2C_CFG[0] );
 mikrobus_logInit( _LOG_USBUART_A, 9600 );
 mikrobus_logWrite(" --- System Init --- ", _LOG_LINE);
 Delay_ms( 100 );
}

void applicationInit()
{
 hallcurrent4_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, _HALLCURRENT4_DEVICE_SLAVE_ADDRESS );
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
