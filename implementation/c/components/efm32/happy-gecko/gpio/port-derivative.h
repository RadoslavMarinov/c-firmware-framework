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
typedef struct
{
	uint32_t control;
	uint32_t mode[2];
	uint32_t output;
	uint32_t raiseOutputCommand;
	uint32_t clearOutputCommand;
	uint32_t toggleOutputCommand;
	uint32_t input;
	uint32_t lock;
} __port_Port;


 /**********************************************************************************************************************
 * Private object-like macros
 **********************************************************************************************************************/

#define __port_getModePortAPin(pin)									( PORT_selfData.portA.mode[(pin)/8] )
#define __port_getModePortBPin(pin)									( PORT_selfData.portB.mode[(pin)/8] )
#define __port_getModePortCPin(pin)									( PORT_selfData.portC.mode[(pin)/8] )
#define __port_getModePortDPin(pin)									( PORT_selfData.portD.mode[(pin)/8] )
#define __port_getModePortEPin(pin)									( PORT_selfData.portE.mode[(pin)/8] )
#define __port_getModePortFPin(pin)									( PORT_selfData.portF.mode[(pin)/8] )

#define __port_getMaskModePin(pin)									( 0xF << __port_getOffsetModePin(pin) )

#define __port_getValueModeDisabledPin(pin)							( 0 << __port_getOffsetModePin(pin) )
#define __port_getValueModeInputPin(pin)							( 1 << __port_getOffsetModePin(pin) )
#define __port_getValueModeInputPullPin(pin)						( 2 << __port_getOffsetModePin(pin) )
#define __port_getValueModeInputPullFilterPin(pin)					( 3 << __port_getOffsetModePin(pin) )
#define __port_getValueModePushPullOutputPin(pin)					( 4 << __port_getOffsetModePin(pin) )


/**********************************************************************************************************************
* Private function-like macros that DO return value
**********************************************************************************************************************/


 /**********************************************************************************************************************
 * Private function-like macros that DO NOT return value
 **********************************************************************************************************************/



/**********************************************************************************************************************
* Public typedefs
**********************************************************************************************************************/

typedef struct
{
	__port_Port portA;
	__port_Port portB;
	__port_Port portC;
	__port_Port portD;
	__port_Port portE;
	__port_Port portF;
}port_SelfData;
/**********************************************************************************************************************
* Public object-like macros
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO return value
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO NOT return value
**********************************************************************************************************************/

// ----------------- GPIO_Px_MODE ----------------- //
// Port A pin modes

#define port_setModeDisabledPortAPin(pin)				do{ __port_setProperty( \
																__port_getPortAModePin(pin),\
																__port_getMaskModePin(pin),\
																__port_getValueModeDisabledPin(pin) );\
														}while(0)




// ----------------- GPIO_Px_DOUTSET ----------------- //




// ----------------- GPIO_Px_DOUTCLEAR ----------------- //




// ----------------- GPIO_Px_DOUTTOGGLE ----------------- //









#define port_setHighPortAPin(pin)                   		do{  } while(0)


#define port_setLowPortAOutputPin(pin)                   	do{ port_clearPinsOutput( selfData, __port_getPinMask( pin ) );  } while(0)
#define port_togglePortAOutputPin(pin)                  	do{ port_togglePinsOutput( selfData, __port_getPinMask( pin ) ); } while(0)

/**********************************************************************************************************************
* Public function declarations (extern)
**********************************************************************************************************************/

#endif //__PORT_DERIVATIVE_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
