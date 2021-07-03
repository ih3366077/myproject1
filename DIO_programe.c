#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_private.h"
#include "DIO_interface.h"


void  DIO_voidSetPinDirection (u8 PORTID , u8 PINID , u8 Direction ) {
	/*	Range Check				*/
	if ( (PORTID < 4) && (PINID < 8) ) 
	{
		if ( Direction == OUTPUT ) {
			switch(PORTID)
		{
			case PORTA :	SET_BIT(DDRA_REG ,PINID); 	break;
			case PORTB :	SET_BIT(DDRB_REG ,PINID);	break;
			case PORTC :	SET_BIT(DDRC_REG ,PINID);	break;
			case PORTD :	SET_BIT(DDRD_REG ,PINID);	break;
		}
		}
	
	else if (Direction == INPUT)
	{
		switch(PORTID)
		{
			case PORTA :	CLR_BIT(DDRA_REG ,PINID); 	break;
			case PORTB :	CLR_BIT(DDRB_REG ,PINID);	break;
			case PORTC :	CLR_BIT(DDRC_REG ,PINID);	break;
			case PORTD :	CLR_BIT(DDRD_REG ,PINID);	break;
		}
	}
	else {
		/* return error */
	}
}
   else {
	   /* return error */
   }
	   
}

void    DIO_voidSetPinValue(u8 PORTID , u8 PINID , u8 Value ) {

 if ( (PORTID < 4) && (PINID < 8) ) 
	{
		if ( Value == HIGH ) {
			switch(PORTID)
		{
			case PORTA :	SET_BIT(PORTA_REG ,PINID); 	break;
			case PORTB :	SET_BIT(PORTB_REG ,PINID);	break;
			case PORTC :	SET_BIT(PORTC_REG ,PINID);	break;
			case PORTD :	SET_BIT(PORTD_REG ,PINID);	break;
		}
		}
	
	else if (Value == LOW)
	{
		switch(PORTID)
		{
			case PORTA :	CLR_BIT(PORTA_REG ,PINID); 	break;
			case PORTB :	CLR_BIT(PORTB_REG ,PINID);	break;
			case PORTC :	CLR_BIT(PORTC_REG ,PINID);	break;
			case PORTD :	CLR_BIT(PORTD_REG ,PINID);	break;
		}
	}
	else {
		/* return error */
	}
}
   else {
	   /* return error */
   }	
}

void    DIO_voidTogPinValue(u8 PORTID , u8 PINID  ) {

	if ( (PORTID < 4) && (PINID < 8) )
	{
			switch(PORTID)
			{
				case PORTA :	TOG_BIT(PORTA_REG ,PINID); 	break;
				case PORTB :	TOG_BIT(PORTB_REG ,PINID);	break;
				case PORTC :	TOG_BIT(PORTC_REG ,PINID);	break;
				case PORTD :	TOG_BIT(PORTD_REG ,PINID);	break;
			}
		
	}
	else {
		/* return error */
	}
}


u8    DIO_u8GetPinValue (u8 PORTID , u8 PINID ){
	u8 Local_u8Data = 0xFF ;
	if ( (PORTID < 4) && (PINID < 8) ) 
	{
		switch(PORTID)
		{
			case PORTA :	Local_u8Data = GET_BIT(PINA_REG ,PINID); 	break;
			case PORTB :	Local_u8Data = GET_BIT(PINB_REG ,PINID);	break;
			case PORTC :	Local_u8Data = GET_BIT(PINC_REG ,PINID);	break;
			case PORTD :	Local_u8Data = GET_BIT(PIND_REG ,PINID);	break;
		}
	}
	else
	{
		/*	Return ERROR			*/
	}
	return Local_u8Data ;
}

void DIO_voidSetPortValue(u8 PortID , u8 Value)
{
	/*		Range Check			*/
	if( PortID < 4 )
	{
		switch(PortID)
		{
			case PORTA : PORTA_REG =  Value ; break ;
			case PORTB : PORTB_REG =  Value ; break ;
			case PORTC : PORTC_REG =  Value ; break ;
			case PORTD : PORTD_REG =  Value ; break ;
		}
	}
	else{/*Return Error*/		}
}

void DIO_voidSetPortDirection(u8 PortID , u8 Direction)
{
	/*		Range Check			*/
	if( PortID < 4 )
	{
		if (Direction == OUTPUT)
		{
		  switch(PortID)
		    {
		    	case PORTA : DDRA_REG =  0xFF ; break ;
		    	case PORTB : DDRB_REG =  0xFF ; break ;
		    	case PORTC : DDRC_REG =  0xFF ; break ;
		    	case PORTD : DDRD_REG =  0xFF ; break ;
		    }
		}
		if (Direction == INPUT)
		{
			switch(PortID)
			{
				case PORTA : DDRA_REG =  0x00 ; break ;
				case PORTB : DDRB_REG =  0x00 ; break ;
				case PORTC : DDRC_REG =  0x00 ; break ;
				case PORTD : DDRD_REG =  0x00 ; break ;
			}
		}
	}
	else{/*Return Error*/		}
}