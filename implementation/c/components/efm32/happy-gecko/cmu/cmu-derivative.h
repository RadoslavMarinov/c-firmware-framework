/***********************************************************************************************************************
* C Header: cmu-derivative.h
* Component: Clock Management Unit
*=====================================================================================================================
* C Software Construction Framework v1-1-03.16
* © 2016 ADD-Bulgaria Ltd.
**********************************************************************************************************************/

/**********************************************************************************************************************
* Include guard
**********************************************************************************************************************/
#ifndef __CMU_DERIVATIVE_INTERFCE__
#define __CMU_DERIVATIVE_INTERFCE__


/**********************************************************************************************************************
* Dependency check
**********************************************************************************************************************/
// #ifndef
// 	#error Missing required
// #endif

/**********************************************************************************************************************
* Include the derivative headers of the INTERNAL (owned) classes
**********************************************************************************************************************/
//#include "xxx-yyy-derivative.h"

/**********************************************************************************************************************
* Private typedefs (__xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private object-like macros   (__xxx)
**********************************************************************************************************************/

// Level 0 register oriented
#define __cmu_getControl()											( cmu_selfData.control )
#define __cmu_getHighFrequencyCoreClockDivision()                   ( cmu_selfData.highFrequencyCoreClockDivision )
#define __cmu_getHighFrequencyPeripheralClockDivision()             ( cmu_selfData.highFrequencyPeripheralClockDivision )
#define __cmu_getHfrcoControl()                                     ( cmu_selfData.hfrcoControl )
#define __cmu_getLfrcoControl()                                     ( cmu_selfData.lfrcoControl )
#define __cmu_getAuxhfrcoControl()                                  ( cmu_selfData.auxhfrcoControl )
#define __cmu_getCalibrationControl()                               ( cmu_selfData.calibrationControl )
#define __cmu_getCalibrationCounter()                               ( cmu_selfData.calibrationCounter )
#define __cmu_getLowFrequencyClockSelect()                          ( cmu_selfData.lowFrequencyClockSelect )
#define __cmu_getStatus()                                           ( cmu_selfData.status )
#define __cmu_getInterruptFlag()                                    ( cmu_selfData.interruptFlag )
#define __cmu_getInterruptEnable()                                  ( cmu_selfData.interruptEnable )
#define __cmu_getHighFrequencyCoreClockEnable0()                    ( cmu_selfData.highFrequencyCoreClockEnable0 )
#define __cmu_getHighFrequencyPeripheralClockEnable0()              ( cmu_selfData.highFrequencyPeripheralClockEnable0 )
#define __cmu_getSynchronizationBusy()                              ( cmu_selfData.synchronizationBusy )
#define __cmu_getFreeze()                                           ( cmu_selfData.freeze )
#define __cmu_getLowFrequencyAClockEnable0()                        ( cmu_selfData.lowFrequencyAClockEnable0 )
#define __cmu_getLowFrequencyBClockEnable0()                        ( cmu_selfData.lowFrequencyBClockEnable0 )
#define __cmu_getLowFrequencyCClockEnable0()                        ( cmu_selfData.lowFrequencyCClockEnable0 )
#define __cmu_getLowFrequencyAPrescaler0()                          ( cmu_selfData.lowFrequencyAPrescaler0 )
#define __cmu_getLowFrequencyBPrescaler0()                          ( cmu_selfData.lowFrequencyBPrescaler0 )
#define __cmu_getPcntControl()                                      ( cmu_selfData.pcntControl )
#define __cmu_getIoRouting()                                        ( cmu_selfData.ioRouting )
#define __cmu_getConfigurationLock()                                ( cmu_selfData.configurationLock )
#define __cmu_getUsbClockRecoveryControl()                          ( cmu_selfData.usbClockRecoveryControl )
#define __cmu_getUshfrcoControl()                                   ( cmu_selfData.ushfrcoControl )
#define __cmu_getUshfrcoFrequencyTune()                             ( cmu_selfData.ushfrcoFrequencyTune )
#define __cmu_getUshfrcoConfiguration()                             ( cmu_selfData.ushfrcoConfiguration )

// -------------------   Level 2 property oriented  -------------------  //

// 0x08 High Frequency Peripheral Clock Division Register
#define __cmu_getMaskHighFrequencyPeripheralClockEnable()			( __cmu_getBitMask( 8, 8 ) )
#define __cmu_getValueHighFrequencyPeripheralClockEnable()			( __cmu_getPropertyValue( 1, 8 ) )

//0x44 High Frequency Peripheral Clock Enable Register 0
#define __cmu_getMaskTimer0HighFrequencyClockEnable()							( __cmu_getBitMask( 0, 0 ) )
#define __cmu_getValueTimer0HighFrequencyClockEnable()                          ( __cmu_getPropertyValue( 1, 0 ) )

#define __cmu_getMaskTimer1HighFrequencyClockEnable()							( __cmu_getBitMask( 1, 1 ) )
#define __cmu_getValueTimer1HighFrequencyClockEnable()                          ( __cmu_getPropertyValue( 1, 1) )

#define __cmu_getMaskTimer2HighFrequencyClockEnable()                          	( __cmu_getBitMask( 2, 2 ) )
#define __cmu_getValueTimer2HighFrequencyClockEnable()                          ( __cmu_getPropertyValue( 1, 2 ) )

#define __cmu_getMaskUsart0HighFrequencyClockEnable()                          	( __cmu_getBitMask( 3, 3 ) )
#define __cmu_getValueUsart0HighFrequencyClockEnable()                          ( __cmu_getPropertyValue( 1, 3 ) )

#define __cmu_getMaskUsart1HighFrequencyClockEnable()                    		( __cmu_getBitMask( 4, 4 ) )
#define __cmu_getValueUsart1HighFrequencyClockEnable()                          ( __cmu_getPropertyValue( 1, 4 ) )

#define __cmu_getMaskAnalogComparator0HighFrequencyClockEnable()               	( __cmu_getBitMask( 5, 5 ) )
#define __cmu_getValueAnalogComparator0HighFrequencyClockEnable()               ( __cmu_getPropertyValue( 1, 5 ) )

#define __cmu_getMaskPeripheralReflexSystemHighFrequencyClockEnable()          	( __cmu_getBitMask( 6, 6 ) )
#define __cmu_getValuePeripheralReflexSystemHighFrequencyClockEnable()         	( __cmu_getPropertyValue( 1, 6 ) )

#define __cmu_getMaskCurrentDacHighFrequencyClockEnable()   					( __cmu_getBitMask( 7, 7 ) )
#define __cmu_getValueCurrentDacHighFrequencyClockEnable()   					( __cmu_getPropertyValue( 1, 7 ) )

#define __cmu_getMaskGpioHighFrequencyClockEnable()                      		( __cmu_getBitMask( 8, 8 ) )
#define __cmu_getValueGpioHighFrequencyClockEnable()                        	( __cmu_getPropertyValue( 1, 8 ) )

#define __cmu_getMaskVoltageComparatorHighFrequencyClockEnable()         		( __cmu_getBitMask( 9, 9 ) )
#define __cmu_getValueVoltageComparatorHighFrequencyClockEnable()               ( __cmu_getPropertyValue( 1, 9 ) )

#define __cmu_getMaskAdc0HighFrequencyClockEnable()  							( __cmu_getBitMask( 10, 10 ) )
#define __cmu_getValueAdc0HighFrequencyClockEnable()         					( __cmu_getPropertyValue( 1, 10 ) )

#define __cmu_getMaskI2c0HighFrequencyClockEnable()								( __cmu_getBitMask( 11, 11 ) )
#define __cmu_getValueI2c0HighFrequencyClockEnable()                     		( __cmu_getPropertyValue( 1, 11 ) )



/**********************************************************************************************************************
* Private function-like macros that DO return value  (__xxx)
**********************************************************************************************************************/
// Level 0 register oriented
#define __cmu_setControl(value)										do{ cmu_selfData.control = (value);											}while(0)
#define __cmu_setHighFrequencyCoreClockDivision(value)              do{ cmu_selfData.highFrequencyCoreClockDivision = (value); 					}while(0)
#define __cmu_setHighFrequencyPeripheralClockDivision(value)        do{ cmu_selfData.highFrequencyPeripheralClockDivision = (value); 			}while(0)
#define __cmu_setHfrcoControl(value)                                do{ cmu_selfData.hfrcoControl = (value);									}while(0)
#define __cmu_setLfrcoControl(value)                                do{ cmu_selfData.lfrcoControl = (value);									}while(0)
#define __cmu_setAuxhfrcoControl(value)                             do{ cmu_selfData.auxhfrcoControl = (value); 								}while(0)
#define __cmu_setCalibrationControl(value)                          do{ cmu_selfData.calibrationControl = (value); 								}while(0)
#define __cmu_setCalibrationCounter(value)                          do{ cmu_selfData.calibrationCounter = (value);								}while(0)
#define __cmu_setEnableDisableOscillator(value)                     do{ cmu_selfData.enableDisableOscillator = (value); 						}while(0)
#define __cmu_setCommand(value)                                     do{ cmu_selfData.command = (value);											}while(0)
#define __cmu_setLowFrequencyClockSelect(value)                     do{ cmu_selfData.lowFrequencyClockSelect = (value); 						}while(0)
#define __cmu_setInterruptFlagSet(value)                            do{ cmu_selfData.interruptFlagSet = (value);								}while(0)
#define __cmu_setInterruptFlagClear(value)                          do{ cmu_selfData.interruptFlagClear = (value); 								}while(0)
#define __cmu_setInterruptEnable(value)                             do{ cmu_selfData.interruptEnable = (value); 								}while(0)
#define __cmu_setHighFrequencyCoreClockEnable0(value)               do{ cmu_selfData.highFrequencyCoreClockEnable0 = (value);					}while(0)
#define __cmu_setHighFrequencyPeripheralClockEnable0(value)         do{ cmu_selfData.highFrequencyPeripheralClockEnable0 = (value);			 	}while(0)
#define __cmu_setFreeze(value)                                      do{ cmu_selfData.freeze = (value); 											}while(0)
#define __cmu_setLowFrequencyAClockEnable0(value)                   do{ cmu_selfData.lowFrequencyAClockEnable0 = (value);						}while(0)
#define __cmu_setLowFrequencyBClockEnable0(value)                   do{ cmu_selfData.lowFrequencyBClockEnable0 = (value); 						}while(0)
#define __cmu_setLowFrequencyCClockEnable0(value)                   do{ cmu_selfData.lowFrequencyCClockEnable0 = (value); 						}while(0)
#define __cmu_setLowFrequencyAPrescaler0(value)                     do{ cmu_selfData.lowFrequencyAPrescaler0 = (value);							}while(0)
#define __cmu_setLowFrequencyBPrescaler0(value)                     do{ cmu_selfData.lowFrequencyBPrescaler0 = (value); 						}while(0)
#define __cmu_setPcntControl(value)                                 do{ cmu_selfData.pcntControl = (value);										}while(0)
#define __cmu_setIoRouting(value)                                   do{ cmu_selfData.ioRouting = (value); 										}while(0)
#define __cmu_setConfigurationLock(value)                           do{ cmu_selfData.configurationLock = (value);								}while(0)
#define __cmu_setUsbClockRecoveryControl(value)                     do{ cmu_selfData.usbClockRecoveryControl = (value); 						}while(0)
#define __cmu_setUshfrcoControl(value)                              do{ cmu_selfData.ushfrcoControl = (value); 									}while(0)
#define __cmu_setUshfrcoFrequencyTune(value)                        do{ cmu_selfData.ushfrcoFrequencyTune = (value);							}while(0)
#define __cmu_setUshfrcoConfiguration(value)                        do{ cmu_selfData.ushfrcoConfiguration = (value); 							}while(0)



/**********************************************************************************************************************
* Private function-like macros that DO NOT return value (__xxx)
**********************************************************************************************************************/


/**********************************************************************************************************************
* Public typedefs  (xxx)
**********************************************************************************************************************/
typedef struct
{
	volatile uint32_t control;
	volatile uint32_t highFrequencyCoreClockDivision;
	volatile uint32_t highFrequencyPeripheralClockDivision;
	volatile uint32_t hfrcoControl;
	volatile uint32_t lfrcoControl;
	volatile uint32_t auxhfrcoControl;
	volatile uint32_t calibrationControl;
	volatile uint32_t calibrationCounter;
	volatile uint32_t enableDisableOscillator;
	volatile uint32_t command;
	volatile uint32_t lowFrequencyClockSelect;
	volatile uint32_t status;
	volatile uint32_t interruptFlag;
	volatile uint32_t interruptFlagSet;
	volatile uint32_t interruptFlagClear;
	volatile uint32_t interruptEnable;
	volatile uint32_t highFrequencyCoreClockEnable0;
	volatile uint32_t highFrequencyPeripheralClockEnable0;
	uint32_t padding0[2];
	volatile uint32_t synchronizationBusy;
	volatile uint32_t freeze;
	volatile uint32_t lowFrequencyAClockEnable0;
	uint32_t padding1[1];
	volatile uint32_t lowFrequencyBClockEnable0;
	volatile uint32_t lowFrequencyCClockEnable0;
	volatile uint32_t lowFrequencyAPrescaler0;
	uint32_t padding2[1];
	volatile uint32_t lowFrequencyBPrescaler0;
	uint32_t padding3[1];
	volatile uint32_t pcntControl;
	uint32_t padding4[1];
	volatile uint32_t ioRouting;
	volatile uint32_t configurationLock;
	uint32_t padding5[18];
	volatile uint32_t usbClockRecoveryControl;
	volatile uint32_t ushfrcoControl;
	volatile uint32_t ushfrcoFrequencyTune;
	volatile uint32_t ushfrcoConfiguration;
}cmu_SelfData;
/**********************************************************************************************************************
* Public object-like macros  (xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO return value (xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO NOT return value (xxx)
**********************************************************************************************************************/
// Lecel 1 Property oriented. The property's register can be obtained from the right side of the macro.


// 0x08 High Frequency Peripheral Clock Division Register
#define cmu_enableHighFrequencyPeripheralClock()					do{ __cmu_setProperty( \
																		__cmu_getHighFrequencyPeripheralClockDivision(), \
																		__cmu_getMaskHighFrequencyPeripheralClockEnable(), \
																		__cmu_getValueHighFrequencyPeripheralClockEnable() );\
																	}while(0)

#define cmu_disableHighFrequencyPeripheralClock()					do{ __cmu_setProperty( \
																		__cmu_getHighFrequencyPeripheralClockDivision(), \
																		__cmu_getMaskHighFrequencyPeripheralClockEnable(), \
																		0 );\
																	}while(0)


// 0x44 High Frequency Peripheral Clock Enable Register 0
#define cmu_enableGpioHighFrequencyPeripheralClock()				do{ \
																		__cmu_setProperty( \
																			__cmu_getHighFrequencyPeripheralClockEnable0(), \
																			__cmu_getMaskGpioHighFrequencyClockEnable(),\
																			__cmu_getValueGpioHighFrequencyClockEnable() );\
																	}while(0)

/**********************************************************************************************************************
* Public function declarations(extern)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public Objects declaration
**********************************************************************************************************************/
	extern cmu_SelfData cmu_selfData;


#endif //__CMU_DERIVATIVE_INTERFCE__
/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/
