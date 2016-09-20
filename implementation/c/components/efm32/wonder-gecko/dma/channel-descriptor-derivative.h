/**********************************************************************************************************************
 * C Header: chanel-decriptor-derivative.h
 * Component: DMA
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __CHANNEL_DECRIPTOR_DERIVATIVE__
#define __CHANNEL_DECRIPTOR_DERIVATIVE__

 /**********************************************************************************************************************
 * Include the component's configuration file
 **********************************************************************************************************************/
#include "dma-configuration.h"

 /**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/

#ifndef CHANNEL_DESCRIPTOR_getBitsMask
	#define Mssing required CHANNEL_DESCRIPTOR_getBitsMask(EndBit, StartBit)
#endif

#ifndef CHANNEL_DESCRIPTOR_setProperty
	#error Missing required CHANNEL_DESCRIPTOR_setProperty(object, mask, value)
#endif

#ifndef CHANNEL_DESCRIPTOR_dataStructure
	#error Missing required CHANNEL_DESCRIPTOR_dataStructure
#endif

#ifndef CHANNEL_DESCRIPTOR_clearBits
	#error Missing required CHANNEL_DESCRIPTOR_clearBits(reg, mask)
#endif

#ifndef CHANNEL_DESCRIPTOR_getCh0TransferCount
	#error Missing required CHANNEL_DESCRIPTOR_getCh0TransferCount()
#endif

 /**********************************************************************************************************************
 * Private typedefs
 **********************************************************************************************************************/
typedef struct
{
	volatile uint32_t sourceEndPointer;
	volatile uint32_t destinationEndPointer;
	volatile uint32_t control;
	volatile uint32_t user;
}chanel_descriptor_SelfData; 					//SingleChannelControlDataStructure;



 /**********************************************************************************************************************
 * Private object-like macros
 **********************************************************************************************************************/

#define __channel_descriptor_channelDataStrrucure						( CHANNEL_DESCRIPTOR_dataStructure )

#define __channel_descriptor_primaryDataStructure(channel)				( __channel_descriptor_channelDataStrrucure.primary[channel] )
#define __channel_descriptor_alternateDataStructure(channel)			( __channel_descriptor_channelDataStrrucure.alternate[channel] )


#define __channel_descriptor_primaryDataStructureUser(channel)						( __channel_descriptor_primaryDataStructure(channel).user )
#define __channel_descriptor_primaryDataStructureControl(channel)					( __channel_descriptor_primaryDataStructure(channel).control )
#define __channel_descriptor_primaryDataStructureDestinationEndPointer(channel)		( __channel_descriptor_primaryDataStructure(channel).destinationEndPointer )
#define __channel_descriptor_primaryDataStructureSourceEndPointer(channel)			( __channel_descriptor_primaryDataStructure(channel).sourceEndPointer )

#define __channel_descriptor_alternateDataStructureUser(channel)						( __channel_descriptor_alternateDataStructure(channel).user )
#define __channel_descriptor_alternateDataStructureControl(channel)						( __channel_descriptor_alternateDataStructure(channel).control )
#define __channel_descriptor_alternateDataStructureDestinationEndPointer(channel)		( __channel_descriptor_alternateDataStructure(channel).destinationEndPointer )
#define __channel_descriptor_alternateDataStructureSourceEndPointer(channel)			( __channel_descriptor_alternateDataStructure(channel).sourceEndPointer )

#define __channel_descriptor_getNumberMinusOneValue(transferCount)				( ((transferCount) - 1) << 4 )

 /**********************************************************************************************************************
 * Private function-like macros that DO return value
 **********************************************************************************************************************/
#define __channel_descriptor_getPrimaryDestinationIncrementation(channel) (\
		(channel_descriptor_getPrimaryDestinationAddressIncrement(channel)==channel_descriptor_getDestinationAddressIncrementByteValue())?1:\
		(channel_descriptor_getPrimaryDestinationAddressIncrement(channel)==channel_descriptor_getDestinationAddressIncrementHalfWordValue())?2:\
		(channel_descriptor_getPrimaryDestinationAddressIncrement(channel)==channel_descriptor_getDestinationAddressIncrementWordValue())?4:0)\


#define __channel_descriptor_getPrimaryRightAlignedNMinus1(channel)					( channel_descriptor_getPrimaryNMinus1(channel) >> 4 )
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

// get data structure primary channel
#define channel_descriptor_getPrimaryDataStructureUser(channel) 					( __channel_descriptor_primaryDataStructureUser(channel) )
#define channel_descriptor_getPrimaryDataStructureControl(channel)					( __channel_descriptor_primaryDataStructureControl(channel) )
#define channel_descriptor_getPrimaryDataStructureDestinationEndPointer(channel) 	( __channel_descriptor_primaryDataStructureDestinationEndPointer(channel) )
#define channel_descriptor_getPrimaryDataStructureSourceEndPointer(channel)			( __channel_descriptor_primaryDataStructureSourceEndPointer(channel) )
// get data structure alternate channel
#define channel_descriptor_getAlternateDataStructureUser(channel) 					( __channel_descriptor_alternateDataStructureUser(channel) )
#define channel_descriptor_getAlternateDataStructureControl(channel)				( __channel_descriptor_alternateDataStructureControl(channel) )
#define channel_descriptor_getAlternateDataStructureDestinationEndPointer(channel) 	( __channel_descriptor_alternateDataStructureDestinationEndPointer(channel) )
#define channel_descriptor_getAlternateDataStructureSourceEndPointer(channel)		( __channel_descriptor_alternateDataStructureSourceEndPointer(channel) )

// DST_INC
// DESTINATION ADDRESS INCREMENT MUST BE GREATER THAN OR EQUAL TO THE SOURCE DATA WIDTH !!!
#define channel_descriptor_getDestinationAddressIncrementMask()						( CHANNEL_DESCRIPTOR_getBitsMask(31, 30) )
#define channel_descriptor_getPrimaryDestinationAddressIncrement(channel)			( CHANNEL_DESCRIPTOR_getProperty(\
																					__channel_descriptor_primaryDataStructureControl(channel),\
																					channel_descriptor_getDestinationAddressIncrementMask() ))
#define channel_descriptor_getDestinationAddressIncrementByteValue()				( CHANNEL_DESCRIPTOR_getPropertyValue(0b00, 30) )
#define channel_descriptor_getDestinationAddressIncrementHalfWordValue()			( CHANNEL_DESCRIPTOR_getPropertyValue(0b01, 30) )
#define channel_descriptor_getDestinationAddressIncrementWordValue()				( CHANNEL_DESCRIPTOR_getPropertyValue(0b10, 30) )
#define channel_descriptor_getDestinationAddressIncrementNoIncrementValue()			( CHANNEL_DESCRIPTOR_getPropertyValue(0b11, 30) )
// DST_SIZE
// DESTINATION DATA SIZE(RIGHT-ALIGNED VALUE) MUST BE EQUAL TO THE SOURCE DATA SIZE (RIGHT-ALIGNED VALUE)
#define channel_descriptor_getDestinationDataSizeMask()								( CHANNEL_DESCRIPTOR_getBitsMask(29, 28) )
#define channel_descriptor_getDestinationDataSizeByteValue()						( CHANNEL_DESCRIPTOR_getPropertyValue(0b00, 28) )
#define channel_descriptor_getDestinationDataSizeHalfWordValue()					( CHANNEL_DESCRIPTOR_getPropertyValue(0b01, 28) )
#define channel_descriptor_getDestinationDataSizeWordValue()						( CHANNEL_DESCRIPTOR_getPropertyValue(0b10, 28) )
// SRC_INC
#define channel_descriptor_getSourceAddressIncrementMask()							( CHANNEL_DESCRIPTOR_getBitsMask(27, 26) )
#define channel_descriptor_getSourceAddressIncrementByteValue()                     ( CHANNEL_DESCRIPTOR_getPropertyValue(0b00, 26) )
#define channel_descriptor_getSourceAddressIncrementHalfWordValue()                 ( CHANNEL_DESCRIPTOR_getPropertyValue(0b01, 26) )
#define channel_descriptor_getSourceAddressIncrementWordValue()                     ( CHANNEL_DESCRIPTOR_getPropertyValue(0b10, 26) )
#define channel_descriptor_getSourceAddressIncrementNoIncrementValue()              ( CHANNEL_DESCRIPTOR_getPropertyValue(0b11, 26) )
// SRC_SIZE
#define channel_descriptor_getSourceDataSizeMask()									( CHANNEL_DESCRIPTOR_getBitsMask(25, 24) )
#define channel_descriptor_getSourceDataSizeByteValue()								( CHANNEL_DESCRIPTOR_getPropertyValue(0b00, 24) )
#define channel_descriptor_getSourceDataSizeHalfWordValue()							( CHANNEL_DESCRIPTOR_getPropertyValue(0b01, 24) )
#define channel_descriptor_getSourceDataSizeWordValue()								( CHANNEL_DESCRIPTOR_getPropertyValue(0b10, 24) )
// DST_PROT_CTRL
#define channel_descriptor_getDestinationDataAccessControlMask()					( CHANNEL_DESCRIPTOR_getBitsMask(23, 21) )
#define channel_descriptor_getDestinationDataAccessControlNonPriviledgedValue()		( CHANNEL_DESCRIPTOR_getPropertyValue(0, 24) )
#define channel_descriptor_getDestinationDataAccessControlPriviledgedValue()		( CHANNEL_DESCRIPTOR_getPropertyValue(1, 24) )
// SRC_PROT_CTRL
#define channel_descriptor_getSourceDataAccessControlMask()							( CHANNEL_DESCRIPTOR_getBitsMask(20, 18) )
#define channel_descriptor_getSourceDataAccessControlNonPriviledgedValue()			( CHANNEL_DESCRIPTOR_getPropertyValue(0, 18) )
#define channel_descriptor_getSourceDataAccessControlPriviledgedValue()				( CHANNEL_DESCRIPTOR_getPropertyValue(1, 18) )
// R_POWER
#define channel_descriptor_getArbitrationPeriodMask()								( CHANNEL_DESCRIPTOR_getBitsMask(17, 14) )
#define channel_descriptor_getArbitrateAfterEachTransferValue()						( CHANNEL_DESCRIPTOR_getPropertyValue(0b0000, 14) )
#define channel_descriptor_getArbitrateAfter2TransfersValue()						( CHANNEL_DESCRIPTOR_getPropertyValue(0b0001, 14) )
#define channel_descriptor_getArbitrateAfter4TransfersValue()						( CHANNEL_DESCRIPTOR_getPropertyValue(0b0010, 14) )
#define channel_descriptor_getArbitrateAfter8TransfersValue()						( CHANNEL_DESCRIPTOR_getPropertyValue(0b0011, 14) )
#define channel_descriptor_getArbitrateAfter16TransfersValue()						( CHANNEL_DESCRIPTOR_getPropertyValue(0b0100, 14) )
#define channel_descriptor_getArbitrateAfter32TransfersValue()						( CHANNEL_DESCRIPTOR_getPropertyValue(0b0101, 14) )
#define channel_descriptor_getArbitrateAfter64TransfersValue()						( CHANNEL_DESCRIPTOR_getPropertyValue(0b0110, 14) )
#define channel_descriptor_getArbitrateAfter128TransfersValue()						( CHANNEL_DESCRIPTOR_getPropertyValue(0b0111, 14) )
#define channel_descriptor_getArbitrateAfter256TransfersValue()						( CHANNEL_DESCRIPTOR_getPropertyValue(0b1000, 14) )
#define channel_descriptor_getArbitrateAfter512TransfersValue()						( CHANNEL_DESCRIPTOR_getPropertyValue(0b1001, 14) )
#define channel_descriptor_getArbitrateAfter1024TransfersValue()					( CHANNEL_DESCRIPTOR_getPropertyValue(0b1010, 14) )
// N_MINUS_1
#define channel_descriptor_getCycleTransferCountMask()								( CHANNEL_DESCRIPTOR_getBitsMask(13, 4) )
#define channel_descriptor_getPrimaryNMinus1(channel)								( CHANNEL_DESCRIPTOR_getProperty( \
																					__channel_descriptor_primaryDataStructureControl(channel),\
																					channel_descriptor_getCycleTransferCountMask()) )

#define channel_descriptor_getPrimaryRemainTransferCount(channel)					( ( channel_descriptor_getPrimaryNMinus1(channel) >> 4 ) + 1 )

#define channel_descriptor_getCh0PrimaryRemainingTransferCount()					( channel_descriptor_getPrimaryRemainTransferCount(0) )





#define channel_descriptor_getAlternateNMinus1(channel)								( CHANNEL_DESCRIPTOR_getProperty(\
																					__channel_descriptor_alternateDataStructureControl(channel),\
																					channel_descriptor_getCycleTransferCountMask()))\
// NEXT_USEBURST
#define channel_descriptor_getNextUseBurstMask()									( CHANNEL_DESCRIPTOR_getBitsMask(3, 3) )
// CYCLE_CTRL
#define channel_descriptor_getCycleControlMask()									( CHANNEL_DESCRIPTOR_getBitsMask(2, 0) )
#define channel_descriptor_getStopDataStructureValue()								( CHANNEL_DESCRIPTOR_getPropertyValue(0b000, 0) )
#define channel_descriptor_getBasicModeValue()										( CHANNEL_DESCRIPTOR_getPropertyValue(0b001, 0) )
#define channel_descriptor_getAutoRequestModeValue()								( CHANNEL_DESCRIPTOR_getPropertyValue(0b010, 0) )
#define channel_descriptor_getPingPongModeValue()                                   ( CHANNEL_DESCRIPTOR_getPropertyValue(0b011, 0) )
#define channel_descriptor_getPrimaryMemoryScatterGatherModeValue()                 ( CHANNEL_DESCRIPTOR_getPropertyValue(0b100, 0) )
#define channel_descriptor_getAlternateMemoryScatterGathereModeValue()              ( CHANNEL_DESCRIPTOR_getPropertyValue(0b101, 0) )
#define channel_descriptor_getPrimaryPeripheralScatterGathereModeValue()          	( CHANNEL_DESCRIPTOR_getPropertyValue(0b110, 0) )
#define channel_descriptor_getAlternatePeripheralScatterGathereModeValue()          ( CHANNEL_DESCRIPTOR_getPropertyValue(0b111, 0) )

// Primary properties
#define channel_descriptor_getPrimaryDestinationDataSize(channel)					( channel_descriptor_getPrimaryDataStructureControl(channel) & \
																					channel_descriptor_getDestinationDataSizeMask() )

#define channel_descriptor_getPrimarySourceAddressIncrement(channel)				( channel_descriptor_getPrimaryDataStructureControl(channel) & \
																					channel_descriptor_getSourceAddressIncrementMask() )

#define channel_descriptor_getPrimarySourceDataSize(channel)						( channel_descriptor_getPrimaryDataStructureControl(channel) & \
																					channel_descriptor_getSourceDataSizeMask() )

#define channel_descriptor_getPrimaryDestinationDataAccessControl(channel)			( channel_descriptor_getPrimaryDataStructureControl(channel) & \
																					channel_descriptor_getDestinationDataAccessControlMask() )

#define channel_descriptor_getPrimarySourceDataAccessControl(channel)				( channel_descriptor_getPrimaryDataStructureControl(channel) & \
																					channel_descriptor_getSourceDataAccessControlMask() )

#define channel_descriptor_getPrimaryArbitrationPeriod(channel)						( channel_descriptor_getPrimaryDataStructureControl(channel) & \
																					channel_descriptor_getArbitrationPeriodMask() )

#define channel_descriptor_getPrimaryCycleTransferCount(channel)					( channel_descriptor_getPrimaryDataStructureControl(channel) & \
																					channel_descriptor_getCycleTransferCountMask() )

#define channel_descriptor_isPrimaryNextUseBurstRaised(channel)						( channel_descriptor_getPrimaryDataStructureControl(channel) & \
																					channel_descriptor_getNextUseBurstMask() )

#define channel_descriptor_getPrimaryCycleControl(channel)							( channel_descriptor_getPrimaryDataStructureControl(channel) & \
																					channel_descriptor_getCycleControlMask() )

// Alternate properties
#define channel_descriptor_getAlternateDestinationAddressIncrement(channel)			( channel_descriptor_getAlternateDataStructureControl(channel) & \
																					channel_descriptor_getDestinationAddressIncrementMask()	)

#define channel_descriptor_getAlternateDestinationDataSize(channel)					( channel_descriptor_getAlternateDataStructureControl(channel) & \
																					channel_descriptor_getDestinationDataSizeMask() )

#define channel_descriptor_getAlternateSourceAddressIncrement(channel)				( channel_descriptor_getAlternateDataStructureControl(channel) & \
																					channel_descriptor_getSourceAddressIncrementMask() )

#define channel_descriptor_getAlternateSourceDataSize(channel)						( channel_descriptor_getAlternateDataStructureControl(channel) & \
																					channel_descriptor_getSourceDataSizeMask() )

#define channel_descriptor_getAlternateDestinationDataAccessControl(channel)		( channel_descriptor_getAlternateDataStructureControl(channel) & \
																					channel_descriptor_getDestinationDataAccessControlMask() )

#define channel_descriptor_getAlternateSourceDataAccessControl(channel)				( channel_descriptor_getAlternateDataStructureControl(channel) & \
																					channel_descriptor_getSourceDataAccessControlMask() )

#define channel_descriptor_getAlternateArbitrationPeriod(channel)					( channel_descriptor_getAlternateDataStructureControl(channel) & \
																					channel_descriptor_getArbitrationPeriodMask() )

#define channel_descriptor_getAlternateCycleTransferCount(channel)					( channel_descriptor_getAlternateDataStructureControl(channel) & \
																					channel_descriptor_getCycleTransferCountMask() )

#define channel_descriptor_isAlternateNextUseBurstRaised(channel)					( channel_descriptor_getAlternateDataStructureControl(channel) & \
																					channel_descriptor_getNextUseBurstMask() )

#define channel_descriptor_getAlternateCycleControl(channel)						( channel_descriptor_getAlternateDataStructureControl(channel) & \
																					channel_descriptor_getCycleControlMask() )


//--Gives the address for specified channel where DMA shall write next.
#define channel_descriptor_getPrimaryNextWriteAddress(channel)		( (uint32_t)CHANNEL_DESCRIPTOR_getCh0DestEndAddr() -\
							( (__channel_descriptor_getPrimaryDestinationIncrementation(channel)) * ( __channel_descriptor_getPrimaryRightAlignedNMinus1(0) )  ))

#define channel_descriptor_getCh0PrimaryNextWriteAddress()			( channel_descriptor_getPrimaryNextWriteAddress(0) )

 /**********************************************************************************************************************
 * Public function-like macros that DO NOT return value
 **********************************************************************************************************************/


/********************************* SET PRIMARY DATA STRUCURE *********************************/

// SRC_END_POINTER
#define channel_descriptor_setPrimarySourceEndPointer(channel, address)			do{ channel_descriptor_getPrimaryDataStructureSourceEndPointer(channel) = \
																					( ((uint32_t)(address)) );\
																				}while(0)



// SRC_INC
#define channel_descriptor_setPrimarySourceAddressIncrementByte(channel)				do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                    			channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                    			channel_descriptor_getSourceAddressIncrementMask(),\
                                                                                    			channel_descriptor_getSourceAddressIncrementByteValue());\
                                                                                    		}while(0)

#define channel_descriptor_setPrimarySourceAddressIncrementHalfWord(channel)			do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getSourceAddressIncrementMask(),\
                                                                                            	channel_descriptor_getSourceAddressIncrementHalfWordValue());\
                                                                                            }while(0)

#define channel_descriptor_setPrimarySourceAddressIncrementWord(channel)				do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getSourceAddressIncrementMask(),\
                                                                                            	channel_descriptor_getSourceAddressIncrementWordValue());\
                                                                                            }while(0)

#define channel_descriptor_setPrimarySourceAddressIncrementNoIncrement(channel)		do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getSourceAddressIncrementMask(),\
                                                                                            	channel_descriptor_getSourceAddressIncrementNoIncrementValue());\
                                                                                            }while(0)

// SRC_SIZE
#define channel_descriptor_setPrimarySourceDataSizeByte(channel)							do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getSourceDataSizeMask(),\
                                                                                            	channel_descriptor_getSourceDataSizeByteValue() );\
                                                                                            }while(0)
#define channel_descriptor_setPrimarySourceDataSizeHalfWord(channel)						do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getSourceDataSizeMask(),\
                                                                                            	channel_descriptor_getSourceDataSizeHalfWordValue() );\
                                                                                            }while(0)
#define channel_descriptor_setPrimarySourceDataSizeWord(channel)							do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getSourceDataSizeMask(),\
                                                                                            	channel_descriptor_getSourceDataSizeWordValue() );\
                                                                                            }while(0)






// SRC_ACCESS_CTRL
#define channel_descriptor_setPrimarySourceDataAccessControlNonPriviledged(channel)	do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getSourceDataAccessControlMask(),\
                                                                                            	channel_descriptor_getSourceDataAccessControlNonPriviledgedValue() );\
                                                                                            }while(0)

#define channel_descriptor_setPrimarySourceDataAccessControlPriviledgedValue(channel)		do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getSourceDataAccessControlMask(),\
                                                                                            	channel_descriptor_getSourceDataAccessControlPriviledgedValue() );\
                                                                                            }while(0)

// R_POWER ARBITRATION PERIOD
#define channel_descriptor_setPrimaryArbitrateAfterEachTransfer(channel)				do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfterEachTransferValue() );\
                                                                                            }while(0)
#define channel_descriptor_setPrimaryArbitrateAfter2Transfers(channel)					do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter2TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setPrimaryArbitrateAfter4Transfers(channel)					do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter4TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setPrimaryArbitrateAfter8Transfers(channel)                 do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter8TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setPrimaryArbitrateAfter16Transfers(channel)                do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter16TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setPrimaryArbitrateAfter32Transfers(channel)                do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter32TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setPrimaryArbitrateAfter64Transfers(channel)                do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter64TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setPrimaryArbitrateAfter128Transfers(channel)               do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter128TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setPrimaryArbitrateAfter256Transfers(channel)               do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter256TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setPrimaryArbitrateAfter512Transfers(channel)               do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter512TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setPrimaryArbitrateAfter1024Transfers(channel)              do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter1024TransfersValue() );\
                                                                                            }while(0)

// N_MINUS_1 ( value = {1....1024Transfers } )
#define channel_descriptor_setPrimaryCycleTransferCount(channel, transferCount)				do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getCycleTransferCountMask(),\
                                                                                            	__channel_descriptor_getNumberMinusOneValue(transferCount));\
                                                                                            }while(0)
	// NEXT_USEBURST
#define channel_descriptor_raisePrimaryNextUseBurst(channel)								do{ CHANNEL_DESCRIPTOR_raiseBits(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getNextUseBurstMask() );\
                                                                                            }while(0)
#define channel_descriptor_clearPrimaryNextUseBurst(channel)								do{ CHANNEL_DESCRIPTOR_clearBits(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getNextUseBurstMask() );\
                                                                                            }while(0)

	// CYCLE_CTRL

#define channel_descriptor_setPrimaryStopDataStructureValue(channel)						do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getCycleControlMask(),\
                                                                                            	channel_descriptor_getStopDataStructureValue());\
                                                                                            }while(0)
#define channel_descriptor_setPrimaryBasicMode(channel)                                 	do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getCycleControlMask(),\
                                                                                            	channel_descriptor_getBasicModeValue());\
                                                                                            }while(0)
#define channel_descriptor_setPrimaryAutoRequestMode(channel)                            	do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getCycleControlMask(),\
                                                                                            	channel_descriptor_getAutoRequestModeValue());\
                                                                                            }while(0)
#define channel_descriptor_setPrimaryPingPongMode(channel)                         			do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getCycleControlMask(),\
                                                                                            	channel_descriptor_getPingPongModeValue());\
                                                                                            }while(0)
#define channel_descriptor_setPrimaryMemoryScatterGatherMode(channel)                 		do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getCycleControlMask(),\
                                                                                            	channel_descriptor_getPrimaryMemoryScatterGatherModeValue());\
                                                                                            }while(0)
#define channel_descriptor_setPrimaryPeripheralScatterGathereMode(channel)					do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getCycleControlMask(),\
                                                                                            	channel_descriptor_getPrimaryPeripheralScatterGathereModeValue());\
                                                                                            }while(0)


// DST_END_POINTER
#define channel_descriptor_setPrimaryDestinationEndPointer(channel, address)	do{ channel_descriptor_getPrimaryDataStructureDestinationEndPointer(channel)=\
																					( ((uint32_t)(address)) );\
																				}while(0)
// DST_INC
#define channel_descriptor_setPrimaryDestinationAddressIncrementByte(channel)				do{ CHANNEL_DESCRIPTOR_setProperty(\
																						channel_descriptor_getPrimaryDataStructureControl(channel),\
																						channel_descriptor_getDestinationAddressIncrementMask(),\
																						channel_descriptor_getDestinationAddressIncrementByteValue());\
																					}while(0)

#define channel_descriptor_setPrimaryDestinationAddressIncrementHalfWord(channel)			do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                    	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                    	channel_descriptor_getDestinationAddressIncrementMask(),\
                                                                                    	channel_descriptor_getDestinationAddressIncrementHalfWordValue());\
                                                                                    }while(0)

#define channel_descriptor_setPrimaryDestinationAddressIncrementWord(channel)				do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                    	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                    	channel_descriptor_getDestinationAddressIncrementMask(),\
                                                                                    	channel_descriptor_getDestinationAddressIncrementWordValue());\
                                                                                    }while(0)

#define channel_descriptor_setPrimaryDestinationAddressIncrementNoIncrement(channel)  do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                    	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                    	channel_descriptor_getDestinationAddressIncrementMask(),\
                                                                                    	channel_descriptor_getDestinationAddressIncrementNoIncrementValue());\
                                                                                    }while(0)

// DST_ACCESS_CTRL
#define channel_descriptor_setPrimaryDestinationDataAccessControlNonPriviledged(channel) 		do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getDestinationDataAccessControlMask(),\
                                                                                            	channel_descriptor_getDestinationDataAccessControlNonPriviledgedValue() );\
                                                                                            }while(0)

#define channel_descriptor_setPrimaryDestinationDataAccessControlPriviledgedValue(channel)	do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                            	channel_descriptor_getDestinationDataAccessControlMask(),\
                                                                                            	channel_descriptor_getDestinationDataAccessControlPriviledgedValue() );\
                                                                                            }while(0)

// DST_SIZE
// DESTINATION DATA SIZE(RIGHT-ALIGNED VALUE) MUST BE EQUAL TO THE SOURCE DATA SIZE (RIGHT-ALIGNED VALUE)
#define channel_descriptor_setPrimaryDestinationDataSizeByte(channel)					do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                    			channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                    			channel_descriptor_getDestinationDataSizeMask(),\
                                                                                    			channel_descriptor_getDestinationDataSizeByteValue());\
                                                                                    		}while(0)
#define channel_descriptor_setPrimaryDestinationDataSizeHalfWord(channel)				do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                    			channel_descriptor_getPrimaryDataStructureControl(channel),\
                                                                                    			channel_descriptor_getDestinationDataSizeMask(),\
                                                                                    			channel_descriptor_getDestinationDataSizeHalfWordValue());\
																							}while(0)
#define channel_descriptor_setPrimaryDestinationDataSizeWord(channel)					do{ CHANNEL_DESCRIPTOR_setProperty(\
																								channel_descriptor_getPrimaryDataStructureControl(channel),\
																								channel_descriptor_getDestinationDataSizeMask(),\
																								channel_descriptor_getDestinationDataSizeWordValue());\
																							}while(0)

/********************************* SET ALTERNATE DATA STRUCURE *********************************/
// DST_INC
#define channel_descriptor_setAlternateDestinationAddressIncrementByte(channel)				do{ CHANNEL_DESCRIPTOR_setProperty(\
																						channel_descriptor_getAlternateDataStructureControl(channel),\
																						channel_descriptor_getDestinationAddressIncrementMask(),\
																						channel_descriptor_getDestinationAddressIncrementByteValue());\
																					}while(0)
#define channel_descriptor_setAlternateDestinationAddressIncrementHalfWord(channel)			do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                    	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                    	channel_descriptor_getDestinationAddressIncrementMask(),\
                                                                                    	channel_descriptor_getDestinationAddressIncrementHalfWordValue());\
                                                                                    }while(0)
#define channel_descriptor_setAlternateDestinationAddressIncrementWord(channel)				do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                    	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                    	channel_descriptor_getDestinationAddressIncrementMask(),\
                                                                                    	channel_descriptor_getDestinationAddressIncrementWordValue());\
                                                                                    }while(0)
#define channel_descriptor_setAlternateDestinationAddressIncrementNoIncrement(channel)  do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                    	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                    	channel_descriptor_getDestinationAddressIncrementMask(),\
                                                                                    	channel_descriptor_getDestinationAddressIncrementNoIncrement());\
                                                                                    }while(0)
// DST_SIZE
// DESTINATION DATA SIZE(RIGHT-ALIGNED VALUE) MUST BE EQUAL TO THE SOURCE DATA SIZE (RIGHT-ALIGNED VALUE)
#define channel_descriptor_setAlternateDestinationDataSizeByte(channel)					do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                    			channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                    			channel_descriptor_getDestinationDataSizeMask(),\
                                                                                    			channel_descriptor_getDestinationDataSizeByteValue());\
                                                                                    		}while(0)
#define channel_descriptor_setAlternateDestinationDataSizeHalfWord(channel)				do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                    			channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                    			channel_descriptor_getDestinationDataSizeMask(),\
                                                                                    			channel_descriptor_getDestinationDataSizeHalfWordValue());\
																							}while(0)
#define channel_descriptor_setAlternateDestinationDataSizeWord(channel)					do{ CHANNEL_DESCRIPTOR_setProperty(\
																								channel_descriptor_getAlternateDataStructureControl(channel),\
																								channel_descriptor_getDestinationDataSizeMask(),\
																								channel_descriptor_getDestinationDataSizeWordValue());\
																							}while(0)

// SRC_INC
#define channel_descriptor_setAlternateSourceAddressIncrementByte(channel)				do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                    			channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                    			channel_descriptor_getSourceAddressIncrementMask(),\
                                                                                    			channel_descriptor_getSourceAddressIncrementByteValue());\
                                                                                    		}while(0)

#define channel_descriptor_setAlternateSourceAddressIncrementHalfWord(channel)			do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getSourceAddressIncrementMask(),\
                                                                                            	channel_descriptor_getSourceAddressIncrementHalfWordValue());\
                                                                                            }while(0)

#define channel_descriptor_setAlternateSourceAddressIncrementWord(channel)				do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getSourceAddressIncrementMask(),\
                                                                                            	channel_descriptor_getSourceAddressIncrementWordValue());\
                                                                                            }while(0)

#define channel_descriptor_setAlternateSourceAddressIncrementNoIncrement(channel)		do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getSourceAddressIncrementMask(),\
                                                                                            	channel_descriptor_getSourceAddressIncrementNoIncrementValue());\
                                                                                            }while(0)

// SRC_SIZE
#define channel_descriptor_setAlternateSourceDataSizeByte(channel)						do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getSourceDataSizeMask(),\
                                                                                            	channel_descriptor_getSourceDataSizeByteValue() );\
                                                                                            }while(0)
#define channel_descriptor_setAlternateSourceDataSizeHalfWord(channel)					do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getSourceDataSizeMask(),\
                                                                                            	channel_descriptor_getSourceDataSizeHalfWordValue() );\
                                                                                            }while(0)
#define channel_descriptor_setAlternateSourceDataSizeWord(channel)						do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getSourceDataSizeMask(),\
                                                                                            	channel_descriptor_getSourceDataSizeWordValue() );\
                                                                                            }while(0)

// DST_PROT_CTRL
#define channel_descriptor_setAlternateDestinationDataAccessControlNonPriviledged(channel) 		do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getDestinationDataAccessControlMask(),\
                                                                                            	channel_descriptor_getDestinationDataAccessControlNonPriviledgedValue() );\
                                                                                            }while(0)

#define channel_descriptor_setAlternateDestinationDataAccessControlPriviledged(channel)	do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getDestinationDataAccessControlMask(),\
                                                                                            	channel_descriptor_getDestinationDataAccessControlPriviledgedValue() );\
                                                                                            }while(0)


// SRC_PROT_CTRL
#define channel_descriptor_setAlternateSourceDataAccessControlNonPriviledged(channel)	do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getSourceDataAccessControlMask(),\
                                                                                            	channel_descriptor_getSourceDataAccessControlNonPriviledgedValue() );\
                                                                                            }while(0)

#define channel_descriptor_setAlternateSourceDataAccessControlPriviledged(channel)		do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getSourceDataAccessControlMask(),\
                                                                                            	channel_descriptor_getSourceDataAccessControlPriviledgedValue() );\
                                                                                            }while(0)

// R_POWER
#define channel_descriptor_setAlternateArbitrateAfterEachTransfer(channel)				do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfterEachTransferValue() );\
                                                                                            }while(0)
#define channel_descriptor_setAlternateArbitrateAfter2Transfers(channel)					do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter2TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setAlternateArbitrateAfter4Transfers(channel)					do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter4TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setAlternateArbitrateAfter8Transfers(channel)                 do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter8TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setAlternateArbitrateAfter16Transfers(channel)                do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter16TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setAlternateArbitrateAfter32Transfers(channel)                do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter32TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setAlternateArbitrateAfter64Transfers(channel)                do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter64TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setAlternateArbitrateAfter128Transfers(channel)               do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter128TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setAlternateArbitrateAfter256Transfers(channel)               do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter256TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setAlternateArbitrateAfter512Transfers(channel)               do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter512TransfersValue() );\
                                                                                            }while(0)
#define channel_descriptor_setAlternateArbitrateAfter1024Transfers(channel)              do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getArbitrationPeriodMask(),\
                                                                                            	channel_descriptor_getArbitrateAfter1024TransfersValue() );\
                                                                                            }while(0)

// N_MINUS_1 ( value = {0....1023}{1Transfer....1024Transfers } )
#define channel_descriptor_setAlternateCycleTransferCount(channel, transferCount)			do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getCycleTransferCountMask(),\
                                                                                            	__channel_descriptor_getNumberMinusOneValue(transferCount) );\
                                                                                            }while(0)
	// NEXT_USEBURST
#define channel_descriptor_raiseAlternateNextUseBurst(channel)								do{ CHANNEL_DESCRIPTOR_raiseBits(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getNextUseBurstMask() );\
                                                                                            }while(0)

	// CYCLE_CTRL
#define channel_descriptor_setAlternateStopDataStructure(channel)								do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getCycleControlMask(),\
                                                                                            	channel_descriptor_getStopDataStructureValue());\
                                                                                            }while(0)
#define channel_descriptor_setAlternateBasicMode(channel)                                              do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getCycleControlMask(),\
                                                                                            	channel_descriptor_getBasicModeValue());\
                                                                                            }while(0)
#define channel_descriptor_setAlternateAutoRequestMode(channel)                                        do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getCycleControlMask(),\
                                                                                            	channel_descriptor_getAutoRequestModeValue());\
                                                                                            }while(0)
#define channel_descriptor_setAlternatePingPongMode(channel)                                           do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getCycleControlMask(),\
                                                                                            	channel_descriptor_getPingPongModeValue());\
                                                                                            }while(0)
#define channel_descriptor_setAlternateMemoryScatterGathereMode(channel)                      do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getCycleControlMask(),\
                                                                                            	channel_descriptor_getAlternateMemoryScatterGathereModeValue());\
                                                                                            }while(0)
#define channel_descriptor_setAlternatePeripheralScatterGathereMode(channel)                  do{ CHANNEL_DESCRIPTOR_setProperty(\
                                                                                            	channel_descriptor_getAlternateDataStructureControl(channel),\
                                                                                            	channel_descriptor_getCycleControlMask(),\
                                                                                            	channel_descriptor_getAlternatePeripheralScatterGathereModeValue());\
                                                                                            }while(0)




#define channel_descriptor_setAlternateDestinationEndPointer(channel, address)	do{ channel_descriptor_getAlternateDataStructureDestinationEndPointer(channel)=\
																					( address );\
																				}while(0)

#define channel_descriptor_setAlternateSourceEndPointer(channel, address)			do{ channel_descriptor_getAlternateDataStructureSourceEndPointer(channel) = \
																					( address );\
																				}while(0)
//													__channel_descriptor_primaryDataStructureControl(0) = 0xC0000031;
#define channel_descriptor_init()				do{;\
													channel_descriptor_setPrimaryDestinationEndPointer(0, CHANNEL_DESCRIPTOR_getCh0DestEndAddr() );\
													channel_descriptor_setPrimarySourceEndPointer(0, CHANNEL_DESCRIPTOR_getCh0SourceEndAddr() );\
													channel_descriptor_setPrimaryDestinationAddressIncrementByte(0);\
													channel_descriptor_setPrimaryDestinationDataSizeByte(0);\
													channel_descriptor_setPrimarySourceAddressIncrementNoIncrement(0);\
													channel_descriptor_setPrimarySourceDataSizeByte(0);\
													channel_descriptor_setPrimaryDestinationDataAccessControlNonPriviledged(0);\
													channel_descriptor_setPrimarySourceDataAccessControlNonPriviledged(0);\
													channel_descriptor_setPrimaryArbitrateAfterEachTransfer(0);\
													channel_descriptor_setPrimaryCycleTransferCount(0, CHANNEL_DESCRIPTOR_getCh0TransferCount() );\
													channel_descriptor_clearPrimaryNextUseBurst(0);\
													channel_descriptor_setPrimaryBasicMode(0);\
												}while(0)
 /**********************************************************************************************************************
 * Public function declarations (extern)
 **********************************************************************************************************************/

#endif //__CHANNEL_DECRIPTOR_DERIVATIVE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
