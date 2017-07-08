/*
 *
 *   Using the on-board LEDs
 *  
 */

#include "project-conf.h"
#include "contiki.h"
#include "dev/leds.h"
#include <stdlib.h>

PROCESS(, );
AUTOSTART_PROCESSES();


PROCESS_THREAD(, ev, data)
{
  PROCESS_BEGIN();
   

    while (1)	{
		
	PROCESS_WAIT_EVENT();	
   }

  PROCESS_END();
}
