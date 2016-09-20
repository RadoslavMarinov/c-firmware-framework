/**********************************************************************************************************************
 * C Configuration Header: communicator-configuration.h
 * Component: Communicator
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/


 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __COMMUNICATOR_CONFIGURATION__
#define __COMMUNICATOR_CONFIGURATION__

/**********************************************************************************************************************
* Typedef declarations necessary for aggregated classes
**********************************************************************************************************************/



/**********************************************************************************************************************
* Bottom Limit Object-like macros
**********************************************************************************************************************/
#define BOTTOM_LIMIT_selfData										COMMUNICATOR_selfData.bottom_limit

/**********************************************************************************************************************
* Bottom Limit Function-like macros that DO return value
**********************************************************************************************************************/
#define BOTTOM_LIMIT_getChar()										( range_getChar() )
#define BOTTOM_LIMIT_getGlossaryChar(row)							( communicator_slmbEMeter.reg[row].name[reader_getColumn()] )

/**********************************************************************************************************************
* Bottom Limit Function-like macros that DO NOT return value
**********************************************************************************************************************/
#define BOTTOM_LIMIT_responseNotFound()								do{ range_confirmNotFound(); 												}while(0)
#define BOTTOM_LIMIT_responseFound()								do{ range_confirmFound(); 													}while(0)



/**********************************************************************************************************************
* COMMUNICATOR Object-like macros
**********************************************************************************************************************/
#define COMMUNICATOR_getPhraseWordCount()							( 2 )
//#define COMMUNICATOR_getRegisterCount()								( 3 )
#define COMMUNICATOR_PhraseSelfData									phrase_SelfData
#define COMMUNICATOR_ReaderSelfData 								reader_SelfData
#define COMMUNICATOR_ReceiverSelfData								receiver_SelfData
#define COMMUNICATOR_TransmitterSelfData							transmitter_SelfData
#define COMMUNICATOR_WordSelfData									word_SelfData
#define COMMUNICATOR_buffer											COMMUNICATOR_selfData.buffer
#define COMMUNICATOR_RangeSelfData 									range_SelfData
#define COMMUNICATOR_TopLimitSelfData 								top_limit_SelfData
#define COMMUNICATOR_BottomLimitSelfData							bottom_limit_SelfData

/**********************************************************************************************************************
* COMMUNICATOR Function-like macros that DO return value
**********************************************************************************************************************/
#define COMMUNICATOR_getBuffer()									( COMMUNICATOR_selfData.buffer )
#define COMMUNICATOR_getReceiverLastAnalyzedCharIndex()				( receiver_getLastAnalyzedCharIndex() )

#define COMMUNICATOR_isCommandRead()                                 ( phrase_isRead() )
#define COMMUNICATOR_isCommandWrite()                                ( phrase_isWrite() )
/**********************************************************************************************************************
* COMMUNICATOR Function-like macros that DO NOT return value
**********************************************************************************************************************/

#define COMMUNICATOR_setUpTransmitter() 							do{ transmitter_setUpBufferTransfer( word_getNameStart(), word_getNameEndPlus1() +\
																		strlen((const char*)&communicator_getBufferElement(word_getNameEndPlus1())));\
																	}while(0)

#define COMMUNICATOR_phraseInit()									do{ phrase_init(); 															}while(0)

#define COMMUNICATOR_setUpTransmitterBufferTransfer(startIndex, endIndex) do{ transmitter_setUpBufferTransfer( startIndex, endIndex ); 			}while(0)
#define COMMUNICATOR_setUpTransmitterTransfer( address, transferCount )   do{ transmitter_setUpTransfer( address, transferCount );				}while(0)
#define COMMUNICATOR_onTransmitterIdle()							do{ receiver_setEventReset();												}while(0)
#define COMMUNICATOR_onBufferOverflow()								do{ transmitter_setEventTransmit(); 										}while(0)
#define COMMUNICATOR_onInvalid()            						do{ transmitter_setEventTransmit(); 										}while(0)
#define COMMUNICATOR_onRead()               						do{ transmitter_setEventTransmit(); 										}while(0)
#define COMMUNICATOR_onWrite()              						do{ transmitter_setEventTransmit();											}while(0)

// Append stringized register-address to the end of the buffer-name. NOTE than thereis an space before the adderss string
#define COMMUNICATOR_prepareResponse()								(sprintf( __communicator_getBufferElementAddress(word_getNameEndPlus1()), " %X\n",\
																	communicator_getGlossaryRegAddressValue(range_getTop())))

// Server methods
#define COMMUNICATOR_requestReader()								do{ reader_indicateSearch(); 												}while(0)
#define COMMUNICATOR_requestTransmitter()							do{ transmitter_indicateTransmit(); 										}while(0)





//=====  =====  =====  =====  =====  =====  =====  =====  =====  =====  =====  =====  =====  =====

/**********************************************************************************************************************
* RANGE Object-like macros
**********************************************************************************************************************/
#define RANGE_selfData													COMMUNICATOR_selfData.range

/**********************************************************************************************************************
* RANGE Function-like macros that DO return value
**********************************************************************************************************************/
#define RANGE_getGlossaryChar(row)										( communicator_slmbEMeter.reg[row].name[reader_getColumn()] )
#define RANGE_getTop() 													( top_limit_getTop() )
#define RANGE_getBottom()												( bottom_limit_getBottom() )
/**********************************************************************************************************************
* READER Function-like macros that DO NOT return value
**********************************************************************************************************************/

#define RANGE_setColumn(col)										do{ READER_selfData.column = (col); 										}while(0)

#define RANGE_onOutOfRange()										do{ ; }while(0)
#define RANGE_onSelect()											do{ /*limmit_setEvSelectTop(); */											}while(0)
#define RANGE_onSelected()											do{ ; }while(0)
#define RANGE_onSelectBottom()										do{ ; }while(0)
#define RANGE_responseNotFound() 									do{ reader_confirmCharNotFound(); 											}while(0)
#define RANGE_responseFound()										do{ reader_confirmCharFound(); 												}while(0)
#define RANGE_responseReady()										do{ reader_confirmRangeReady(); 											}while(0)
#define RANGE_onSetBottom()											do{ ; }while(0)
#define RANGE_onIdle()												do{ ; }while(0)


#define RANGE_requestTopLimit()										do{												\
																		top_limit_init();							\
																		top_limit_setTop( range_getTop() );			\
																		top_limit_setBottom( range_getBottom() ); 	\
																		top_limit_indicateSearch();					\
																	}while(0)

#define RANGE_requestBottomLimit()									do{	\
																		bottom_limit_init();\
																		bottom_limit_setTop( range_getTop() );\
																		bottom_limit_setBottom( range_getBottom() );\
																		bottom_limit_indicateSearch();\
																	}while(0)

/**********************************************************************************************************************
* READER Object-like macros
**********************************************************************************************************************/
#define READER_selfData												COMMUNICATOR_selfData.reader
/**********************************************************************************************************************
* READER Function-like macros that DO return value
**********************************************************************************************************************/
#define READER_getGlossaryTopRow() 									( 0 )	//Array firs element is always 0
#define READER_getGlossaryBottomRow() 								( COMMUNICATOR_getInterlocutorRegsterCount() - 1 )

#define READER_getInputStartColumn()								( word_getNameStart() )
#define READER_getInputEndColumn()									( COMMUNICATOR_selfData.word[0].endIndexPlus1 - 1 )

#define READER_getInputChar()										( communicator_getBufferElement( word_getNameStart() + (reader_getColumn() ) ) )
#define READER_getGlossaryChar(row, column)							( communicator_slmbEMeter.reg[row].name[column] )

#define READER_getNameSize()										( word_getNameEndPlus1() - word_getNameStart()  )

/**********************************************************************************************************************
* READER Function-like macros that DO NOT return value
**********************************************************************************************************************/

#define READER_RequestRangeSearch()									do{ range_indicateSelect(); 												}while(0)
#define READER_requestRangeReset()									do{ range_indicateReset(); 													}while(0)
#define READER_setRangeChar(ch)										do{ range_setCharacter( ch ); 												}while(0)

#define READER_updateRangeCharacter()								do{ range_setCharacter( READER_getInputChar() ); 							}while(0)
#define READER_initializeRange()									do{range_init(); 															}while(0)
/* The first element of an array is always 0 */
/* The last element's ordinal number is: ( (the cardinal number of the array) - 1) */
#define READER_initializeRangeLimits()								do{ \
																		range_setTop(0); \
																		range_setBottom( COMMUNICATOR_getInterlocutorRegsterCount() - 1 );\
																	}while(0)

#define READER_responseFound()										do{ communicator_confirmFound(); 											}while(0)
#define READER_responseNotFound()									do{ communicator_confirmNotFound(); 										}while(0)



#define READER_onStringNotFound() 									do{ ; }while(0)
#define READER_onStringFound()										do{ ; }while(0)

/**********************************************************************************************************************
* RECEIVER Object-like macros
**********************************************************************************************************************/
#define RECEIVER_selfData											COMMUNICATOR_selfData.receiver
#define RECEIVER_getBuffer()										( COMMUNICATOR_selfData.buffer )

/**********************************************************************************************************************
* RECEIVER Function-like macros that DO return value
**********************************************************************************************************************/
#define RECEIVER_getToAnalyzeNextIndex()							( RECEIVER_selfData.toAnalyzeNextIndex )
//--channel descriptor
#define RECEIVER_getChannelDescriptorCh0PrimaryNextWriteAddress() 	( COMMUNICATOR_getChannelDescriptorCh0PrimaryNextWriteAddress() )
#define RECEIVER_getChannelDescriptorCh0PrimaryRemainigTransferCount()		( COMMUNICATOR_getChannelDescriptorCh0PrimaryRemainingTransferCount() )
//--communicator
#define RECEIVER_getBufferStartAddress()							( ((uint32_t)&COMMUNICATOR_selfData.buffer[0]) )
#define RECEIVER_getBufferSize()									( COMMUNICATOR_getBufferSize() )
//-- dma
#define RECEIVER_isDmaCh0Done()										( COMMUNICATOR_isDmaCh0Done() )
//--transmitter
#define RECEIVER_transmitter_isTransmitterBusy()					( transmitter_isStateBusy() )
#define RECEIVER_transmitter_isTransmitterIdle()					( transmitter_isStateIdle() )
//--uart1
#define RECEIVER_isUart1RxDataAvailable()							( COMMUNICATOR_isUart1RxDataAvailable() )



/**********************************************************************************************************************
* RECEIVER Function-like macros that DO NOT return value
**********************************************************************************************************************/
//-- emit events

//Server methods

#define RECEIVER_setPhraseRead()                   					do{ phrase_setRead(); 														}while(0)
#define RECEIVER_setPhraseWrite()                  					do{ phrase_setWrite(); 														}while(0)
#define RECEIVER_setPhraseInvalid()                					do{ phrase_setInvalid(); 													}while(0)


#define RECEIVER_onInvalid()
#define RECEIVER_onRead()
#define RECEIVER_onWrite()
#define RECEIVER_onBufferOverflow()



//--frame
#define RECEIVER_setFrameStateBufferOverflow()						do{ COMMUNICATOR_setFrameStateBufferOverflow(); 							}while(0)
#define RECEIVER_setFrameStateInvalid()								do{ phrase_setStateInvalid(); 												}while(0)
#define RECEIVER_setFrameStateRead()								do{ phrase_setStateRead(); 													}while(0)
#define RECEIVER_setFrameStateWrite()								do{ phrase_setStateWrite(); 												}while(0)
//--transmitter
#define RECEIVER_startTransmitterTransfer(startIndex, endIndex) 	do{ transmitter_setUpBufferTransfer( startIndex, endIndex );				}while(0)
//--word
#define RECEIVER_setWordNameStartIndex()							do{ word_setNameStart( receiver_getLastAnalyzedCharIndex() ); 				}while(0)
#define RECEIVER_setWordNameEndIndexPlus1()							do{ word_setNameEndPlus1( receiver_getLastAnalyzedCharIndex() ); 			}while(0)
#define RECEIVER_setWordValueStartIndex()							do{ word_setValueStart( receiver_getLastAnalyzedCharIndex() ) ; 			}while(0)
#define RECEIVER_setWordValueEndIndexPlus1()						do{ word_setValueEndPlus1( receiver_getLastAnalyzedCharIndex() ); 			}while(0)

/**********************************************************************************************************************
* Top Limit Object-like macros
**********************************************************************************************************************/
#define TOP_LIMIT_selfData											COMMUNICATOR_selfData.top_limit

/**********************************************************************************************************************
* Top Limit Function-like macros that DO return value
**********************************************************************************************************************/

#define TOP_LIMIT_getChar()											( range_getChar() )
#define TOP_LIMIT_getGlossaryChar(row)      						( communicator_slmbEMeter.reg[row].name[reader_getColumn()] )
/**********************************************************************************************************************
* Top Limit Function-like macros that DO NOT return value
**********************************************************************************************************************/
#define TOP_LIMIT_responseFound()									do{ range_confirmFound(); 													}while(0)
#define TOP_LIMIT_responseNotFound()								do{ range_confirmNotFound();												}while(0)



/**********************************************************************************************************************
* TRANSMITTER Object-like macros
**********************************************************************************************************************/
//--transmitter
#define TRANSMITTER_selfData										COMMUNICATOR_selfData.transmitter



/**********************************************************************************************************************
* TRANSMITTER Object-like macros
**********************************************************************************************************************/
#define TRANSMITTER_getBuffer() 									( COMMUNICATOR_buffer )

//--transmitter
#define TRANSMITTER_setDmaCh1SourceUart1()						    do{ COMMUNICATOR_setDmaCh1SourceUart1();                                    }while(0)
#define TRANSMITTER_selectDmaCh1InputSignalRxDataAvailable()	    do{ COMMUNICATOR_selectDmaCh1InputSignalRxDataAvailable();                  }while(0)
#define TRANSMITTER_selectDmaCh1InputSignalTxBufferLevel()	  		do{ COMMUNICATOR_selectDmaCh1InputSignalTxBufferLevel();					}while(0)
#define TRANSMITTER_enableDma()								        do{ COMMUNICATOR_enableDma();                                               }while(0)
#define TRANSMITTER_useDmaCh1PrimaryStructure()				        do{ COMMUNICATOR_useDmaCh1PrimaryStructure();                               }while(0)
#define TRANSMITTER_setDmaControlDataBasePointer()					do{ COMMUNICATOR_setDmaControlDataBasePointer();                            }while(0)
#define TRANSMITTER_enableDmaCh1PeripheralRequest()			        do{ COMMUNICATOR_enableDmaCh1PeripheralRequest();                           }while(0)
#define TRANSMITTER_enableDmaCh1() 									do{ COMMUNICATOR_enableDmaCh1();											}while(0)

#define TRANSMITTER_setCh1PrimaryDestinationEndPointer(address)	   				do{ COMMUNICATOR_setCh1PrimaryDestinationEndPointer(address);				}while(0)
#define TRANSMITTER_setCh1PrimarySourceEndPointer(address)			        	do{ COMMUNICATOR_setCh1PrimarySourceEndPointer(address);			        }while(0)
#define TRANSMITTER_setCh1PrimaryDestinationAddressIncrementByte()          	do{ COMMUNICATOR_setCh1PrimaryDestinationAddressIncrementByte();            }while(0)
#define TRANSMITTER_setCh1PrimaryDestinationAddressIncrementNoIncrement()   	do{ COMMUNICATOR_setCh1PrimaryDestinationAddressIncrementNoIncrement();     }while(0)
#define TRANSMITTER_setCh1PrimaryDestinationDataSizeByteValue()	            	do{ COMMUNICATOR_setCh1PrimaryDestinationDataSizeByteValue();	            }while(0)
#define TRANSMITTER_setCh1PrimarySourceAddressIncrementNoIncrement()	    	do{ COMMUNICATOR_setCh1PrimarySourceAddressIncrementNoIncrement();	        }while(0)
#define TRANSMITTER_setCh1PrimarySourceAddressIncrementByte()		        	do{ COMMUNICATOR_setCh1PrimarySourceAddressIncrementByte();		            }while(0)
#define TRANSMITTER_setCh1PrimarySourceDataSizeByte()				        	do{ COMMUNICATOR_setCh1PrimarySourceDataSizeByte();				            }while(0)
#define TRANSMITTER_setCh1PrimaryDestinationDataAccessControlNonPriviledged()  	do{ COMMUNICATOR_setCh1PrimaryDestinationDataAccessControlNonPriviledged(); }while(0)
#define TRANSMITTER_setCh1PrimarySourceDataAccessControlNonPriviledged()       	do{ COMMUNICATOR_setCh1PrimarySourceDataAccessControlNonPriviledged();      }while(0)
#define TRANSMITTER_setCh1PrimaryArbitrateAfterEachTransfer()		            do{ COMMUNICATOR_setCh1PrimaryArbitrateAfterEachTransfer();		            }while(0)
#define TRANSMITTER_setCh1PrimaryCycleTransferCount(trCount)		            do{ COMMUNICATOR_setCh1PrimaryCycleTransferCount(trCount);		            }while(0)
#define TRANSMITTER_clearCh1PrimaryNextUseBurst()					            do{ COMMUNICATOR_clearCh1PrimaryNextUseBurst();					            }while(0)
#define TRANSMITTER_setCh1PrimaryBasicMode()                                   	do{ COMMUNICATOR_setCh1PrimaryBasicMode();	                                }while(0)
#define TRANSMITTER_onIdle()													do{ communicator_transmitterIdle();											}while(0)

//-- Client methods



#endif //__COMMUNICATOR_CONFIGURATION__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
