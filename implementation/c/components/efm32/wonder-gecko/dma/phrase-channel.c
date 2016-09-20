
/**********************************************************************************************************************
* C Source File: phrase-channel.c
* Component: DMA
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
/*
void phrase_channel_init(void)
{
//-- Initialize descriptor
}

bool phrase_channel_dispatchEvents(void)
{
//-- locals
	uint8_t c;
//-- analyze events
	if( PHRASE_CHANNEL_isChannelDone() ) goto phrase_channel_onChannelDone;
	return false;
//-- handle events
	phrase_channel_onChannelDone:
	{
		PHRASE_CHANNEL_clearChannelInterruptFlag();
	}
	goto phrase_channel_toAnalyseChar;
//-- analyze received character
	phrase_channel_toAnalyseChar:
	{
		c = PHRASE_CHANNEL_getReceivedByte();
		switch( c )
		{
			case 10:
				goto phrase_channel_onEndOfFrame;
		}
	}
	goto phrase_channel_toCheckBuffer;
//-- Check Buffer
	phrase_channel_toCheckBuffer:
	{
		if( PHRASE_CHANNEL_getPointer() >= PHRASE_CHANNEL_getBufferLimit() ) goto phrase_channel_onBufferOverflow;
	}
	goto phrase_channel_toContinue;
//-- Check Buffer
	phrase_channel_toContinue:
	{

	}
	return true;
//-- handle events
//--
	phrase_channel_onEndOfFrame:
	{
		PHRASE_CHANNEL_onEndOfFrame();
	}
	return true;
//--
	phrase_channel_onBufferOverflow:
	{
		PHRASE_CHANNEL_onBufferOverflow();
	}
	return true;
}
*/
/**********************************************************************************************************************
* End of File
***********************************************************************************************************************/
