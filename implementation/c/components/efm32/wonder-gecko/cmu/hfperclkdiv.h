/**********************************************************************************************************************
* C Header: hfperclkdiv.h
 * Component: cmu
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include guard
#ifndef __HFPERCLKDIV_INTERFACE__
#define __HFPERCLKDIV_INTERFACE__

//Include the component's configuration file
#include "cmu-configuration.h"

/**********************************************************************************************************************
 * Class: High Peripheral Clock Division
 **********************************************************************************************************************/


/**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/

#ifndef HFPERCLKDIV_selfData
	#error Missing required HFPERCLKDIV_selfData
#endif

#ifndef HFPERCLKDIV_setPorperty
	#error Missing required HFPERCLKDIV_setPorperty(object, mask, value)
#endif

#ifndef HFPERCLKDIV_getPropertyValue
	#error Missing required HFPERCLKDIV_getPropertyValue(value, offset)
#endif



#ifndef
	#error Missing required
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

	// HFPERCLKEN
#define hfperclkdiv_getHfperclken()							( HFPERCLKDIV_getPropertyValue(1, 8))
#define hfperclkdiv_isHfperclkenRaised()					( HFPERCLKDIV_selfData & hfperclkdiv_getHfperclken() )
	//HFPERCLKDIV
#define hfperclkdiv_getHfperclkdiv()						( HFPERCLKDIV_selfData &  hfperclkdiv_getHfperclkdivMask() )
#define hfperclkdiv_getHfperclkdivMask()					( HFPERCLKDIV_getPropertyValue(15, 0) )
#define hfperclkdiv_getHfperclkdivHfclk()					( HFPERCLKDIV_getPropertyValue(0, 0) )
#define hfperclkdiv_getHfperclkdivHfclk2()					( HFPERCLKDIV_getPropertyValue(1, 0) )
#define hfperclkdiv_getHfperclkdivHfclk4()					( HFPERCLKDIV_getPropertyValue(2, 0) )
#define hfperclkdiv_getHfperclkdivHfclk8()					( HFPERCLKDIV_getPropertyValue(3, 0) )
#define hfperclkdiv_getHfperclkdivHfclk16()					( HFPERCLKDIV_getPropertyValue(4, 0) )
#define hfperclkdiv_getHfperclkdivHfclk32()					( HFPERCLKDIV_getPropertyValue(5, 0) )
#define hfperclkdiv_getHfperclkdivHfclk64()					( HFPERCLKDIV_getPropertyValue(6, 0) )
#define hfperclkdiv_getHfperclkdivHfclk128()				( HFPERCLKDIV_getPropertyValue(7, 0) )
#define hfperclkdiv_getHfperclkdivHfclk256()				( HFPERCLKDIV_getPropertyValue(8, 0) )
#define hfperclkdiv_getHfperclkdivHfclk512()				( HFPERCLKDIV_getPropertyValue(9, 0) )

/**********************************************************************************************************************
 * Public function-like macros that DO NOT return value
 **********************************************************************************************************************/

	// HFPERCLKEN
#define hfperclkdiv_raiseHfperclken()						do{ HFPERCLKDIV_selfData | hfperclkdiv_getHfperclken(); 						}while(0)
#define hfperclkdiv_clearHfperclken()						do{ HFPERCLKDIV_selfData &=  (~hfperclkdiv_getHfperclken()); 					}while(0)
	//HFPERCLKDIV
#define hfperclkdiv_setHfperclkdiv(value)					do{ HFPERCLKDIV_setProperty(HFPERCLKDIV_selfData, hfperclkdiv_getHfperclkdivMask(), value); }while(0)
#define hfperclkdiv_setHfperclkdivHfclk()					do{ hfperclkdiv_setHfperclkdiv( hfperclkdiv_getHfperclkdivHfclk() );
#define hfperclkdiv_setHfperclkdivHfclk2()                  do{ hfperclkdiv_setHfperclkdiv( hfperclkdiv_getHfperclkdivHfclk2() );           }while(0)
#define hfperclkdiv_setHfperclkdivHfclk4()                  do{ hfperclkdiv_setHfperclkdiv( hfperclkdiv_getHfperclkdivHfclk4() );           }while(0)
#define hfperclkdiv_setHfperclkdivHfclk8()                  do{ hfperclkdiv_setHfperclkdiv( hfperclkdiv_getHfperclkdivHfclk8() );           }while(0)
#define hfperclkdiv_setHfperclkdivHfclk16()                 do{ hfperclkdiv_setHfperclkdiv( hfperclkdiv_getHfperclkdivHfclk16() );          }while(0)
#define hfperclkdiv_setHfperclkdivHfclk32()                 do{ hfperclkdiv_setHfperclkdiv( hfperclkdiv_getHfperclkdivHfclk32() );          }while(0)
#define hfperclkdiv_setHfperclkdivHfclk64()                 do{ hfperclkdiv_setHfperclkdiv( hfperclkdiv_getHfperclkdivHfclk64() );          }while(0)
#define hfperclkdiv_setHfperclkdivHfclk128()                do{ hfperclkdiv_setHfperclkdiv( hfperclkdiv_getHfperclkdivHfclk128() );         }while(0)
#define hfperclkdiv_setHfperclkdivHfclk256()                do{ hfperclkdiv_setHfperclkdiv( hfperclkdiv_getHfperclkdivHfclk256() );         }while(0)
#define hfperclkdiv_setHfperclkdivHfclk512()                do{ hfperclkdiv_setHfperclkdiv( hfperclkdiv_getHfperclkdivHfclk512() );         }while(0)


/**********************************************************************************************************************
 * Public function declarations (extern)
 **********************************************************************************************************************/


#endif //__HFPERCLKDIV_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
