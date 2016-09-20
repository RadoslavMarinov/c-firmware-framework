


// This function can be easily adjusted to return byte, word, double word, quad word ..... or other types just by changing its arguments
// and eventually its return type. NOTE that the local variable "value" must conform the return type.
uint32_t convertStringHex2DoubleWord(const char* string, uint8_t stringLength)
{
   uint8_t i;
   uint8_t c;
   uint32_t value = 0;
   for(i=0; i < stringLength; i++)
   {
      c = string[stringLength - i - 1];
      if( c >= '0' && c <= '9' )
      {
    	  value |= ( (c - '0') << (i * 4) );
      }
      else if( (c >= 'a') && (c <= 'f') )
      {
    	  value |= ( (c - 87) << (i * 4));
      }
      else
      {
    	  ;//Throw some exception ;
      }
   }
   return value;
}

