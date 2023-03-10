

#ifndef _LINK_LAYER_H_
#define _LINK_LAYER_H_

#include "packet.h"
#include "proto_types.h"

//#define LL_RX_TIMEOUT_REMOVE


#define  TX_PACKET_LIST_SIZE         10
#define  RX_PACKET_LIST_SIZE         10

#define  BUFFER_FULL			    (-10)
#define  ALLOCATION_FAILED          (-11)

#define  MAX_NUMBER_OF_TRANSMITION   (5) //the maximum number of time a packet is transmitted to the network 

#define  LL_RX_TIMEOUT 		(1000)

#define  LL_TX_BUTTLE_NECK    6 // number of packet that cause transmition to be delayed

typedef enum lib_state{
						State_recv ,  // RX mode
						State_recv_proc, //Process rx packets
						State_transmit , //transmit PAckets
						State_list_clear //check list for timeout packets
						}
						lib_state_t;

//this function will be executed when a data is transmitted and received by receiver
typedef void (*ask_received_callback)() ;

struct packet_holder
{
    packet_t packet ;
    int transmition_time ;
    int recv_time ;
    int number_of_transmition ;
    ask_received_callback Ask_callback ;
} ;

typedef struct packet_holder packet_holder_t ;

//should be called first , default adress is 0xFF
int ll_init(u8 addr);

void ll_process(void) ;

int ll_send_ASK(u8 dest ,u8 id) ;

int ll_send_NANK(u8 dest ,u8 id) ;

//send a data packet 
int ll_send_to(u8 dest ,u8 *data ,int data_len ) ;

//check Rx list for data from the dest (return a payload length and copy the payload in data)
int  ll_get_recv_from(u8 src ,u8 *data );

//do the actuel transmition , should be called from ll_process
void ll_transmit(void) ;

//get the received data ,converted into packet_t type and put it in Rx queue 
void ll_receive(u8 * payload , int size) ;

int get_tx_size() ;

int get_rx_size() ;

void ll_debug_tx_list() ;

/*
 * data : buffer to copy the received data
 * len  : pointer that will hold the data length
 * retutn the address source of data ,or -1 if no recv
 */
int ll_get_recv(u8 * data ,int * len ) ;

//this function should be called in ll_process ,it will remove the tx packet that got a response
void ll_process_received() ;

//should be called whene TxDone
void ll_set_transmition_done() ;

void ll_debug_Rx_list() ;

/*
void State_transiton_tx_done() ;

void State_transition_resp_to_send() ;

void State_transition_valide_packet();
*/

#endif /*_LINK_LAYER_H_*/
