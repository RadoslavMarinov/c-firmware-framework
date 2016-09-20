/**********************************************************************************************************************
 * C Header: hfperclken0.h
 * Component: cmu
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include guard
#ifndef __HFPERCLKEN0_INTERFACE__
#define __HFPERCLKEN0_INTERFACE__

//Include the component's configuration file
#include "cmu-configuration.h"

/**********************************************************************************************************************
 * Class: High Frequency Peripheral Clock Enable 0
 **********************************************************************************************************************/


/**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/
#ifndef HFPERCLKEN0_selfData
	#error Missing required HFPERCLKEN0_selfData
#endif

#ifndef HFPERCLKEN0_getPropetyValue
	#error Missing required HFPERCLKEN0_getPropetyValue(value, offset)
#endif


/**********************************************************************************************************************
 * Private typedefs
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Private object-like macros
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Private function-like macros that DO return value
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Private function-like macros that DO NOT return value
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Public typedefs
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Public object-like macros
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Public function-like macros that DO return value
 **********************************************************************************************************************/

	// GPIO
#define hfperclken0_getGpioValue()					( HFPERCLKEN0_getPropetyValue(1, 13) )
#define hfperclken0_isGpioRaised()					( HFPERCLKEN0_selfData & hfperclken0_getGpioValue() )
	// UART1
#define hfperclken0_getUart1Value()					( HFPERCLKEN0_getPropetyValue(1, 4) )
#define hfperclken0_isUart1Raised()					( HFPERCLKEN0_selfData & hfperclken0_getUart1Value() )
	// UART0
#define hfperclken0_getUart0Value()					( HFPERCLKEN0_getPropetyValue(1, 3) )
#define hfperclken0_isUart0Raised()					( HFPERCLKEN0_selfData & hfperclken0_getUart0Value() )
	// USART2
#define hfperclken0_getUsart2Value()				( HFPERCLKEN0_getPropetyValue(1, 2) )
#define hfperclken0_isUsart2Raised()				( HFPERCLKEN0_selfData & hfperclken0_getUsart2Value() )
	// USART1
#define hfperclken0_getUsart1Value()				( HFPERCLKEN0_getPropetyValue(1, 1) )
#define hfperclken0_isUsart1Raised()				( HFPERCLKEN0_selfData & hfperclken0_getUsart1Value() )
	// USART0
#define hfperclken0_getUsart0Value()				( HFPERCLKEN0_getPropetyValue(1, 0) )
#define hfperclken0_isUsart0Raised()				( HFPERCLKEN0_selfData & hfperclken0_getUsart0Value() )

/**********************************************************************************************************************
 * Public function-like macros that DO NOT return value
 **********************************************************************************************************************/
	// Common Methods
#define HFPERCLKEN0_raiseBit(bit)				    do{ HFPERCLKEN0_selfData |= bit;													} while(0)
#define HFPERCLKEN0_clearBit(bit)			        do{ HFPERCLKEN0_selfData &=  ~bit;	 												} while(0)

	// GPIO
#define hfperclken0_raiseGpio()						do{ HFPERCLKEN0_setBit(hfperclken0_getGpioValue() );                              	} while(0)
#define hfperclken0_clearGpio()						do{ HFPERCLKEN0_clearBit(hfperclken0_getGpioValue() );                              } while(0)
	// UART1
#define hfperclken0_raiseUart1()					do{ HFPERCLKEN0_setBit(hfperclken0_getUart1Value() );                          		} while(0)
#define hfperclken0_clearUart1()					do{ HFPERCLKEN0_clearBit(hfperclken0_getUart1Value() );  				 			} while(0)
	// UART0
#define hfperclken0_raiseUart0()					do{ HFPERCLKEN0_setBit(hfperclken0_getUart0Value() );                          		} while(0)
#define hfperclken0_clearUart0()					do{ HFPERCLKEN0_clearBit(hfperclken0_getUart0Value() );  				 			} while(0)
	// USART2
#define hfperclken0_raiseUsart2()					do{ HFPERCLKEN0_setBit(hfperclken0_getUsart2Value() );                          	} while(0)
#define hfperclken0_clearUsart2()					do{ HFPERCLKEN0_clearBit(hfperclken0_getUsart2Value() );  				 			} while(0)
	// USART1
#define hfperclken0_raiseUsart1()					do{ HFPERCLKEN0_setBit(hfperclken0_getUsart1Value() );                          	} while(0)
#define hfperclken0_clearUsart1()					do{ HFPERCLKEN0_clearBit(hfperclken0_getUsart1Value() );  				 			} while(0)
	// USART0
#define hfperclken0_raiseUsart0()					do{ HFPERCLKEN0_setBit(hfperclken0_getUsart0Value() );                          	} while(0)
#define hfperclken0_clearUsart0()					do{ HFPERCLKEN0_clearBit(hfperclken0_getUsart0Value() );  				 			} while(0)


/**********************************************************************************************************************
 * Public function declarations (extern)
 **********************************************************************************************************************/
#endif //__HFPERCLKEN0_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
