![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# HallCurrent4 Click

- **CIC Prefix**  : HALLCURRENT4
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : nov 2018.

---

### Software Support

We provide a library for the HallCurrent4 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2673/hallcurrent-4-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

This library provides basic functionality for reading the current value and controlling the click board.

Key functions :

- ``` float hallcurrent4_getCurrent() ``` - Reads current in mA
- ``` uint16_t hallcurrent4_readData() ``` - Reads current 12bit data

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Initializations driver init
- Application Task - (code snippet) - Reads Current value in mA and logs this data to USBUART every 1 sec.

```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2673/hallcurrent-4-click) page.

Other mikroE Libraries used in the example:

- I2C
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
