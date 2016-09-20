/***********************************************************************************************************************
 * C Header: cmu-derivative.h
 * Component: CMU
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

// Include guard
#ifndef __CMU_DERIVATIVE_INTERFACE__
#define __CMU_DERIVATIVE_INTERFACE__

// Include component configuration file
#include "cmu-configuration.h"


 /**********************************************************************************************************************
 * Class: Clock Management Unit
 **********************************************************************************************************************/
 /**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/



 /**********************************************************************************************************************
 * Private typedefs
 **********************************************************************************************************************/



 /**********************************************************************************************************************
 * Private object-like macros
 **********************************************************************************************************************/
#define __cmu_ctrl					cmu_selfData._ctrl
#define __cmu_hfcoreclken0  		cmu_selfData._hfcoreclken0
#define __cmu_hfperclkdiv			cmu_selfData._hfperclkdiv
#define __cmu_oscencmd				cmu_selfData._oscencmd
#define __cmu_cmd					cmu_selfData._cmd
#define __cmu_status				cmu_selfData._status
#define __cmu_hfperclken0			cmu_selfData._hfperclken0
#define __cmu_lock 					cmu_selfData._lock
 /**********************************************************************************************************************
 * Private function-like macros that DO return value
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private function-like macros that DO NOT return value
 **********************************************************************************************************************/
#define __cmu_setHighPeripheralClockDevider(mask, value)			do{ __cmu_setProperty(__cmu_hfperclkdiv, mask, value); 		}while(0)
/**********************************************************************************************************************
* Public typedefs, that DO NOT depend on EXTERNAL declarations
**********************************************************************************************************************/
typedef struct
{
	volatile uint32_t _ctrl; 			// CMU Control Register
	volatile uint32_t _hfcoreclkdiv; 	// High Frequency Core Clock Division Register
	volatile uint32_t _hfperclkdiv; 	// High Frequency Peripheral Clock Division Register
	volatile uint32_t _hfrcoctrl; 		// HFRCO Control Register
	volatile uint32_t _lfrcoctrl; 		// LFRCO Control Register
	volatile uint32_t _auxhfrcoctrl; 	// AUXHFRCO Control Register
	volatile uint32_t _calctrl; 		// Calibration Control Register
	volatile uint32_t _calcnt; 			// Calibration Counter Register
	volatile uint32_t _oscencmd; 		// Oscillator Enable/Disable Command Register
	volatile uint32_t _cmd; 			// Command Register
	volatile uint32_t _lfclksel; 		// Low Frequency Clock Select Register
	volatile uint32_t _status; 			// Status Register
	volatile uint32_t _if; 				// Interrupt Flag Register
	volatile uint32_t _ifs; 			// Interrupt Flag Set Register
	volatile uint32_t _ifc; 			// Interrupt Flag Clear Register
	volatile uint32_t _ien; 			// Interrupt Enable Register
	volatile uint32_t _hfcoreclken0;	// High Frequency Core Clock Enable Register 0
	volatile uint32_t _hfperclken0; 	// High Frequency Peripheral Clock Enable Register 0
			 uint32_t _reserved0[2]; 	// Reserved for future use **/
	volatile uint32_t _syncbusy; 		// Synchronization Busy Register
	volatile uint32_t _freeze; 			// Freeze Register
	volatile uint32_t _lfaclken0; 		// Low Frequency A Clock Enable Register 0 (Async Reg)
			 uint32_t _reserved1[1]; 	// Reserved for future use **/
	volatile uint32_t _lfbclken0; 		// Low Frequency B Clock Enable Register 0 (Async Reg)
	 	 	 uint32_t _reserved2[1]; 	// Reserved for future use **/
	volatile uint32_t _lfapresc0; 		// Low Frequency A Prescaler Register 0 (Async Reg)
			 uint32_t _reserved3[1]; 	// Reserved for future use **/
	volatile uint32_t _lfbpresc0; 		// Low Frequency B Prescaler Register 0 (Async Reg)
			 uint32_t _reserved4[1]; 	// Reserved for future use **/
	volatile uint32_t _pcntctrl; 		// PCNT Control Register
	volatile uint32_t _lcdctrl;			// LCD Control Register
	volatile uint32_t _route; 			// I/O Routing Register
	volatile uint32_t _lock; 			// Configuration Lock Register
}cmu_SelfData;


// Public object-like macros that DO NOT depend on EXTERNAL declarations

/**********************************************************************************************************************
* Public function-like macros that DO return value and DO NOT depend on EXTERNAL declarations
**********************************************************************************************************************/
	// CTRL_HFXOBUFCUR
#define cmu_getHfxobufcurMask()						( __cmu_getBitMask(6,5) )
#define cmu_getHfxobufcur()							( __cmu_ctrl & cmu_getHfxobufcurMask() )
#define cmu_getHfxobufcurBoostupto32mhz()			( __cmu_getPropertyValue(1,5) )
#define cmu_getHfxobufcurBoostabove32mhz()			( __cmu_getPropertyValue(3,5) )

#define cmu_getEnableDmaClockMask()					( __cmu_getBitMask(0, 0) )

	// HFPERCLKDIV_HFPERCLKEN
#define cmu_getHfperclkenValue()					( __cmu_getPropertyValue(1, 8) )
#define cmu_isHfperclkenRaised()					( __cmu_hfperclkdiv & cmu_getHfperclkenValue() )
	// HFPERCLKDIV_HFPERCLKDIV
#define cmu_getHighPeripheralClockDeviderMask()			( __cmu_getBitMask(3, 0) )
#define cmu_getHighPeripheralClockDevider()				( __cmu_hfperclkdiv & cmu_getHighPeripheralClockDeviderMask() )
#define cmu_getHighPeripheralClockDevider1Value()		( __cmu_getPropertyValue(0, 0) )
#define cmu_getHighPeripheralClockDevider2Value()		( __cmu_getPropertyValue(1, 0) )
#define cmu_getHighPeripheralClockDevider4Value()		( __cmu_getPropertyValue(2, 0) )
#define cmu_getHighPeripheralClockDevider8Value()       ( __cmu_getPropertyValue(3, 0) )
#define cmu_getHighPeripheralClockDevider16Value()      ( __cmu_getPropertyValue(4, 0) )
#define cmu_getHighPeripheralClockDevider32Value()      ( __cmu_getPropertyValue(5, 0) )
#define cmu_getHighPeripheralClockDevider64Value()      ( __cmu_getPropertyValue(6, 0) )
#define cmu_getHighPeripheralClockDevider128Value()     ( __cmu_getPropertyValue(7, 0) )
#define cmu_getHighPeripheralClockDevider256Value()     ( __cmu_getPropertyValue(8, 0) )
#define cmu_getHighPeripheralClockDevider512Value()     ( __cmu_getPropertyValue(9, 0) )


	// OSCENCMD(W1)
#define cmu_getHfxodisAssert()						( __cmu_getPropertyValue(1,3) )
#define cmu_getHfxoenAssert()						( __cmu_getPropertyValue(1,2) )
#define cmu_getHfrcodisAssert()						( __cmu_getPropertyValue(1,1) )
#define cmu_getHfrcoenAssert()						( __cmu_getPropertyValue(1,0) )
	// CMD_HFCLKSEL
#define cmu_getHfclkselMask()						( __cmu_getBitMask(2,0) )
#define cmu_getHfclksel()							( __cmu_cmd & cmu_getHfclkselMask() )
#define cmu_getHfclkselHfrco()						( __cmu_getPropertyValue(1,0) )
#define cmu_getHfclkselHfxo()						( __cmu_getPropertyValue(2,0) )
#define cmu_getHfclkselLfrco()						( __cmu_getPropertyValue(3,0) )
#define cmu_getHfclkselLfxo()						( __cmu_getPropertyValue(4,0) )
	// STATUS(R)
#define cmu_getHfxoselValue()						( __cmu_getPropertyValue(1, 11) )
#define cmu_isHfxoselRaised()						( __cmu_status & cmu_getHfxoselValue() )
#define cmu_getHfrcoselValue()              		( __cmu_getPropertyValue(1, 10) )				// 1 After reset
#define cmu_isHfrcoselRaised()						( __cmu_status & cmu_getHfrcoselValue() )
#define cmu_getLfxordyValue()                       ( __cmu_getPropertyValue(1, 9) )
#define cmu_isLfxordyRaised()						( __cmu_status & cmu_getLfxordyValue() )
#define cmu_getLfxoensValue()                       ( __cmu_getPropertyValue(1, 8) )
#define cmu_isLfxoensRaised()						( __cmu_status & cmu_getLfxoensValue() )
#define cmu_getLfrcordyValue()                      ( __cmu_getPropertyValue(1, 7) )
#define cmu_isLfrcordyRaised()						( __cmu_status & cmu_getLfrcordyValue() )
#define cmu_getLfrcoensValue()                      ( __cmu_getPropertyValue(1, 6) )
#define cmu_isLfrcoensRaised()						( __cmu_status & cmu_getLfrcoensValue() )
#define cmu_getAuxhfrcordyValue()                   ( __cmu_getPropertyValue(1, 5) )
#define cmu_isAuxhfrcordyRaised()					( __cmu_status & cmu_getAuxhfrcordyValue() )
#define cmu_getAuxhfrcoensValue()                   ( __cmu_getPropertyValue(1, 4) )
#define cmu_isAuxhfrcoensRaised()					( __cmu_status & cmu_getAuxhfrcoensValue() )
#define cmu_getHfxordyValue()                       ( __cmu_getPropertyValue(1, 3) )
#define cmu_isHfxordyRaised()						( __cmu_status & cmu_getHfxordyValue() )
#define cmu_getHfxoensValue()                       ( __cmu_getPropertyValue(1, 2) )
#define cmu_isHfxoselRaised()						( __cmu_status & cmu_getHfxoselValue() )
#define cmu_getHfrcordyValue()                      ( __cmu_getPropertyValue(1, 1) )
#define cmu_isHfrcordyRaised()						( __cmu_status & cmu_getHfrcordyValue() )
#define cmu_getHfrcoensValue()                      ( __cmu_getPropertyValue(1, 0) )
#define cmu_isHfxoselRaised()						( __cmu_status & cmu_getHfxoselValue() )
	//HFPERCLKEN0_GPIO
#define cmu_isGpioRaised()							( __cmu_hfperclken0 & cmu_getGpioValue() )
#define cmu_getGpioValue()							( __cmu_getPropertyValue(1, 13) )
	//HFPERCLKEN0_UART1
#define cmu_getUart1ClockEnableMask()				( __cmu_getBitMask(4, 4) )
#define cmu_getUart1ClockEnable()					( __cmu_hfperclken0 & cmu_enableUart1ClockMask() )
#define cmu_getUart1ClockEnableValue()				( __cmu_getPropertyValue(1, 4) )
	//HFPERCLKEN0_TIMER0
#define cmu_getTimer0ClockEnableMask()				( __cmu_getBitMask(5, 5) )
#define cmu_getTimer0ClockEnable()					( __cmu_hfperclken0 & cmu_getTimer0ClockEnableMask() )
#define cmu_getTimer0ClockEnableValue()				( __cmu_getPropertyValue(1, 5) )
//HFPERCLKEN0_USART1
#define cmu_getUsart1ClockEnableMask()				( __cmu_getBitMask(1, 1) )
#define cmu_getUsart1ClockEnable()					( __cmu_hfperclken0 & cmu_getTimer0ClockEnableMask() )
#define cmu_getUsart1ClockEnableValue()				( __cmu_getPropertyValue(1, 1) )


	//LOCK_LOCKKEY
#define cmu_isLockkeyRaised()						( __cmu_lock & 1 )		//CMU registers are locked if 1 returned.













/**********************************************************************************************************************
* Public function-like macros that DO NOT return value and DO NOT depend on EXTERNAL declarations
**********************************************************************************************************************/

	// CTRL_HFXOBUFCUR
#define cmu_setHfxobufcurBoostupto32mhz()			do{ __cmu_setProperty(__cmu_ctrl, cmu_getHfxobufcurMask(),  cmu_getHfxobufcurBoostupto32mhz()); 	} while(0)
#define cmu_setHfxobufcurBoostabove32mhz()			do{ __cmu_setProperty(__cmu_ctrl, cmu_getHfxobufcurMask(),  cmu_getHfxobufcurBoostabove32mhz()); 	} while(0)



// HFPERCLKDIV_HFPERCLKEN
#define cmu_raiseHfperclken()						do{ __cmu_hfperclkdiv |= cmu_getHfperclkenValue(); 													} while(0)
#define cmu_clearHfperclken()						do{ __cmu_hfperclkdiv &= ~cmu_getHfperclkenValue(); 												} while(0)
	//HFCORECLKEN0
#define cmu_enableDmaClock()						do{ __cmu_raiseBits(__cmu_hfcoreclken0, cmu_getEnableDmaClockMask() ); }while(0)
	//HFPERCLKDIV_HFPERCLKEN
#define cmu_setHighPeripheralClockDevider1()		do{  __cmu_setHighPeripheralClockDevider(cmu_getHighPeripheralClockDeviderMask(), cmu_getHighPeripheralClockDevider1Value() ); 				} while(0)
#define cmu_setHighPeripheralClockDevider2()		do{  __cmu_setHighPeripheralClockDevider(cmu_getHighPeripheralClockDeviderMask(), cmu_getHighPeripheralClockDevider2Value() ); 				} while(0)
#define cmu_setHighPeripheralClockDevider4()		do{  __cmu_setHighPeripheralClockDevider(cmu_getHighPeripheralClockDeviderMask(), cmu_getHighPeripheralClockDevider4Value() ); 				} while(0)
#define cmu_setHighPeripheralClockDevider8()        do{  __cmu_setHighPeripheralClockDevider(cmu_getHighPeripheralClockDeviderMask(), cmu_getHighPeripheralClockDevider8Value() ); 				} while(0)
#define cmu_setHighPeripheralClockDevider16()       do{  __cmu_setHighPeripheralClockDevider(cmu_getHighPeripheralClockDeviderMask(), cmu_getHighPeripheralClockDevider16Value() ); 				} while(0)
#define cmu_setHighPeripheralClockDevider32())      do{  __cmu_setHighPeripheralClockDevider(cmu_getHighPeripheralClockDeviderMask(), cmu_getHighPeripheralClockDevider32Value() ); 				} while(0)
#define cmu_setHighPeripheralClockDevider64()       do{  __cmu_setHighPeripheralClockDevider(cmu_getHighPeripheralClockDeviderMask(), cmu_getHighPeripheralClockDevider64Value() ); 				} while(0)
#define cmu_setHighPeripheralClockDevider128()      do{  __cmu_setHighPeripheralClockDevider(cmu_getHighPeripheralClockDeviderMask(), cmu_getHighPeripheralClockDevider128Value() ); 			} while(0)
#define cmu_setHighPeripheralClockDevider256()      do{  __cmu_setHighPeripheralClockDevider(cmu_getHighPeripheralClockDeviderMask(), cmu_getHighPeripheralClockDevider256Value() ); 			} while(0)
#define cmu_setHighPeripheralClockDevider512()      do{  __cmu_setHighPeripheralClockDevider(cmu_getHighPeripheralClockDeviderMask(), cmu_getHighPeripheralClockDevider512Value() ); 			} while(0)
// OSCENCMD
#define cmu_raiseHfxodis()							do{ __cmu_oscencmd = cmu_getHfxodisAssert(); 	}while(0)
#define cmu_raiseHfxoen()							do{ __cmu_oscencmd = cmu_getHfxodisAssert(); 	}while(0)
#define cmu_raiseHfrcodis()							do{ __cmu_oscencmd = cmu_getHfrcodisAssert(); 	}while(0)
#define cmu_raiseHfrcoen()							do{ __cmu_oscencmd = cmu_getHfrcoenAssert(); 	}while(0)
	// CMD
#define cmu_setHfclkselHfrco()						do{ __cmu_setProperty(__cmu_cmd, cmu_getHfclkselMask(), cmu_getHfclkselHfrco() ); 	}while(0)
#define cmu_setHfclkselHfxo()                       do{ __cmu_setProperty(__cmu_cmd, cmu_getHfclkselMask(), cmu_getHfclkselHfxo() ); 	}while(0)
#define cmu_setHfclkselLfrco()                      do{ __cmu_setProperty(__cmu_cmd, cmu_getHfclkselMask(), cmu_getHfclkselLfrco() ); 	}while(0)
#define cmu_setHfclkselLfxo()                       do{ __cmu_setProperty(__cmu_cmd, cmu_getHfclkselMask(), cmu_getHfclkselLfxo() ); 	}while(0)



//HFPERCLKEN0_GPIO
#define cmu_enableGpio()							do{ __cmu_hfperclken0 |= cmu_getGpioValue(); 										} while(0)
#define cmu_disanleGpio()							do{ __cmu_hfperclken0 &=  ~cmu_getGpioValue(); 										} while(0)
#define cmu_toggleGpio()
//HFPERCLKEN0_UART1
#define cmu_enableUart1Clock()						do{ __cmu_hfperclken0 |= cmu_getUart1ClockEnableValue(); 	 						} while(0)
#define cmu_disableUart1Clock()						do{ __cmu_hfperclken0 &= ( ~cmu_getUart1ClockEnableValue() ); 						} while(0)
//HFPERCLKEN0_TIMER0
#define cmu_enableTimer0Clock()						do{ __cmu_hfperclken0 |= cmu_getTimer0ClockEnableValue(); 	 						} while(0)
#define cmu_disableTimer0Clock()					do{ __cmu_hfperclken0 &= ( ~cmu_getTimer0ClockEnableValue() ); 						} while(0)
//HFPERCLKEN0_USART1
#define cmu_enableUsart1Clock()						do{ __cmu_hfperclken0 |= cmu_getUsart1ClockEnableValue(); 	 						} while(0)
#define cmu_disableUsart1Clock()					do{ __cmu_hfperclken0 &= ( ~cmu_getUsart1ClockEnableValue() ); 						} while(0)



// LOCK
#define cmu_raiseLockkey()							do{ __cmu_lock = 0; 																} while(0)
#define cmu_clearLockkey()							do{ __cmu_lock = 0x580E; 															} while(0)


/**********************************************************************************************************************
* Public function declarations(extern), that DO NOT depend on EXTERNAL declarations
**********************************************************************************************************************/
// Include header files of all(own) INTERNAL classes

// Public typedefs, that DO depend on EXTERNAL declarations

// Public object-like macros that DO depend on EXTERNAL declarations

// Public function-like macros that DO return value and DO depend on EXTERNAL declarations

// Public function-like macros that DO NOT return value and DO depend on EXTERNAL declarations

#define cmu_init()			do{	cmu_raiseHfperclken();\
								cmu_setHighPeripheralClockDevider1();\
								cmu_enableGpio();\
								cmu_enableUart1Clock();\
								cmu_enableTimer0Clock();\
								cmu_enableUsart1Clock();\
								cmu_enableDmaClock();\
							} while(0)
															//Selects the HFRCO as a source for HFCLK,	Set to enable the clock for GPIO

// Public function declarations(extern), that DO depend on EXTERNAL declarations


/**********************************************************************************************************************
* Component's data object declarations
**********************************************************************************************************************/
extern cmu_SelfData cmu_selfData;

#endif // __CMU_DERIVATIVE_INTERFACE__
/**********************************************************************************************************************
 * End of File
 **********************************************************************************************************************/
