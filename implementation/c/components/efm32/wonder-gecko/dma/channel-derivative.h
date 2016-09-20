/***********************************************************************************************************************
 * C Header: xxx-yyy-derivative.h
 * Component:
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __CHANNEL_DERIVATIVE_INTERFCE__
#define __CHANNEL_DERIVATIVE_INTERFCE__


 /**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/
#ifndef CHANNEL_getBitsMask
 	#error Missing required CHANNEL_getBitsMask()
 #endif

#ifndef CHANNEL_getPorperty
	#error Missing required CHANNEL_getPorperty(reg, mask)
#endif

#ifndef CHANNEL_assert1
	#error CHANNEL_assert1(reg, mask)
#endif


//#ifndef
// 	#error Missing required
// #endif


 /**********************************************************************************************************************
 * Private typedefs (__xxx)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private object-like macros   (__xxx)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private function-like macros that DO return value  (__xxx)
 **********************************************************************************************************************/



 /**********************************************************************************************************************
 * Private function-like macros that DO NOT return value (__xxx)
 **********************************************************************************************************************/

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

 /**********************************************************************************************************************
 * Public object-like macros  (xxx)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public function-like macros that DO return value (xxx)
 **********************************************************************************************************************/

#define channel_getChannel0Mask()							( CHANNEL_getBitsMask(0, 0) )
#define channel_getChannel1Mask()							( CHANNEL_getBitsMask(1, 1) )
#define channel_getChannel2Mask()							( CHANNEL_getBitsMask(2, 2) )
#define channel_getChannel3Mask()							( CHANNEL_getBitsMask(3, 3) )
#define channel_getChannel4Mask()							( CHANNEL_getBitsMask(4, 4) )
#define channel_getChannel5Mask()							( CHANNEL_getBitsMask(5, 5) )
#define channel_getChannel6Mask()							( CHANNEL_getBitsMask(6, 6) )
#define channel_getChannel7Mask()							( CHANNEL_getBitsMask(7, 7) )
#define channel_getChannel8Mask()							( CHANNEL_getBitsMask(8, 8) )
#define channel_getChannel9Mask()							( CHANNEL_getBitsMask(9, 9) )
#define channel_getChannel10Mask()							( CHANNEL_getBitsMask(10, 10) )
#define channel_getChannel11Mask()							( CHANNEL_getBitsMask(11, 11) )

	//CHNUM
#define channel_getNumberOfAvailableChannelsMask()			( CHANNEL_getBitsMask(20, 16) )
#define channel_getNumberOfAvailableChannels()				( CHANNEL_getPorperty( CHANNEL_getStatus(), channel_getNumberOfAvailableChannelsMask() ) + 1 )


//CHWAITSTATUS
#define channel_isChannel0WaitOnRequestRaised()				( CHANNEL_getPorperty( CHANNEL_getWaitOnRequestStatus(), channel_getChannel0Mask() ) )
#define channel_isChannel1WaitOnRequestRaised()             ( CHANNEL_getPorperty( CHANNEL_getWaitOnRequestStatus(), channel_getChannel1Mask() ) )
#define channel_isChannel2WaitOnRequestRaised()             ( CHANNEL_getPorperty( CHANNEL_getWaitOnRequestStatus(), channel_getChannel2Mask() ) )
#define channel_isChannel3WaitOnRequestRaised()             ( CHANNEL_getPorperty( CHANNEL_getWaitOnRequestStatus(), channel_getChannel3Mask() ) )
#define channel_isChannel4WaitOnRequestRaised()             ( CHANNEL_getPorperty( CHANNEL_getWaitOnRequestStatus(), channel_getChannel4Mask() ) )
#define channel_isChannel5WaitOnRequestRaised()             ( CHANNEL_getPorperty( CHANNEL_getWaitOnRequestStatus(), channel_getChannel5Mask() ) )
#define channel_isChannel6WaitOnRequestRaised()             ( CHANNEL_getPorperty( CHANNEL_getWaitOnRequestStatus(), channel_getChannel6Mask() ) )
#define channel_isChannel7WaitOnRequestRaised()             ( CHANNEL_getPorperty( CHANNEL_getWaitOnRequestStatus(), channel_getChannel7Mask() ) )
#define channel_isChannel8WaitOnRequestRaised()             ( CHANNEL_getPorperty( CHANNEL_getWaitOnRequestStatus(), channel_getChannel8Mask() ) )
#define channel_isChannel9WaitOnRequestRaised()             ( CHANNEL_getPorperty( CHANNEL_getWaitOnRequestStatus(), channel_getChannel9Mask() ) )
#define channel_isChannel10WaitOnRequestRaised()            ( CHANNEL_getPorperty( CHANNEL_getWaitOnRequestStatus(), channel_getChannel10Mask() ) )
#define channel_isChannel11WaitOnRequestRaised()            ( CHANNEL_getPorperty( CHANNEL_getWaitOnRequestStatus(), channel_getChannel11Mask() ) )

//CHREQMASKS

#define channel_isChannel0PeripheralRequestEnabled()
#define channel_isChannel1PeripheralRequestEnabled()
#define channel_isChannel2PeripheralRequestEnabled()
#define channel_isChannel3PeripheralRequestEnabled()
#define channel_isChannel4PeripheralRequestEnabled()
#define channel_isChannel5PeripheralRequestEnabled()
#define channel_isChannel6PeripheralRequestEnabled()
#define channel_isChannel7PeripheralRequestEnabled()
#define channel_isChannel8PeripheralRequestEnabled()
#define channel_isChannel9PeripheralRequestEnabled()
#define channel_isChannel10PeripheralRequestEnabled()
#define channel_isChannel11PeripheralRequestEnabled()
 /**********************************************************************************************************************
 * Public function-like macros that DO NOT return value (xxx)
 **********************************************************************************************************************/

//CHSWREQ
#define channel_requestChannel0()							do{ CHANNEL_asser1(CHANNEL_getSoftwareRequest(), channel_getChannel0Mask() ); }while(0)
#define channel_requestChannel1()                           do{ CHANNEL_asser1(CHANNEL_getSoftwareRequest(), channel_getChannel1Mask() ); }while(0)
#define channel_requestChannel2()                           do{ CHANNEL_asser1(CHANNEL_getSoftwareRequest(), channel_getChannel2Mask() ); }while(0)
#define channel_requestChannel3()                           do{ CHANNEL_asser1(CHANNEL_getSoftwareRequest(), channel_getChannel3Mask() ); }while(0)
#define channel_requestChannel4()                           do{ CHANNEL_asser1(CHANNEL_getSoftwareRequest(), channel_getChannel4Mask() ); }while(0)
#define channel_requestChannel5()                           do{ CHANNEL_asser1(CHANNEL_getSoftwareRequest(), channel_getChannel5Mask() ); }while(0)
#define channel_requestChannel6()                           do{ CHANNEL_asser1(CHANNEL_getSoftwareRequest(), channel_getChannel6Mask() ); }while(0)
#define channel_requestChannel7()                           do{ CHANNEL_asser1(CHANNEL_getSoftwareRequest(), channel_getChannel7Mask() ); }while(0)
#define channel_requestChannel8()                           do{ CHANNEL_asser1(CHANNEL_getSoftwareRequest(), channel_getChannel8Mask() ); }while(0)
#define channel_requestChannel9()                           do{ CHANNEL_asser1(CHANNEL_getSoftwareRequest(), channel_getChannel9Mask() ); }while(0)
#define channel_requestChannel10()                          do{ CHANNEL_asser1(CHANNEL_getSoftwareRequest(), channel_getChannel10Mask() ); }while(0)
#define channel_requestChannel11()                          do{ CHANNEL_asser1(CHANNEL_getSoftwareRequest(), channel_getChannel11Mask() ); }while(0)

 /**********************************************************************************************************************
 * Public function declarations(extern)
 **********************************************************************************************************************/

#endif //__CHANNEL_DERIVATIVE_INTERFCE__
/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/
