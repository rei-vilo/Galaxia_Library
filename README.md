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
  
### <color=red>**Warning**</color>

**The Galaxia library relies on the Energia MT implementation of RTOS. As so, some RTOS elements may work with one distribution of Energia but not antoher, and others have been removed from the last distribution of Energia MT.**

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
