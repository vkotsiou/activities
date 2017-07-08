/*
 *
 *   Ping Command with Rime Primitive Unicast
 *  
 */

#include "project-conf.h"
#include "contiki.h"
#include "net/rime.h"
#include <stdlib.h>

static clock_time_t start_time,end_time,time_interval;

PROCESS(ping, "pinging");
AUTOSTART_PROCESSES(&ping);


/*--------------------------Unicast--------------------------------*/
static struct unicast_conn uc;
static void recv_uc(struct unicast_conn *c, const rimeaddr_t *from)
{
   rimeaddr_t receiver;
   char *packet=(char *)packetbuf_dataptr();

  if (rimeaddr_node_addr.u8[0]==1) {
   ;
   
    printf("Reply from %d.0 time=%ld ms \n", ,);
    
  }else {
  
      receiver.u8[0] = from->u8[0];
      receiver.u8[1] = 0;
      
      packetbuf_clear();
      packetbuf_copyfrom("Pong", 4);
      
      unicast_send(&uc, &receiver);
      printf("Pong \n");
  }
    
}
static const struct unicast_callbacks unicast_callbacks = {recv_uc};


/*---------------------------------------------------------------------------*/
PROCESS_THREAD(ping, ev, data)
{
  rimeaddr_t receiver;

  PROCESS_BEGIN();
   
  unicast_open(&uc, 146, &unicast_callbacks);
  
  if (rimeaddr_node_addr.u8[0]==1){ 
    
      receiver.u8[0] = 2;
      receiver.u8[1] = 0;
      
      packetbuf_clear();
      packetbuf_copyfrom("Ping", 4);
      
      unicast_send(&uc, &receiver);
      
      
      
      printf("Pinging %d.0 \n",receiver.u8[0]);
      
  }
	
    while (1)	{
	//Wait here for an event to happen
	PROCESS_WAIT_EVENT();		
	// and loop
	}

  PROCESS_END();
}
