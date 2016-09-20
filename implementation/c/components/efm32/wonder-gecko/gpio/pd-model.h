/**********************************************************************************************************************
 * C Header: pd-model.h
 * Component | Composition | Application: Xxx Yyy Zzz
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __XXX_YYY_INTERFACE__
#define __XXX_YYY_INTERFACE__

 /**********************************************************************************************************************
 * Include the component's configuration file
 **********************************************************************************************************************/
#include "gpio-configuration.h"

/**********************************************************************************************************************
 * Class: Port D Mode Low
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/

#ifndef PD_MODEL_selfData
	#error Missing required PD_MODEL_selfData
#endif

#ifndef PD_MODEL_setProperty
	#error Missing required PD_MODEL_setProperty
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
	//MODE0
#define pd_model_getMode0()						( PD_MODEL_selfData & pd_model_getMode0Mask() )
#define pd_model_getMode0Mask()					( PD_MODEL_getPropertyValue(15,0) )
#define pd_model_getMode0Pushpull()				( PD_MODEL_getPropertyValue(4,0) )
	//MODE1
#define pd_model_getMode1()						( PD_MODEL_selfData & pd_model_getMode1Mask() )
#define pd_model_getMode1Mask()					( PD_MODEL_getPropertyValue(15,4) )
#define pd_model_getMode1Pushpull()				( PD_MODEL_getPropertyValue(4,0) )
#define pd_model_getMode1Input()				( PD_MODEL_getPropertyValue(1,0) )
	//MODE2
#define pd_model_getMode2()						( PD_MODEL_selfData & pd_model_getMode2Mask() )
#define pd_model_getMode2Mask()					( PD_MODEL_getPropertyValue(15,8) )
#define pd_model_getMode2Pushpull()				( PD_MODEL_getPropertyValue(4,0) )
	//MODE3
#define pd_model_getMode3()						( PD_MODEL_selfData & pd_model_getMode3Mask() )
#define pd_model_getMode3Mask()					( PD_MODEL_getPropertyValue(15,0) )
#define pd_model_getMode3Pushpull()				( PD_MODEL_getPropertyValue(4,12) )

 /**********************************************************************************************************************
 * Public function-like macros that DO NOT return value
 **********************************************************************************************************************/

#define pd_model_setMode0(value)				do{ PD_MODEL_setProperty(PD_MODEL_selfData, pd_model_getMode0Mask(), value); 		} while(0)
#define pd_model_setMode0Pushpull()				do{ pd_model_setMode0(pd_model_getMode0Pushpull() ); 								} while(0)

#define pd_model_setMode1(value)				do{ PD_MODEL_setProperty(PD_MODEL_selfData, pd_model_getMode1Mask(), value); 		} while(0)
#define pd_model_setMode1Pushpull()				do{ pd_model_setMode1(pd_model_getMode1Pushpull() ); 								} while(0)
#define pd_model_setMode1Input()				do{ pd_model_setMode1(pd_model_getMode1Input() ); 									} while(0)

#define pd_model_setMode2(value)				do{ PD_MODEL_setProperty(PD_MODEL_selfData, pd_model_getMode2Mask(), value); 		} while(0)
#define pd_model_setMode2Pushpull()				do{ pd_model_setMode2(pd_model_getMode2Pushpull() );								} while(0)

#define pd_model_setMode3(value)				do{ PD_MODEL_setProperty(PD_MODEL_selfData, pd_model_getMode3Mask(), value); 		} while(0)
#define pd_model_setMode3Pushpull()				do{ pd_model_setMode3(pd_model_getMode3Pushpull() );								} while(0)


 /**********************************************************************************************************************
 * Public function declarations (extern)
 **********************************************************************************************************************/

#endif //__XXX_YYY_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
