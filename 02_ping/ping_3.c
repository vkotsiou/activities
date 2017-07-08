/*
 *
 *   Ping Command with Rime Primitives Unicast
 *  
 */
#include "project-conf.h"
#include "contiki.h"
#include "net/rime.h"
#include <stdlib.h>

#define NO_OFF_PACKETS 100

static clock_time_t start_time,end_time,time_interval;
void send_packet();
void show_stats();
static unsigned int packets=0,received_packets=0 ,min=4000,max=0,avg=0,sum=0;

PROCESS(ping, "pinging");
AUTOSTART_PROCESSES(&ping);


/*--------------------------Unicast--------------------------------*/
static struct unicast_conn uc;
static void
recv_uc(struct unicast_conn *c, const rimeaddr_t *from)
{
   rimeaddr_t receiver;

  if (rimeaddr_node_addr.u8[0]==1) {
    end_time=clock_time();
    time_interval= (end_time-start_time)*1000/CLOCK_SECOND;
    printf("Reply from %d.0 time=%ld ms \n", from->u8[0],time_interval);
    
    
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
      send_packet();   
  }
	
    while (1)	{
	//Wait here for an event to happen
	  PROCESS_WAIT_EVENT();
	// and loop
	}
  PROCESS_END();
}

void send_packet() {
 static struct ctimer timerPing,timerStats;
 rimeaddr_t receiver;
  if (packets<NO_OFF_PACKETS) {
      receiver.u8[0] = 2;
      receiver.u8[1] = 0;
      
      packetbuf_clear();
      packetbuf_copyfrom("Ping", 4);
      packets++;
      start_time=clock_time();
      
      unicast_send(&uc, &receiver);
           
      printf("Pinging %d.0 %d packet  \n",receiver.u8[0],packets);
      
      
  }else {
    
  }
	    
}

void show_stats(){
  
  printf("Ping Statistics \n");
  printf("  Packets: Sent = %d Received = %d Lost = %d \n", ,,);
  printf("Approximate round trip times in milli-seconds: \n");
  printf("  Minimum = %d ms, Maximum = %d ms, Average = %d ms \n",,,);
}
