/*
 *
 *   Gradient Based Routing with Rime Primitives broadcast and unicast
 *  
 */

#include "project-conf.h"
#include "contiki.h"
#include "net/rime.h"
#include <stdlib.h>

#define BUFF_SIZE 10
#define GRAND_DELAY 45
#define CBR_RATE 10


static uint8_t My_Rank =100,seq=0;
void send_gradient(),generate_packet();

static uint8_t buff[BUFF_SIZE],fatherID=-1;


PROCESS(routing, "routing test");
AUTOSTART_PROCESSES(&routing);

/*---------------------Broadcast----------------------------------------------------*/
static void broadcast_recv(struct broadcast_conn *c, const rimeaddr_t *from)
{
  static struct ctimer timerNd;
  
 
    printf("Gradient Received from %d.%d:  with Rank %d\n",from->u8[0], from->u8[1], rcv_rank);
    if (rcv_rank+1<My_Rank) {
      static unsigned int counter = 0;
      

      
      printf("My New Rank is %d Father %d \n",My_Rank,fatherID);
    }
  
}
static const struct broadcast_callbacks broadcast_call = {broadcast_recv};
static struct broadcast_conn broadcast;

/*--------------------------Unicast--------------------------------*/
static struct unicast_conn uc;
static void
recv_uc(struct unicast_conn *c, const rimeaddr_t *from)
{
   char *packet=(char *)packetbuf_dataptr();

  if (rimeaddr_node_addr.u8[0]==1) {
    printf("Sink from %d -- Seqno %d  from %d  \n",packet[0],packet[1],from->u8[0]);
  }else { // forward
      
    
  }
}
static const struct unicast_callbacks unicast_callbacks = {recv_uc};



/*---------------------------------------------------------------------------*/
PROCESS_THREAD(routing, ev, data)
{
  static struct etimer et;
  static struct ctimer timerSnk,timerEmt;
   
  PROCESS_BEGIN();
  //cc2420_set_txpower(9);
   
  broadcast_open(&broadcast, 129, &broadcast_call);
  unicast_open(&uc, 146, &unicast_callbacks);
  
  if (rimeaddr_node_addr.u8[0]==1){ // Sink 
      
  }else { // Nodes
      
  }
	
    while (1)	{
	//Wait here for an event to happen
	PROCESS_WAIT_EVENT();
	// and loop
	}

  PROCESS_END();
}
void send_gradient() {
    
    
    
    printf("Sending Gradient %d\n",My_Rank);
  
}


void generate_packet() {
  static struct ctimer timerCBR;
  rimeaddr_t receiver;

      
      
      packetbuf_clear();
      packetbuf_copyfrom(buff, BUFF_SIZE);
      
      unicast_send(&uc, &receiver);
      
      ctimer_set(&timerCBR, CLOCK_SECOND*CBR_RATE, generate_packet, NULL);
      printf("Generate packet %d -- %d \n",rimeaddr_node_addr.u8[0],seq);
  
}

