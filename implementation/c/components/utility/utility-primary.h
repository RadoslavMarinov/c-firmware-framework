/**********************************************************************************************************************
 * C Header: utility-primary.h
 * Component: Utility
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __UTILITY_PRIMATRY_INTERFACE__
#define __UTILITY_PRIMATRY_INTERFACE__


 /**********************************************************************************************************************
 * Include the primary headers of the INTERNAL (owned) classes
 **********************************************************************************************************************/
//#include "xxx-yyy-primary.h"


 /**********************************************************************************************************************
 * Private  typedefs  (__xxx_)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private  Object-like macro definitions  (__xxx_)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private Function-like macro definitions  (__xxx_)  that DO return value
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private Function-like macro definitions  (__xxx_) that DON'T RETURN VALUE
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Protected typedefs  (__xxx_)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Protected Object-like macro definitions  (__xxx_)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Protected Function-like macro definitions  (__xxx_)  that DO return value
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Protected Function-like macro definitions  (__xxx_) that DON'T RETURN VALUE
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public  typedefs  (xxx_)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public  Object-like macro definitions  (xxx_)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public Function-like macro definitions  (xxx_)  that DO return value
 **********************************************************************************************************************/

#define utility_getSFRegisterAddress(object, reg )					( (uint32_t)(&object.reg) )
#define utility_getPropertyValue(value, startBit)					( (value) << (startBit) )
#define utility_getProperty(reg, mask)								( reg & (mask) )

#define utility_getObject(base, offset)								( *((uint32_t*)( (base) + (offset) ) ) )



 /**********************************************************************************************************************
 * Public Function-like macro definitions  (xxx_) that DON'T RETURN VALUE
 **********************************************************************************************************************/
#define utility_setProperty(object, mask, value)  					do{ object = ( object & ~(mask) ) | (value);				} while(0)
#define utility_setRegister(reg, value)								do{ reg = (value); } while(0)
#define utility_assert1(reg, mask)									do{ reg = (mask); }while(0) //more efficient than raise_bit, since only write operation is used





void utility_delayCycles(uint32_t count)
{
	while( (count--) > 0)
		;
}


#endif //__UTILITY_PRIMATRY_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
