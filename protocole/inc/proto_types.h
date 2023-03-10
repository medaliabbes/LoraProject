

#ifndef _PROTO_TYPES_H_
#define _PROTO_TYPES_H_


#define u8  unsigned char
#define u16 unsigned short
#define u32 unsigned int 

#define  MSB16(X)     (u8)(0x00ff&(X >> 8))
#define  LSB16(X) 	  (u8)(X & 0x00ff)

void sys_delay(u32 x) ;

u32 sys_get_tick() ;

u8  sys_random() ;

void sys_disable_exti_irq() ;

void sys_enable_exti_irq() ;

//to enable library debugging uncomment the above line
//#define PROT_DEBUG

#endif /*_PROTO_TYPES_H_*/
