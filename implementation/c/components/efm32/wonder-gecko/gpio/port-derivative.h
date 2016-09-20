/**********************************************************************************************************************
 * C Header: port.h
 * Component: gpio
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __PORT_DERIVATIVE_INTERFACE__
#define __PORT_DERIVATIVE_INTERFACE__

/**********************************************************************************************************************
 * Class: Port
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

 /**********************************************************************************************************************
 * Private function-like macros that DO return value
 **********************************************************************************************************************/
#define __port_getPortA()									( PORT_selfData[0])
#define __port_getPortB()									( PORT_selfData[1])
#define __port_getPortC()									( PORT_selfData[2)
#define __port_getPortD()									( PORT_selfData[3])
#define __port_getPortE()									( PORT_selfData[4])
#define __port_getPortF()									( PORT_selfData[5])


 /**********************************************************************************************************************
 * Private function-like macros that DO NOT return value
 **********************************************************************************************************************/

// Port A pin modes
#define __port_setPortAModeDisabledPin(pin)				do{ PORT_selfData[0].mode[(pin)/8] = port_getPinDisabledMode(pin); 						}while(0)
#define __port_setPortAModeInputPin(pin)				do{ PORT_selfData[0].mode[(pin)/8] = port_getPinInputMode(pin); 						}while(0)
#define __port_setPortAModeInputPullPin(pin)			do{ PORT_selfData[0].mode[(pin)/8] = port_getModeInputPullPin(pin); 					}while(0)
#define __port_setPortAModeInputPullFilterPin(pin)		do{ PORT_selfData[0].mode[(pin)/8] = port_getModeInputPullFilterPin(pin); 				}while(0)
#define __port_setPortAModePushPullOutputPin(pin)		do{ PORT_selfData[0].mode[(pin)/8] = port_getModePushPullOutputPin(pin); 				}while(0)

// Port B pin modes
#define __port_setPortBModeDisabledPin(pin)				do{ PORT_selfData[1].mode[(pin)/8] = port_getPinDisabledMode(pin); 						}while(0)
#define __port_setPortBModeInputPin(pin)				do{ PORT_selfData[1].mode[(pin)/8] = port_getPinInputMode(pin); 						}while(0)
#define __port_setPortBModeInputPullPin(pin)			do{ PORT_selfData[1].mode[(pin)/8] = port_getModeInputPullPin(pin); 					}while(0)
#define __port_setPortBModeInputPullFilterPin(pin)		do{ PORT_selfData[1].mode[(pin)/8] = port_getModeInputPullFilterPin(pin); 				}while(0)
#define __port_setPortBModePushPullOutputPin(pin)		do{ PORT_selfData[1].mode[(pin)/8] = port_getModePushPullOutputPin(pin); 				}while(0)

// Port C pin modes
#define __port_setPortCModeDisabledPin(pin)				do{ PORT_selfData[2].mode[(pin)/8] = port_getPinDisabledMode(pin); 						}while(0)
#define __port_setPortCModeInputPin(pin)				do{ PORT_selfData[2].mode[(pin)/8] = port_getPinInputMode(pin); 						}while(0)
#define __port_setPortCModeInputPullPin(pin)			do{ PORT_selfData[2].mode[(pin)/8] = port_getModeInputPullPin(pin); 					}while(0)
#define __port_setPortCModeInputPullFilterPin(pin)		do{ PORT_selfData[2].mode[(pin)/8] = port_getModeInputPullFilterPin(pin); 				}while(0)
#define __port_setPortCModePushPullOutputPin(pin)		do{ PORT_selfData[2].mode[(pin)/8] = port_getModePushPullOutputPin(pin); 				}while(0)

// Port D pin modes
#define __port_setPortDModeDisabledPin(pin)				do{ PORT_selfData[3].mode[(pin)/8] = port_getPinDisabledMode(pin); 						}while(0)
#define __port_setPortDModeInputPin(pin)				do{ PORT_selfData[3].mode[(pin)/8] = port_getPinInputMode(pin); 						}while(0)
#define __port_setPortDModeInputPullPin(pin)			do{ PORT_selfData[3].mode[(pin)/8] = port_getModeInputPullPin(pin); 					}while(0)
#define __port_setPortDModeInputPullFilterPin(pin)		do{ PORT_selfData[3].mode[(pin)/8] = port_getModeInputPullFilterPin(pin); 				}while(0)
#define __port_setPortDModePushPullOutputPin(pin)		do{ PORT_selfData[3].mode[(pin)/8] = port_getModePushPullOutputPin(pin); 				}while(0)

// Port E pin modes
#define __port_setPortEModeDisabledPin(pin)				do{ PORT_selfData[4].mode[(pin)/8] = port_getPinDisabledMode(pin); 						}while(0)
#define __port_setPortEModeInputPin(pin)				do{ PORT_selfData[4].mode[(pin)/8] = port_getPinInputMode(pin); 						}while(0)
#define __port_setPortEModeInputPullPin(pin)			do{ PORT_selfData[4].mode[(pin)/8] = port_getModeInputPullPin(pin); 					}while(0)
#define __port_setPortEModeInputPullFilterPin(pin)		do{ PORT_selfData[4].mode[(pin)/8] = port_getModeInputPullFilterPin(pin); 				}while(0)
#define __port_setPortEModePushPullOutputPin(pin)		do{ PORT_selfData[4].mode[(pin)/8] = port_getModePushPullOutputPin(pin); 				}while(0)

// Port F pin modes
#define __port_setPortFModeDisabledPin(pin)				do{ PORT_selfData[5].mode[(pin)/8] = port_getPinDisabledMode(pin); 						}while(0)
#define __port_setPortFModeInputPin(pin)				do{ PORT_selfData[5].mode[(pin)/8] = port_getPinInputMode(pin); 						}while(0)
#define __port_setPortFModeInputPullPin(pin)			do{ PORT_selfData[5].mode[(pin)/8] = port_getModeInputPullPin(pin); 					}while(0)
#define __port_setPortFModeInputPullFilterPin(pin)		do{ PORT_selfData[5].mode[(pin)/8] = port_getModeInputPullFilterPin(pin); 				}while(0)
#define __port_setPortFModePushPullOutputPin(pin)		do{ PORT_selfData[5].mode[(pin)/8] = port_getModePushPullOutputPin(pin); 				}while(0)

 /**********************************************************************************************************************
 * Public typedefs
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public object-like macros
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public function-like macros that DO return value
 **********************************************************************************************************************/








// Pin Input
#define port_getPinsInput(selfData,pins)                ( selfData.input & pins )
#define port_isPinInputRaised(selfData,pin)             ( port_getPinsInput( selfData, __port_getPinMask( pin ) ) )
	// Pin Output
#define port_getPinsOutput(selfData,pins)               ( selfData.output & pins )
#define port_isPinOutputRaised(selfData,pin)            ( port_getPinsOutput( selfData, __port_getPinMask( pin ) ) )
	// Pin Mode
#define port_getPinMode(selfData,pin)                   ( selfData.mode[ pin / 8 ] & ( 0x000F << __port_getPinModeOffset( pin ) ) )

 /**********************************************************************************************************************
 * Public function-like macros that DO NOT return value
 **********************************************************************************************************************/
	// Pin Output
#define port_setOutput(selfData, value)						do { selfData = value; } while(0)
#define port_raisePinsOutput(selfData,pins)              	do { selfData.raiseOutputCommand = pins; } while(0)
#define port_clearPinsOutput(selfData,pins)             	do { selfData.clearOutputCommand = pins; } while(0)
#define port_togglePinsOutput(selfData,pins)             	do { selfData.toggleOutputCommand = pins; } while(0)
	//
#define port_raisePinOutput(selfData,pin)                   do { port_raisePinsOutput( selfData, __port_getPinMask( pin ) );  } while(0)
#define port_clearPinOutput(selfData,pin)                   do { port_clearPinsOutput( selfData, __port_getPinMask( pin ) );  } while(0)
#define port_togglePinOutput(selfData,pin)                  do { port_togglePinsOutput( selfData, __port_getPinMask( pin ) ); } while(0)
	// Pin Mode
#define port_setPinsMode(selfData,index,modes)              do{ selfData.mode[index] = modes; } while(0)



 /**********************************************************************************************************************
 * Public function declarations (extern)
 **********************************************************************************************************************/

#endif //__PORT_DERIVATIVE_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
