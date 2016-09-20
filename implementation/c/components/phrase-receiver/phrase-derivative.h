/***********************************************************************************************************************
 * C Header: phrase-derivative.h
 * Component:
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __PHRASE_DERIVATIVE_INTERFCE__
#define __PHRASE_DERIVATIVE_INTERFCE__

/***********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/
// #ifndef
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
#define __phrase_getState()										( PHRASE_selfData.state  )
 /**********************************************************************************************************************
 * Private function-like macros that DO NOT return value (__xxx)
 **********************************************************************************************************************/
#define __phrase_setState( st )									do{ PHRASE_selfData.state = st; 		}while(0)
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
	PHRASE_State state;
} phrase_SelfData;

/**********************************************************************************************************************
 * Public object-like macros  (xxx)
 **********************************************************************************************************************/
#define phrase_getState()											( PHRASE_selfData.state )

#define phrase_isRead() 											( phrase_getState() == __phrase_stRead ? true : false )
#define phrase_isWrite()											( phrase_getState() == __phrase_stWrite ? true : false )

/**********************************************************************************************************************
* Public function-like macros that DO return value (xxx)
**********************************************************************************************************************/
#define __phrase_setStateInvalid()									do{ __phrase_setState( __phrase_stInvald ); 								}while(0)
#define __phrase_setStateRead()										do{ __phrase_setState( __phrase_stRead ); 									}while(0)
#define __phrase_setStateWrite()									do{ __phrase_setState( __phrase_stWrite ); 									}while(0)

#define phrase_setCommandRead()										do{ __phrase_setStateRead();													}while(0)
#define phrase_setCommandWrite()           							do{ __phrase_setStateWrite();  												}while(0)
#define phrase_setCommandInvalid()        							do{ __phrase_setStateInvalid();   											}while(0)
 /**********************************************************************************************************************
 * Public function-like macros that DO NOT return value (xxx)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public function declarations(extern)
 **********************************************************************************************************************/
extern void phrase_init(void);
#endif //__PHRASE_DERIVATIVE_INTERFCE__
/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/
