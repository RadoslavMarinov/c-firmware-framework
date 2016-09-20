/***********************************************************************************************************************
 * C Header: usrt.h
 * Component: USART
 *===================================================================================================================== 
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __USART_DERIVATIVE_INTERFCE__
#define __USART_DERIVATIVE_INTERFCE__


 /**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/
//#ifndef USART_selfData
//	#error Missing required USART_selfData
//#endif

 /**********************************************************************************************************************
 * Private typedefs
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private object-like macros
 **********************************************************************************************************************/



#define __usart_getControl(object) 				( object.control )	 			// Return control register from object
#define __usart_getFrameFormat(object) 			( object.frameFormat )	 			// Return control register from object
#define __usart_getCommand(object) 				( object.command )
#define __usart_getStatus(object) 				( object.status )
#define __usart_getClockControl(object)			( object.clockControl )
#define __usart_getRxData(object)				( object.rxBufferData )
#define __usart_getRxDouble(object)				( object.rxFifoDoubleData )
#define __usart_getTxData(object)				( object.txBufferData )
#define __usart_getTxDoubleData(object)    		( object.txBufferDoubleData )
#define __usart_getInterruptFlag(object)		( object.interruptFlag )
#define __usart_getInterruptFlagSet(object)		( object.interruptFlagSet )
#define __usart_getInterruptFlagClear(object)	( object.interruptFlagClear )
#define __usart_getRoute(object)				( object.ioRouting )

 /**********************************************************************************************************************
 * Private function-like macros that DO return value
 **********************************************************************************************************************/


 /**********************************************************************************************************************
 * Private function-like macros that DO NOT return value
 **********************************************************************************************************************/
#define __usart_setCommand(object, value)					do{ object.command = value; 												} while(0)
#define __usart_setClockControl(object, mask, value)		do{ __usart_setProperty(__usart_getClockControl(object), mask, value); 		} while(0)//When value is not predefined. Value is a 15bit number
#define __usart_setTxData(object, value)					do{ object.txBufferData = (value); 											} while(0)//Value is 8bit var
#define __usart_setTxDoubleData(object, value)              do{ object.txBufferDoubleData = (value);									} while(0)//Value is 16bit var .Sending order: Tx[0] sent first then Tx[1]


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
volatile uint32_t control;
volatile uint32_t frameFormat;
volatile uint32_t triggerControl;
volatile uint32_t command;
volatile uint32_t status;
volatile uint32_t clockControl;
volatile uint32_t rxBufferDataExtended;
volatile uint32_t rxBufferData;
volatile uint32_t rxBufferDoubleDataExtended;
volatile uint32_t rxFifoDoubleData;
volatile uint32_t rxBufferDataExtendedPeek;
volatile uint32_t rxBufferDoubleDataExtendedPeek;
volatile uint32_t txBufferDataExtended;
volatile uint32_t txBufferData;
volatile uint32_t txBufferDoubleDataExtended;
volatile uint32_t txBufferDoubleData;
volatile uint32_t interruptFlag;
volatile uint32_t interruptFlagSet;
volatile uint32_t interruptFlagClear;
volatile uint32_t interruptEnable;
volatile uint32_t irdaControl;
volatile uint32_t ioRouting;
volatile uint32_t input;
volatile uint32_t i2sControl;
} usart_SelfData;

 /**********************************************************************************************************************
 * Public object-like macros
 **********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO return value
 **********************************************************************************************************************/

//============================================ USARTn_CTRL ============================================

// 28 BYTESWAP IN DOUBLE ACCESS ------------- DO RETURN ----------------------------------------------------------------------
#define usart_getByteSwapDoubleAccessMask()							( USART_getBitMask(28, 28) )
#define usart_getByteSwapDoubleAccessValue()						( __usart_getPropertyValue(1, 28) )
// 28 BYTESWAP IN DOUBLE ACCESS ------------- DO NOT RETURN -------------------------------------------------------------
#define usart_setByteSwapDoubleAccess(object)						do{ \
                                                                    	__usart_setProperty(\
                                                                    	__usart_getControl(object),\
                                                                    	usart_getByteSwapDoubleAccessMask(),\
                                                                    	usart_getByteSwapDoubleAccessValue());\
                                                                    }while(0)
#define usart_setUsart1ByteSwapDoubleAccess() 						do{ usart_setByteSwapDoubleAccess(usart_usart1); 							}while(0)

// 0 SYNC ------------- DO RETURN ----------------------------------------------------------------------
#define usart_getSynchronousModeMask()								( USART_getBitMask(0, 0) )
#define usart_getSynchronousModeValue()								( __usart_getPropertyValue(1, 0) )
#define usart_getAsynchronousModeValue()							( __usart_getPropertyValue(0, 0) )
#define usart_isSynchronousModeRaised(object)						( __usart_getControl(object) &  usart_getSynchronousModeMask() )
// SYNC ------------- DO NOT RETURN -------------
#define usart_setSynchronousMode(object)							do{ \
																		__usart_setProperty(\
																		__usart_getControl(object),\
																		usart_getSynchronousModeMask(),\
																		usart_getSynchronousModeValue() );\
																	}while(0)

#define usart_setAynchronousMode(object)							do{ \
																		__usart_setProperty(\
																		__usart_getControl(object),\
																		usart_getSynchronousModeMask(),\
																		usart_getAsynchronousModeValue() );\
																	}while(0)

#define usart_setUsart1SynchronousMode()							do{ usart_setSynchronousMode( usart_usart1 ); 			}while(0)
#define usart_setUsart1AsynchronousMode()							do{ usart_setAsynchronousMode( usart_usart1 ); 			}while(0)

// 5 OVS ------------- DO RETURN -----------------------------------------------------------------------
#define usart_getOversamplingModeMask()								( USART_getBitMask(6, 5) )
#define usart_getOversamplingMode(object)							( __usart_getControl(object) & usart_getOversamplingModeMask() )
#define usart_getOversamplingMode16Value()							( __usart_getPropertyValue(0, 5) )	//DEFAULT
#define usart_getOversamplingMode8Value()							( __usart_getPropertyValue(1, 5) )
#define usart_getOversamplingMode6Value()							( __usart_getPropertyValue(5, 5) )
#define usart_getOversamplingMode4Value()							( __usart_getPropertyValue(3, 5) )
// OVS ------------- DO NOT RETURN -------------
#define usart_setOversamplingMode16Value(object)			        do{ __usart_setProperty(__usart_getControl(object),		\
															        	usart_getOversamplingModeMask(),					\
															        	usart_getOversamplingMode16Value() );				\
															        } while(0)

#define usart_setOversamplingMode8Value(object)				        do{ __usart_setProperty(__usart_getControl(object),		\
															        	usart_getOversamplingModeMask(),					\
															        	usart_getOversamplingMode8Value() );				\
															        } while(0)

#define usart_setOversamplingMode6Value(object)				        do{ __usart_setProperty(__usart_getControl(object),		\
															        	usart_getOversamplingModeMask(),					\
															        	usart_getOversamplingMode6Value() );				\
															        } while(0)

#define usart_setOversamplingMode4Value(object)				        do{ __usart_setProperty(__usart_getControl(object),		\
															        	usart_getOversamplingModeMask(),					\
															        	usart_getOversamplingMode4Value() );				\
															        } while(0)

// 8 CLKPOL ------------- DO RETURN --------------------------------------------------------------------
#define usart_getClockPolarityMask()								( USART_getBitMask(8, 8) )
#define usart_getClockPolarityIdleLowValue()                        ( __usart_getPropertyValue(0, 8) )
#define usart_getClockPolarityIdleHighValue()						( __usart_getPropertyValue(1, 8) )
#define usart_getClockPolarity(object)									( __usart_getClockControl(object) & usart_getClockPolarityMask() )

// CLKPOL ------------- DO NOT RETURN -------------
#define usart_setClockPolarityIdleLow(object)						do{ \
																		__usart_setProperty(\
																				__usart_getControl(object),\
																				usart_getClockPolarityMask(),\
																				usart_getClockPolarityIdleLowValue();\
																	}while(0)

#define usart_setClockPolarityIdleHigh(object)						do{ \
																		__usart_setProperty(\
																				__usart_getControl(object),\
																				usart_getClockPolarityMask(),\
																				usart_getClockPolarityIdleHighValue());\
																	}while(0)

#define usart_setUsart1ClockPolarityIdleHigh()						do{ usart_setClockPolarityIdleHigh(usart_usart1); 							}while(0)
#define usart_setUsart1ClockPolarityIdleLow()						do{ usart_setClockPolarityIdleLow(usart_usart1); 							}while(0)


// 9 CLKPHA ------------- DO RETURN --------------------------------------------------------------------
#define usart_getClockPhaseMask()									( USART_getBitMask(9, 9) )
#define usart_getSampleLeadingEdgeValue()                           ( __usart_getPropertyValue(0, 9) )
#define usart_getSampleTrailingEdgeValue()							( __usart_getPropertyValue(1, 9) )
#define usart_getClockPhase(object)									( __usart_getClockControl(object) & usart_getClockPhaseMask() )
// CLKPHA ------------- DO NOT RETURN -------------
#define usart_setClockPhaseLeadingEdge(object)						do{ \
																		__usart_setProperty(\
																				__usart_getControl(object),\
																				usart_getClockPhaseMask(),\
																				usart_getSampleLeadingEdgeValue());\
																	}while(0)

#define usart_setClockPhaseTrailingEdge(object)						do{ \
																		__usart_setProperty(\
																				__usart_getControl(object),\
																				usart_getClockPhaseMask(),\
																				usart_getSampleTrailingEdgeValue());\
																	}while(0)

#define usart_setUsart1ClockPhaseLeadingEdge()                      do{ usart_setClockPhaseLeadingEdge(usart_usart1); 							}while(0)
#define usart_setUsart1ClockPhaseTrailingEdge()						do{ usart_setClockPhaseTrailingEdge(usart_usart1); 							}while(0)




// 10 MSBF ------------- DO RETURN ---------------------------------------------------------------------
#define usart_getMostSignificatntBitFirstMask()						( USART_getBitMask(10, 10) )
#define usart_getMostSignificatntBitFirstValue()					( __usart_getPropertyValue(1, 10) )
#define usart_getLeastSignificatntBitFirstValue()					( __usart_getPropertyValue(0, 10) )
#define usart_getLeastSignificatntBitFirst(object)					( __usart_getControl(object) & usart_getMostSignificatntBitFirstMask() )
// MSBF ------------- DO NOT RETURN -------------
#define usart_setMostSignificatntBitFirst(object)					do{ \
																		__usart_setProperty(\
																				__usart_getControl(object),\
																				usart_getMostSignificatntBitFirstMask(),\
																				usart_getMostSignificatntBitFirstValue());\
																	}while(0)

#define usart_setLeastSignificatntBitFirst(object)					do{ \
																		__usart_setProperty(\
																				__usart_getControl(object),\
																				usart_getMostSignificatntBitFirstMask(),\
																				usart_getLeastSignificatntBitFirstValue());\
																	}while(0)

#define usart_setUsart1MostSignificatntBitFirst()					do{ usart_setMostSignificatntBitFirst(usart_usart1); 						}while(0)
#define usart_setUsart1LeastSignificatntBitFirst()					do{ usart_setLeastSignificatntBitFirst(usart_usart1); 						}while(0)


// 12 TXBIL ------------- DO RETURN --------------------------------------------------------------------
#define usart_getTxBufferInterruptLevelMask()						( USART_getBitMask(12, 12) )
#define usart_getTxBufferInterruptLevelEmptyValue()					( __usart_getPropertyValue(0, 12) )
#define usart_getTxBufferInterruptLevelHalfFullValue()				( __usart_getPropertyValue(1, 12) )
// TXBIL ------------- DO NOT RETURN -------------
#define usart_setTxBufferInterruptLevelEmpty(object)                do{ __usart_setProperty(__usart_getControl(object),		\
																		usart_getTxBufferInterruptLevelMask(),				\
																		usart_getTxBufferInterruptLevelEmptyValue() );		\
																	}while(0)

#define usart_setTxBufferInterruptLevelHalfFull(object)            	do{ __usart_setProperty(__usart_getControl(object),		\
																		usart_getTxBufferInterruptLevelMask(),				\
																		usart_getTxBufferInterruptLevelHalfFullValue() );	\
																	}while(0)

#define usart_setUsart1TxBufferInterruptLevelEmpty()				do{ usart_setTxBufferInterruptLevelEmpty(usart_usart1); }while(0)
#define usart_setUsart1TxBufferInterruptLevelHalfFull()	            do{ usart_setTxBufferInterruptLevelHalfFull(usart_usart1);}while(0)

// 16 AUTOCS ------------- DO RETURN --------------------------------------------------------------------
#define usart_getAutoChipSelectMask()								( USART_getBitMask(16, 16) )
#define usart_getAutoChipSelectActivateValue()						( __usart_getPropertyValue(1, 16) )
#define usart_getAutoChipSelectDeactivateValue()					( __usart_getPropertyValue(0, 16) )
#define usart_getAutoChipSelect(object)								( __usart_getClockControl(object) & usart_getAutoChipSelectMask() )
// 16 AUTOCS ------------- DO NOT RETURN -------------
#define usart_activateAutoChipSelect(object)						do{ \
																		__usart_setProperty(__usart_getControl(object),\
																				usart_getAutoChipSelectMask(),\
																				usart_getAutoChipSelectActivateValue());\
																	}while(0)

#define usart_activateUsart1AutoChipSelect()						do{ usart_activateAutoChipSelect(usart_usart1); 							}while(0)

#define usart_deactivateAutoChipSelect(object)						do{ \
																		__usart_setProperty(__usart_getControl(object),\
																				usart_getAutoChipSelectMask();\
																				usart_getAutoChipSelectDeactivateValue();\
																	}while(0)





//============================================ END USARTn_CTRL ============================================




//============================================ USARTn_FRAME============================================

// 0 - 3 DATABITS ------------- DO RETURN ---------------------------------------------------------------
#define usart_getFrameDataBitsMask()								( USART_getBitMask(3, 0) )
//
#define usart_getFourDataBitsValue()								( __usart_getPropertyValue(1, 0) )
#define usart_getFiveDataBitsValue()								( __usart_getPropertyValue(2, 0) )
#define usart_getSixDataBitsValue()									( __usart_getPropertyValue(3, 0) )
#define usart_getSevenDataBitsValue()								( __usart_getPropertyValue(4, 0) )
#define usart_getEightDataBitsValue()								( __usart_getPropertyValue(5, 0) )
#define usart_getNineDataBitsValue()								( __usart_getPropertyValue(6, 0) )
#define usart_getTenDataBitsValue()									( __usart_getPropertyValue(7, 0) )
#define usart_getElevenDataBitsValue()								( __usart_getPropertyValue(8, 0) )
#define usart_getTwelveDataBitsValue()								( __usart_getPropertyValue(9, 0) )
#define usart_getThirtheenDataBitsValue()							( __usart_getPropertyValue(10, 0) )
#define usart_getFourtheenDataBitsValue()							( __usart_getPropertyValue(11, 0) )
#define usart_getFiveteenDataBitsValue()							( __usart_getPropertyValue(12, 0) )
#define usart_getSixteenDataBitsValue()								( __usart_getPropertyValue(13, 0) )
//
#define usart_getFrameDataBits(object)								( __usart_getFrameFormat(object) )
// 0 - 3 DATABITS ------------- DO NOT RETURN ---------------------------------------------------------------
#define usart_setFrameSixteenDataBits(object)						do{ \
																		__usart_setProperty(__usart_getFrameFormat(object), 	\
																				usart_getFrameDataBitsMask(),					\
																				usart_getSixteenDataBitsValue());				\
																	} while(0)

#define usart_setFrameFiveteenDataBits(object)						do{ \
																		__usart_setProperty(__usart_getFrameFormat(object), 	\
																				usart_getFrameDataBitsMask(),					\
																				usart_getFiveteenDataBitsValue());				\
																	} while(0)

#define usart_setUsart1FrameFiveteenDataBits()						do{ usart_setFrameFiveteenDataBits(usart_usart1); 							}while(0)
#define usart_setUsart1FrameSixteenDataBits()						do{ usart_setFrameSixteenDataBits(usart_usart1); 							}while(0)








//============================================ END USARTn_FRAME ============================================


//============================================ USARTn_CMD ============================================

// 5 MASTERDIS ------------- DO RETURN ---------------------------------------------------------------
#define usart_getMasterDisableMask()  								( USART_getBitMask(5, 5) )
#define usart_getMasterDisableValue() 								( __usart_getPropertyValue(1, 5) )
// MASTERDIS ------------- DO NOT RETURN -------------
#define usart_enableSlave(object)									do{ __usart_setCommand(object,  usart_getMasterDisableValue() ); 			}while(0)
#define usart_enableUsart1Slave()									do{ usart_enableSlave(__usart_getCommand(usart_usart1)); 					}while(0)

// 4 MASTEREN(W1) ------------- DO RETURN ------------------------------------------------------------
#define usart_getMasterEnableMask()  								( USART_getBitMask(4, 4) )
#define usart_getMasterEnableValue() 								( __usart_getPropertyValue(1, 4) )
// 4 MASTEREN ------------- DO NOT RETURN -------------
#define usart_eanbleMaster(object)									do{ __usart_setCommand(object,  usart_getMasterEnableValue() ); 			}while(0)
#define usart_enableUsart1Master()									do{ usart_eanbleMaster(usart_usart1); 										}while(0)
																	//Should not be enabled while TXENS is set to 1
// 3 TXDIS (W1) ------------- DO RETURN ------------------------------------------------------------
#define usart_getTransmitterDisableMask()			                ( USART_getBitMask(3, 3) )
#define usart_getTransmitterDisableValue()			                ( __usart_getPropertyValue(1, 3) )
// 3 TXDIS (W1) ------------- DO NOT RETURN -------------
#define usart_disableTransmitter(object)					        do{ __usart_setCommand(object, usart_getTransmitterDisableValue() ); 		}while(0)

// 2 TXEN (W1) ------------- DO RETURN ------------------------------------------------------------
#define usart_getTransmitterEnableMask()			                ( USART_getBitMask(2, 2) )
#define usart_getTransmitterEnableValue()			                ( __usart_getPropertyValue(1, 2) )
// 2 TXEN (W1) ------------- DO NOT RETURN -------------
#define usart_enableTransmitter(object)						        do{ __usart_setCommand(object, usart_getTransmitterEnableValue() ); 		}while(0)
#define usart_enableUsart1Transmitter()								do{ usart_enableTransmitter(usart_usart1); 									}while(0)
// 1 RXDIS (W1) ------------- DO RETURN ------------------------------------------------------------
#define usart_getReceiverDisableMask()				                ( USART_getBitMask(1, 1) )
#define usart_getReceiverDisableValue()				                ( __usart_getPropertyValue(1, 1) )
// 1 RXDIS (W1) ------------- DO NOT RETURN -------------
#define usart_disableReceiver(object)						        do{ __usart_setCommand(object, usart_getReceiverDisableValue() ); 			}while(0)

// 0 RXEN (W1) ------------- DO RETURN ------------------------------------------------------------
#define usart_getReceiverEnableMask()				                ( USART_getBitMask(0, 0) )
#define usart_getReceiverEnableValue()				                ( __usart_getPropertyValue(1, 0) )
// 0 RXEN (W1) ------------- DO NOT RETURN -------------
#define usart_enableReceiver(object)						        do{ __usart_setCommand(object, usart_getReceiverEnableValue() );			}while(0)
#define usart_enableUsart1Receiver()								do{ usart_enableReceiver(usart_usart1);			 							}while(0)
//============================================ END USARTn_CMD ============================================

//============================================ STATUS ============================================
// 8 RXFULL ------------- DO RETURN --------------------------------------------------------------
#define usart_getRxFifoFullMask()					( USART_getBitMask(8, 8) )
#define usart_getRxFifoFullValue()					( __usart_getPropertyValue(1, 8) )
#define usart_isRxFifoFull(object)					( __usart_getStatus(object) & usart_getRxFifoFullMask() )

// STATUS_RXDATAV (R)
#define usart_getRxDataValidMask()					( USART_getBitMask(7, 7) )
#define usart_getRxDataValidValue()					( __usart_getPropertyValue(1, 7) )
#define usart_isRxDataAvailable(object)				( __usart_getStatus(object) & usart_getRxDataValidMask() )
#define usart_isUart1RxDataAvailable()				( usart_isRxDataAvailable(usart_uart1) )
// STATUS_TXBL (R)
#define usart_getTxBufferLevelMask()				( USART_getBitMask(6, 6) )
#define usart_getTxBufferLevelValue()				( __usart_getPropertyValue(1, 6) )
#define usart_isTxBufferEmpty(object)						( __usart_getStatus(object) & usart_getTxBufferLevelMask()) // Set when there is room for new data in TX
// STATUS_TXC (R)
#define usart_getTxCompleteMask()					( USART_getBitMask(5, 5) )
#define usart_getTxCompleteValue()                  ( __usart_getPropertyValue(1, 5) )
#define usart_isTxComplete(object)                 	( __usart_getStatus(object) & usart_getTxCompleteMask())	// Set when TX buffers and shift register are empty



//============================================ END STATUS ============================================

//============================================ CLKDIV ============================================
// 6-20 DIV ------------- DO RETURN --------------------------------------------------------------
#define usart_getFractionalClockDividerMask()		( USART_getBitMask(20, 6) )
#define usart_getFractionalClockDivider(object)		( __usart_getClockControl(object) & usart_getFractionalClockDividerMask() )
// 6-20 DIV ------------- DO RETURN ----------------------
#define usart_setFractionalClockDivider(object, value)		do{ __usart_setProperty(__usart_getClockControl(object), 	\
																usart_getFractionalClockDividerMask(),					\
																(value));												\
															} while(0)		//value takes shifted CLKDIV value (Excel table dependency)

#define usart_setUsart1FractionalClockDivider(value)		do{ usart_setFractionalClockDivider(usart_usart1, value ); }while(0)
//============================================ END CLKDIV ============================================




//============================================ RXDOUBLE============================================
#define usart_getRxDoubleMask()										( USART_getBitMask(15, 0) )

#define usart_getRxDouble(object)									( __usart_getRxDouble(object) )
#define usart_getUsart1RxDouble()									( usart_getRxDouble(usart_usart1) )

//============================================ END RXDOUBLE============================================



//============================================ IFC ============================================

// GENERAL ------------- DO RETURN -----------------------------------------------------------------------------
#define usart_getInterruptFlagClearMask()						( USART_getBitMask(12, 3) | USART_getBitMask(1, 0) )
// GENERAL ------------- DO NOT RETURN -----------------------------------------------------------------------------
#define usart_clearAllInterruptFlags(object)					do{ \
																	__usart_writeOne( \
																			__usart_getInterruptFlagClear(object),\
																			usart_getInterruptFlagClearMask());\
																}while(0)

#define usart_clearUsart1AllInterruptFlags()					do{ usart_clearAllInterruptFlags(usart_usart1); 								}while(0)

//============================================ END IFC ============================================


//============================================ ROUTE ============================================
// 8-10 LOCATION ------------- DO RETURN -----------------------------------------------------------------------------
#define usart_getLocationMask()						( USART_getBitMask(10, 8) )
#define usart_getLocation(object)					( __usart_getRoute(object) & usart_getLocationMask() )
#define usart_getLocation0Value()					( __usart_getPropertyValue(0, 8) )
#define usart_getLocation1Value()					( __usart_getPropertyValue(1, 8) )
#define usart_getLocation2Value()					( __usart_getPropertyValue(2, 8) )
#define usart_getLocation3Value()					( __usart_getPropertyValue(3, 8) )
#define usart_getLocation4Value()					( __usart_getPropertyValue(4, 8) )
#define usart_getLocation5Value()					( __usart_getPropertyValue(5, 8) )
#define usart_getLocation(object)					( __usart_getRoute(object) & usart_getLocationMask() )
// 8-10 LOCATION ------------- DO RETURN ----------------------
#define usart_setLocation0(object)									do{ \
																		__usart_setProperty( \
																				__usart_getRoute(object),\
																				usart_getLocationMask(),\
																				usart_getLocation0Value() );\
																	}while(0)

#define usart_setLocation1(object)							        do{ \
																		__usart_setProperty( \
																				__usart_getRoute(object),\
																				usart_getLocationMask(),\
																				usart_getLocation1Value());\
																	}while(0)

#define usart_setLocation2(object)							        do{ \
																		__usart_setProperty(\
																				__usart_getRoute(object),\
																				usart_getLocationMask(),\
																				usart_getLocation2Value());\
																	}while(0)

#define usart_setLocation3(object)							        do{ \
																		__usart_setProperty( \
																				__usart_getRoute(object),\
																				usart_getLocationMask(),\
																				usart_getLocation3Value() );\
																	}while(0)

#define usart_setLocation4(object)							        do{ \
																		__usart_setProperty(\
																				__usart_getRoute(object),\
																				usart_getLocationMask(),\
																				usart_getLocation4Value() );\
																	}while(0)

#define usart_setLocation5(object)							        do{ \
																		__usart_setProperty( \
																				__usart_getRoute(object),\
																				usart_getLocationMask(),\
																				usart_getLocation5Value() );\
																	}while(0)

#define usart_setUsart1Location1()									do{ usart_setLocation1(usart_usart1); 										}while(0)

// 3 CLKPEN ------------- DO RETURN -------------------------------------------------------------------------
#define usart_getClockPinEnableMask()				                ( USART_getBitMask(3, 3) )
#define isClockPinEnabled(object)					                ( __usart_getRoute(object) & usart_getClockPinEnableMask() )
#define usart_getClockPinEnableValue()				                ( __usart_getPropertyValue(1, 3) )
// 3 CLKPEN ------------- DO RETURN ----------------------
#define usart_enableClockPin(object)   								do{	USART_raiseBits(__usart_getRoute(object), usart_getClockPinEnableValue()); 	}while(0)
#define usart_enableUsart1ClockPin()								do{ usart_enableClockPin(usart_usart1); 									}while(0)
// 2 CSPEN ------------- DO RETURN -------------------------------------------------------------------------
#define usart_getChipSelectPinEnableMask()			                ( USART_getBitMask(2, 2) )
#define isChipSelectPinEnabled(object)				                ( __usart_getRoute(object) & usart_getChipSelectPinEnableMask() )
#define usart_getChipSelectPinEnableValue()			                ( __usart_getPropertyValue(1, 2) )
// 2 CSPEN ------------- DO RETURN ----------------------
#define usart_enableChipsSelectPin(object)			                do{ USART_raiseBits(__usart_getRoute(object), usart_getChipSelectPinEnableValue());}while(0)
#define usart_enableUsart1ChipsSelectPin()							do{ usart_enableChipsSelectPin(usart_usart1); 								}while(0)
// 1 TXPEN ------------- DO RETURN -------------------------------------------------------------------------
#define usart_getTxPinEnableMask()					                ( USART_getBitMask(1, 1) )
#define isTxPinEnabled(object)						                ( __usart_getRoute(object) & usart_getTxPinEnableMask() )
#define usart_getTxPinEnableValue()					                ( __usart_getPropertyValue(1, 1) )
// 1 TXPEN ------------- DO RETURN ----------------------
#define usart_enableTxPin(object)					                do{ USART_raiseBits(__usart_getRoute(object), usart_getTxPinEnableValue());	}while(0)
#define usart_enableUsart1TxPin()					           		do{ usart_enableTxPin(usart_usart1);										}while(0)

// 0 RXPEN ------------- DO RETURN -------------------------------------------------------------------------
#define usart_getRxPinEnableMask()					                ( USART_getBitMask(0, 0) )
#define isRxPinEnabled(object)						                ( __usart_getRoute(object) & usart_getRxPinEnableMask() )
#define usart_getRxPinEnableValue()					                ( __usart_getPropertyValue(1, 0) )
// 0 RXPEN ------------- DO RETURN ----------------------
#define usart_enableRxPin(object)									do{ USART_raiseBits(__usart_getRoute(object), usart_getRxPinEnableValue());	}while(0)
#define usart_enableUsart1RxPin()									do{ usart_enableRxPin(usart_usart1); 										}while(0)
//============================================ END ROUTE ============================================





	// RXDATA_RXDATA
#define usart_getRxDataMask()
#define usart_getRxData(object)						( __usart_getRxData(object) )
#define usart_getUart1RxData()						( usart_getRxData(usart_uart1) )
#define usart_getUart1RxData()						( usart_getRxData(usart_uart1) )
#define usart_getUsart1RxData()						( usart_getRxData(usart_usart1) )
	// RXDATA_RXDOUBLE
#define usart_getRxFifo(object)						( __usart_getRxFifo(object) )

	// TXDATA
#define usart_getTxData(object)						( __usart_getTxData(object) )
#define usart_getUart1TxData()						( usart_getTxData(usart_uart1) )
#define usart_getUsart1TxData()						( usart_getTxData(usart_usart1) )

	// IF
#define usart_getRxDataAvailableMask()				( USART_getBitMask(2, 2) )
#define usart_isRxDataAvailableInterruptFlagRaised(object)	( __usart_getInterruptFlag(object) & usart_getRxDataAvailableMask() )

	// ROUTE_LOCATION
#define usart_getLocationMask()						( USART_getBitMask(10, 8) )
#define usart_getLocation(object)					( __usart_getRoute(object) & usart_getLocationMask() )
#define usart_getLocation0Value()					( __usart_getPropertyValue(0, 8) )
#define usart_getLocation1Value()					( __usart_getPropertyValue(1, 8) )
#define usart_getLocation2Value()					( __usart_getPropertyValue(2, 8) )
#define usart_getLocation3Value()					( __usart_getPropertyValue(3, 8) )
#define usart_getLocation4Value()					( __usart_getPropertyValue(4, 8) )
#define usart_getLocation5Value()					( __usart_getPropertyValue(5, 8) )
	// ROUTE_CLKPEN
#define usart_getClockPinEnableMask()				( USART_getBitMask(3, 3) )
#define isClockPinEnabled(object)					( __usart_getRoute(object) & usart_getClockPinEnableMask() )
#define usart_getClockPinEnableValue()				( __usart_getPropertyValue(1, 3) )
	// ROUTE_CSPEN
#define usart_getChipSelectPinEnableMask()			( USART_getBitMask(2, 2) )
#define isChipSelectPinEnabled(object)				( __usart_getRoute(object) & usart_getChipSelectPinEnableMask() )
#define usart_getChipSelectPinEnableValue()			( __usart_getPropertyValue(1, 2) )
	// ROUTE_TXPEN
#define usart_getTxPinEnableMask()					( USART_getBitMask(1, 1) )
#define isTxPinEnabled(object)						( __usart_getRoute(object) & usart_getTxPinEnableMask() )
#define usart_getTxPinEnableValue()					( __usart_getPropertyValue(1, 1) )
	// ROUTE_RXPEN
#define usart_getRxPinEnableMask()					( USART_getBitMask(0, 0) )
#define isRxPinEnabled(object)						( __usart_getRoute(object) & usart_getRxPinEnableMask() )

//-- object address


 /**********************************************************************************************************************
 * Public function-like macros that DO NOT return value
 **********************************************************************************************************************/


	// TXDATA_TXDATA
#define usart_loadTxData(object, value)						do{ __usart_setTxData(object, value ); 									}while(0)
#define usart_loadUsart1TxData(value)						do{ usart_loadTxData(usart_usart1, value); 									}while(0)


	// TXDATA_TXDOUBLE
#define usart_laodTxDoubleData(object, value)				do{ __usart_setTxDoubleData(object, value ); 							} while(0)

	// IF






#define usart_init()			do{\
									usart_eanbleMaster(usart_uart1); 							\
									usart_enableTransmitter(usart_uart1);						\
									usart_enableReceiver(usart_uart1);							\
									usart_setFractionalClockDivider(usart_uart1, 23104); 		\
									usart_setLocation2(usart_uart1);							\
									usart_enableTxPin(usart_uart1);								\
									usart_enableRxPin(usart_uart1);								\
								}while(0) /*7Mhz HPERCLK, OVS-16, BAUD-9600, PARITY-NONE, STOP_BIT-1 */
/**********************************************************************************************************************
 * Public function declarations(extern)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public Objects declaration
 **********************************************************************************************************************/
extern usart_SelfData usart_uart0, usart_uart1, usart_usart0, usart_usart1, usart_usart2;


#endif// __USART_DERIVATIVE_INTERFCE__
/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/

//============================================ REGISTER NAME ============================================
// # XX ------------- DO RETURN -------------------------------------------------------------------------
// # XX ------------- DO RETURN ----------------------
//============================================ END REGISTER NAME ============================================
/*
 * DEFAULTS
 * Parity none
 * Databits 8
 * Stop bits 1
 *
 */
