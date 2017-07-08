/*
 *
 *   Using the on-board LEDs
 *   Blinking Red LED every 2 secs
 *   Using Contiki Callback Timer
 *
 */

#include "project-conf.h"
#include "contiki.h"
#include "dev/leds.h"
#include <stdlib.h>

void toggle();

PROCESS(blink, "blinking leds");
AUTOSTART_PROCESSES(&blink);


/*---------------------------------------------------------------------------*/
PROCESS_THREAD(blink, ev, data)
{
 s

 PROCESS_BEGIN();
 
    
 while (1){
	//Wait here for an event to happen
	PROCESS_WAIT_EVENT();	
	// and loop
	}
 PROCESS_END();
}

void toggle() {
  
}
