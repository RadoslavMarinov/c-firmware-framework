/**********************************************************************************************************************
 * C Configuration Header: electricity-meter-application-configuration.h
 * Application: Electricity Meter Application
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include guard
#ifndef __ELECTRICITY_METER_APPLICATION_CONFIGURATION__
#define __ELECTRICITY_METER_APPLICATION_CONFIGURATION__

/**********************************************************************************************************************
* Configuration files of component
**********************************************************************************************************************/

//
#include "components/efm32/cmu/cmu-configuration.h"
#include "components/efm32/gpio/gpio-configuration.h"
#include "components/efm32/usart/usart-configuration.h"
#include "components/efm32/dma/dma-configuration.h"
#include "components/communicator/communicator-configuration.h"
#include "components/spi-exchanger/spi-exchanger-configuration.h"
#include "components/phrase-receiver/phrase-receiver-configuration.h"
#include "components/transmitter/transmitter-configuration.h"
#include "components/electricity-meter-m90e32as/electricity-meter-m90e32as-configuration.h"
//



 /**********************************************************************************************************************
 * Interface declarations required by its(own) INTERNAL and EXTERNAL classes
 **********************************************************************************************************************/
	//BITS
#define BITS_isSingleTranslationUnit()								( electricity_meter_application_isSingleTranslationUnit() )
#define BITS_selfData												electricity_meter_application_selfData.bits
#define BITS_count 													10
	//CALLER
#define CALLER_isSingleTranslationUnit()                   			( electricity_meter_application_isSingleTranslationUnit() )
#define CALLER_selfData												electricity_meter_application_selfData.caller
#define CALLER_confirmMeterInitializationBit						0
#define CALLER_confimMeterReadingsBit								1
#define CALLER_isBitRaised(b)										( bits_isBitRaised(b) )
#define CALLER_raiseBit(b)											do{ bits_raiseBit(b);                                               		}while(0)
#define CALLER_clearBit(b)											do{ bits_clearBit(b) ;                                              		}while(0)
#define CALLER_toggleBit(b)											do{ bits_toggleBit(b) ;                                             		}while(0)
#define CALLER_setBit(b,v)											do{ bits_setBit(b,v);                                              			}while(0)
#define CALLER_requestMeterInitialization()							electricity_meter_m90e32as_requestInitialization()
	//CMU
#define CMU_singleTranslationUnit()									( electricity_meter_application_isSingleTranslationUnit() )
#define CMU_getBitMask(higherBit, lowerBit)							( bits_getBitMask(higherBit, lowerBit) )
#define CMU_setProperty(object, mask, value)						do{ utility_setProperty(object, mask, value); }while(0)
#define CMU_raiseBits(reg, mask)									do{ bits_raiseBits(reg, mask);	}while(0)
//--
/**********************************************************************************************************************
* COMMUNICATOR Object-like macros
**********************************************************************************************************************/
#define COMMUNICATOR_selfData										electricity_meter_application_selfData.communicator
/**********************************************************************************************************************
* COMMUNICATOR Function-like macros that DO return value
**********************************************************************************************************************/
#define COMMUNICATOR_isSingleTranslationUnit()						( electricity_meter_application_isSingleTranslationUnit() )
#define COMMUNICATOR_getRegisterNameLength()						20
#define COMMUNICATOR_getInterlocutorRegsterCount()					201
#define COMMUNICATOR_getBufferSize()								40
#define COMMUNICATOR_getNameCapacity()								12
#define COMMUNICATOR_getValueCapacity()								12
#define COMMUNICATOR_getChannelDescriptorCh0PrimaryNextWriteAddress()		( channel_descriptor_getCh0PrimaryNextWriteAddress() )
#define COMMUNICATOR_getChannelDescriptorCh0PrimaryRemainingTransferCount()	( channel_descriptor_getCh0PrimaryRemainingTransferCount() )
#define COMMUNICATOR_isDmaCh0Done()									( dma_isChannel0Done() )
#define COMMUNICATOR_setFrameStateBufferOverflow()					( BUFFEROVERFLOWN = true )
#define COMMUNICATOR_getPhraseNameMarkCount()						( 16 )
#define COMMUNICATOR_getCommandCount()								( 16 )
/**********************************************************************************************************************
* COMMUNICATOR Function-like macros that DO NOT return value
**********************************************************************************************************************/
#define COMMUNICATOR_setDmaCh1SourceUart1()							do{ dma_selectCh1SourceUart1(); 											}while(0)
#define COMMUNICATOR_selectDmaCh1InputSignalRxDataAvailable()		do{ dma_selectCh1InputSignalRxDataAvailable(); 								}while(0)
#define COMMUNICATOR_selectDmaCh1InputSignalTxBufferLevel()			do{ dma_selectCh1InputSignalTxBufferLevel(); 								}while(0)
#define COMMUNICATOR_enableDma()									do{ dma_enable();															}while(0)
#define COMMUNICATOR_useDmaCh1PrimaryStructure()					do{ dma_usePrimaryStructureForChannel1(); 									}while(0)
#define COMMUNICATOR_setDmaControlDataBasePointer()					do{ dma_setChannelControlDataBasePointer(); 								}while(0)
#define COMMUNICATOR_enableDmaCh1PeripheralRequest()				do{ dma_enablePeripheralRequestForChannel1(); 								}while(0)
#define COMMUNICATOR_enableDmaCh0()									do{ dma_enableChannel1();													}while(0)
#define COMMUNICATOR_setCh1PrimaryDestinationEndPointer(address)	do{	channel_descriptor_setPrimaryDestinationEndPointer(1, (address));		}while(0)
#define COMMUNICATOR_setCh1PrimarySourceEndPointer(address)			do{ channel_descriptor_setPrimarySourceEndPointer(1, (address)); 			}while(0)
#define COMMUNICATOR_setCh1PrimaryDestinationAddressIncrementByte() do{ channel_descriptor_setPrimaryDestinationAddressIncrementByte(1); 		}while(0)
#define COMMUNICATOR_setCh1PrimaryDestinationAddressIncrementNoIncrement() do{ channel_descriptor_setPrimaryDestinationAddressIncrementNoIncrement(1); }while(0)
#define COMMUNICATOR_setCh1PrimaryDestinationDataSizeByteValue()	do{ channel_descriptor_setPrimaryDestinationDataSizeByte(1); 			}while(0)
#define COMMUNICATOR_setCh1PrimarySourceAddressIncrementNoIncrement()	do{ channel_descriptor_setPrimarySourceAddressIncrementNoIncrement(1); 	}while(0)
#define COMMUNICATOR_setCh1PrimarySourceAddressIncrementByte()		do{ channel_descriptor_setPrimarySourceAddressIncrementByte(1); 			}while(0)
#define COMMUNICATOR_setCh1PrimarySourceDataSizeByte()				do{ channel_descriptor_setPrimarySourceDataSizeByte(1);						}while(0)
#define COMMUNICATOR_setCh1PrimaryDestinationDataAccessControlNonPriviledged() do{ channel_descriptor_setPrimaryDestinationDataAccessControlNonPriviledged(1); }while(0)
#define COMMUNICATOR_setCh1PrimarySourceDataAccessControlNonPriviledged() do{ channel_descriptor_setPrimarySourceDataAccessControlNonPriviledged(1); }while(0)
#define COMMUNICATOR_setCh1PrimaryArbitrateAfterEachTransfer()		do{ channel_descriptor_setPrimaryArbitrateAfterEachTransfer(1); 			}while(0)
#define COMMUNICATOR_setCh1PrimaryCycleTransferCount(trCount)		do{ channel_descriptor_setPrimaryCycleTransferCount(1, trCount); 			}while(0)
#define COMMUNICATOR_clearCh1PrimaryNextUseBurst()					do{ channel_descriptor_clearPrimaryNextUseBurst(1); 						}while(0)
#define COMMUNICATOR_setCh1PrimaryBasicMode()						do{ channel_descriptor_setPrimaryBasicMode(1); 								}while(0)

//== Client methods
#define COMMUNICATOR_requestElectricityMeterWrite()					do{ electricity_meter_m90e32as_indicateWrite(addr, val);								}while(0)
#define COMMUNICATOR_requestElectricityMeterRead(addr)				do{ electricity_meter_m90e32as_indicateRead(addr);									}while(0)


//--

/**********************************************************************************************************************
* DMA Object-like macros
**********************************************************************************************************************/
#define DMA_selfData												electricity_meter_application_selfData.dma
/**********************************************************************************************************************
* DMA Function-like macros that DO return value
**********************************************************************************************************************/
#define DMA_getPrimaryChannelCount() 								4		//dma-receiver(prim. Ch0), communicator-transmitter(prim. Ch1),
																			//spi-tx(prim. ch3), spi-rx(prim. ch4)
#define DMA_getAlternateChannelCount() 								0
#define DMA_isSingleTranslationUnit()								( electricity_meter_application_isSingleTranslationUnit() )
#define DMA_getUsart1TxBufferAddress()								( utility_getSFRegisterAddress(0x4000C400UL, 0x034UL) ) //USART1_BaseAddres + TxBufferOffset
#define DMA_getUart1TxBufferAddress()								( utility_getSFRegisterAddress(0x4000E400UL, 0x034UL) )
#define DMA_getPropertyValue(value, startBit)						( utility_getPropertyValue(value, startBit) )
#define DMA_getBitsMask(EndBit, StartBit)							( bits_getBitMask(EndBit, StartBit) )
#define DMA_getProperty(reg, mask) 									( utility_getProperty(reg, mask) )
#define DMA_assert1(reg, mask)										( utility_assert1(reg, mask) )
#define DMA_getCh0TransferCount()									( COMMUNICATOR_getBufferSize() )
#define DMA_getCh0SourceEndAddr()									( (uint32_t)( & usart_uart1.rxBufferData) )
#define DMA_getCh0DestEndAddr()										( ( ( & COMMUNICATOR_selfData.buffer[0] ) + ( DMA_getCh0TransferCount() - 1 ) ) )
/**********************************************************************************************************************
* DMA Function-like macros that DO NOT return value
**********************************************************************************************************************/
#define DMA_raiseBits(reg, mask)									do{ bits_raiseBits(reg, mask); 												}while(0)
#define DMA_clearBits(reg, mask)									do{ bits_clearBits(reg, mask); 												}while(0)
#define DMA_setRegister(reg, value)									do{ utility_setRegister(reg, value); 										}while(0)
#define DMA_assertBits(reg, mask)									do{ bits_assertBits(reg, mask);												}while(0)
#define DMA_setProperty(object, mask, value)						do{ utility_setProperty(object, mask, value); 								}while(0)
//--
/**********************************************************************************************************************
* XXX Object-like macros
**********************************************************************************************************************/


/**********************************************************************************************************************
* XXX Function-like macros that DO return value
**********************************************************************************************************************/


/**********************************************************************************************************************
* XXX Function-like macros that DO NOT return value
**********************************************************************************************************************/
//function-like macros that DO return value

//-- receiver


// function-like macros that DO NOT return value

//==


/**********************************************************************************************************************
* Interface declarations required by the application class: ELECTRICITY_METER_APPLICATION
**********************************************************************************************************************/
#define ELECTRICITY_METER_APPLICATION_DmaSelfData					dma_SelfData
#define ELECTRICITY_METER_APPLICATION_CallerSelfData		        caller_SelfData
#define ELECTRICITY_METER_APPLICATION_CommunicatorSelfData			communicator_SelfData
#define ELECTRICITY_METER_APPLICATION_BitsSelfData	                bits_SelfData
#define ELECTRICITY_METER_APPLICATION_ElectricityMeterSelfData      electricity_meter_m90e32as_SelfData
#define ELECTRICITY_METER_APPLICATION_TranslatorSelfData      		translator_SelfData
#define ELECTRICITY_METER_APPLICATION_ElectricityMeterRegister		electricity_meter_m90e32as_Register
#define ELECTRICITY_METER_APPLICATION_SpiExchanger					spi_exchanger_SelfData
#define ELECTRICITY_METER_APPLICATION_PhraseReceiverSelfData		phrase_receiver_SelfData

/**********************************************************************************************************************
* ELECTRICITY_METER_APPLICATION Object-like macros
**********************************************************************************************************************/
#define ELECTRICITY_METER_APPLICATION_selfData						electricity_meter_application_selfData

/**********************************************************************************************************************
* ELECTRICITY_METER_APPLICATION Function-like macros that DO return value
**********************************************************************************************************************/

#define MY_DEBUG

// Is Running Methods
#define ELECTRICITY_METER_APPLICATION_isReaderRunning() 			( true )
#define ELECTRICITY_METER_APPLICATION_isRangeRunning()              ( true )
#define ELECTRICITY_METER_APPLICATION_isTopLimitRunning()           ( range_isTopLimitRunning() )
#define ELECTRICITY_METER_APPLICATION_isBottomLimitRunning()        ( range_isBottomLimitRunning() )

// Dispatch Events Methods
#define ELECTRICITY_METER_APPLICATION_dispatchReaderEvents()		( reader_dispatchEvents() )
#define ELECTRICITY_METER_APPLICATION_dispatchRangeEvents()         ( range_dispatchEvents() )
#define ELECTRICITY_METER_APPLICATION_dispatchTopLimitEvents()      ( top_limit_dispatchEvents() )
#define ELECTRICITY_METER_APPLICATION_dispatchBottomLimitEvents()   ( bottom_limit_dispatchEvents() )
#define ELECTRICITY_METER_APPLICATION_isSingleTranslationUnit()		( electricity_meter_application_isSingleTranslationUnit() )
#define ELECTRICITY_METER_APPLICATION_receiverDispatchEvents()   	( receiver_dispatchEvents() )
#define ELECTRICITY_METER_APPLICATION_transmitterDispatchEvents()   ( transmitter_dispatchEvents() )
#define ELECTRICITY_METER_APPLICATION_communicatorDispatchEvents()  ( communicator_dispatchEvents() )
#define ELECTRICITY_METER_APPLICATION_readerDispatchEvents()		( reader_dispatchEvents() )
#define ELECTRICITY_METER_APPLICATION_bottomLimitDispatchEvents()	( bottom_limit_dispatchEvents() )
#define ELECTRICITY_METER_APPLICATION_dispatchElectricityMeterM90e32asEvents() ( electricity_meter_m90e32as_dispatchEvents() )
#define ELECTRICITY_METER_APPLICATION_dispatchTranslatorEvents()	( translator_dispatchEvents() )
#define ELECTRICITY_METER_APPLICATION_dispatchSpiExchangerEvents()	( spi_exchanger_dispatchEvents() )
//Configuration

/**********************************************************************************************************************
* ELECTRICITY_METER_APPLICATION Function-like macros that DO NOT return value
**********************************************************************************************************************/
#define ELECTRICITY_METER_APPLICATION_assertEventNone()				do{ ; }while(0)


#define ELECTRICITY_METER_APPLICATION_cmuInit()						do{ cmu_init(); 															}while(0)
#define ELECTRICITY_METER_APPLICATION_gpioInit()                    do{ gpio_init(); 															}while(0)
#define ELECTRICITY_METER_APPLICATION_usartInit()					do{ usart_init();			 												}while(0)
#define ELECTRICITY_METER_APPLICATION_timerInit()                 	do{ timer_init();  															}while(0)
#define ELECTRICITY_METER_APPLICATION_dmaInit()						do{ dma_init();																}while(0)
#define ELECTRICITY_METER_APPLICATION_phraseReceiverInit()				do{ receiver_init(); 														}while(0)
#define ELECTRICITY_METER_APPLICATION_communicatorInit()    		do{ communicator_init(); 													}while(0)
#define ELECTRICITY_METER_APPLICATION_transmitterInit()				do{ transmitter_init(); 													}while(0)
#define ELECTRICITY_METER_APPLICATION_topLimitInit()				do{ top_limit_init();														}while(0)
#define ELECTRICITY_METER_APPLICATION_readerInit()					do{ reader_init();															}while(0)
#define ELECTRICITY_METER_APPLICATION_bottomLimitInit()				do{ bottom_limit_init(); 													}while(0)
#define ELECTRICITY_METER_APPLICATION_rangeInit()					do{ range_init(); 															}while(0)
#define ELECTRICITY_METER_APPLICATION_initElectricityMeterM90E32AS()		do{ electricity_meter_m90e32as_init(); 										}while(0)
#define ELECTRICITY_METER_APPLICATION_initSpiExchanger()			do{ spi_exchanger_init(); 													}while(0)

//==




/**********************************************************************************************************************
*  ELECTRICITY_METER_M90E32AS Object-like macros
**********************************************************************************************************************/
#define ELECTRICITY_METER_M90E32AS_register									ELECTRICITY_METER_M90E32AS_selfData.registers
#define ELECTRICITY_METER_M90E32AS_selfData									electricity_meter_application_selfData.electricity_meter_m90e32as
/**********************************************************************************************************************
* ELECTRICITY_METER_M90E32AS Function-like macros that DO return value
**********************************************************************************************************************/

#define ELECTRICITY_METER_M90E32AS_isSingleTranslationUnit()		( electricity_meter_application_isSingleTranslationUnit() )

#define ELECTRICITY_METER_M90E32AS_getRegisterCount()				255

#define ELECTRICITY_METER_M90E32AS_frameGetValue()					( frame_getValue() )
#define ELECTRICITY_METER_M90E32AS_frameGetAddress()				( frame_getAddress() )


/**********************************************************************************************************************
* ELECTRICITY_METER_M90E32AS  Function-like macros that DO NOT return value
**********************************************************************************************************************/
#define ELECTRICITY_METER_M90E32AS_reponseDone()					do{ communicator_confirmElectricityMeterDone(); 					}while(0)
#define ELECTRICITY_METER_M90E32AS_readRegister()					do{ electricity_meter_m90e32as_obtainRegister(); 					}while(0)
#define ELECTRICITY_METER_M90E32AS_writeRegister()					do{ electricity_meter_m90e32as_writeRegister(); 					}while(0)


// Auxiliaries

#define ELECTRICITY_METER_M90E32AS_setUpFrameWrite()				do{ \
																		frame_write(\
																				electricity_meter_m90e32as_getAddress(),\
																				electricity_meter_m90e32as_getValue() );\
																	}while(0)

#define ELECTRICITY_METER_M90E32AS_frameWrite(address, value)		do{ frame_write(address, value); 									}while(0)
#define ELECTRICITY_METER_M90E32AS_frameRead(address)				do{ frame_read(address); 											}while(0)


// Server-like methods
#define ELECTRICITY_METER_M90E32AS_requestSpiExchangerRead()		do{ spi_exchanger_indicateRead(); 									}while(0)
#define ELECTRICITY_METER_M90E32AS_requestSpiExchangerWrite()		do{ spi_exchanger_indicateWrite(); 									}while(0)
// Client-like methods
#define ELECTRICITY_METER_M90E32AS_responseDoneRead()				do{ translator_confirm();											}while(0)
#define ELECTRICITY_METER_M90E32AS_responseDoneWrite()				do{ translator_confirm();											}while(0)

//--

/**********************************************************************************************************************
* FRAME Object-like macros
**********************************************************************************************************************/


/**********************************************************************************************************************
* FRAME Function-like macros that DO return value
**********************************************************************************************************************/
#define FRAME_16BIT


/**********************************************************************************************************************
* FRAME Function-like macros that DO NOT return value
**********************************************************************************************************************/

//--
/**********************************************************************************************************************
* GPIO Object-like macros
**********************************************************************************************************************/
/**********************************************************************************************************************
* GPIO Function-like macros that DO return value
**********************************************************************************************************************/
#define GPIO_isSingleTranslationUnit()          ( electricity_meter_application_isSingleTranslationUnit() )
#define GPIO_getA00Mode()                       ( port_getPinDisabledMode(  0 ) )
#define GPIO_getA01Mode()                       ( port_getPinDisabledMode(  1 ) )
#define GPIO_getA02Mode()                       ( port_getPinDisabledMode(  2 ) )
#define GPIO_getA03Mode()                       ( port_getPinDisabledMode(  3 ) )
#define GPIO_getA04Mode()                       ( port_getPinDisabledMode(  4 ) )
#define GPIO_getA05Mode()                       ( port_getPinDisabledMode(  5 ) )
#define GPIO_getA06Mode()                       ( port_getPinDisabledMode(  6 ) )
#define GPIO_getA07Mode()                       ( port_getPinDisabledMode(  7 ) )
#define GPIO_getA08Mode()                       ( port_getPinDisabledMode(  8 ) )
#define GPIO_getA09Mode()                       ( port_getPinDisabledMode(  9 ) )
#define GPIO_getA10Mode()                       ( port_getPinDisabledMode( 10 ) )
#define GPIO_getA11Mode()                       ( port_getPinDisabledMode( 11 ) )
#define GPIO_getA12Mode()                       ( port_getPinDisabledMode( 12 ) )
#define GPIO_getA13Mode()                       ( port_getPinDisabledMode( 13 ) )
#define GPIO_getA14Mode()                       ( port_getPinDisabledMode( 14 ) )
#define GPIO_getA15Mode()                       ( port_getPinDisabledMode( 15 ) )
//
#define GPIO_getB00Mode()                       ( port_getPinDisabledMode(  0 ) )
#define GPIO_getB01Mode()                       ( port_getPinDisabledMode(  1 ) )
#define GPIO_getB02Mode()                       ( port_getPinDisabledMode(  2 ) )
#define GPIO_getB03Mode()                       ( port_getPinDisabledMode(  3 ) )
#define GPIO_getB04Mode()                       ( port_getPinDisabledMode(  4 ) )
#define GPIO_getB05Mode()                       ( port_getPinDisabledMode(  5 ) )
#define GPIO_getB06Mode()                       ( port_getPinDisabledMode(  6 ) )
#define GPIO_getB07Mode()                       ( port_getPinDisabledMode(  7 ) )
#define GPIO_getB08Mode()                       ( port_getPinDisabledMode(  8 ) )
#define GPIO_getB09Mode()                       ( port_getModePushPullOutputPin(  9 ) )
#define GPIO_getB10Mode()                       ( port_getPinInputMode( 10 ) )
#define GPIO_getB11Mode()                       ( port_getPinDisabledMode( 11 ) )
#define GPIO_getB12Mode()                       ( port_getPinDisabledMode( 12 ) )
#define GPIO_getB13Mode()                       ( port_getPinDisabledMode( 13 ) )
#define GPIO_getB14Mode()                       ( port_getPinDisabledMode( 14 ) )
#define GPIO_getB15Mode()                       ( port_getPinDisabledMode( 15 ) )
//
#define GPIO_getC00Mode()                       ( port_getPinDisabledMode(  0 ) )
#define GPIO_getC01Mode()                       ( port_getPinDisabledMode(  1 ) )
#define GPIO_getC02Mode()                       ( port_getPinDisabledMode(  2 ) )
#define GPIO_getC03Mode()                       ( port_getPinDisabledMode(  3 ) )
#define GPIO_getC04Mode()                       ( port_getPinDisabledMode(  4 ) )
#define GPIO_getC05Mode()                       ( port_getPinDisabledMode(  5 ) )
#define GPIO_getC06Mode()                       ( port_getPinDisabledMode(  6 ) )
#define GPIO_getC07Mode()                       ( port_getPinDisabledMode(  7 ) )
#define GPIO_getC08Mode()                       ( port_getPinDisabledMode(  8 ) )
#define GPIO_getC09Mode()                       ( port_getPinDisabledMode(  9 ) )
#define GPIO_getC10Mode()                       ( port_getPinDisabledMode( 10 ) )
#define GPIO_getC11Mode()                       ( port_getPinDisabledMode( 11 ) )
#define GPIO_getC12Mode()                       ( port_getPinDisabledMode( 12 ) )
#define GPIO_getC13Mode()                       ( port_getPinDisabledMode( 13 ) )
#define GPIO_getC14Mode()                       ( port_getPinDisabledMode( 14 ) )
#define GPIO_getC15Mode()                       ( port_getPinDisabledMode( 15 ) )
//
#define GPIO_getD00Mode()                       ( port_getModePushPullOutputPin(  0 ) )
#define GPIO_getD01Mode()                       ( port_getPinInputMode(  1 ) )
#define GPIO_getD02Mode()                       ( port_getModePushPullOutputPin(  2 ) )
#define GPIO_getD03Mode()                       ( port_getModePushPullOutputPin(  3 ) )
#define GPIO_getD04Mode()                       ( port_getPinDisabledMode(  4 ) )
#define GPIO_getD05Mode()                       ( port_getPinDisabledMode(  5 ) )
#define GPIO_getD06Mode()                       ( port_getPinDisabledMode(  6 ) )
#define GPIO_getD07Mode()                       ( port_getPinDisabledMode(  7 ) )
#define GPIO_getD08Mode()                       ( port_getPinDisabledMode(  8 ) )
#define GPIO_getD09Mode()                       ( port_getPinDisabledMode(  9 ) )
#define GPIO_getD10Mode()                       ( port_getPinDisabledMode( 10 ) )
#define GPIO_getD11Mode()                       ( port_getPinDisabledMode( 11 ) )
#define GPIO_getD12Mode()                       ( port_getPinDisabledMode( 12 ) )
#define GPIO_getD13Mode()                       ( port_getPinDisabledMode( 13 ) )
#define GPIO_getD14Mode()                       ( port_getPinDisabledMode( 14 ) )
#define GPIO_getD15Mode()                       ( port_getPinDisabledMode( 15 ) )
//
#define GPIO_getE00Mode()                       ( port_getPinDisabledMode(  0 ) )
#define GPIO_getE01Mode()                       ( port_getPinDisabledMode(  1 ) )
#define GPIO_getE02Mode()                       ( port_getModePushPullOutputPin(  2 ) )
#define GPIO_getE03Mode()                       ( port_getModePushPullOutputPin(  3 ) )
#define GPIO_getE04Mode()                       ( port_getPinDisabledMode(  4 ) )
#define GPIO_getE05Mode()                       ( port_getPinDisabledMode(  5 ) )
#define GPIO_getE06Mode()                       ( port_getPinDisabledMode(  6 ) )
#define GPIO_getE07Mode()                       ( port_getPinDisabledMode(  7 ) )
#define GPIO_getE08Mode()                       ( port_getPinDisabledMode(  8 ) )
#define GPIO_getE09Mode()                       ( port_getPinDisabledMode(  9 ) )
#define GPIO_getE10Mode()                       ( port_getPinDisabledMode( 10 ) )
#define GPIO_getE11Mode()                       ( port_getPinDisabledMode( 11 ) )
#define GPIO_getE12Mode()                       ( port_getPinDisabledMode( 12 ) )
#define GPIO_getE13Mode()                       ( port_getPinDisabledMode( 13 ) )
#define GPIO_getE14Mode()                       ( port_getPinDisabledMode( 14 ) )
#define GPIO_getE15Mode()                       ( port_getPinDisabledMode( 15 ) )
//
#define GPIO_getF00Mode()                       ( port_getPinDisabledMode(  0 ) )
#define GPIO_getF01Mode()                       ( port_getPinDisabledMode(  1 ) )
#define GPIO_getF02Mode()                       ( port_getPinDisabledMode(  2 ) )
#define GPIO_getF03Mode()                       ( port_getPinDisabledMode(  3 ) )
#define GPIO_getF04Mode()                       ( port_getPinDisabledMode(  4 ) )
#define GPIO_getF05Mode()                       ( port_getPinDisabledMode(  5 ) )
#define GPIO_getF06Mode()                       ( port_getPinDisabledMode(  6 ) )
#define GPIO_getF07Mode()                       ( port_getPinDisabledMode(  7 ) )
#define GPIO_getF08Mode()                       ( port_getPinDisabledMode(  8 ) )
#define GPIO_getF09Mode()                       ( port_getPinDisabledMode(  9 ) )
#define GPIO_getF10Mode()                       ( port_getPinDisabledMode( 10 ) )
#define GPIO_getF11Mode()                       ( port_getPinDisabledMode( 11 ) )
#define GPIO_getF12Mode()                       ( port_getPinDisabledMode( 12 ) )
#define GPIO_getF13Mode()                       ( port_getPinDisabledMode( 13 ) )
#define GPIO_getF14Mode()                       ( port_getPinDisabledMode( 14 ) )
#define GPIO_getF15Mode()                       ( port_getPinDisabledMode( 15 ) )
//--//Output registers initial states
//PortA
#define GPIO_getPinA00OutputLevel()				( port_getPinOutputLow(  0 ) )
#define GPIO_getPinA01OutputLevel()				( port_getPinOutputLow(  1 ) )
#define GPIO_getPinA02OutputLevel()				( port_getPinOutputLow(  2 ) )
#define GPIO_getPinA03OutputLevel()             ( port_getPinOutputLow(  3 ) )
#define GPIO_getPinA04OutputLevel()             ( port_getPinOutputLow(  4 ) )
#define GPIO_getPinA05OutputLevel()             ( port_getPinOutputLow(  5 ) )
#define GPIO_getPinA06OutputLevel()             ( port_getPinOutputLow(  6 ) )
#define GPIO_getPinA07OutputLevel()             ( port_getPinOutputLow(  7 ) )
#define GPIO_getPinA08OutputLevel()             ( port_getPinOutputLow(  8 ) )
#define GPIO_getPinA09OutputLevel()             ( port_getPinOutputLow(  9 ) )
#define GPIO_getPinA10OutputLevel()             ( port_getPinOutputLow( 10 ) )
#define GPIO_getPinA11OutputLevel()             ( port_getPinOutputLow( 11 ) )
#define GPIO_getPinA12OutputLevel()             ( port_getPinOutputLow( 12 ) )
#define GPIO_getPinA13OutputLevel()             ( port_getPinOutputLow( 13 ) )
#define GPIO_getPinA14OutputLevel()             ( port_getPinOutputLow( 14 ) )
#define GPIO_getPinA15OutputLevel()             ( port_getPinOutputLow( 15 ) )
//PortB
#define GPIO_getPinB00OutputLevel()				( port_getPinOutputLow(  0 ) )
#define GPIO_getPinB01OutputLevel()				( port_getPinOutputLow(  1 ) )
#define GPIO_getPinB02OutputLevel()				( port_getPinOutputLow(  2 ) )
#define GPIO_getPinB03OutputLevel()             ( port_getPinOutputLow(  3 ) )
#define GPIO_getPinB04OutputLevel()             ( port_getPinOutputLow(  4 ) )
#define GPIO_getPinB05OutputLevel()             ( port_getPinOutputLow(  5 ) )
#define GPIO_getPinB06OutputLevel()             ( port_getPinOutputLow(  6 ) )
#define GPIO_getPinB07OutputLevel()             ( port_getPinOutputLow(  7 ) )
#define GPIO_getPinB08OutputLevel()             ( port_getPinOutputLow(  8 ) )
#define GPIO_getPinB09OutputLevel()             ( port_getPinOutputLow(  9 ) )
#define GPIO_getPinB10OutputLevel()             ( port_getPinOutputLow( 10 ) )
#define GPIO_getPinB11OutputLevel()             ( port_getPinOutputLow( 11 ) )
#define GPIO_getPinB12OutputLevel()             ( port_getPinOutputLow( 12 ) )
#define GPIO_getPinB13OutputLevel()             ( port_getPinOutputLow( 13 ) )
#define GPIO_getPinB14OutputLevel()             ( port_getPinOutputLow( 14 ) )
#define GPIO_getPinB15OutputLevel()             ( port_getPinOutputLow( 15 ) )
//PortC
#define GPIO_getPinC00OutputLevel()				( port_getPinOutputLow(  0 ) )
#define GPIO_getPinC01OutputLevel()				( port_getPinOutputLow(  1 ) )
#define GPIO_getPinC02OutputLevel()				( port_getPinOutputLow(  2 ) )
#define GPIO_getPinC03OutputLevel()             ( port_getPinOutputLow(  3 ) )
#define GPIO_getPinC04OutputLevel()             ( port_getPinOutputLow(  4 ) )
#define GPIO_getPinC05OutputLevel()             ( port_getPinOutputLow(  5 ) )
#define GPIO_getPinC06OutputLevel()             ( port_getPinOutputLow(  6 ) )
#define GPIO_getPinC07OutputLevel()             ( port_getPinOutputLow(  7 ) )
#define GPIO_getPinC08OutputLevel()             ( port_getPinOutputLow(  8 ) )
#define GPIO_getPinC09OutputLevel()             ( port_getPinOutputLow(  9 ) )
#define GPIO_getPinC10OutputLevel()             ( port_getPinOutputLow( 10 ) )
#define GPIO_getPinC11OutputLevel()             ( port_getPinOutputLow( 11 ) )
#define GPIO_getPinC12OutputLevel()             ( port_getPinOutputLow( 12 ) )
#define GPIO_getPinC13OutputLevel()             ( port_getPinOutputLow( 13 ) )
#define GPIO_getPinC14OutputLevel()             ( port_getPinOutputLow( 14 ) )
#define GPIO_getPinC15OutputLevel()             ( port_getPinOutputLow( 15 ) )
//PortD
#define GPIO_getPinD00OutputLevel()				( port_getPinOutputLow(  0 ) )
#define GPIO_getPinD01OutputLevel()				( port_getPinOutputLow(  1 ) )
#define GPIO_getPinD02OutputLevel()				( port_getPinOutputLow(  2 ) )
#define GPIO_getPinD03OutputLevel()             ( port_getPinOutputLow(  3 ) )
#define GPIO_getPinD04OutputLevel()             ( port_getPinOutputLow(  4 ) )
#define GPIO_getPinD05OutputLevel()             ( port_getPinOutputLow(  5 ) )
#define GPIO_getPinD06OutputLevel()             ( port_getPinOutputLow(  6 ) )
#define GPIO_getPinD07OutputLevel()             ( port_getPinOutputLow(  7 ) )
#define GPIO_getPinD08OutputLevel()             ( port_getPinOutputLow(  8 ) )
#define GPIO_getPinD09OutputLevel()             ( port_getPinOutputLow(  9 ) )
#define GPIO_getPinD10OutputLevel()             ( port_getPinOutputLow( 10 ) )
#define GPIO_getPinD11OutputLevel()             ( port_getPinOutputLow( 11 ) )
#define GPIO_getPinD12OutputLevel()             ( port_getPinOutputLow( 12 ) )
#define GPIO_getPinD13OutputLevel()             ( port_getPinOutputLow( 13 ) )
#define GPIO_getPinD14OutputLevel()             ( port_getPinOutputLow( 14 ) )
#define GPIO_getPinD15OutputLevel()             ( port_getPinOutputLow( 15 ) )
//PortE
#define GPIO_getPinE00OutputLevel()				( port_getPinOutputLow(  0 ) )
#define GPIO_getPinE01OutputLevel()				( port_getPinOutputLow(  1 ) )
#define GPIO_getPinE02OutputLevel()				( port_getPinOutputLow(  2 ) )
#define GPIO_getPinE03OutputLevel()             ( port_getPinOutputLow(  3 ) )
#define GPIO_getPinE04OutputLevel()             ( port_getPinOutputLow(  4 ) )
#define GPIO_getPinE05OutputLevel()             ( port_getPinOutputLow(  5 ) )
#define GPIO_getPinE06OutputLevel()             ( port_getPinOutputLow(  6 ) )
#define GPIO_getPinE07OutputLevel()             ( port_getPinOutputLow(  7 ) )
#define GPIO_getPinE08OutputLevel()             ( port_getPinOutputLow(  8 ) )
#define GPIO_getPinE09OutputLevel()             ( port_getPinOutputLow(  9 ) )
#define GPIO_getPinE10OutputLevel()             ( port_getPinOutputLow( 10 ) )
#define GPIO_getPinE11OutputLevel()             ( port_getPinOutputLow( 11 ) )
#define GPIO_getPinE12OutputLevel()             ( port_getPinOutputLow( 12 ) )
#define GPIO_getPinE13OutputLevel()             ( port_getPinOutputLow( 13 ) )
#define GPIO_getPinE14OutputLevel()             ( port_getPinOutputLow( 14 ) )
#define GPIO_getPinE15OutputLevel()             ( port_getPinOutputLow( 15 ) )
//PortF
#define GPIO_getPinF00OutputLevel()				( port_getPinOutputLow(  0 ) )
#define GPIO_getPinF01OutputLevel()				( port_getPinOutputLow(  1 ) )
#define GPIO_getPinF02OutputLevel()				( port_getPinOutputLow(  2 ) )
#define GPIO_getPinF03OutputLevel()             ( port_getPinOutputLow(  3 ) )
#define GPIO_getPinF04OutputLevel()             ( port_getPinOutputLow(  4 ) )
#define GPIO_getPinF05OutputLevel()             ( port_getPinOutputLow(  5 ) )
#define GPIO_getPinF06OutputLevel()             ( port_getPinOutputLow(  6 ) )
#define GPIO_getPinF07OutputLevel()             ( port_getPinOutputLow(  7 ) )
#define GPIO_getPinF08OutputLevel()             ( port_getPinOutputLow(  8 ) )
#define GPIO_getPinF09OutputLevel()             ( port_getPinOutputLow(  9 ) )
#define GPIO_getPinF10OutputLevel()             ( port_getPinOutputLow( 10 ) )
#define GPIO_getPinF11OutputLevel()             ( port_getPinOutputLow( 11 ) )
#define GPIO_getPinF12OutputLevel()             ( port_getPinOutputLow( 12 ) )
#define GPIO_getPinF13OutputLevel()             ( port_getPinOutputLow( 13 ) )
#define GPIO_getPinF14OutputLevel()             ( port_getPinOutputLow( 14 ) )
#define GPIO_getPinF15OutputLevel()             ( port_getPinOutputLow( 15 ) )
/**********************************************************************************************************************
* GPIO Function-like macros that DO NOT return value
**********************************************************************************************************************/
//--

/**********************************************************************************************************************
* RANGE Object-like macros
**********************************************************************************************************************/
/**********************************************************************************************************************
* RANGE Function-like macros that DO return value
**********************************************************************************************************************/
/**********************************************************************************************************************
* READER Function-like macros that DO NOT return value
**********************************************************************************************************************/
//==


//==
/**********************************************************************************************************************
* READER Object-like macros
**********************************************************************************************************************/

/**********************************************************************************************************************
* READER Function-like macros that DO return value
**********************************************************************************************************************/

/**********************************************************************************************************************
* READER Function-like macros that DO NOT return value
**********************************************************************************************************************/
//--



//==
/**********************************************************************************************************************
* RECEIVER Object-like macros
**********************************************************************************************************************/
#define PHRASE_RECEIVER_selfData									( electricity_meter_application_selfData.phrase_receiver )

/**********************************************************************************************************************
* RECEIVER Function-like macros that DO return value
**********************************************************************************************************************/

#define PHRASE_RECEIVER_isSingleTranslationUnit()					( electricity_meter_application_isSingleTranslationUnit() )
#define PHRASE_RECEIVER_getBufferSize()								40

#define PHRASE_RECEIVER_isUartRxDataAvailable()						( usart_isUart1RxDataAvailable() )

#define PHRASE_RECEIVER_isBufferOverflown()							( dma_isChannel0Done() && channel_descriptor_getCh0PrimaryRemainingTransferCount() )

#define PHRASE_RECEIVER_getAmountOfReceivedCharacters()	( PHRASE_RECEIVER_getBufferSize() - channel_descriptor_getCh0PrimaryRemainingTransferCount() )

/**********************************************************************************************************************
* RECEIVER Function-like macros that DO NOT return value
**********************************************************************************************************************/

#define PHRASE_RECEIVER_resetDma()									do{  \
																		dma_clearChannel0DoneInterruptFlag();\
																		channel_descriptor_setPrimaryCycleTransferCount(0, sizeof(COMMUNICATOR_Buffer));\
																		channel_descriptor_setPrimaryBasicMode(0);\
																		dma_enableChannel0();\
																	}while(0)

#define PHRASE_RECEIVER_initDma()									do{	\
																		dma_selectSourceUart1(0);\
																		dma_selectInputSignalRxDataAvailable(0);\
																		dma_usePrimaryStructureForChannel0();\
																		dma_setChannelControlDataBasePointer();\
																		dma_enablePeripheralRequestForChannel0();\
																		\
																		\
																		channel_descriptor_setPrimarySourceEndPointer(0, &(usart_getUart1RxData()));\
																		channel_descriptor_setPrimarySourceDataSizeByte(0);\
																		channel_descriptor_setPrimarySourceAddressIncrementNoIncrement(0);\
																		channel_descriptor_setPrimarySourceDataAccessControlNonPriviledged(0);\
																		channel_descriptor_setPrimaryDestinationEndPointer(0, \
																				( (uint32_t)&(phrase_receiver_getBufferElement(0)) ) + \
																				COMMUNICATOR_getBufferSize() - 1 ); \
																		channel_descriptor_setPrimaryDestinationDataSizeByte(0);\
																		channel_descriptor_setAlternateDestinationAddressIncrementByte(0);\
																		channel_descriptor_setPrimaryDestinationDataAccessControlNonPriviledged(0);\
																		channel_descriptor_setPrimaryArbitrateAfterEachTransfer(0);\
																		channel_descriptor_setPrimaryCycleTransferCount(0, PHRASE_RECEIVER_getBufferSize());\
																		channel_descriptor_setPrimaryBasicMode(0);\
																		channel_descriptor_clearPrimaryNextUseBurst(0);\
																		\
																		\
																		dma_enable();\
																	}while(0)

#define PHRASE_RECEIVER_startDma()									do{ dma_enableChannel0(); 													}while(0)
#define PHRASE_RECEIVER_stopDma()									do{ dma_disableChannel0(); 													}while(0)

//== Server-like macros
#define PHRASE_RECEIVER_requestWrite()								do{ ; }while(0)
#define PHRASE_RECEIVER_requestRead()								do{ ; }while(0)

//-- Auxiliary
#define PHRASE_RECEIVER_onInvalid()									do{ ; }while(0)
#define PHRASE_RECEIVER_onBufferOverflow()							do{ ; }while(0)
//----------------------

/**********************************************************************************************************************
* SPI_EXCHANGER Object-like macros
**********************************************************************************************************************/
#define SPI_EXCHANGER_selfData										( electricity_meter_application_selfData.spi_exchanger )

/**********************************************************************************************************************
* SPI_EXCHANGER Function-like macros that DO return value
**********************************************************************************************************************/
#define SPI_EXCHANGER_isSingleTranslationUnit()						( electricity_meter_application_isSingleTranslationUnit() )
#define SPI_EXCHANGER_isDmaReadChannelDone()						( dma_isChannel2Done() )
#define SPI_EXCHANGER_isDmaWriteChannelDone()						( dma_isChannel3Done() )
/**********************************************************************************************************************
* SPI_EXCHANGER Function-like macros that DO NOT return value
**********************************************************************************************************************/
// ===== SPI =====
#define SPI_EXCHANGER_initSpi()	 									do{ /*CTRL*/\
																		usart_setUsart1SynchronousMode();\
																		usart_setUsart1ClockPolarityIdleHigh();\
																		usart_setUsart1ClockPhaseTrailingEdge();\
																		usart_setUsart1MostSignificatntBitFirst();\
																		usart_setUsart1TxBufferInterruptLevelHalfFull();\
																		usart_activateUsart1AutoChipSelect();\
																		usart_setUsart1ByteSwapDoubleAccess();\
																		/*FRAME*/\
																		usart_setUsart1FrameSixteenDataBits();\
																		/*CMD*/\
																		usart_enableUsart1Master();\
																		usart_enableUsart1Transmitter();\
																		usart_enableUsart1Receiver();\
																		/*CLKDIV*/\
																		usart_setUsart1FractionalClockDivider(17664);\
																		/*IFC*/\
																		usart_clearUsart1AllInterruptFlags();\
																		/*ROUTE*/\
																		usart_setUsart1Location1();\
																		usart_enableUsart1ClockPin();\
																		usart_enableUsart1ChipsSelectPin();\
																		usart_enableUsart1TxPin();\
																		usart_enableUsart1RxPin();\
																	}while(0)
// ===== DMA =====
#define SPI_EXCHANGER_initDmaRxChannel()                       		do{ \
																	     dma_selectSourceUsart1(2);\
																	     dma_selectInputSignalRxDataAvailable(2);\
																	     dma_usePrimaryStructureForChannel2();\
																	     dma_setChannelControlDataBasePointer();\
																	     dma_enablePeripheralRequestForChannel2();\
																	     \
																	     \
																	     channel_descriptor_setPrimarySourceEndPointer(2,\
																	    		 ((uint32_t)&usart_getUsart1RxDouble()) );\
																	     channel_descriptor_setPrimarySourceDataSizeHalfWord(2);\
																	     channel_descriptor_setPrimarySourceAddressIncrementNoIncrement(2);\
																	     channel_descriptor_setPrimarySourceDataAccessControlNonPriviledged(2);\
																	     channel_descriptor_setPrimaryDestinationEndPointer(2,\
																	    		 ((uint32_t)frame_getAddressOfRead()));\
																	     channel_descriptor_setPrimaryDestinationDataSizeHalfWord(2);\
																	     channel_descriptor_setPrimaryDestinationAddressIncrementNoIncrement(2);\
																	     channel_descriptor_setPrimaryDestinationDataAccessControlNonPriviledged(2);\
																	     channel_descriptor_setPrimaryArbitrateAfterEachTransfer(2);\
																	     channel_descriptor_setPrimaryCycleTransferCount(2, 2);\
																	     channel_descriptor_setPrimaryBasicMode(2);\
																	     channel_descriptor_clearPrimaryNextUseBurst(2);\
																	     \
																	     \
																	     dma_enable();\
																	}while(0)

#define SPI_EXCHANGER_startDmaRxChannel()                      		do{ dma_enableChannel2();     												}while(0)

#define SPI_EXCHANGER_recycleRxTransfer()							do{ \
																		dma_clearChannel2DoneInterruptFlag();\
																		channel_descriptor_setPrimaryCycleTransferCount(2, 2);\
																		channel_descriptor_setPrimaryBasicMode(2);\
																		dma_enableChannel2();\
																	}while(0)

#define SPI_EXCHANGER_initDmaTxChannel()                       		do{ \
																	     dma_selectSourceUsart1(3);\
																	     dma_selectInputSignalTxBufferLevel(3);\
																	     dma_usePrimaryStructureForChannel3();\
																	     dma_setChannelControlDataBasePointer();\
																	     dma_enablePeripheralRequestForChannel3();\
																	     \
																	     \
																	     channel_descriptor_setPrimarySourceEndPointer(3,\
																	    		 ((uint32_t)frame_getAddressOfWrite()) + (4 - 1) );\
																	     channel_descriptor_setPrimarySourceDataSizeByte(3);\
																	     channel_descriptor_setPrimarySourceAddressIncrementByte(3);\
																	     channel_descriptor_setPrimarySourceDataAccessControlNonPriviledged(3);\
																	     channel_descriptor_setPrimaryDestinationEndPointer(3, &usart_getUsart1TxData() );\
																	     channel_descriptor_setPrimaryDestinationDataSizeByte(3);\
																	     channel_descriptor_setPrimaryDestinationAddressIncrementNoIncrement(3);\
																	     channel_descriptor_setPrimaryDestinationDataAccessControlNonPriviledged(3);\
																	     channel_descriptor_setPrimaryArbitrateAfterEachTransfer(3);\
																	     channel_descriptor_setPrimaryCycleTransferCount(3, 4);\
																	     channel_descriptor_setPrimaryBasicMode(3);\
																	     channel_descriptor_clearPrimaryNextUseBurst(3);\
																	     \
																	     \
																	     dma_enable();\
																	}while(0)

#define SPI_EXCHANGER_startDmaTxChannel()                  			do{ dma_enableChannel3();     												}while(0)


#define SPI_EXCHANGER_recycleTxTransfer()							do{ \
																		dma_clearChannel3DoneInterruptFlag();\
																		channel_descriptor_setPrimaryCycleTransferCount(3, 4);\
																		channel_descriptor_setPrimaryBasicMode(3);\
																		dma_enableChannel3();\
																	}while(0)





#define SPI_EXCHANGER_initDMA()										do{ \
																		SPI_EXCHANGER_initDmaRxChannel(); \
																		SPI_EXCHANGER_initDmaTxChannel();\
																	}while(0)

#define SPI_EXCHANGER_recycleDma()									do{ \
																		SPI_EXCHANGER_recycleTxTransfer(); \
																		SPI_EXCHANGER_recycleRxTransfer();  \
																	}while(0)

#define SPI_EXCHANGER_clearDmaReadChannelDone()						do{ dma_clearChannel2DoneInterruptFlag(); 									}while(0)
#define SPI_EXCHANGER_clearDmaWriteChannelDone()                    do{ dma_clearChannel3DoneInterruptFlag(); 									}while(0)

// Client Like
#define SPI_EXCHANGER_responseDone()								do{ electricity_meter_m90e32as_confirmDone(); 							}while(0)


//----------------------

//--
/**********************************************************************************************************************
* TIMER Object-like macros
**********************************************************************************************************************/
#define TIMER_raiseBits(reg, mask)									do{ bits_raiseBits(reg, mask); 												} while(0)
#define TIMER_clearBits(reg, mask)   								do{ bits_clearBits(reg, mask); 												} while(0)
#define TIMER_assertBits(reg, mask)									do{ bits_assertBits(reg, mask); 											} while(0)
/**********************************************************************************************************************
* TIMER Function-like macros that DO return value
**********************************************************************************************************************/
#define TIMER_isSingleTranslationUnit()				 				( electricity_meter_application_isSingleTranslationUnit() )
#define TIMER_getBitMask(EndBit, StartBit)							( bits_getBitMask(EndBit, StartBit) )

/**********************************************************************************************************************
* TIMER Function-like macros that DO NOT return value
**********************************************************************************************************************/
//--

/**********************************************************************************************************************
* Top Limit Object-like macros
**********************************************************************************************************************/
#define TOP_LIMIT_assertEventNone()								 	do{ ELECTRICITY_METER_APPLICATION_assertEventNone(); 						}while(0)

/**********************************************************************************************************************
* Top Limit Function-like macros that DO return value
**********************************************************************************************************************/


/**********************************************************************************************************************
* Top Limit Function-like macros that DO NOT return value
**********************************************************************************************************************/
#define TOP_LIMIT_onIdle()
#define TOP_LIMIT_onRejected()										do{ ; }while(0)


//==
/**********************************************************************************************************************
* Translator Object-like macros
**********************************************************************************************************************/
#define TRANSLATOR_selfData											ELECTRICITY_METER_APPLICATION_selfData.translator
/**********************************************************************************************************************
* Translator Function-like macros that DO return value
**********************************************************************************************************************/
#define TRANSLATOR_isCommandRead()									( phrase_isRead() )

#define TRANSLATOR_getWordAddress()									( word_getAddress() )
#define TRANSLATOR_getWordValue()                                   ( word_getValue() )
/**********************************************************************************************************************
* Translator Function-like macros that DO NOT return value
**********************************************************************************************************************/

#define TRANSLATOR_requestElectricityMeterRead(address)				do{ \
																		electricity_meter_m90e32as_indicateRead(address);\
																	}while(0)

#define TRANSLATOR_requestElectricityMeterWrite(address, value)		do{ \
																			electricity_meter_m90e32as_indicateWrite(address, value);\
																	}while(0)

// Server-Like macros
#define TRANSLATOR_requestTransmitter() 							do{ transmitter_indicateTransmit(); 										}while(0)
#define TRANSLATOR_requestReceiverReset()							do{ receiver_indicateReset(); 												}while(0)

// Auxiliaries

#define TRANSLATOR_preparePhrase()									do{	 \
																		sprintf( (char *)communicator_getBufferAddress(),\
																				"%02x %04x\n",\
																				electricity_meter_m90e32as_getAddress(), \
																				electricity_meter_m90e32as_getValue());  \
																	}while(0)

#define TRANSLATOR_prepareTransmission()										do{	 \
																					channel_descriptor_setPrimarySourceEndPointer(1,\
																							((uint32_t)communicator_getBufferAddress()) +\
																							strlen( (const char*) communicator_getBufferAddress() ));\
																					dma_clearChannel1DoneInterruptFlag(); \
																					channel_descriptor_setPrimaryCycleTransferCount(\
																				1,\
																				1 + strlen((char*)communicator_getBufferAddress())\
																				);\
																				channel_descriptor_setPrimaryBasicMode(1);\
																	}while(0)

//==


//==
/**********************************************************************************************************************
* TRANSMITTER Object-like macros
**********************************************************************************************************************/
/**********************************************************************************************************************
* TRANSMITTER Function-like macros that DO return value
**********************************************************************************************************************/
#define TRANSMITTER_getCh1DescDestinationEndPointer()				( (uint32_t)&usart_getTxData(usart_uart1) )
#define TRANSMITTER_isDmaCh1Done()									( dma_isChannel1Done() )
/**********************************************************************************************************************
* TRANSMITTER Function-like macros that DO NOT return value
**********************************************************************************************************************/
#define TRANSMITTER_clearDmaCh1Done()								do{ dma_clearChannel1DoneInterruptFlag();									}while(0)
#define TRANSMITTER_onUnexpectedDmaDone()

// Clinet-like methods
#define TRANSMITTER_responseDone()									do{ translator_confirm();													}while(0)



#define TRANSMITTER_initializeDma()									do{ \
																		dma_selectSourceUart1(1);\
																		dma_selectInputSignalTxBufferLevel(1);\
																		dma_usePrimaryStructureForChannel1();\
																		dma_setChannelControlDataBasePointer();\
																		dma_enablePeripheralRequestForChannel1();\
																		\
																		\
																		channel_descriptor_setPrimarySourceEndPointer(1,\
																				((uint32_t)communicator_getBufferAddress()) +\
																				strlen( (const char*) communicator_getBufferAddress() ));\
																		channel_descriptor_setPrimarySourceDataSizeByte(1);\
																		channel_descriptor_setPrimarySourceAddressIncrementByte(1);\
																		channel_descriptor_setPrimarySourceDataAccessControlNonPriviledged(1);\
																		channel_descriptor_setPrimaryDestinationEndPointer(1, &usart_getUart1TxData() );\
																		channel_descriptor_setPrimaryDestinationDataSizeByte(1);\
																		channel_descriptor_setPrimaryDestinationAddressIncrementNoIncrement(1);\
																		channel_descriptor_setPrimaryDestinationDataAccessControlNonPriviledged(1);\
																		channel_descriptor_setPrimaryArbitrateAfterEachTransfer(1);\
																		channel_descriptor_setPrimaryCycleTransferCount(1,\
																				strlen( (const char*) communicator_getBufferAddress() ) + 1);\
																		channel_descriptor_setPrimaryBasicMode(1);\
																		channel_descriptor_clearPrimaryNextUseBurst(1);\
																		\
																		\
																		dma_enable();\
																	}while(0)

#define TRANSMITTER_startDma()										do{ dma_enableChannel1();													 }while(0)


// Auxiliary
#define TRANSMITTER_stop()											do{ dma_disableChannel1(); 														}while(0)

//==

//==
/**********************************************************************************************************************
* USART Object-like macros
**********************************************************************************************************************/
/**********************************************************************************************************************
* USART Function-like macros that DO return value
**********************************************************************************************************************/
#define USART_singleTranslationUnit()				 				electricity_meter_application_isSingleTranslationUnit()
#define USART_getBitMask(EndBit, StartBit)							bits_getBitMask(EndBit, StartBit)
#define USART_raiseBits(reg, mask)									do{ (reg) |= (mask); 														}while(0);

/**********************************************************************************************************************
* USART Function-like macros that DO NOT return value
**********************************************************************************************************************/
#define USART_assert1(reg, mask)									do{ utility_assert1(__usart_getInterruptFlagClear(usart_uart1), mask);		}while(0)

/**********************************************************************************************************************
* USART  Function-like macros that DO return value
**********************************************************************************************************************/



/**********************************************************************************************************************
* Typedef declarations necessary for classes aggregated by the application
**********************************************************************************************************************/

// Communicator
typedef uint8_t COMMUNICATOR_Event;
typedef uint8_t COMMUNICATOR_State;
typedef uint8_t	COMMUNICATOR_Address;
typedef uint8_t COMMUNICATOR_Buffer[COMMUNICATOR_getBufferSize()];
// Electricity Meter
typedef uint8_t ELECTRICITY_METER_M90E32AS_Event;
typedef uint8_t ELECTRICITY_METER_M90E32AS_State;

// Electricity Meter Application
typedef uint8_t ELECTRICITY_METER_APPLICATION_Event;
typedef uint8_t ELECTRICITY_METER_APPLICATION_State;

// Range
typedef uint8_t RANGE_RowIndex;
typedef uint8_t RANGE_Event;
typedef uint8_t RANGE_State;
// Reader
typedef uint8_t READER_Event;
typedef uint8_t READER_State;
typedef uint8_t READER_RowIndex;
typedef uint8_t READER_ColumnIndex;

// SPI Exchanger
typedef uint8_t SPI_EXCHANGER_State;
typedef uint8_t SPI_EXCHANGER_Event;

// Top Limit
typedef uint8_t TOP_LIMIT_Limit;	//Depends on RANGE_RowIndex ( TOP_LIMIT_RowIndex <= RANGE_RowIndex/2 )

// Transmitter
typedef uint8_t TRANSMITTER_State;
typedef uint8_t TRANSMITTER_Event;

//-- Phrase
typedef uint8_t PHRASE_State;
typedef uint8_t PHRASE_Event;

//-- Receiver
typedef uint8_t PHRASE_RECEIVER_State;
typedef uint8_t PHRASE_RECEIVER_Event;

//-- Top limit
typedef uint8_t TOP_LIMIT_Event;
typedef uint8_t TOP_LIMIT_State;

//-- Bottom Limit
typedef uint8_t BOTTOM_LIMIT_Event;
typedef uint8_t BOTTOM_LIMIT_State;

#endif //__ELECTRICITY_METER_APPLICATION_CONFIGURATION__
 /**********************************************************************************************************************
 * End of File
 **********************************************************************************************************************/
