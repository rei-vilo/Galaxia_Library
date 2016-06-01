///
/// @file		LED1.ino
/// @brief		Events for Energia MT
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
int value3 = 0;


// Setup
void LED1_setup()
{
    Serial.begin(115200);
    pinMode(RED_LED, OUTPUT);
}

// Loop
void LED1_loop()
{
    uint32_t events = myEvent1.waitFor(Event_Id_01);
    value3 = 1 - value3;
    digitalWrite(RED_LED, value3);

    mySemaphore.waitFor();
    Serial.print(millis(), DEC);
    Serial.print("\t: myEvent1 *   (");
    Serial.print(bin2String(events));
    Serial.print(") red   ");
    Serial.println(value3 ? "ON" : "OFF");
    mySemaphore.post();

}

