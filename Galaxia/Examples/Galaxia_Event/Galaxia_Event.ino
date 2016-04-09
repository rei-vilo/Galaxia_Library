///
/// @mainpage	Galaxia_Event
///
/// @details	Example of Events for Hackster.io
/// @n
/// @n
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
///


///
/// @file		Galaxia_Event.ino
/// @brief		Main sketch
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


// Include core, application, user and local libraries
#include "Energia.h"
#include "rtosGlobals.h"

// Add setup code
void setup()
{
    myEvent1.begin();
    mySemaphore.begin(1);
    Serial.begin(115200);
    Serial.println();
    Serial.println("* Events for Energia MT");
}

// Add loop code
void loop()
{
    myEvent1.send(Event_Id_01);
    
    mySemaphore.waitFor();
    Serial.print(millis(), DEC);
    Serial.print("\t: myEvent1 1   (");
    Serial.print(bin2String(Event_Id_01));
    Serial.println(")");
    mySemaphore.post();
    
    delay(2000);
}
