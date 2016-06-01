///
/// @file		LED1.ino
/// @brief		Task for Energia MT
/// @details	Example of Events for Hackster.io
/// @n
/// @n @b		Project EMT-event
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
///
/// @date		05/06/2015 21:20
/// @version	101
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///



// Include core, application, user and local libraries
#include "Energia.h"
#include "rtosGlobals.h"

// Define variables and constants
int value2 = 0;

// Setup
void LED2_setup()
{
    Serial.begin(115200);
    pinMode(GREEN_LED, OUTPUT);
}

// Loop
void LED2_loop()
{
    // AND
    //    uint32_t events = myEvent2.waitFor(Event_Id_02 + Event_Id_03, Event_Id_NONE);
    // OR
    uint32_t events = myEvent2.waitFor(Event_Id_NONE, Event_Id_02 + Event_Id_03);
    
    value2 = 1 - value2;
    digitalWrite(GREEN_LED, value2);
    
    mySemaphore.waitFor();
    Serial.print(millis(), DEC);
    Serial.print("\t: myEvent2  ** (");
    Serial.print(bin2String(events));
    Serial.print(") green ");
    Serial.println(value2 ? "ON" : "OFF");
    mySemaphore.post();
}

