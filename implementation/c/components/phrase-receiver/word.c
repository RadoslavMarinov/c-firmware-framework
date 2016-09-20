/**********************************************************************************************************************
* C Source File: word.c
* Component: Communicator
*=====================================================================================================================
* C Software Construction Framework v1-1-03.16
* © 2016 ADD-Bulgaria Ltd.
**********************************************************************************************************************/

/**********************************************************************************************************************
* Include application header
**********************************************************************************************************************/
#include "application.h"


/**********************************************************************************************************************
* Private function definitions (static)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function definitions.
**********************************************************************************************************************/


/* Input:
 *  string: allowed characters in the string: {{'0'.....'1'},{'a'......'f'}};
 *  stringLength accepts values: {1,2,3,4}.
 *
 *  The function can process bigger strings by giving stringLenght bigger value, but the type of the returned value must be appropriately changed.
 */
uint16_t word_convertStringHex2Word(const char* string, uint8_t stringLength)
{
   uint8_t i;
   uint8_t c;
   uint16_t word = 0;
   for(i=0; i < stringLength; i++)
   {
      c = string[stringLength - i - 1];
      if( c >= '0' && c <= '9' )
      {
          word |= ( (c - '0') << (i * 4) );
      }
      else if( (c >= 'a') && (c <= 'f') )
      {
          word |= ( (c - 87) << (i * 4));
      }
      else
      {
    	  WORD_onInvalidStringFormat();
      }
   }
   return word;
}



/* Input:
 *  string: allowed characters in the string: {{'0'.....'1'},{'a'......'f'}};
 *  stringLength accepts values: {1,2}.
 *
 *  The function can process bigger strings by giving stringLenght bigger value, but the type of the returned value must be appropriately changed.
 */
uint8_t word_convertStringHex2Byte(const char* string, uint8_t stringLength)
{
   uint8_t i;
   uint8_t c;
   uint8_t octet = 0;
   for(i=0; i < stringLength; i++)
   {
      c = string[stringLength - i - 1];
      if( c >= '0' && c <= '9' )
      {
    	  octet |= ( (c - '0') << (i * 4) );
      }
      else if( (c >= 'a') && (c <= 'f') )
      {
    	  octet |= ( (c - 87) << (i * 4));
      }
      else
      {
    	  WORD_onInvalidStringFormat();
      }
   }
   return octet;
}

// void xxx_yyy_init(void){}
// bool xxx_yyy_dispatchEvents(void)
//{
//-- Detect Events -------------------------------------------------------------
//-- Dispatch Events ------------------------------------------------------------
//-- Actions -------------------------------------------------------------------------------
//== Event-State handler
//== Exit Actions - some exit actions may not be triggered by "Exit" event.
//== Transition
//class_name_[evenName]fromSourceStateNameDestinationStateName:	//if from one state to another there is more than one transition then the event differentiate the identificator.
//== Departure
//}

/**********************************************************************************************************************
* End of File
***********************************************************************************************************************/
