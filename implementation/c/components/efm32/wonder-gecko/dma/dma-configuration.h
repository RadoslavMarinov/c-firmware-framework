/**********************************************************************************************************************
 * C Configuration Header: dma-configuration.h
 * Component: DMA
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __DMA_CONFIGURATION__
#define __DMA_CONFIGURATION__

 /**********************************************************************************************************************
 * Interface declarations required by its own classes
 **********************************************************************************************************************/

/************************ typedef macros ************************/

//-- DMA
#define DMA_ChannelDescriptorSelfData								chanel_descriptor_SelfData


//--phrase
#define PHRASE_CHANNEL_State										uint8_t


/*************************  Object-like macros  *************************/
//-channel
#define CHANNEL_getStatus()											( dma_sfr.status )
#define CHANNEL_getControlDataBasePointer()			 				( dma_sfr.channelControlDataBasePointer )
#define CHANNEL_getAlternateControlDataBasePointer()				( dma_sfr.channelAlternateControlDataBasePointer )
#define CHANNEL_getWaitOnRequestStatus()							( dma_sfr.channelWaitOnRequestStatus )
#define CHANNEL_getSoftwareRequest()								( dma_sfr.channelSoftwareRequest )
#define CHANNEL_getRequestMaskSet()					 				( dma_sfr.channelRequestMaskSet )
#define CHANNEL_getRequestMaskClear()				 				( dma_sfr.channelRequestMaskClear )
#define CHANNEL_getEnableSet()						 				( dma_sfr.channelEnableSet )
#define CHANNEL_getEnableClear()									( dma_sfr.channelEnableClear )
#define CHANNEL_getAlternateSet()					 				( dma_sfr.channelAlternateSet )
#define CHANNEL_getAlternateClear()					 				( dma_sfr.channelAlternateClear )
#define CHANNEL_getPrioritySet()									( dma_sfr.channelPrioritySet )
#define CHANNEL_getPriorityClear()					 				( dma_sfr.channelPriorityClear )
#define CHANNEL_getRequestStatus()									( dma_sfr.channelRequestStatus )
#define CHANNEL_getInterruptFlag()									( dma_sfr.interruptFlag )
#define CHANNEL_getInterruptFlagSet()								( dma_sfr.interruptFlagSet )
#define CHANNEL_getInterruptFlagClear()								( dma_sfr.interruptFlagClear )
#define CHANNEL_getInterruptEnable()								( dma_sfr.interruptEnable )
#define CHANNEL_getControl(channel)									( dma_sfr.channelControl[channel] )

//--channel descriptor

#define CHANNEL_DESCRIPTOR_dataStructure							( DMA_selfData )
#define CHANNEL_DESCRIPTOR_getCh0SourceEndAddr()				( DMA_getCh0SourceEndAddr() )
#define CHANNEL_DESCRIPTOR_getCh0DestEndAddr()					( DMA_getCh0DestEndAddr() )
#define CHANNEL_DESCRIPTOR_getCh0TransferCount()					( DMA_getCh0TransferCount() )


/************************ Function-like macros that DO return value *************************/
#define CHANNEL_DESCRIPTOR_getUsart1TxBufferAddress()				( DMA_getUsart1TxBufferAddress() )
#define CHANNEL_DESCRIPTOR_getUart1TxBufferAddress()				( DMA_getUart1TxBufferAddress() )
#define CHANNEL_DESCRIPTOR_getProperty(reg, mask)					( CHANNEL_getPorperty(reg, mask) )

#define CHANNEL_DESCRIPTOR_getBitsMask(EndBit, StartBit)			( DMA_getBitsMask(EndBit, StartBit) )
#define CHANNEL_DESCRIPTOR_getPropertyValue(value, startBit)		( DMA_getPropertyValue(value, startBit) )
#define CHANNEL_assert1(reg, mask)									( DMA_assert1(reg, mask) )

#define CHANNEL_getBitsMask(EndBit, StartBit)						( DMA_getBitsMask(EndBit, StartBit) )
#define CHANNEL_getPorperty(reg, mask)								( DMA_getProperty(reg, mask) )

/************************ Function-like macros that DO NOT return value ************************/

//--channel descriptor
#define CHANNEL_DESCRIPTOR_setProperty(object, mask, value)			do{ DMA_setProperty(object, mask, value); }while(0)
#define CHANNEL_DESCRIPTOR_raiseBits(reg, mask) 					do{ DMA_raiseBits(reg, mask);}while(0)
#define CHANNEL_DESCRIPTOR_clearBits(reg, mask) 					do{ DMA_clearBits(reg, mask);}while(0)

//-- DMA
#define DMA_channelDescriptorInit()									do{ channel_descriptor_init(); }while(0)

#endif //__DMA_CONFIGURATION__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
