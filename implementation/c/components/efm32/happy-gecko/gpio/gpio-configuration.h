/**********************************************************************************************************************
 * C Configuration Header: gpio-configuration.h
 * Component: GPIO
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __GPIO_CONFIGURATION__
#define __GPIO_CONFIGURATION__

/**********************************************************************************************************************
 * Interface declarations required by its own classes
 **********************************************************************************************************************/

//

//
//
//

/**********************************************************************************************************************
* GPIO Object-like macros
**********************************************************************************************************************/
#define GPIO_PortSelfData                        					port_SelfData
/**********************************************************************************************************************
* GPIO Function-like macros that DO return value
**********************************************************************************************************************/
#define GPIO_isPinInputRaised(port,pin)     						( port_isPinInputRaised(port, pin) )
#define GPIO_pins_0_7                          						port_pins_0_7
#define GPIO_pins_8_15                         						port_pins_8_15
/**********************************************************************************************************************
* GPIO Function-like macros that DO NOT return value
**********************************************************************************************************************/
// Port
#define GPIO_setPinsMode(port,pinGroup,mode)      					do{ port_setPinsMode( port, pinGroup, mode ); 								}while(0)
#define GPIO_setPortOutput(port, value)			  					do{ port_setOutput(port, value); 											}while(0)
// Pin
#define GPIO_togglePinOutput(port, pin)         					do{ port_togglePinOutput(port, pin); 										}while(0)


/**********************************************************************************************************************
* PORT Object-like macros
**********************************************************************************************************************/
#define PORT_selfData												(gpio_selfData.ports)
/**********************************************************************************************************************
* PORT Function-like macros that DO return value
**********************************************************************************************************************/
#define PORT_isSingleTranslationUnit()          ( GPIO_isSingleTranslationUnit() )
/**********************************************************************************************************************
* PORT Function-like macros that DO NOT return value
**********************************************************************************************************************/

#endif // __GPIO_CONFIGURATION__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
