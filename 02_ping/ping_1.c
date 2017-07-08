/*
 *
 *   Ping Command with Rime Primitive Unicast
 *  
 */

#include "project-conf.h"
#include "contiki.h"
#include "net/rime.h"
#include <stdlib.h>

PROCESS(ping, "pinging");
AUTOSTART_PROCESSES(&ping);

/*--------------------------Unicast--------------------------------*/
static struct unicast_conn uc;
static void
recv_uc(struct unicast_conn *c, const rimeaddr_t *from)
{
  
   
  if (rimeaddr_node_addr.u8[0]==1) {
    
  }else {
  
      
  }
    
}
static const struct unicast_callbacks unicast_callbacks = {recv_uc};


/*---------------------------------------------------------------------------*/
PROCESS_THREAD(ping, ev, data)
{
  rimeaddr_t receiver;;
   
  unicast_open(&uc, 146, &unicast_callbacks);
  
  
  if (rimeaddr_node_addr.u8[0]==1){ 
    
      
      
  }
	
    while (1)	{
	//Wait here for an event to happen
	 PROCESS_WAIT_EVENT();
	// and loop
	}

  PROCESS_END();
}
