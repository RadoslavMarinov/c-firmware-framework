#ifndef __BITS_PRIMARY_INTERFACE__
#define __BITS_PRIMARY_INTERFACE__



/**********************************************************************************************************************
 * Publuc function-like macro definitions
 **********************************************************************************************************************/
#define bits_getBitCount(MSBit, LSBit)						( (MSBit + 1) - LSBit )
#define bits_getBitMaskRightAligned(MSBit, LSBit)			( 0xFFFFFFFF >> (32 - bits_getBitCount(MSBit, LSBit) ))
#define bits_getBitMask(MSBit, LSBit)						( bits_getBitMaskRightAligned(MSBit, LSBit) << LSBit )
#define bits_raiseBits(reg, mask)							do{ reg |= (mask); 	} while(0)
#define bits_clearBits(reg, mask) 							do{ reg &= ~(mask); } while(0)
#define bits_assertBits(reg, mask)							do{ reg = (mask); 	} while(0)			//When W1 only has effect

#endif //__BITS_PRIMARY_INTERFACE__


#define getBitMask(MSBit, LSBit)			( ( 0xFFFFFFFF >> ( 32 - (MSBit) + 1 - (LSBit) ) ) << (LSBit) )
