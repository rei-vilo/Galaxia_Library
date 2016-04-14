# Galaxia Library
Galaxy Library with RTOS elements for Energia MT

*Why the Galaxia name? With LaunchPad, BoosterPack and Energia, let's stay in space and explore new galaxies!*

### Content

The Galaxia Library encapsulates RTOS elements as objects for an easier use. 

It runs on the boards supported by Energia MT: LaunchPad MSP432, LaunchPad CC3200 and RedBearLab CC3200-based boards. 

The library comes with an umbrella header `Galaxia.h` for an easier `#include`.

> `#include "Galaxia.h"`

Because SWI has been removed from RTOS for Energia MT 0101E0017, **SWI** And **SWITrigger** are no longer operational.

Make sure to select the variant of the board with `EMT`.

* Threads elements
	* HWI
	* SWI (1)
	* SWI with trigger (SWItrigger) (1)
	* Task

* Synchronisation elements
	* Event
	* Semaphore
	* Mailbox (2)
	* Timer (3)
	* Clock 
	
Notes

1.	SWI has been removed from RTOS for Energia MT 0101E0017
2.	Mailbox supersedes Queue
3. 	Clock recommended over Timer
 

### Reference 

* [Exploring RTOS with Galaxia on Energia MT](http://embeddedcomputing.weebly.com/exploring-rtos-with-galaxia.html)
* [TI-RTOS: Real-Time Operating System (RTOS)](http://www.ti.com/tool/ti-rtos)

### Installation

Place the Galaxia folder on the `Libraries` folder of the sketchbook.

### Licence

Creative Commons [Attribution-NonCommercial-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-nc-sa/4.0/)
