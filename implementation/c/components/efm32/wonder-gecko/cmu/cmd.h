/**********************************************************************************************************************
 * C Header: cmd.h
 * Component: cmu
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include guard
#ifndef __CMD_INTERFACE__
#define __CMD_INTERFACE__

//Include the component's configuration file
#include "cmu-configuration.h"

/**********************************************************************************************************************
 * Class: Command
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *Dependency check
 **********************************************************************************************************************/


#define CMD_selfData
	#error Missing required CMD_selfData
#endif

#define CMD_setProperty
	#error Missing required CMD_setProperty(object, mask, value)
#endif

#define CMD_getPropertyValue
	#error CMD_getPropertyValue(value, offset)
#endif


/**********************************************************************************************************************
 *Private typedefs
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *Private object-like macros
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *Private function-like macros that DO return value
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *Private function-like macros that DO NOT return value
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *Public typedefs
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *Public object-like macros
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *Public function-like macros that DO return value
 **********************************************************************************************************************/

#define cmd_getHfclksel()						( CMD_selfData & cmd_getHfclkselMask() )
#define cmd_getHfclkselMask()					( CMD_getPropertyValue(7, 0) )

#define cmd_getHfclkselHfrco()					( CMD_getPropertyValue(1, 0) )
#define cmd_getHfclkselHfxo()					( CMD_getPropertyValue(2, 0) )
#define cmd_getHfclkselLfrco()					( CMD_getPropertyValue(3, 0) )
#define cmd_getHfclkselLfxo()					( CMD_getPropertyValue(4, 0) )

/**********************************************************************************************************************
 *Public function-like macros that DO NOT return value
 **********************************************************************************************************************/

#define cmd_setHfclksel(value)					do{ CMD_setProperty(CMD_selfData, cmd_getHfclkselMask(), value); 							}while(0)
#define cmd_setHfclkselHfrco()					do{ cmd_setHfclksel(cmd_getHfclkselHfrco());												}while(0)							}while(0)
#define cmd_setHfclkselHfxo()					do{ cmd_setHfclksel(cmd_getHfclkselHfxo());                                                 }while(0)
#define cmd_setHfclkselLfrco()					do{ cmd_setHfclksel(cmd_getHfclkselLfrco());                                                }while(0)
#define cmd_setHfclkselLfxo()	                do{ cmd_setHfclksel(cmd_getHfclkselLfxo());                                                 }while(0)

/**********************************************************************************************************************
 *Public function declarations (extern)
 **********************************************************************************************************************/

#endif //__CMD_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/