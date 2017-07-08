/*
 *
 *   Using the on-board LEDs
 *   Blinking Red LED every 2 secs
 *   Using Contiki Event Timer
 *
 */

#include "project-conf.h"
#include "contiki.h"
#include "dev/leds.h"
#include <stdlib.h>

PROCESS(blink, "blinking leds");
AUTOSTART_PROCESSES(&blink);

PROCESS_THREAD(blink, ev, data)
{
  
  PROCESS_BEGIN();
 
  while (1)	{
	
	}

  PROCESS_END();
}
