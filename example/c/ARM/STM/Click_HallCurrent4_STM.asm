_systemInit:
;Click_HallCurrent4_STM.c,30 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_HallCurrent4_STM.c,32 :: 		mikrobus_i2cInit( _MIKROBUS1, &_HALLCURRENT4_I2C_CFG[0] );
MOVW	R0, #lo_addr(__HALLCURRENT4_I2C_CFG+0)
MOVT	R0, #hi_addr(__HALLCURRENT4_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_HallCurrent4_STM.c,33 :: 		mikrobus_logInit( _LOG_USBUART_A, 9600 );
MOVW	R1, #9600
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_HallCurrent4_STM.c,34 :: 		mikrobus_logWrite(" --- System Init --- ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_HallCurrent4_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_HallCurrent4_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_HallCurrent4_STM.c,35 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_HallCurrent4_STM.c,36 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_HallCurrent4_STM.c,38 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_HallCurrent4_STM.c,40 :: 		hallcurrent4_i2cDriverInit( (T_HALLCURRENT4_P)&_MIKROBUS1_GPIO, (T_HALLCURRENT4_P)&_MIKROBUS1_I2C, _HALLCURRENT4_DEVICE_SLAVE_ADDRESS );
MOVS	R2, __HALLCURRENT4_DEVICE_SLAVE_ADDRESS
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_hallcurrent4_i2cDriverInit+0
;Click_HallCurrent4_STM.c,41 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_HallCurrent4_STM.c,43 :: 		void applicationTask()
SUB	SP, SP, #60
STR	LR, [SP, #0]
;Click_HallCurrent4_STM.c,48 :: 		Current = hallcurrent4_getCurrent();
BL	_hallcurrent4_getCurrent+0
; Current start address is: 4 (R1)
MOV	R1, R0
;Click_HallCurrent4_STM.c,50 :: 		mikrobus_logWrite(" Current value: ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr2_Click_HallCurrent4_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_HallCurrent4_STM+0)
STR	R1, [SP, #4]
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_HallCurrent4_STM.c,51 :: 		FloatToStr(Current, demoText);
ADD	R0, SP, #8
MOV	R1, R0
LDR	R0, [SP, #4]
; Current end address is: 4 (R1)
BL	_FloatToStr+0
;Click_HallCurrent4_STM.c,52 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
ADD	R0, SP, #8
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_HallCurrent4_STM.c,53 :: 		mikrobus_logWrite(" mA", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr3_Click_HallCurrent4_STM+0)
MOVT	R0, #hi_addr(?lstr3_Click_HallCurrent4_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_HallCurrent4_STM.c,55 :: 		mikrobus_logWrite(" ------------------------- ", _LOG_LINE );
MOVW	R0, #lo_addr(?lstr4_Click_HallCurrent4_STM+0)
MOVT	R0, #hi_addr(?lstr4_Click_HallCurrent4_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_HallCurrent4_STM.c,56 :: 		Delay_ms( 1000 );
MOVW	R7, #6911
MOVT	R7, #183
NOP
NOP
L_applicationTask2:
SUBS	R7, R7, #1
BNE	L_applicationTask2
NOP
NOP
NOP
;Click_HallCurrent4_STM.c,57 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #60
BX	LR
; end of _applicationTask
_main:
;Click_HallCurrent4_STM.c,59 :: 		void main()
;Click_HallCurrent4_STM.c,61 :: 		systemInit();
BL	_systemInit+0
;Click_HallCurrent4_STM.c,62 :: 		applicationInit();
BL	_applicationInit+0
;Click_HallCurrent4_STM.c,64 :: 		while (1)
L_main4:
;Click_HallCurrent4_STM.c,66 :: 		applicationTask();
BL	_applicationTask+0
;Click_HallCurrent4_STM.c,67 :: 		}
IT	AL
BAL	L_main4
;Click_HallCurrent4_STM.c,68 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
