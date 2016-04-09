
  Galaxia_Event
  Project
  ----------------------------------
  Developed with embedXcode

  Project Galaxia_Event
  Created by ReiVilo on 09/04/2016
  Copyright © 2016 ReiVilo
  Licence ___VARIABLE_projectLicense___



  References
  ----------------------------------

This is an example of multi-events.

Event_Id_01 2000 LED red
Event_Id_02 1000 LED green
Event_Id_03  500 LED green

- LED red is triggered by Event_Id_01
- LED green is triggered
    . by (Event_Id_02 AND Event_Id_03)
    . or (Event_Id_02 OR Event_Id_03)


* Events for Energia MT - AND

1       : myEvent1 1   (0100)
4       : myEvent1 *   (0100) red   ON
10      : myEvent2  2  (0010)
30      : myEvent2   3 (0001)
31      : myEvent2  ** (0011) green ON
2004    : myEvent1 1   (0100)
2005    : myEvent1 *   (0100) red   OFF
3031    : myEvent2   3 (0001)
4005    : myEvent1 1   (0100)
4006    : myEvent1 *   (0100) red   ON
5011    : myEvent2  2  (0010)
5012    : myEvent2  ** (0011) green OFF
6006    : myEvent1 1   (0100)
6007    : myEvent1 *   (0100) red   OFF
6032    : myEvent2   3 (0001)
8007    : myEvent1 1   (0100)
8008    : myEvent1 *   (0100) red   ON
9033    : myEvent2   3 (0001)
10008   : myEvent1 1   (0100)
10009   : myEvent1 *   (0100) red   OFF
10013   : myEvent2  2  (0010)
10015   : myEvent2  ** (0011) green ON
12009   : myEvent1 1   (0100)
12010   : myEvent1 *   (0100) red   ON
12034   : myEvent2   3 (0001)
14010   : myEvent1 1   (0100)
14011   : myEvent1 *   (0100) red   OFF
15015   : myEvent2  2  (0010)
15016   : myEvent2  ** (0011) green OFF
15035   : myEvent2   3 (0001)


* Events for Energia MT - OR

1       : myEvent1 1   (0100)
4       : myEvent1 *   (0100) red   ON
10      : myEvent2  2  (0010)
11      : myEvent2  ** (0010) green ON
30      : myEvent2   3 (0001)
31      : myEvent2  ** (0001) green OFF
2004    : myEvent1 1   (0100)
2005    : myEvent1 *   (0100) red   OFF
3031    : myEvent2   3 (0001)
3032    : myEvent2  ** (0001) green ON
4005    : myEvent1 1   (0100)
4006    : myEvent1 *   (0100) red   ON
5011    : myEvent2  2  (0010)
5012    : myEvent2  ** (0010) green OFF
6006    : myEvent1 1   (0100)
6007    : myEvent1 *   (0100) red   OFF
6032    : myEvent2   3 (0001)
6033    : myEvent2  ** (0001) green ON
8007    : myEvent1 1   (0100)
8008    : myEvent1 *   (0100) red   ON
9033    : myEvent2   3 (0001)
9034    : myEvent2  ** (0001) green OFF
10008   : myEvent1 1   (0100)
10009   : myEvent1 *   (0100) red   OFF
10013   : myEvent2  2  (0010)
10015   : myEvent2  ** (0010) green ON
12009   : myEvent1 1   (0100)
12010   : myEvent1 *   (0100) red   ON
12034   : myEvent2   3 (0001)
12035   : myEvent2  ** (0001) green OFF
14010   : myEvent1 1   (0100)
14011   : myEvent1 *   (0100) red   OFF
15015   : myEvent2  2  (0010)
15016   : myEvent2  ** (0010) green ON
15035   : myEvent2   3 (0001)
15036   : myEvent2  ** (0001) green OFF


* NOTE
Only a single Task can pend on an Event object at a time.


  embedXcode
  embedXcode+
  ----------------------------------
  Embedded Computing on Xcode
  Copyright © Rei VILO, 2010-2016
  All rights reserved
  http://embedXcode.weebly.com

