/**********************************************************************************************************************
 * C Header: status.h
 * Component: cmu
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include guard
#ifndef __STATUS_INTERFACE__
#define __STATUS_INTERFACE__

//Include the component's configuration file
#include "cmu-configuration.h"

/**********************************************************************************************************************
 * Class: Status
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *Dependency check
 **********************************************************************************************************************/

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
	// LFXOSEL
#define status_getLfxosel()				( STATUS_getPropertyValue(1, 13) )
#define status_isLfxoselRaised()		( STATUS_selfData &  status_getLfxosel())
	// LFRCOSEL
#define status_getLfrcosel()			( STATUS_getPropertyValue(1, 12) )
#define status_isLfrcoselRaised()		( STATUS_selfData &  status_getLfrcosel())
	// HFXOSEL
#define status_getHfxosel()				( STATUS_getPropertyValue(1, 11) )
#define status_isLHfxoselRaised()		( STATUS_selfData &  status_getLfrcosel())
	// HFRCOSEL
#define status_getHfrcosel()			( STATUS_getPropertyValue(1, 10) )
#define status_isLHfrcoselRaised()		( STATUS_selfData &  status_getHfrcosel())
	// LFXORDY
#define status_getLfxordy()				( STATUS_getPropertyValue(1, 9) )
#define status_isLLfxordyRaised()		( STATUS_selfData &  status_getLfxordy())
	// LFXOENS
#define status_getLfxoens()				( STATUS_getPropertyValue(1, 8) )
#define status_isLLfxoensRaised()		( STATUS_selfData &  status_getLfxoens())
	// LFRCORDY
#define status_getLfrcordy()			( STATUS_getPropertyValue(1, 7) )
#define status_isLLfrcordyRaised()		( STATUS_selfData &  status_getLfrcordy())
	// LFRCOENS
#define status_getLfrcoens()			( STATUS_getPropertyValue(1, 6) )
#define status_isLLfrcoensRaised()		( STATUS_selfData &  status_getLfrcoens())
	// AUXHFRCORDY
#define status_getAuxhfrcordy()			( STATUS_getPropertyValue(1, 5) )
#define status_isLAuxhfrcordyRaised()		( STATUS_selfData &  status_getAuxhfrcordy())
	// AUXHFRCOENS
#define status_getAuxhfrcoens()			( STATUS_getPropertyValue(1, 4) )
#define status_isLAuxhfrcoensRaised()	( STATUS_selfData &  status_getAuxhfrcoens())
	// HFXORDY
#define status_getHfxordy()				( STATUS_getPropertyValue(1, 3) )
#define status_isHfxordyRaised()		( STATUS_selfData &  status_getHfxordy())
	// HFXOENS
#define status_getHfxoens()				( STATUS_getPropertyValue(1, 2) )
#define status_isHfxoensRaised()		( STATUS_selfData &  status_getHfxoens())
	// HFRCORDY
#define status_getHfrcordy()			( STATUS_getPropertyValue(1, 1) )
#define status_isHfrcordyRaised()		( STATUS_selfData &  status_getHfrcordy())
	// HFRCOENS
#define status_getHfrcoens()			( STATUS_getPropertyValue(1, 0) )
#define status_isHfrcoensRaised()		( STATUS_selfData &  status_getHfrcoens())

/**********************************************************************************************************************
 *Public function-like macros that DO NOT return value
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *Public function declarations (extern)
 **********************************************************************************************************************/


#endif //__STATUS_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
