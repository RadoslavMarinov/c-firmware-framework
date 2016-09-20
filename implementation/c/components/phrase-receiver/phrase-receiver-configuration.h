/**********************************************************************************************************************
* C Configuration Header: phrase-receiver-configuration.h
* Component: Phrase Receiver
*=====================================================================================================================
* C Software Construction Framework v1-1-03.16
* © 2016 ADD-Bulgaria Ltd.
**********************************************************************************************************************/

/**********************************************************************************************************************
* Include guard
**********************************************************************************************************************/
#ifndef __PHRASE_RECEIVER_CONFIGURATION__
#define __PHRASE_RECEIVER_CONFIGURATION__




/**********************************************************************************************************************
* PHRASE_RECEIVER Object-like macros
**********************************************************************************************************************/
#define PHRASE_RECEIVER_PhraseSelfData								phrase_SelfData
#define PHRASE_RECEIVER_WordSelfData								word_SelfData
/**********************************************************************************************************************
* PHRASE_RECEIVER Function-like macros that DO return value
**********************************************************************************************************************/

/**********************************************************************************************************************
* PHRASE_RECEIVER Function-like macros that DO NOT return value
**********************************************************************************************************************/









/**********************************************************************************************************************
* PHRASE Object-like macros
**********************************************************************************************************************/
#define PHRASE_selfData												(PHRASE_RECEIVER_selfData.phrase)

/**********************************************************************************************************************
* PHRASE Function-like macros that DO return value
**********************************************************************************************************************/



/**********************************************************************************************************************
* PHRASE Function-like macros that DO NOT return value
**********************************************************************************************************************/
#define PHRASE_RECEIVER_initPhrase()								do{ phrase_init(); 															}while(0)

#define PHRASE_RECEIVER_setWordNameStart()							do{ word_setNameStart( phrase_receiver_getToAnalyzeNext() - 1 );			}while(0)
#define PHRASE_RECEIVER_setWordNameEnd()							do{ word_setNameEnd( phrase_receiver_getToAnalyzeNext() - 1 );				}while(0)


#define PHRASE_RECEIVER_setWordValueStart()							do{ word_setValueStart( phrase_receiver_getToAnalyzeNext() - 1 ); 			}while(0)
#define PHRASE_RECEIVER_setWordValueEnd()                           do{ word_setValueEnd( phrase_receiver_getToAnalyzeNext() - 1 );				}while(0)

#define PHRASE_RECEIVER_setPhraseCommandRead()						do{ phrase_setCommandRead(); 												}while(0)
#define PHRASE_RECEIVER_setPhraseCommandWrite()						do{ phrase_setCommandWrite(); 												}while(0)
#define PHRASE_RECEIVER_setPhraseCommandInvalid()					do{ phrase_setCommandInvalid(); 											}while(0)









/**********************************************************************************************************************
* WORD Object-like macros
**********************************************************************************************************************/

#define WORD_selfData												(PHRASE_RECEIVER_selfData.word)

/**********************************************************************************************************************
* WORD Function-like macros that DO return value
**********************************************************************************************************************/

/**********************************************************************************************************************
* WORD Function-like macros that DO NOT return value
**********************************************************************************************************************/
#define WORD_onInvalidStringFormat()								do{ ; }while(0)

#endif //__PHRASE_RECEIVER_CONFIGURATION__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
