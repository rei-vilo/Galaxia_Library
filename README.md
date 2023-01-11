# Galaxia Library
Galaxy Library with RTOS elements for Energia MT

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/aff06d9329714cb4a4af11198922a5e7)](https://www.codacy.com/gh/rei-vilo/Galaxia_Library/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=rei-vilo/Galaxia_Library&amp;utm_campaign=Badge_Grade)

*Why the Galaxia name? With LaunchPad, BoosterPack and Energia, let's stay in space and explore new galaxies!*

### Content

The Galaxia Library encapsulates RTOS elements as objects for an easier use. 

It runs on the boards supported by Energia MT: 

* No IoT: LaunchPad MSP432P401R and MSP432P4111
* sub-1 GHz: LaunchPad CC1310 and CC1312
* BLE + sub-1 GHz: LaunchPad CC1350 and CC1352, LPSTK-CC1352
* BLE: LaunchPad CC2652
* WiFi: LaunchPad CC3200, CC3220, CC3235
* Ethernet: LaunchPad MSP432E401Y

The library comes with an umbrella header `Galaxia.h` for an easier `#include`.

> `#include "Galaxia.h"`

Because SWI has been removed from RTOS for Energia MT 0101E0017, **SWI** And **SWITrigger** are no longer operational.

Make sure to select the variant of the board with `EMT`.

### Elements 

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
  
### <font color="red">Warning</font>

<font color="red">The Galaxia library relies on the Energia MT implementation of RTOS. As so, some RTOS elements may work with one distribution of Energia but not antoher. Similarly, some RTOS elements may have been removed from the last distribution of Energia MT.</font>

### Tutorials

General documentation is available at [Exploring RTOS with Galaxia on Energia MT](http://embeddedcomputing.weebly.com/exploring-rtos-with-galaxia.html).

I've posted four tutorials on Hacskter.io:

* [Multi-Tasking with Energia MT with Galaxia Library](https://www.hackster.io/rei-vilo/multi-tasking-with-energia-mt-and-galaxia-library-20bd64?ref=user&amp;ref_id=55319&amp;offset=2)
* [Manage Single Resource with Energia MT and Galaxia](https://www.hackster.io/rei-vilo/manage-single-resource-with-energia-mt-and-galaxia-cadb26?ref=user&amp;ref_id=55319&amp;offset=1)
* [Send Data Across Tasks with Energia and Galaxia](https://www.hackster.io/rei-vilo/send-data-across-tasks-with-energia-and-galaxia-8be05c?ref=user&amp;ref_id=55319&amp;offset=0)
* [Events with Energia MT and Galaxia Library](https://www.hackster.io/rei-vilo/events-with-energia-mt-and-galaxia-library-741d9b?ref=user&amp;ref_id=55319&amp;offset=0)

Feel free to click on the **Respect** button!

### Installation

Place the Galaxia folder on the `Libraries` folder of the sketchbook.

### Reference 

* [Exploring RTOS with Galaxia on Energia MT](http://embeddedcomputing.weebly.com/exploring-rtos-with-galaxia.html)
* [TI-RTOS: Real-Time Operating System (RTOS)](http://www.ti.com/tool/ti-rtos)

### Licence

![image](https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png)

This work is licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-nc-sa/4.0/).
