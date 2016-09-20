/***********************************************************************************************************************
 * C Header: frame-derivative.h
 * Component:electricity-meter-m90e32as
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __FRAME_DERIVATIVE_INTERFCE__
#define __FRAME_DERIVATIVE_INTERFCE__

 /**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/
// #ifndef
// 	#error Missing required
// #endif


#if !defined FRAME_8BIT && !defined FRAME_16BIT
	#error Missing required FRAME FORMAT
#endif

/**********************************************************************************************************************
* Private typedefs (__xxx)
**********************************************************************************************************************/


/********************************************************************************************************************************
 *________________________________________________________________________________________________________________________________
 * 				        octet[0]          |      octet[1]           |            octet[2]             |        octet[3]          |
 * MSBit First		R/W x x x x x A9? A8? | A7 A6 A5 A4 A3 A2 A1 A0 |	D15 D14 D13 D12 D11 D10 D9 D8 |  D7 D6 D5 D4 D3 D2 D1 D0 |
 *--------------------------------------------------------------------------------------------------------------------------------
 * A - Address bit
 * A? - These bits do not represent any available address. Address range ( 0x00 - 0xFF).
 * D - Data bit
********************************************************************************************************************************/
typedef struct
{
	uint8_t octet[ 4 ];
}__frame_Buffer;

/**********************************************************************************************************************
* Private object-like macros   (__xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private function-like macros that DO return value  (__xxx)
**********************************************************************************************************************/
#define __frame_getReadOctet(index)									( FRAME_selfData.input.octet[index] )
#define __frame_getWriteOctet(index)								( FRAME_selfData.output.octet[index] )

/**********************************************************************************************************************
* Private function-like macros that DO NOT return value (__xxx)
**********************************************************************************************************************/
#define __frame_setWriteOctet( number, value )						do{ FRAME_selfData.output.octet[number] = (value); 							}while(0)


/**********************************************************************************************************************
* Protected typedefs (_xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Protected object-like macros  (_xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Protected function-like macros that DO return value  (_xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Protected function-like macros that DO NOT return value  (_xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public typedefs  (xxx)
**********************************************************************************************************************/
typedef struct
{
	__frame_Buffer input;
	__frame_Buffer output;	// Compiler will pad up to 8 bytes anyway
}frame_SelfData;
/**********************************************************************************************************************
* Public object-like macros  (xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO return value (xxx)
**********************************************************************************************************************/

#ifdef FRAME_8BIT
#define frame_getValue()												( (__frame_getReadOctet(0) << 8) | (__frame_getReadOctet(1) )

#define frame_getAddressOfRead()										( &FRAME_selfData.input )
#define frame_getAddressOfWrite()										( &FRAME_selfData.output )
#endif //FRAME_8BIT

#ifdef FRAME_16BIT
#define frame_getValue()												( (uint16_t)( (__frame_getReadOctet(0) << 8 ) | (__frame_getReadOctet(1)) ) )
#define frame_getAddress()												( (uint8_t)(__frame_getWriteOctet(1)) )

#define frame_getAddressOfRead()										( &FRAME_selfData.input )
#define frame_getAddressOfWrite()										( &FRAME_selfData.output )
#endif//FRAME_16BIT

/**********************************************************************************************************************
* Public function-like macros that DO NOT return value (xxx)
**********************************************************************************************************************/

#ifdef FRAME_8BIT
#define frame_setAddress(addr)											do{ __frame_setWriteOctet( 1, (addr));									}while(0)
//
#define frame_setCommandRead()											do{ __frame_setWriteOctet( 0, 0x80 ); 									}while(0)
#define frame_setCommandWrite()											do{ __frame_setWriteOctet( 0, 0x00 ); 									}while(0)

#define frame_setValue(value)										do{ \
																			__frame_setWriteOctet( 2, (uint8_t)((value) >> 8) );\
																			__frame_setWriteOctet( 3,  (uint8_t)(value) );\
																		}while(0)

#define frame_write(address, value)										do{ \
																			frame_setCommandWrite();\
																			frame_setValue(value);\
																			frame_setAddress(address);\
																		}while(0)

#define frame_read(address)												do{ \
																			frame_setCommandRead(); \
																			frame_setAddress(address);\
																		}while(0)
#endif //FRAME_8BIT


#ifdef FRAME_16BIT
#define frame_setAddress(addr)											do{ __frame_setWriteOctet( 1, (uint8_t)(addr));							}while(0)

#define frame_setCommandRead()											do{ __frame_setWriteOctet( 0, 0x80 ); 									}while(0)
#define frame_setCommandWrite()											do{ __frame_setWriteOctet( 0, 0x00 ); 									}while(0)

#define frame_setValue(value)											do{ \
																			__frame_setWriteOctet( 2, (uint8_t)((value) >> 8 ) );\
																			__frame_setWriteOctet( 3,  (uint8_t)(value) );\
																		}while(0)





#define frame_write(address, value)										do{ \
																			frame_setCommandWrite();\
																			frame_setValue(value);\
																			frame_setAddress(address);\
																		}while(0)





#define frame_read(address)												do{ \
																			frame_setCommandRead(); \
																			frame_setAddress(address);\
																		}while(0)

#endif //FRAME_16BIT


/**********************************************************************************************************************
* Public function declarations(extern)
**********************************************************************************************************************/

#endif //__FRAME_DERIVATIVE_INTERFCE__
/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/
