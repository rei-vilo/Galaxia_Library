///
/// @file		rtosGlobals.h
/// @brief		Global variables for Energia MT project
///
/// @details	Example of Events for Hackster.io
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		ReiVilo
/// @author		ReiVilo
/// @date		09/04/2016 11:47
/// @version	101
///
/// @copyright	(c) ReiVilo, 2016
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
/// @n
///


// Core library
#include "Energia.h"

#ifndef rtosGlobals_h
#define rtosGlobals_h

// Include application, user and local libraries
#include "Event.h"
#include "Semaphore.h"

///
/// @brief	myEvent
///
Event myEvent1;
Event myEvent2;

///
/// @brief	mySemaphore
///
Semaphore mySemaphore;


///
/// @brief	Convert binary value into string
/// @param	value binary value
/// @param	positions number of positions, default=4
/// @return	string
/// @note   bin2String(5, 4) = "0101"
///
String bin2String(uint8_t value, uint8_t positions = 4)
{
    String result = "";
    for (uint8_t i = 0; i < positions; i++)
    {
        result += ((value % 2) ? "1" : "0");
        value >>= 1;
    }
    return result;
}
#endif
