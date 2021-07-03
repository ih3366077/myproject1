/*
 * Slave.c
 *
 * Created: 23/11/42 12:51:05 ص
 * Author : ih321
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "SPI_interface.h"


int main(void)
{
	DDRC_REG = 0xff;
	
	SPI_SlaveInit();
	u8 data;
	    
    while (1) 
    {
		data = SPI_ResieveData();
		PORTA_REG=data;
		if (data=='x')
		{
			TOG_BIT(PORTC_REG,0);
		}
		if (data=='y')
		{
			TOG_BIT(PORTC_REG,1);
		}
    }
}

