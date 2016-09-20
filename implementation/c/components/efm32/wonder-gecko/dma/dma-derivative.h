/***********************************************************************************************************************
 * C Header: dma-derivative.h
 * Component:
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __DMA_DERIVATIVE_INTERFCE__
#define __DMA_DERIVATIVE_INTERFCE__

/**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/

#ifndef DMA_selfData
	#error Missing required DMA_selfData
#endif

#ifndef DMA_getPropertyValue
	#error Missing required DMA_getPropertyValue(value, startBit)
#endif

#ifndef DMA_setProperty
	#error Missing required DMA_setProperty(object, mask, value)
#endif

#ifndef DMA_getUsart1TxBufferAddress
	#error Missing required DMA_getUsart1TxBufferAddress()
#endif

#ifndef DMA_getUart1TxBufferAddress
	#error Missing required DMA_getUart1TxBufferAddress()
#endif

#ifndef DMA_getProperty
	#error Missing required DMA_getProperty(reg, mask)
#endif

#ifndef DMA_assert1
	#error Missing required DMA_assert1(reg, mask)
#endif

#ifndef DMA_getPrimaryChannelCount
	#error Missing required DMA_getPrimaryChannelCount()
#endif

#ifndef DMA_getAlternateChannelCount
	#error Missing required DMA_getAlternateChannelCount()
#endif

#ifndef DMA_getCh0SourceEndAddr
	#error Missing required DMA_getCh0SourceEndAddr()
#endif

#ifndef DMA_getCh0DestEndAddr
	#error Missing required DMA_getCh0DestEndAddr()
#endif

#ifndef DMA_getCh0TransferCount
	#error Missing required DMA_getCh0TransferCount()
#endif

 /**********************************************************************************************************************
 * Include the derivative headers of the INTERNAL (owned) classes
 **********************************************************************************************************************/
#include "channel-derivative.h"
#include "channel-descriptor-derivative.h"
#include "ping-pong-derivative.h"
#include "phrase-channel-derivative.h"

 /**********************************************************************************************************************
 * Private typedefs
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private object-like macros
 **********************************************************************************************************************/

#define dma_getStatus()													( dma_sfr.status )
#define dma_getConfiguration()											( dma_sfr.configuration )
#define dma_getChannelControlDataBasePointer()							( dma_sfr.channelControlDataBasePointer )
#define dma_getChannelAlternateControlDataBasePointer()					( dma_sfr.channelAlternateControlDataBasePointer )
#define dma_getChannelSoftwareRequest()									( dma_sfr.channelSoftwareRequest )
#define dma_getChannelRequestMaskSet()									( dma_sfr.channelRequestMaskSet )
#define dma_getChannelRequestMaskClear()								( dma_sfr.channelRequestMaskClear )
#define dma_getChannelEnableSet()										( dma_sfr.channelEnableSet )
#define dma_getChannelEnableClear()										( dma_sfr.channelEnableClear )
#define dma_getChannelAlternateSet()									( dma_sfr.channelAlternateSet )
#define dma_getChannelAlternateClear()									( dma_sfr.channelAlternateClear )
#define dma_getChannelPrioritySet()										( dma_sfr.channelPrioritySet )
#define dma_getChannelPriorityClear()									( dma_sfr.channelPriorityClear )
#define dma_getBusErrorClear()											( dma_sfr.busErrorClear )
#define dma_getChannelRequestStatus()									( dma_sfr.channelRequestStatus )
#define dma_getInterruptFlag()											( dma_sfr.interruptFlag )
#define dma_getInterruptFlagSet()										( dma_sfr.interruptFlagSet )
#define dma_getInterruptFlagClear()										( dma_sfr.interruptFlagClear )
#define dma_getInterruptEnable()										( dma_sfr.interruptEnable )
#define dma_getChannelControl(channel)									( dma_sfr.channelControl[channel] )

 /**********************************************************************************************************************
 * Private function-like macros that DO return value
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private function-like macros that DO NOT return value
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Protected typedefs
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Protected object-like macros
 **********************************************************************************************************************/


 /**********************************************************************************************************************
 * Protected function-like macros that DO return value
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Protected function-like macros that DO NOT return value
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public typedefs
 **********************************************************************************************************************/


typedef struct
{
	union
	{
		uint32_t word[64];
        DMA_ChannelDescriptorSelfData primary[ DMA_getPrimaryChannelCount() ];
        uint32_t padding[64-(4*DMA_getPrimaryChannelCount())];
	};
    DMA_ChannelDescriptorSelfData alternate[ DMA_getAlternateChannelCount() ];
}dma_SelfData;

typedef struct
{
	volatile uint32_t status;
	volatile uint32_t configuration;
	volatile uint32_t channelControlDataBasePointer;
	volatile uint32_t channelAlternateControlDataBasePointer;
	volatile uint32_t channelWaitOnRequestStatus;
	volatile uint32_t channelSoftwareRequest;
	volatile uint32_t channelUseburstSet;
	volatile uint32_t channelUseburstClear;
	volatile uint32_t channelRequestMaskSet;
	volatile uint32_t channelRequestMaskClear;
	volatile uint32_t channelEnableSet;
	volatile uint32_t channelEnableClear;
	volatile uint32_t channelAlternateSet;
	volatile uint32_t channelAlternateClear;
	volatile uint32_t channelPrioritySet;
	volatile uint32_t channelPriorityClear;
			 uint32_t reserved0[3];
	volatile uint32_t busErrorClear;
			 uint32_t reserved1[880];
	volatile uint32_t channelRequestStatus;
			 uint32_t reserved2[1];
	volatile uint32_t channelSingleRequestStatus;
			 uint32_t reserved3[121];
	volatile uint32_t interruptFlag;
	volatile uint32_t interruptFlagSet;
	volatile uint32_t interruptFlagClear;
	volatile uint32_t interruptEnable;
	volatile uint32_t control;
	volatile uint32_t retainDescriptorState;
			 uint32_t reserved4[2];
	volatile uint32_t channel0Loop;
	volatile uint32_t channel1Loop;
			 uint32_t reserved5[14];
	volatile uint32_t channel0Rectangle;
			 uint32_t reserved6[39];
	volatile uint32_t channelControl[12];
}dma_Sfr;
 /**********************************************************************************************************************
 * Public object-like macros
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public function-like macros that DO return value
 **********************************************************************************************************************/

	// CHANNEL MASKS
#define dma_getChannel0Mask()							( DMA_getBitsMask(0, 0) )
#define dma_getChannel1Mask()							( DMA_getBitsMask(1, 1) )
#define dma_getChannel2Mask()							( DMA_getBitsMask(2, 2) )
#define dma_getChannel3Mask()							( DMA_getBitsMask(3, 3) )
#define dma_getChannel4Mask()							( DMA_getBitsMask(4, 4) )
#define dma_getChannel5Mask()							( DMA_getBitsMask(5, 5) )
#define dma_getChannel6Mask()							( DMA_getBitsMask(6, 6) )
#define dma_getChannel7Mask()							( DMA_getBitsMask(7, 7) )
#define dma_getChannel8Mask()							( DMA_getBitsMask(8, 8) )
#define dma_getChannel9Mask()							( DMA_getBitsMask(9, 9) )
#define dma_getChannel10Mask()							( DMA_getBitsMask(10, 10) )
#define dma_getChannel11Mask()							( DMA_getBitsMask(11, 11) )

	// CONFIG
#define dma_getEnableMask()									( DMA_getBitsMask(0, 0) )
#define dma_getEnableValue()								( DMA_getPropertyValue(1, 0))
	//CTRLBASE
	// ALTCTRLBASE

	// CHSWREQ
#define dma_getChannelSoftwareRequestMask()					( DMA_getBitsMask(11, 0) )
	// CHREQMASKS
#define dma_getChannelRequestMaskSetMask()					( DMA_getBitsMask(11, 0) )
#define dma_isPeripheralRequestForChannel0Enabled()			( dma_getChannelRequestMaskSet() & dma_getChannel0Mask() )
#define dma_isPeripheralRequestForChannel1Enabled()			( dma_getChannelRequestMaskSet() & dma_getChannel1Mask() )
#define dma_isPeripheralRequestForChannel2Enabled()			( dma_getChannelRequestMaskSet() & dma_getChannel2Mask() )
#define dma_isPeripheralRequestForChannel3Enabled()			( dma_getChannelRequestMaskSet() & dma_getChannel3Mask() )
#define dma_isPeripheralRequestForChannel4Enabled()			( dma_getChannelRequestMaskSet() & dma_getChannel4Mask() )
#define dma_isPeripheralRequestForChannel5Enabled()			( dma_getChannelRequestMaskSet() & dma_getChannel5Mask() )
#define dma_isPeripheralRequestForChannel6Enabled()			( dma_getChannelRequestMaskSet() & dma_getChannel6Mask() )
#define dma_isPeripheralRequestForChannel7Enabled()			( dma_getChannelRequestMaskSet() & dma_getChannel7Mask() )
#define dma_isPeripheralRequestForChannel8Enabled()			( dma_getChannelRequestMaskSet() & dma_getChannel8Mask() )
#define dma_isPeripheralRequestForChannel9Enabled()			( dma_getChannelRequestMaskSet() & dma_getChannel9Mask() )
#define dma_isPeripheralRequestForChannel10Enabled()		( dma_getChannelRequestMaskSet() & dma_getChannel10Mask() )
#define dma_isPeripheralRequestForChannel11Enabled()		( dma_getChannelRequestMaskSet() & dma_getChannel11Mask() )


	// CHENS
#define dma_isChannel0Enabled()							( dma_getChannelEnableSet() & dma_getChannel0Mask() )
#define dma_isChannel1Enabled()							( dma_getChannelEnableSet() & dma_getChannel1Mask() )
#define dma_isChannel2Enabled()							( dma_getChannelEnableSet() & dma_getChannel2Mask() )
#define dma_isChannel3Enabled()							( dma_getChannelEnableSet() & dma_getChannel3Mask() )
#define dma_isChannel4Enabled()							( dma_getChannelEnableSet() & dma_getChannel4Mask() )
#define dma_isChannel5Enabled()							( dma_getChannelEnableSet() & dma_getChannel5Mask() )
#define dma_isChannel6Enabled()							( dma_getChannelEnableSet() & dma_getChannel6Mask() )
#define dma_isChannel7Enabled()							( dma_getChannelEnableSet() & dma_getChannel7Mask() )
#define dma_isChannel8Enabled()							( dma_getChannelEnableSet() & dma_getChannel8Mask() )
#define dma_isChannel9Enabled()							( dma_getChannelEnableSet() & dma_getChannel9Mask() )
#define dma_isChannel10Enabled()						( dma_getChannelEnableSet() & dma_getChannel10Mask() )
#define dma_isChannel11Enabled()						( dma_getChannelEnableSet() & dma_getChannel11Mask() )

	//CHPRIS
#define dma_isChannel0PriorityHigh()					( dma_getChannelPrioritySet() & dma_getChannel0Mask() )
#define dma_isChannel1PriorityHigh()					( dma_getChannelPrioritySet() & dma_getChannel1Mask() )
#define dma_isChannel2PriorityHigh()					( dma_getChannelPrioritySet() & dma_getChannel2Mask() )
#define dma_isChannel3PriorityHigh()					( dma_getChannelPrioritySet() & dma_getChannel3Mask() )
#define dma_isChannel4PriorityHigh()					( dma_getChannelPrioritySet() & dma_getChannel4Mask() )
#define dma_isChannel5PriorityHigh()					( dma_getChannelPrioritySet() & dma_getChannel5Mask() )
#define dma_isChannel6PriorityHigh()					( dma_getChannelPrioritySet() & dma_getChannel6Mask() )
#define dma_isChannel7PriorityHigh()					( dma_getChannelPrioritySet() & dma_getChannel7Mask() )
#define dma_isChannel8PriorityHigh()					( dma_getChannelPrioritySet() & dma_getChannel8Mask() )
#define dma_isChannel9PriorityHigh()					( dma_getChannelPrioritySet() & dma_getChannel9Mask() )
#define dma_isChannel10PriorityHigh()					( dma_getChannelPrioritySet() & dma_getChannel10Mask() )
#define dma_isChannel11PriorityHigh()					( dma_getChannelPrioritySet() & dma_getChannel11Mask() )
	// ERRORC
#define dma_getBusErrorClearMask()						( DMA_getBitsMask(0, 0) )
#define dma_hasBusError()								( dma_getBusErrorClear() & dma_getBusErrorClearMask() )
	// CHREQSTATUS
#define dma_isChannel0Requested()						( dma_getChannelRequestStatus() & dma_getChannel0Mask() )
#define dma_isChannel1Requested()						( dma_getChannelRequestStatus() & dma_getChannel1Mask() )
#define dma_isChannel2Requested()						( dma_getChannelRequestStatus() & dma_getChannel2Mask() )
#define dma_isChannel3Requested()						( dma_getChannelRequestStatus() & dma_getChannel3Mask() )
#define dma_isChannel4Requested()						( dma_getChannelRequestStatus() & dma_getChannel4Mask() )
#define dma_isChannel5Requested()						( dma_getChannelRequestStatus() & dma_getChannel5Mask() )
#define dma_isChannel6Requested()						( dma_getChannelRequestStatus() & dma_getChannel6Mask() )
#define dma_isChannel7Requested()						( dma_getChannelRequestStatus() & dma_getChannel7Mask() )
#define dma_isChannel8Requested()						( dma_getChannelRequestStatus() & dma_getChannel8Mask() )
#define dma_isChannel9Requested()						( dma_getChannelRequestStatus() & dma_getChannel9Mask() )
#define dma_isChannel10Requested()						( dma_getChannelRequestStatus() & dma_getChannel10Mask() )
#define dma_isChannel11Requested()						( dma_getChannelRequestStatus() & dma_getChannel11Mask() )
	// IF
#define dma_getErrorInterruptFlagMask()					( DMA_getBitsMask(31, 31) )
#define dma_isChannel0Done()							( dma_getInterruptFlag() & dma_getChannel0Mask() )
#define dma_isChannel1Done()							( dma_getInterruptFlag() & dma_getChannel1Mask() )
#define dma_isChannel2Done()							( dma_getInterruptFlag() & dma_getChannel2Mask() )
#define dma_isChannel3Done()							( dma_getInterruptFlag() & dma_getChannel3Mask() )
#define dma_isChannel4Done()							( dma_getInterruptFlag() & dma_getChannel4Mask() )
#define dma_isChannel5Done()							( dma_getInterruptFlag() & dma_getChannel5Mask() )
#define dma_isChannel6Done()							( dma_getInterruptFlag() & dma_getChannel6Mask() )
#define dma_isChannel7Done()							( dma_getInterruptFlag() & dma_getChannel7Mask() )
#define dma_isChannel8Done()							( dma_getInterruptFlag() & dma_getChannel8Mask() )
#define dma_isChannel9Done()							( dma_getInterruptFlag() & dma_getChannel9Mask() )
#define dma_isChannel10Done()							( dma_getInterruptFlag() & dma_getChannel10Mask() )
#define dma_isChannel11Done()							( dma_getInterruptFlag() & dma_getChannel11Mask() )
#define dma_isBusErrorFlagRaised()						( dma_getInterruptFlag() & dma_getErrorInterruptFlagMask() )


	//CHx_CTRL_SOURCESEL
#define dma_getSourceSelectMask()						( DMA_getBitsMask(21, 16) )
#define dma_getSourceSelect(channel)					( dma_getChannelControl(channel) & dma_getSourceSelectMask() )
#define dma_getNoSourceValue()							( DMA_getPropertyValue(0b000000, 16 ) )
#define dma_getADC0Value()								( DMA_getPropertyValue(0b001000, 16 ) )
#define dma_getDAC0()									( DMA_getPropertyValue(0b001010, 16 ) )
#define dma_getUsart0Value()							( DMA_getPropertyValue(0b001100, 16 ) )
#define dma_getUsart1Value()							( DMA_getPropertyValue(0b001101, 16 ) )
#define dma_getUsart2Value()							( DMA_getPropertyValue(0b001110, 16 ) )
#define dma_getUART0Value()								( DMA_getPropertyValue(0b010000, 16 ) )
#define dma_getUART1Value()								( DMA_getPropertyValue(0b010001, 16 ) )
#define dma_getTi2c0Value()								( DMA_getPropertyValue(0b010100, 16 ) )
#define dma_getTi2c1Value()								( DMA_getPropertyValue(0b010101, 16 ) )
#define dma_getTimer0Value()					        ( DMA_getPropertyValue(0b011000, 16 ) )
#define dma_getTimer1Value()                            ( DMA_getPropertyValue(0b011001, 16 ) )
#define dma_getTimer2Value()                            ( DMA_getPropertyValue(0b011010, 16 ) )
#define dma_getTimer3Value()                            ( DMA_getPropertyValue(0b011011, 16 ) )
#define dma_getUart0Value()                             ( DMA_getPropertyValue(0b101100, 16 ) )
#define dma_getUart1Value()                             ( DMA_getPropertyValue(0b101101, 16 ) )
#define dma_getMscValue()                               ( DMA_getPropertyValue(0b110000, 16 ) )
#define dma_getAesValue()                               ( DMA_getPropertyValue(0b110001, 16 ) )
#define dma_getLesenseValue()                           ( DMA_getPropertyValue(0b110010, 16 ) )
#define dma_getEbiValue()                               ( DMA_getPropertyValue(0b110011, 16 ) )

	//CHx_CTRL_SIGSEL
#define dma_getSignalSelectMask()						( DMA_getBitsMask(3, 0) )
#define dma_getSignalSelect(channel)					( dma_getChannelControl(channel) & dma_getSignalSelectMask() )

#define dma_getSignalSelectUsartRxDataAvailableValue()	( DMA_getPropertyValue(0b0000, 0) )
#define dma_getSignalSelectUsartTxBufferLevelValue()	( DMA_getPropertyValue(0b0001, 0) )
#define dma_getSignalSelectUsartTxEmptyValue()			( DMA_getPropertyValue(0b0010, 0) )




//
	//
 /**********************************************************************************************************************
 * Public function-like macros that DO NOT return value
 **********************************************************************************************************************/

	//CONFIG
#define dma_enable()									do{ DMA_raiseBits(dma_getConfiguration(), dma_getEnableMask()); 			}while(0)


	//CTRLBASE
#define dma_setChannelControlDataBasePointer()			do{ DMA_setRegister(dma_getChannelControlDataBasePointer(),\
															((uint32_t)&DMA_selfData) );\
														} while(0)

#define dma_setDescriptorBaseAddress(address)  				do{ DMA_setRegister(dma_getChannelControlDataBasePointer(),\
                                                      			((uint32_t)(address)) );\
                                                      	  	}while(0)






// CHSWREQ
#define dma_requestChannel0()							do{ DMA_raiseBits( dma_getChannelSoftwareRequest(),\
															dma_getChannel0Mask() );\
														} while(0)
#define dma_requestChannel1()							do{ DMA_raiseBits( dma_getChannelSoftwareRequest(),\
															dma_getChannel1Mask() );\
														} while(0)
#define dma_requestChannel2()							do{ DMA_raiseBits( dma_getChannelSoftwareRequest(),\
															dma_getChannel2Mask() );\
														} while(0)
#define dma_requestChannel3()							do{ DMA_raiseBits( dma_getChannelSoftwareRequest(),\
															dma_getChannel3Mask() );\
														} while(0)
#define dma_requestChannel4()							do{ DMA_raiseBits( dma_getChannelSoftwareRequest(),\
															dma_getChannel4Mask() );\
														} while(0)
#define dma_requestChannel5()							do{ DMA_raiseBits( dma_getChannelSoftwareRequest(),\
															dma_getChannel5Mask() );\
														} while(0)
#define dma_requestChannel6()							do{ DMA_raiseBits( dma_getChannelSoftwareRequest(),\
															dma_getChannel6Mask() );\
														} while(0)
#define dma_requestChannel7()							do{ DMA_raiseBits( dma_getChannelSoftwareRequest(),\
															dma_getChannel7Mask() );\
														} while(0)
#define dma_requestChannel8()							do{ DMA_raiseBits( dma_getChannelSoftwareRequest(),\
															dma_getChannel8Mask() );\
														} while(0)
#define dma_requestChannel9()							do{ DMA_raiseBits( dma_getChannelSoftwareRequest(),\
															dma_getChannel9Mask() );\
														} while(0)
#define dma_requestChannel10()							do{ DMA_raiseBits( dma_getChannelSoftwareRequest(),\
															dma_getChannel10Mask() );\
														} while(0)
#define dma_requestChannel11()							do{ DMA_raiseBits( dma_getChannelSoftwareRequest(),\
															dma_getChannel11Mask() );\
														} while(0)
	// CHREQMASKS
#define dma_disablePeripheralRequestForChannel0()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskSet(), dma_getChannel0Mask() );\
														}while(0)
#define dma_disablePeripheralRequestForChannel1()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskSet(), dma_getChannel1Mask() );\
														}while(0)
#define dma_disablePeripheralRequestForChannel2()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskSet(), dma_getChannel2Mask() );\
														}while(0)
#define dma_disablePeripheralRequestForChannel3()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskSet(), dma_getChannel3Mask() );\
														}while(0)
#define dma_disablePeripheralRequestForChannel4()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskSet(), dma_getChannel4Mask() );\
														}while(0)
#define dma_disablePeripheralRequestForChannel5()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskSet(), dma_getChannel5Mask() );\
														}while(0)
#define dma_disablePeripheralRequestForChannel6()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskSet(), dma_getChannel6Mask() );\
														}while(0)
#define dma_disablePeripheralRequestForChannel7()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskSet(), dma_getChannel7Mask() );\
														}while(0)
#define dma_disablePeripheralRequestForChannel8()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskSet(), dma_getChannel8Mask() );\
														}while(0)
#define dma_disablePeripheralRequestForChannel9()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskSet(), dma_getChannel9Mask() );\
														}while(0)
#define dma_disablePeripheralRequestForChannel10()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskSet(), dma_getChannel10Mask() );\
														}while(0)
#define dma_disablePeripheralRequestForChannel11()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskSet(), dma_getChannel11Mask() );\
														}while(0)

	// CHREQMASKC
#define dma_enablePeripheralRequestForChannel0()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskClear(), dma_getChannel0Mask() );\
														}while(0)
#define dma_enablePeripheralRequestForChannel1()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskClear(), dma_getChannel1Mask() );\
														}while(0)
#define dma_enablePeripheralRequestForChannel2()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskClear(), dma_getChannel2Mask() );\
														}while(0)
#define dma_enablePeripheralRequestForChannel3()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskClear(), dma_getChannel3Mask() );\
														}while(0)
#define dma_enablePeripheralRequestForChannel4()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskClear(), dma_getChannel4Mask() );\
														}while(0)
#define dma_enablePeripheralRequestForChannel5()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskClear(), dma_getChannel5Mask() );\
														}while(0)
#define dma_enablePeripheralRequestForChannel6()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskClear(), dma_getChannel6Mask() );\
														}while(0)
#define dma_enablePeripheralRequestForChannel7()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskClear(), dma_getChannel7Mask() );\
														}while(0)
#define dma_enablePeripheralRequestForChannel8()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskClear(), dma_getChannel8Mask() );\
														}while(0)
#define dma_enablePeripheralRequestForChannel9()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskClear(), dma_getChannel9Mask() );\
														}while(0)
#define dma_enablePeripheralRequestForChannel10()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskClear(), dma_getChannel10Mask() );\
														}while(0)
#define dma_enablePeripheralRequestForChannel11()		do{\
															DMA_raiseBits(dma_getChannelRequestMaskClear(), dma_getChannel11Mask() );\
														}while(0)


	// CHENS
#define dma_enableChannel0()						do{ DMA_assertBits(dma_getChannelEnableSet(), dma_getChannel0Mask() ); 		} while(0)
#define dma_enableChannel1()						do{ DMA_assertBits(dma_getChannelEnableSet(), dma_getChannel1Mask() ); 		} while(0)
#define dma_enableChannel2()						do{ DMA_assertBits(dma_getChannelEnableSet(), dma_getChannel2Mask() ); 		} while(0)
#define dma_enableChannel3()						do{ DMA_assertBits(dma_getChannelEnableSet(), dma_getChannel3Mask() ); 		} while(0)
#define dma_enableChannel4()						do{ DMA_assertBits(dma_getChannelEnableSet(), dma_getChannel4Mask() ); 		} while(0)
#define dma_enableChannel5()						do{ DMA_assertBits(dma_getChannelEnableSet(), dma_getChannel5Mask() ); 		} while(0)
#define dma_enableChannel6()						do{ DMA_assertBits(dma_getChannelEnableSet(), dma_getChannel6Mask() ); 		} while(0)
#define dma_enableChannel7()						do{ DMA_assertBits(dma_getChannelEnableSet(), dma_getChannel7Mask() ); 		} while(0)
#define dma_enableChannel8()						do{ DMA_assertBits(dma_getChannelEnableSet(), dma_getChannel8Mask() ); 		} while(0)
#define dma_enableChannel9()						do{ DMA_assertBits(dma_getChannelEnableSet(), dma_getChannel9Mask() ); 		} while(0)
#define dma_enableChannel10()						do{ DMA_assertBits(dma_getChannelEnableSet(), dma_getChannel10Mask() ); 		} while(0)
#define dma_enableChannel11()						do{ DMA_assertBits(dma_getChannelEnableSet(), dma_getChannel11Mask() ); 		} while(0)
	// CHENC
#define dma_disableChannel0()						do{ DMA_assertBits(dma_getChannelEnableClear(), dma_getChannel0Mask() ); 		} while(0)
#define dma_disableChannel1()						do{ DMA_assertBits(dma_getChannelEnableClear(), dma_getChannel1Mask() ); 		} while(0)
#define dma_disableChannel2()						do{ DMA_assertBits(dma_getChannelEnableClear(), dma_getChannel2Mask() ); 		} while(0)
#define dma_disableChannel3()						do{ DMA_assertBits(dma_getChannelEnableClear(), dma_getChannel3Mask() ); 		} while(0)
#define dma_disableChannel4()						do{ DMA_assertBits(dma_getChannelEnableClear(), dma_getChannel4Mask() ); 		} while(0)
#define dma_disableChannel5()						do{ DMA_assertBits(dma_getChannelEnableClear(), dma_getChannel5Mask() ); 		} while(0)
#define dma_disableChannel6()						do{ DMA_assertBits(dma_getChannelEnableClear(), dma_getChannel6Mask() ); 		} while(0)
#define dma_disableChannel7()						do{ DMA_assertBits(dma_getChannelEnableClear(), dma_getChannel7Mask() ); 		} while(0)
#define dma_disableChannel8()						do{ DMA_assertBits(dma_getChannelEnableClear(), dma_getChannel8Mask() ); 		} while(0)
#define dma_disableChannel9()						do{ DMA_assertBits(dma_getChannelEnableClear(), dma_getChannel9Mask() ); 		} while(0)
#define dma_disableChannel10()						do{ DMA_assertBits(dma_getChannelEnableClear(), dma_getChannel10Mask() ); 	} while(0)
#define dma_disableChannel11()						do{ DMA_assertBits(dma_getChannelEnableClear(), dma_getChannel11Mask() ); 	} while(0)
	// CHALTS
#define dma_useAlternateStructureForChannel0()		do{ DMA_assertBits( dma_getChannelAlternateSet(), dma_getChannel0Mask() ); 		} while(0)
#define dma_useAlternateStructureForChannel1()		do{ DMA_assertBits( dma_getChannelAlternateSet(), dma_getChannel1Mask() ); 		} while(0)
#define dma_useAlternateStructureForChannel2()		do{ DMA_assertBits( dma_getChannelAlternateSet(), dma_getChannel2Mask() ); 		} while(0)
#define dma_useAlternateStructureForChannel3()		do{ DMA_assertBits( dma_getChannelAlternateSet(), dma_getChannel3Mask() ); 		} while(0)
#define dma_useAlternateStructureForChannel4()		do{ DMA_assertBits( dma_getChannelAlternateSet(), dma_getChannel4Mask() ); 		} while(0)
#define dma_useAlternateStructureForChannel5()		do{ DMA_assertBits( dma_getChannelAlternateSet(), dma_getChannel5Mask() ); 		} while(0)
#define dma_useAlternateStructureForChannel6()		do{ DMA_assertBits( dma_getChannelAlternateSet(), dma_getChannel6Mask() ); 		} while(0)
#define dma_useAlternateStructureForChannel7()		do{ DMA_assertBits( dma_getChannelAlternateSet(), dma_getChannel7Mask() ); 		} while(0)
#define dma_useAlternateStructureForChannel8()		do{ DMA_assertBits( dma_getChannelAlternateSet(), dma_getChannel8Mask() ); 		} while(0)
#define dma_useAlternateStructureForChannel9()		do{ DMA_assertBits( dma_getChannelAlternateSet(), dma_getChannel9Mask() ); 		} while(0)
#define dma_useAlternateStructureForChannel10()		do{ DMA_assertBits( dma_getChannelAlternateSet(), dma_getChannel10Mask() ); 		} while(0)
#define dma_useAlternateStructureForChannel11()		do{ DMA_assertBits( dma_getChannelAlternateSet(), dma_getChannel11Mask() ); 		} while(0)
	// CHALTC
#define dma_usePrimaryStructureForChannel0()		do{ DMA_assertBits( dma_getChannelAlternateClear(), dma_getChannel0Mask() ); 				} while(0)
#define dma_usePrimaryStructureForChannel1()		do{ DMA_assertBits( dma_getChannelAlternateClear(), dma_getChannel1Mask() ); 				} while(0)
#define dma_usePrimaryStructureForChannel2()		do{ DMA_assertBits( dma_getChannelAlternateClear(), dma_getChannel2Mask() ); 				} while(0)
#define dma_usePrimaryStructureForChannel3()		do{ DMA_assertBits( dma_getChannelAlternateClear(), dma_getChannel3Mask() ); 				} while(0)
#define dma_usePrimaryStructureForChannel4()		do{ DMA_assertBits( dma_getChannelAlternateClear(), dma_getChannel4Mask() ); 				} while(0)
#define dma_usePrimaryStructureForChannel5()		do{ DMA_assertBits( dma_getChannelAlternateClear(), dma_getChannel5Mask() ); 				} while(0)
#define dma_usePrimaryStructureForChannel6()		do{ DMA_assertBits( dma_getChannelAlternateClear(), dma_getChannel6Mask() ); 				} while(0)
#define dma_usePrimaryStructureForChannel7()		do{ DMA_assertBits( dma_getChannelAlternateClear(), dma_getChannel7Mask() ); 				} while(0)
#define dma_usePrimaryStructureForChannel8()		do{ DMA_assertBits( dma_getChannelAlternateClear(), dma_getChannel8Mask() ); 				} while(0)
#define dma_usePrimaryStructureForChannel9()		do{ DMA_assertBits( dma_getChannelAlternateClear(), dma_getChannel9Mask() ); 				} while(0)
#define dma_usePrimaryStructureForChannel10()		do{ DMA_assertBits( dma_getChannelAlternateClear(), dma_getChannel10Mask() ); 				} while(0)
#define dma_usePrimaryStructureForChannel11()		do{ DMA_assertBits( dma_getChannelAlternateClear(), dma_getChannel11Mask() ); 				} while(0)
	// CHPRIS
#define dma_setChannel0HighPriority()				do{ DMA_assertBits( dma_getChannelPrioritySet(), dma_getChannel0Mask() );        	} while(0)
#define dma_setChannel1HighPriority()				do{ DMA_assertBits( dma_getChannelPrioritySet(), dma_getChannel1Mask() );         } while(0)
#define dma_setChannel2HighPriority()				do{ DMA_assertBits( dma_getChannelPrioritySet(), dma_getChannel2Mask() );         } while(0)
#define dma_setChannel3HighPriority()				do{ DMA_assertBits( dma_getChannelPrioritySet(), dma_getChannel3Mask() );         } while(0)
#define dma_setChannel4HighPriority()				do{ DMA_assertBits( dma_getChannelPrioritySet(), dma_getChannel4Mask() );         } while(0)
#define dma_setChannel5HighPriority()				do{ DMA_assertBits( dma_getChannelPrioritySet(), dma_getChannel5Mask() );         } while(0)
#define dma_setChannel6HighPriority()				do{ DMA_assertBits( dma_getChannelPrioritySet(), dma_getChannel6Mask() );         } while(0)
#define dma_setChannel7HighPriority()				do{ DMA_assertBits( dma_getChannelPrioritySet(), dma_getChannel7Mask() );         } while(0)
#define dma_setChannel8HighPriority()				do{ DMA_assertBits( dma_getChannelPrioritySet(), dma_getChannel8Mask() );         } while(0)
#define dma_setChannel9HighPriority()				do{ DMA_assertBits( dma_getChannelPrioritySet(), dma_getChannel9Mask() );         } while(0)
#define dma_setChannel10HighPriority()				do{ DMA_assertBits( dma_getChannelPrioritySet(), dma_getChannel10Mask() );        } while(0)
#define dma_setChannel11HighPriority()				do{ DMA_assertBits( dma_getChannelPrioritySet(), dma_getChannel11Mask() );        } while(0)

	// CHPRIC
#define setChannel0DefaultPriority()				do{ DMA_assertBits( dma_getChannelPriorityClear(), dma_getChannel0Mask() )  		} while(0)
#define setChannel1DefaultPriority()				do{ DMA_assertBits( dma_getChannelPriorityClear(), dma_getChannel1Mask() )  		} while(0)
#define setChannel2DefaultPriority()				do{ DMA_assertBits( dma_getChannelPriorityClear(), dma_getChannel2Mask() ) 		} while(0)
#define setChannel3DefaultPriority()				do{ DMA_assertBits( dma_getChannelPriorityClear(), dma_getChannel3Mask() )		} while(0)
#define setChannel4DefaultPriority()				do{ DMA_assertBits( dma_getChannelPriorityClear(), dma_getChannel4Mask() )  		} while(0)
#define setChannel5DefaultPriority()				do{ DMA_assertBits( dma_getChannelPriorityClear(), dma_getChannel5Mask() )  		} while(0)
#define setChannel6DefaultPriority()				do{ DMA_assertBits( dma_getChannelPriorityClear(), dma_getChannel6Mask() )  		} while(0)
#define setChannel7DefaultPriority()				do{ DMA_assertBits( dma_getChannelPriorityClear(), dma_getChannel7Mask() )  		} while(0)
#define setChannel8DefaultPriority()				do{ DMA_assertBits( dma_getChannelPriorityClear(), dma_getChannel8Mask() )  		} while(0)
#define setChannel9DefaultPriority()				do{ DMA_assertBits( dma_getChannelPriorityClear(), dma_getChannel9Mask() )  		} while(0)
#define setChannel10DefaultPriority()				do{ DMA_assertBits( dma_getChannelPriorityClear(), dma_getChannel10Mask() ) 	 	} while(0)
#define setChannel11DefaultPriority()				do{ DMA_assertBits( dma_getChannelPriorityClear(), dma_getChannel11Mask() )  		} while(0)

	//ERRORC
#define dma_clearBussError()						do{ DMA_assertBits( dma_getBusErrorClear(), dma_getBusErrorClearMask() ); 		} while(0)

	// IFS
#define dma_raiseBussErrorInterruptFlag()			do{ DMA_assertBits( dma_getInterruptFlagSet(), dma_getErrorInterruptFlagMask() ); }while (0)
#define dma_raiseChannel0DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagSet(), dma_getChannel0Mask()); } while(0)
#define dma_raiseChannel1DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagSet(), dma_getChannel1Mask()); } while(0)
#define dma_raiseChannel2DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagSet(), dma_getChannel2Mask()); } while(0)
#define dma_raiseChannel3DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagSet(), dma_getChannel3Mask()); } while(0)
#define dma_raiseChannel4DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagSet(), dma_getChannel4Mask()); } while(0)
#define dma_raiseChannel5DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagSet(), dma_getChannel5Mask()); } while(0)
#define dma_raiseChannel6DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagSet(), dma_getChannel6Mask()); } while(0)
#define dma_raiseChannel7DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagSet(), dma_getChannel7Mask()); } while(0)
#define dma_raiseChannel8DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagSet(), dma_getChannel8Mask()); } while(0)
#define dma_raiseChannel9DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagSet(), dma_getChannel9Mask()); } while(0)
#define dma_raiseChannel10DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagSet(), dma_getChannel10Mask()); } while(0)
#define dma_raiseChannel11DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagSet(), dma_getChannel11Mask()); } while(0)

	// IFC
#define dma_clearBussErrorInterruptFlag()			do{ DMA_assertBits( dma_getInterruptFlagClear(), dma_getErrorInterruptFlagMask() ); 	} while (0)
#define dma_clearChannel0DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagClear(), dma_getChannel0Mask()); } while(0)
#define dma_clearChannel1DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagClear(), dma_getChannel1Mask()); } while(0)
#define dma_clearChannel2DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagClear(), dma_getChannel2Mask()); } while(0)
#define dma_clearChannel3DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagClear(), dma_getChannel3Mask()); } while(0)
#define dma_clearChannel4DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagClear(), dma_getChannel4Mask()); } while(0)
#define dma_clearChannel5DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagClear(), dma_getChannel5Mask()); } while(0)
#define dma_clearChannel6DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagClear(), dma_getChannel6Mask()); } while(0)
#define dma_clearChannel7DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagClear(), dma_getChannel7Mask()); } while(0)
#define dma_clearChannel8DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagClear(), dma_getChannel8Mask()); } while(0)
#define dma_clearChannel9DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagClear(), dma_getChannel9Mask()); } while(0)
#define dma_clearChannel10DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagClear(), dma_getChannel10Mask()); } while(0)
#define dma_clearChannel11DoneInterruptFlag()		do{ DMA_assertBits( dma_getInterruptFlagClear(), dma_getChannel11Mask()); } while(0)

	// DMA_CHx_CTRL_SOURCESEL
#define dma_selectSourceNone(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getNoSourceValue() );  	} while(0)
#define dma_selectSourceAdc0(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getADC0Value() );			} while(0)
#define dma_selectSourceDac0(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getDAC0() );              } while(0)
#define dma_selectSourceUsart0(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getUsart0Value() );       } while(0)
#define dma_selectSourceUsart1(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getUsart1Value() );       } while(0)
#define dma_selectSourceUsart2(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getUsart2Value() );       } while(0)
#define dma_selectSourceLeuart0(channel)			do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getUART0Value() );        } while(0)
#define dma_selectSourceLeuart1(channel)			do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getUART1Value() );        } while(0)
#define dma_selectSourceI2c0(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getTi2c0Value() );        } while(0)
#define dma_selectSourceI2c1(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getTi2c1Value() );        } while(0)
#define dma_selectSourceTimer0(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getTimer0Value() );       } while(0)
#define dma_selectSourceTimer1(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getTimer1Value() );       } while(0)
#define dma_selectSourceTimer2(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getTimer2Value() );       } while(0)
#define dma_selectSourceTimer3(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getTimer3Value() );       } while(0)
#define dma_selectSourceUart0(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getUart0Value() );        } while(0)
#define dma_selectSourceUart1(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getUart1Value() );        } while(0)
#define dma_selectSourceMsc(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getMscValue() );          } while(0)
#define dma_selectSourceAes(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getAesValue() );          } while(0)
#define dma_selectSourceLesense(channel)			do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getLesenseValue() );      } while(0)
#define dma_selectSourceEbi(channel)				do{ DMA_setProperty( dma_getChannelControl(channel), dma_getSourceSelectMask(), dma_getEbiValue() );          } while(0)
//--channel 0
#define dma_selectCh0SourceUart1()									do{ dma_selectSourceUart1(0);  												}while(0)
//#define dma_selectCh0SourceUart2()

//--channel 1
#define dma_selectCh1SourceUart1()									do{ dma_selectSourceUart1(1); 												}while(0)
//#define dma_selectCh1SourceUart1()





	// DMA_CHx_CTRL_SIGSEL
#define dma_selectInputSignalRxDataAvailable(channel)		do{ DMA_setProperty( dma_getChannelControl(channel),\
																dma_getSignalSelectMask(),\
																dma_getSignalSelectUsartRxDataAvailableValue() );\
															} while(0)
#define dma_selectInputSignalTxBufferLevel(channel)			do{ DMA_setProperty( dma_getChannelControl(channel),\
																dma_getSignalSelectMask(),\
																dma_getSignalSelectUsartTxBufferLevelValue() );\
															} while(0)
#define dma_selectInputSignalTxEmpty(channel)				do{ DMA_setProperty( dma_getChannelControl(channel),\
																dma_getSignalSelectMask(),\
																dma_getSignalSelectUsartTxEmptyValue() );\
															} while(0)


//--channel 0
#define dma_selectCh1InputSignalTxBufferLevel()				do{ dma_selectInputSignalTxBufferLevel(1); 											}while(0)
//--channel 1





#define dma_init()					do{\
										dma_selectSourceUart1(0);\
										dma_selectInputSignalRxDataAvailable(0);\
										DMA_channelDescriptorInit();\
										dma_enable();\
										dma_usePrimaryStructureForChannel0();\
										dma_setChannelControlDataBasePointer();\
										dma_enablePeripheralRequestForChannel0();\
									}while(0)
/*Channel 0
 * Only Primary Data Structure
 *
 */

 /**********************************************************************************************************************
 * Public function declarations(extern)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public Objects declaration
 **********************************************************************************************************************/
extern dma_Sfr dma_sfr;

#endif //__DMA_DERIVATIVE_INTERFCE__
/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/
