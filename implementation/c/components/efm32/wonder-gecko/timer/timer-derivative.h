/***********************************************************************************************************************
 * C Header: timer-derivative.h
 * Component:
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __TIMER_DERIVATIVE_INTERFCE__
#define __TIMER_DERIVATIVE_INTERFCE__


 /**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/
//#ifndef
//	#error Missing required
//#endif

 /**********************************************************************************************************************
 * Private typedefs
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private object-like macros
 **********************************************************************************************************************/



 /**********************************************************************************************************************
 * Private function-like macros that DO return value
 **********************************************************************************************************************/

#define __timer_getControl(object)				( object.control )
#define __timer_getCommand(object)				( object.command )
#define __timer_getStatus(object)				( object.status )
#define __timer_getInterruptEnable(object)		( object.interruptEnable)
#define __timer_getInterruptFlag(object)		( object.interruptFlag )
#define __timer_getInterruptFlagClear(object)	( object.interruptFlagClear )
#define __timer_getConter(object)				( object.counterValueRegister )

 /**********************************************************************************************************************
 * Private function-like macros that DO NOT return value
 **********************************************************************************************************************/

#define __timer_setControl(object, mask, value)				do{ __timer_setProperty(object.control, mask, value); }while(0)
#define __timer_setCommand(object, mask, value)				do{ __timer_setProperty(object.command, mask, value); }while(0)

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
	volatile uint32_t command;
	volatile uint32_t status;
	volatile uint32_t interruptEnable;
	volatile uint32_t interruptFlag;
	volatile uint32_t interruptFlagSet;
	volatile uint32_t interruptFlagClear;
	volatile uint32_t counterTopValue;
	volatile uint32_t counterTopValueBuffer;
	volatile uint32_t counterValueRegister;
	volatile uint32_t ioRouting;
	volatile uint32_t reserved0[1];
	volatile uint32_t ccChannel0Control;
	volatile uint32_t ccChannel0Value;
	volatile uint32_t ccChannel0ValuePeek;
	volatile uint32_t ccChannel0Buffer;
	volatile uint32_t ccChannel1Control;
	volatile uint32_t ccChannel1Value;
	volatile uint32_t ccChannel1ValuePeek;
	volatile uint32_t ccChannel1Buffer;
	volatile uint32_t ccChannel2Control;
	volatile uint32_t ccChannel2Value;
	volatile uint32_t ccChannel2ValuePeek;
	volatile uint32_t ccChannel2Buffer;
	volatile uint32_t reserved1[4];
	volatile uint32_t DtiControl;
	volatile uint32_t DtiTimeContro;
	volatile uint32_t DtiFaultConfiguration;
	volatile uint32_t DtiOutputGenerationEnable;
	volatile uint32_t DtiFault;
	volatile uint32_t DtiFaultClear;
	volatile uint32_t DtiConfigurationLock;
}timer_SelfData;

 /**********************************************************************************************************************
 * Public object-like macros
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public function-like macros that DO return value
 **********************************************************************************************************************/

	//CTRL_PRESC
#define timer_getPrescalerMask()					( TIMER_getBitMask(27, 24) )
#define timer_getPrescaler(object)					( __timer_getControl(object) & timer_getPrescalerMask() )
#define timer_getPrescalerDivideBy1Value()			( __timer_getPropertyValue(0, 24) )
#define timer_getPrescalerDivideBy2Value()			( __timer_getPropertyValue(1, 24) )
#define timer_getPrescalerDivideBy4Value()			( __timer_getPropertyValue(2, 24) )
#define timer_getPrescalerDivideBy8Value()			( __timer_getPropertyValue(3, 24) )
#define timer_getPrescalerDivideBy16Value()			( __timer_getPropertyValue(4, 24) )
#define timer_getPrescalerDivideBy32Value()			( __timer_getPropertyValue(5, 24) )
#define timer_getPrescalerDivideBy64Value()			( __timer_getPropertyValue(6, 24) )
#define timer_getPrescalerDivideBy128Value()		( __timer_getPropertyValue(7, 24) )
#define timer_getPrescalerDivideBy256Value()		( __timer_getPropertyValue(8, 24) )
#define timer_getPrescalerDivideBy512Value()		( __timer_getPropertyValue(9, 24) )
#define timer_getPrescalerDivideBy1024Value()		( __timer_getPropertyValue(10, 24) )

	// CMD_START
#define timer_getTimerStartMask()						( TIMER_getBitMask(0, 0) )
#define timer_getStartTimer(object)						( __timer_getCommand(object) )
#define timer_getTimerStartValue()						( __timer_getPropertyValue(1, 0) )
	// CMD_STOP
#define timer_getTimerStopMask()                       	( TIMER_getBitMask(1, 1) )
#define timer_getStopTimer(object)                  	( __timer_getCommand(object) )
#define timer_getTimerStopValue()        				( __timer_getPropertyValue(1, 1) )
	//STATUS_RUNNING
#define timer_getRunningMask()							( TIMER_getBitMask(0, 0) )
#define timer_isRunning(object) 						( __timer_getStatus(object) & timer_getRunningMask() )
	// IEN_OF
#define timer_getOverflowInterruptEnableValue()			( timer_getPropertyValue(1, 0) )
#define timer_getOverflowInterruptEnableMask()			( TIMER_getBitMask(0, 0) )
#define timer_isOverflowInterruptEnabled(object)		( __timer_getInterruptEnable(object) & timer_getOverflowInterruptEnableMas() )
	// IF_OF
#define timer_getOverflowInterruptFlagMask()			( TIMER_getBitMask(0, 0) )
#define timer_isOverflowFlagRaised(object)				( __timer_getInterruptFlag(object) & timer_getOverflowInterruptFlagMask() )
	// IFC_OV
#define timer_getOverflowInterruptFlagClearMask()		( TIMER_getBitMask(0, 0) )
	// CNT_CNT
#define timer_getCounterMask()							( TIMER_getBitMask(15, 0) )
#define timer_getCounter(object)						(__timer_getConter(object) & timer_getCounterMask())


 /**********************************************************************************************************************
 * Public function-like macros that DO NOT return value
 **********************************************************************************************************************/

	//CTRL_PRESC
#define timer_setPrescalerDivideBy1Value(object)               do{ __timer_setControl( object, timer_getPrescalerMask(), timer_getPrescalerDivideBy1Value() );		} while(0)
#define timer_setPrescalerDivideBy2Value(object)               do{ __timer_setControl( object, timer_getPrescalerMask(), timer_getPrescalerDivideBy2Value() );      } while(0)
#define timer_setPrescalerDivideBy4Value(object)               do{ __timer_setControl( object, timer_getPrescalerMask(), timer_getPrescalerDivideBy4Value() );      } while(0)
#define timer_setPrescalerDivideBy8Value(object)               do{ __timer_setControl( object, timer_getPrescalerMask(), timer_getPrescalerDivideBy8Value() );      } while(0)
#define timer_setPrescalerDivideBy16Value(object)              do{ __timer_setControl( object, timer_getPrescalerMask(), timer_getPrescalerDivideBy16Value() );     } while(0)
#define timer_setPrescalerDivideBy32Value(object)              do{ __timer_setControl( object, timer_getPrescalerMask(), timer_getPrescalerDivideBy32Value() );     } while(0)
#define timer_setPrescalerDivideBy64Value(object)              do{ __timer_setControl( object, timer_getPrescalerMask(), timer_getPrescalerDivideBy64Value() );     } while(0)
#define timer_setPrescalerDivideBy128Value(object)             do{ __timer_setControl( object, timer_getPrescalerMask(), timer_getPrescalerDivideBy128Value() );    } while(0)
#define timer_setPrescalerDivideBy256Value(object)             do{ __timer_setControl( object, timer_getPrescalerMask(), timer_getPrescalerDivideBy256Value() );    } while(0)
#define timer_setPrescalerDivideBy512Value(object)             do{ __timer_setControl( object, timer_getPrescalerMask(), timer_getPrescalerDivideBy512Value() );    } while(0)
#define timer_setPrescalerDivideBy1024Value(object)            do{ __timer_setControl( object, timer_getPrescalerMask(), timer_getPrescalerDivideBy1024Value() );   } while(0)

	// CMD_START (W1)
#define timer_startTimer(object)								do{ object.command = timer_getTimerStartValue(); 				} while(0)
	// CMD_STOP (W1)
#define timer_stopTimer(object)									do{ object.command = timer_getTimerStopValue();					} while(0)
	//IEN_OF
#define timer_enableOverflowInterrupt(object)					do{ TIMER_raiseBits(__timer_getInterruptEnable(object), timer_getOverflowInterruptEnableMask()); 	} while(0)
#define timer_disableOverflowInterrupt(object)					do{ TIMER_clearBits(__timer_getInterruptEnable(object), timer_getOverflowInterruptEnableMask()); 	} while(0)
	// IFC_OV
#define timer_clearOverflowInterruptFlag(object)				do{ TIMER_assertBits( __timer_getInterruptFlagClear(object), timer_getOverflowInterruptFlagClearMask()); }while(0)




#define timer_init()											do{ timer_setPrescalerDivideBy16Value(timer_timer0);\
																	timer_startTimer(timer_timer0);\
																	timer_clearOverflowInterruptFlag(timer_timer0);\
																} while(0)

 /**********************************************************************************************************************
#define timer_disableOverflowInterrupt(object)
 * Public function declarations(extern)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public Objects declaration
 **********************************************************************************************************************/
extern timer_SelfData timer_timer0, timer_timer1, timer_timer2, timer_timer3;


#endif //__TIMER_DERIVATIVE_INTERFCE__
/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/
