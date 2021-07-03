#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define     OUTPUT          1
#define     INPUT           0
					    
#define     HIGH            1
#define     LOW             0
		 			    
#define     PORTA           0
#define     PORTB           1
#define     PORTC           2
#define     PORTD           3
		 			    		 					 			 
#define     PIN0            0
#define     PIN1            1
#define     PIN2            2
#define     PIN3            3
#define     PIN4            4
#define     PIN5            5
#define     PIN6            6
#define     PIN7            7

void    DIO_voidSetPinDirection(u8 PORTID , u8 PINID , u8 Direction);
void    DIO_voidSetPinValue(u8 PORTID , u8 PINID , u8 Value);
u8      DIO_u8GetPinValue(u8 PORTID , u8 PINID);

void DIO_voidSetPortDirection(u8 PortID , u8 Direction) ;
void DIO_voidSetPortValue(u8 PortID , u8 Value) ;



#endif