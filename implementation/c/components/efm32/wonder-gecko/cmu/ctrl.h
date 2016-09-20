/**********************************************************************************************************************
 * C Header: ctrl.h
 * Component: cmu
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include guard
#ifndef __CTRL_INTERFACE__
#define __CTRL_INTERFACE__

//Include the component's configuration file
#include "cmu-configuration.h"

/**********************************************************************************************************************
 * Class: Control
 **********************************************************************************************************************/




/**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/

#ifndef CTRL_selfData
	#error Missing required CTRL_selfData
#endif

#ifndef CTRL_setProperty
	#error Missing required CTRL_setProperty(object, mask, value)
#endif

#ifndef CTRL_getPropertyValue
	#error Missing required CTRL_getPropertyValue(value, offset)
#endif



#ifndef
	#error Missing required
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
	// CTRL_HFXOBUFCUR
#define ctrl_getHfxobufcur()						( CTRL_selfData &  ctrl_getHfxobufcurtMask() )
#define ctrl_getHfxobufcurtMask()					( CTRL_getPropertyValue(3, 5) )
#define ctrl_getHfxobufcurBoostupto32mhz()			( CTRL_getPropertyValue(1, 5) )
#define ctrl_getHfxobufcurBoostabove32mhz()			( CTRL_getPropertyValue(3, 5) )



	// CTRL_HFXOBOOST
#define ctrl_getHfxoboost()							( CTRL_selfData &  ctrl_getHfxoboostMask() )
#define ctrl_getHfxoboostMask()						( CTRL_getPropertyValue(3, 3) )
#define ctrl_getHfxoboost50percent()				( CTRL_getPropertyValue(0, 2) )
#define ctrl_getHfxoboost70percent()				( CTRL_getPropertyValue(1, 2) )
#define ctrl_getHfxoboost80percent()				( CTRL_getPropertyValue(2, 2) )
#define ctrl_getHfxoboost100percent()				( CTRL_getPropertyValue(3, 2) )



/**********************************************************************************************************************
 *Public function-like macros that DO NOT return value
 **********************************************************************************************************************/

	// CTRL_HFXOBUFCUR
#define ctrl_setHfxobufcur(value)       			do{ CTRL_setProperty( CTRL_selfData, ctrl_getHfxobufcurtMask(), value); } 			while(0)
#define ctrl_setHfxobufcurBoostupto32mhz()			do{ ctrl_setHfxobufcur(ctrl_getHfxobufcurBoostupto32mhz()); } 						while(0)
#define ctrl_setHfxobufcurBoostabove32mhz()			do{ ctrl_setHfxobufcur(ctrl_getHfxobufcurBoostabove32mhz()); } 						while(0)

	// CTRL_HFXOBOOST
#define ctrl_setHfxoboost(value)					do{ CTRL_setProperty( CTRL_selfData, ctrl_getHfxoboostMask(), value); } 			while(0)
#define ctrl_setHfxoboost50percent()				do{ ctrl_setHfxoboost( ctrl_getHfxoboost50percent() ); } 							while(0)
#define ctrl_setHfxoboost70percent()				do{ ctrl_setHfxoboost( ctrl_getHfxoboost70percent() ); } 							while(0)
#define ctrl_setHfxoboost80percent()				do{ ctrl_setHfxoboost( ctrl_getHfxoboost80percent() ); } 							while(0)
#define ctrl_setHfxoboost100percent()               do{ ctrl_setHfxoboost( ctrl_getHfxoboost100percent() ); } 							while(0)

/**********************************************************************************************************************
 * Public function declarations (extern)
 **********************************************************************************************************************/

#endif //__CTRL_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
