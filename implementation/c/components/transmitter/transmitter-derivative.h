/***********************************************************************************************************************
 * C Header: transmitter-derivative.h
 * Component: Communicator
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __TRANSMITTER_DERIVATIVE_INTERFCE__
#define __TRANSMITTER_DERIVATIVE_INTERFCE__

 /**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/
// #ifndef
// 	#error Missing required
// #endif

#ifndef TRANSMITTER_stop
	#error Missing required TRANSMITTER_stop()
#endif

/**********************************************************************************************************************
* Private typedefs (__xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private object-like macros   (__xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private function-like macros that DO return value  (__xxx)
**********************************************************************************************************************/

#define __transmitter_getEvent()									( TRANSMITTER_selfData.event )
#define __transmitter_getState()									( TRANSMITTER_selfData.state )

/**********************************************************************************************************************
* Private function-like macros that DO NOT return value (__xxx)
**********************************************************************************************************************/

#define __transmitter_setEvent(ev)									do{ __transmitter_getEvent() = ( ev ); 										}while(0)
#define __transmitter_setEventNone()                                do{ __transmitter_setEvent( __transmitter_eventNone ); 						}while(0)
#define __transmitter_setEventEntry()                               do{ __transmitter_setEvent( __transmitter_eventEntry ); 					}while(0)
#define __transmitter_setEventTransmit()							do{ __transmitter_setEvent( __transmitter_eventTransmit ); 					}while(0)
#define __transmitter_setEventTransmissionDone()					do{ __transmitter_setEvent( __transmitter_eventTransmissionDone ); 			}while(0)
#define __transmitter_setEventReset()								do{ __transmitter_setEvent( __transmitter_eventReset );			 			}while(0)

#define __transmitter_setState(st)                                  do{ __transmitter_getState() = ( st ); 										}while(0)
#define __transmitter_setStateIdle()								do{ __transmitter_setState( __transmitter_stateIdle ); 						}while(0)
#define __transmitter_setStateBusy()								do{ __transmitter_setState( __transmitter_stateBusy ); 						}while(0)
#define __transmitter_setStateFail()								do{ __transmitter_setState( __transmitter_stateFail ); 						}while(0)

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
	TRANSMITTER_Event event;
	TRANSMITTER_State state;
}transmitter_SelfData;


/**********************************************************************************************************************
* Public object-like macros  (xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO return value (xxx)
**********************************************************************************************************************/

#define transmitter_getState()										( __transmitter_getState() )
#define transmitter_isStateIdle()									( (__transmitter_getState()==__transmitter_stateIdle) ? true, false )
#define transmitter_isStateBusy()									( (__transmitter_getState()==__transmitter_stBusy) ? true, false )

/**********************************************************************************************************************
* Public function-like macros that DO NOT return value (xxx)
**********************************************************************************************************************/

//Client methods (OSI Primitives )
#define transmitter_indicateTransmit()								do{ __transmitter_setEventTransmit(); 										}while(0)



#define transmitter_setEventTransmit()                          	do{ __transmitter_setEvent( __transmitter_eventTransmit ); 					}while(0)
#define transmitter_setEventTransmissionDone()						do{ __transmitter_setEvent( __transmitter_eventTransmissionDone ); 			}while(0)
#define transmitter_start()											do{ TRANSMITTER_enableDmaChannnel1(); 										}while(0)



#define transmitter_reCycle(transferCount)							do{ \
																		TRANSMITTER_setCh1PrimaryCycleTransferCount(transferCount);\
																		TRANSMITTER_setCh1PrimaryBasicMode();\
																		TRANSMITTER_enableDmaChannnel1();\
																	}while(0)

#define transmitter_setUpBufferTransfer( startIndex, endIndex )		do{ \
																		TRANSMITTER_setCh1PrimarySourceEndPointer( &(TRANSMITTER_getBuffer()[endIndex])) ;\
																		TRANSMITTER_setCh1PrimaryCycleTransferCount( (endIndex) - (startIndex) + 1 );\
																		TRANSMITTER_setCh1PrimaryBasicMode();\
																	}while(0)

#define transmitter_setUpTransfer( address, transferCount )		do{	\
																	TRANSMITTER_setCh1PrimarySourceEndPointer( ((uint32_t)address) + (transferCount - 1) );\
																	TRANSMITTER_setCh1PrimaryCycleTransferCount( transferCount );\
																}while(0)




#define transmitter_initializeChannle1PrimaryDescriptor()			do{\
																		/*TRANSMITTER_setCh1PrimarySourceEndPointer(((uint32_t)string) + 12);*/\
																		TRANSMITTER_setCh1PrimarySourceDataSizeByte();\
																		TRANSMITTER_setCh1PrimarySourceAddressIncrementByte();\
																		TRANSMITTER_setCh1PrimarySourceDataAccessControlNonPriviledged();\
																		TRANSMITTER_setCh1PrimaryDestinationEndPointer( TRANSMITTER_getCh1DescDestinationEndPointer() );\
																		TRANSMITTER_setCh1PrimaryDestinationDataSizeByteValue();\
																		TRANSMITTER_setCh1PrimaryDestinationAddressIncrementNoIncrement();\
																		TRANSMITTER_setCh1PrimaryDestinationDataAccessControlNonPriviledged();\
																		TRANSMITTER_setCh1PrimaryArbitrateAfterEachTransfer();\
																		/*TRANSMITTER_setCh1PrimaryCycleTransferCount(13);*/\
																		TRANSMITTER_clearCh1PrimaryNextUseBurst();\
																		/*TRANSMITTER_setCh1PrimaryBasicMode();*/\
																	}while(0)

#define transmitter_initializeDma()									do{ \
																		TRANSMITTER_setDmaCh1SourceUart1();\
																		TRANSMITTER_selectDmaCh1InputSignalTxBufferLevel();\
																		TRANSMITTER_useDmaCh1PrimaryStructure();\
																		TRANSMITTER_setDmaControlDataBasePointer();\
																		TRANSMITTER_enableDmaCh1PeripheralRequest();\
																		\
																		transmitter_initializeChannle1PrimaryDescriptor();\
																		\
																		TRANSMITTER_clearDmaCh1Done();\
																		TRANSMITTER_enableDma();\
																	}while(0)

/*
                                          TRANSMITTER_enableDma();\
*/
//TRANSMITTER_enableDmaCh1();

/**********************************************************************************************************************
* Public function declarations(extern)
**********************************************************************************************************************/
bool transmitter_dispatchEvents(void);
void transmitter_init(void);

#endif //__TRANSMITTER_DERIVATIVE_INTERFCE__
/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/
