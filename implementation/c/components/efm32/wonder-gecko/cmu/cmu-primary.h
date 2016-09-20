#ifndef __CMU_PRIMARY_INTERFACE__
#define __CMU_PRIMARY_INTERFACE__

/**********************************************************************************************************************
 * Include owned primary files
 **********************************************************************************************************************/


/**********************************************************************************************************************
* Private  constants  (__xxx_)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private  typedefs  (__xxx_)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private  Object-like macro definitions  (__xxx_)
**********************************************************************************************************************/
#define __cmu_getPropertyValue(value, startBit)					( (value) << (startBit) )
#define __cmu_getBitMask(MSBit, LSBit)							( (0xFFFFFFFF >> ( 32 - (((MSBit) + 1) - (LSBit))) ) << (LSBit) )

/**********************************************************************************************************************
* Private Function-like macro definitions  (__xxx_)  that DO return value
**********************************************************************************************************************/
#define __cmu_raiseBits(reg, mask)								do{ reg |= (mask); 																}while(0)
#define __cmu_setProperty(object, mask, value)					do{ object = ( object & ~(mask) ) | (value);									}while(0)
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

/**********************************************************************************************************************
* Public Function-like macro definitions  (xxx_) that DON'T RETURN VALUE
**********************************************************************************************************************/

#endif //__CMU_PRIMARY_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
