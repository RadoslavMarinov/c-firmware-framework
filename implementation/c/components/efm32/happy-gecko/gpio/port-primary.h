/**********************************************************************************************************************
 * C Header - Primary interface: port-primary.h
 * Component: gpio
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __PORT_PRIMARY_INTERFACE__
#define __PORT_PRIMARY_INTERFACE__

/**********************************************************************************************************************
 * Class: Port
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private typedefs
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private object-like macros
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private function-like macros that DO return value
 **********************************************************************************************************************/
#define __port_getOffsetModePin(pin)                        ( 4 * ( (pin) % 8 ) )

/**********************************************************************************************************************
* Private function-like macros that DO NOT return value
**********************************************************************************************************************/
#define __port_setProperty(register_, mask, value)					do{ (register_) = ((register_) & (~(mask))) | ((value) & (mask)); 			}while(0)

/**********************************************************************************************************************
* Public typedefs
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public object-like macros
**********************************************************************************************************************/
#define port_pins_0_7                                  0
#define port_pins_8_15                                 1

/**********************************************************************************************************************
* Public function-like macros that DO return value
**********************************************************************************************************************/
	// Pin Mode





	// Pin Output Level

 /**********************************************************************************************************************
 * Public function-like macros that DO NOT return value
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public function declarations (extern)
 **********************************************************************************************************************/

#endif //__PORT_PRIMARY_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
