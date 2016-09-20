





__receiver_stComplete, 						0
__receiver_stSpace,							1
__receiver_stName,							2
__receiver_stNameDelimiter,					3	
__receiver_stValue,							4
__receiver_stValueDelimiter,  				5	

__communicator_evNone,						0				
__communicator_evTransmitterIdle,			1
__communicator_evReceiverRead,				2
__communicator_evReceiverWrite,				3
__communicator_evReceiverInvalid,			4
__communicator_evReceiverBufferOverflow,	5

__transmitter_eventNone,					0
__transmitter_eventTransmit,				1	
__transmitter_eventTransmissionDone,		2


////////////////////////////////////////////////////////////////////////////////
nameIndex;						//buffer name boundaries (lower)
regBottomIndex;					//registers array top boundary
regWorkingIndex;				//index of the register being processed
regTopIndex;					//registers array top boundary
regNameCharIndex;				//index of a character of register name element 

////////////////////////////////////////////////////////////////////////////////

{"channel.map.i", 0x01},	//Current Channel Mapping Configuration      
{"channel.map.u", 0x02},	//Voltage Channel Mapping Configuration      
{"freq.hi.th", 0x0A},		//High Threshold for Frequency Detection     
{"meter.en", 0x00},			//Metering Enable                            
{"o.i.th", 0xB0},			//Over Current Threshold                     
{"o.v.th", 0x06},			//Over Voltage Threshold                     
{"phase.loss.th", 0x09},	//Voltage Phase Losing Threshold             
{"sag.peak.det", 0x05},		//Sag and Peak Detector Period Configuration 
{"sag.th", 0x08},			//Voltage Sag Threshold                      
{"z.x.config", 0x07},		//Zero-Crossing Configuration              

////////////////////////////////////////////////////////////////////////////////
enum
{
	__reader_evNone,			0
	__reader_evSearch,			1
};

enum
{
	__reader_stIdle,			0
	__reader_stRowFound,		1
	__reader_stFindChar,		2
	__reader_stFindEndBorder,	3
	__reader_stFindStartBorder, 4
};  


{"channel.map.i", 0x01},		//0
{"channel.map.u", 0x02},		//1
{"freq.hi.th", 0x0A},			//2
{"meter.en", 0x00},				//3
{"o.i.th", 0xB0},				//4
{"o.v.th", 0x06},				//5
{"phase.loss.th", 0x09},		//6
{"sag.peak.det", 0x05},			//7
{"sag.th", 0x08},				//8
{"z.x.config", 0x07},			//9

|--------- 1 ---------|---------2 ---------|--------- 3 ---------|--------- 4 ---------|--------- 5 ---------|--------- 6 ---------| 
    OS, IS -> 0 c             OS -> 0 c        OS - > 0 c             OS - > 0 c                 OS - > 0 c                    0 c
              1 c                   1 c 			  1 c                    1 c                        1 c                    1 c
              2 f                   2 f        		  2 f                    2 f                        2 f                    2 f
              3 m                   3 m               3 m                    3 m                        3 m                    3 m
              4 o             IS -> 4 o               4 o                    4 o                        4 o                    4 o
              5 o                   5 o               5 o                    5 o                        5 o                    5 o
              6 p                   6 p         IS -> 6 p                    6 p                        6 p                    6 p
              7 s                   7 s               7 s             IS ->  7 s                        7 s                    7 s
              8 s                   8 s               8 s                    8 s                  IS -> 8 s                    8 s
    OE, IE -> 9 z         OE, IE -> 9 z     OE, IE -> 9 z          OE, IE -> 9 z              OE, IE -> 9 z  OE, OS, IE, IS -> 9 z

    o,p,s,s,z
    electricity_meter_application_selfData.communicator.reader.outer.end


							0
{"channel.map.i", 0x01},		//0 <-IS,OS
{"channel.map.u", 0x02},		//1                           
{"freq.hi.th", 0x0A},			//2                        
{"meter.en", 0x00},				//3                        
{"o.i.th", 0xB0},				//4                        
{"o.v.th", 0x06},				//5                                                
{"phase.loss.th", 0x09},		//6                        
{"sag.peak.det", 0x05},			//7                        
{"sag.th", 0x08},				//8                        
{"z.x.config", 0x07},			//9 <- IE,OE
							0
{"channel.map.i", 0x01},		//0 <-IS,OS
{"channel.map.u", 0x02},		//1
{"freq.hi.th", 0x0A},			//2
{"meter.en", 0x00},				//3
{"o.i.th", 0xB0},				//4 <- IE
{"o.v.th", 0x06},				//5
{"phase.loss.th", 0x09},		//6
{"sag.peak.det", 0x05},			//7
{"sag.th", 0x08},				//8
{"z.x.config", 0x07},			//9 <- OE
							0
{"channel.map.i", 0x01},		//0 <-IS,OS
{"channel.map.u", 0x02},		//1
{"freq.hi.th", 0x0A},			//2 <- IE
{"meter.en", 0x00},				//3
{"o.i.th", 0xB0},				//4
{"o.v.th", 0x06},				//5
{"phase.loss.th", 0x09},		//6
{"sag.peak.det", 0x05},			//7
{"sag.th", 0x08},				//8
{"z.x.config", 0x07},			//9 <- OE
							0
{"channel.map.i", 0x01},		//0 <-OS
{"channel.map.u", 0x02},		//1 <-IS
{"freq.hi.th", 0x0A},			//2
{"meter.en", 0x00},				//3
{"o.i.th", 0xB0},				//4
{"o.v.th", 0x06},				//5
{"phase.loss.th", 0x09},		//6
{"sag.peak.det", 0x05},			//7
{"sag.th", 0x08},				//8
{"z.x.config", 0x07},			//9 <- IE,OE
							0
{"channel.map.i", 0x01},		//0 <-OS
{"channel.map.u", 0x02},		//1 <-IS
{"freq.hi.th", 0x0A},			//2
{"meter.en", 0x00},				//3
{"o.i.th", 0xB0},				//4
{"o.v.th", 0x06},				//5 <-IE
{"phase.loss.th", 0x09},		//6
{"sag.peak.det", 0x05},			//7
{"sag.th", 0x08},				//8
{"z.x.config", 0x07},			//9 <-OE
							0
{"channel.map.i", 0x01},		//0 <-OS
{"channel.map.u", 0x02},		//1 <-IS
{"freq.hi.th", 0x0A},			//2
{"meter.en", 0x00},				//3 <-IE
{"o.i.th", 0xB0},				//4
{"o.v.th", 0x06},				//5
{"phase.loss.th", 0x09},		//6 
{"sag.peak.det", 0x05},			//7
{"sag.th", 0x08},				//8
{"z.x.config", 0x07},			//9 <-OE
							0
{"channel.map.i", 0x01},		//0 <-OS
{"channel.map.u", 0x02},		//1 <-IS
{"freq.hi.th", 0x0A},			//2 <-IE
{"meter.en", 0x00},				//3 
{"o.i.th", 0xB0},				//4
{"o.v.th", 0x06},				//5
{"phase.loss.th", 0x09},		//6 
{"sag.peak.det", 0x05},			//7
{"sag.th", 0x08},				//8
{"z.x.config", 0x07},			//9 <-OE
							0
{"channel.map.i", 0x01},		//0 <-OS
{"channel.map.u", 0x02},		//1 <-IS,IE
{"freq.hi.th", 0x0A},			//2
{"meter.en", 0x00},				//3 
{"o.i.th", 0xB0},				//4
{"o.v.th", 0x06},				//5
{"phase.loss.th", 0x09},		//6 
{"sag.peak.det", 0x05},			//7
{"sag.th", 0x08},				//8
{"z.x.config", 0x07},			//9 <-OE
							0
{"channel.map.i", 0x01},		//0 <-IS,OS
{"channel.map.u", 0x02},		//1 <-IE,OE
{"freq.hi.th", 0x0A},			//2
{"meter.en", 0x00},				//3 
{"o.i.th", 0xB0},				//4
{"o.v.th", 0x06},				//5
{"phase.loss.th", 0x09},		//6 
{"sag.peak.det", 0x05},			//7
{"sag.th", 0x08},				//8
{"z.x.config", 0x07},			//9
							0
{"channel.map.i", 0x01},		//0 <-IS,IE,OS
{"channel.map.u", 0x02},		//1 <-OE
{"freq.hi.th", 0x0A},			//2
{"meter.en", 0x00},				//3 
{"o.i.th", 0xB0},				//4
{"o.v.th", 0x06},				//5
{"phase.loss.th", 0x09},		//6 
{"sag.peak.det", 0x05},			//7
{"sag.th", 0x08},				//8
{"z.x.config", 0x07},			//9
							0
{"channel.map.i", 0x01},		//0 <-IS,IE,OS
{"channel.map.u", 0x02},		//1 <-OE
{"freq.hi.th", 0x0A},			//2
{"meter.en", 0x00},				//3 
{"o.i.th", 0xB0},				//4
{"o.v.th", 0x06},				//5
{"phase.loss.th", 0x09},		//6 
{"sag.peak.det", 0x05},			//7
{"sag.th", 0x08},				//8
{"z.x.config", 0x07},			//9
							1
{"channel.map.i", 0x01},		//0 <-IS,OS
{"channel.map.u", 0x02},		//1 <-IE,OE
{"freq.hi.th", 0x0A},			//2
{"meter.en", 0x00},				//3 
{"o.i.th", 0xB0},				//4
{"o.v.th", 0x06},				//5
{"phase.loss.th", 0x09},		//6 
{"sag.peak.det", 0x05},			//7
{"sag.th", 0x08},				//8
{"z.x.config", 0x07},			//9
							1
{"channel.map.i", 0x01},		//0 <-OS
{"channel.map.u", 0x02},		//1 <-IS,IE,OE
{"freq.hi.th", 0x0A},			//2
{"meter.en", 0x00},				//3 
{"o.i.th", 0xB0},				//4
{"o.v.th", 0x06},				//5
{"phase.loss.th", 0x09},		//6 
{"sag.peak.det", 0x05},			//7
{"sag.th", 0x08},				//8
{"z.x.config", 0x07},			//9
							1
{"channel.map.i", 0x01},		//0 <-IS,OS
{"channel.map.u", 0x02},		//1 <-IE,OE
{"freq.hi.th", 0x0A},			//2
{"meter.en", 0x00},				//3 
{"o.i.th", 0xB0},				//4
{"o.v.th", 0x06},				//5
{"phase.loss.th", 0x09},		//6 
{"sag.peak.det", 0x05},			//7
{"sag.th", 0x08},				//8
{"z.x.config", 0x07},			//9
							1
{"channel.map.i", 0x01},		//0 <-IS,IE,OS
{"channel.map.u", 0x02},		//1 <-OE
{"freq.hi.th", 0x0A},			//2
{"meter.en", 0x00},				//3 
{"o.i.th", 0xB0},				//4
{"o.v.th", 0x06},				//5
{"phase.loss.th", 0x09},		//6 
{"sag.peak.det", 0x05},			//7
{"sag.th", 0x08},				//8
{"z.x.config", 0x07},			//9




"sag.ta"



if( ( __reader_getInnerEnd() - __reader_getInnerStart()) == 1 )
{
	goto reader_toSelectEndBorder;
      
}
goto reader_toMoveInnerStart2Average;

reader_toSearchUpperHalf:
{
	if( __reader_areInnerBordersAdjacent() )
	{
		goto reader_toCheckEndChar;
	}
	goto reader_toMoveInnerStart2Average;
}
return true;









		if( __reader_getInputChar() == __reader_getGlossaryChar( __reader_getInnerStart() ) )
		{
			goto reader_toMoveInnerEnd2InnerStart;
		}
		goto reader_toMoveInnerStart2InnerEnd;







////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		enum
{
	__range_evNone,
	__range_evSelect,
	__range_evSelected,
	__range_evNotMember,
};
enum
{
	__range_stWild,
	__range_stSelectTop,
	__range_stSelectBottom,
	__range_stSelected,
	__range_stNotFound,
};


Bott - Top = 1 ->
Avr = Top
AvrCh >= TopCh   --- 
				 --- 
				 --- AvrCh = TopCh
				 --- AvrCh = BottCh
				 --- none


Char >= AvrCh -> 








debug_str_innerTop = (char*)(&communicator_slmbEMeter.reg[RANGE_selfData.inner.top].name[__reader_getColumn()]); debug_str_innerBottom = (char *) (&communicator_slmbEMeter.reg[RANGE_selfData.inner.bottom].name[__reader_getColumn()] ); debug_str_outerTop = (char*)(&communicator_slmbEMeter.reg[RANGE_selfData.outer.top].name[__reader_getColumn()]); //debug_str_outerBottom = (char *) (&communicator_slmbEMeter.reg[RANGE_selfData.outer.bottom].name[__reader_getColumn()] ); column = __reader_getColumn();

communicator_slmbEMeter.reg[RANGE_selfData.inner.top].name[__reader_getColumn()])





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


enum
{
	__top_limit_evNone,
	__top_limit_evDo,
};
enum
{
	__top_limit_stIdle,
	__top_limit_stCompareAverage,
	__top_limit_stSearchDownward,
	__top_limit_stSearchUpward,
	__top_limit_stCompareBottom,
	__top_limit_stFound,
	__top_limit_stNotFound,
	__top_limit_stFail,
};




I am struggling to understand the EFM32WG startup file. So far I have partial success, but still can't find the branch to the main function. Could some one help me to find reference or a document where the entire start-up procedure is explained? Something like this, but specifically for startup_gcc_efm32wg.s.











Entry Action
Idle top_limit_toEntryIdle
	bottom_limit_toEntryAdjacent:
	{
		__bottom_limit_setStateAdjacent();
		__bottom_limit_setEventDo();
	}
	return true;

Exit Action
Idle top_limit_toExitIdle


Do Action
state = Idle, event = Search, top_limit_toSearchIdle
	bottom_limit_toSearchIdle:
	{
		if( bottom_limit_getBottom() > __bottom_limit_getTop() )
			goto bottom_limit_toCompareAverage;
	}
	goto bottom_limit_toRejected;





0 - channel.map.i
1 - channel.map.u
2 - creq.hi.th  	c/r
3 - meter.en
4 - o.i.th
5 - o.v.th
6 - phase.loss.th
7 - sag.peak.det
8 - sag.th
9 - 


0 - channel.map.i
1 - channel.map.u
2 - creq.hi.th                          
3 - meter.en          
4 - o.i.th                 
5 - o.v.th                 
6 - phase.loss.th
7 - sag.peak.det       
8 - sag.th               
9 - s.x.config             


0 - channel.map.i
1 - channel.map.u
2 - creq.hi.th   
3 - meter.en     
4 - o.i.th       
5 - o.v.th       
6 - phase.loss.th
7 - s.x.config   
8 - sag.peak.det 
9 - sag.th       



{"channel.map.i", 0x01},
{"channel.map.u", 0x02},
{"creq.hi.th", 0x0A},	
{"meter.en", 0x00},		
{"o.i.th", 0xB0},		
{"o.v.th", 0x06},		
{"phase.loss.th", 0x09},
{"s.x.config", 0x07},	
{"sag.peak.det", 0x05},	
{"sag.th", 0x08},		



Help -> Eclipse MarketPlace -> Find: TestNG for Eclipse -> Install




#define RECEIVER_getCycleTransferCount											20
#define COMMUNICATOR_getBufferSize()											40
#define RECEIVER_getBufferSize()												( COMMUNICATOR_getBufferSize() )
#define RECEIVER_getChannelDescriptorCh0PrimaryRemainigTransferCount()     		( channel_descriptor_getCh0PrimaryRemainingTransferCount() )