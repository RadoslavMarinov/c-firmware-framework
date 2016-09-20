/**********************************************************************************************************************
 * C Header: pe-model.h
 * Component: gpio
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __PE_MODEL_INTERFACE__
#define __PE_MODEL_INTERFACE__

 /**********************************************************************************************************************
 * Include the component's configuration file
 **********************************************************************************************************************/
#include "gpio-configuration.h"

/**********************************************************************************************************************
 * Class: Port E Mode High
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/

#ifndef PE_MODEL_selfData
	#error Missing required PE_MODEL_selfData
#endif

#ifndef PE_MODEL_setProperty
	#error Missing required PE_MODEL_setProperty(object, mask, value)
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
	// MODE2
#define pe_model_getMode2()							( PE_MODEL_selfData & pe_model_getMode2Mask() )
#define pe_model_getMode2Mask()						( PE_MODEL_getProperty(15, 8) )
#define pe_model_getMode2Pushpull()					( PE_MODEL_getProperty(4, 8 )
	// MODE3
#define pe_model_getMode3()							( PE_MODEL_selfData & pe_model_getMode3Mask() )
#define pe_model_getMode3Mask()						( PE_MODEL_getProperty(15, 12) )
#define pe_model_getMode3Pushpull()					( PE_MODEL_getProperty(4, 12) )

 /**********************************************************************************************************************
 * Public function-like macros that DO NOT return value
 **********************************************************************************************************************/
	// MODE2
#define pe_model_setMode2(value)					do{ PE_MODEL_setProperty( PE_MODEL_selfData, pe_model_getMode2Mask(), value);  	} while(0)
#define pe_model_setMode2Pushpull()					do{ pe_model_setMode2( pe_model_getMode2Pushpull() );  							} while(0)
	// MODE3
#define pe_model_setMode3(value)					do{ PE_MODEL_setProperty( PE_MODEL_selfData, pe_model_getMode3Mask(), value);  	} while(0)
#define pe_model_setMode3Pushpull()					do{ pe_model_setMode3( pe_model_getMode3Pushpull() );  							} while(0)

 /**********************************************************************************************************************
 * Public function declarations (extern)
 **********************************************************************************************************************/

#endif //__PE_MODEL_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/


//PE2 LED-0
//PE3 LED-1
