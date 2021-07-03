/*
 * Master.c
 *
 * Created: 22/11/42 05:41:17 ص
 * Author : ih321
 */ 

#include "STD_TYPES.h"
#include "SPI_interface.h"
#include "BIT_MATH.h"
#include "UART_interface.h"
#include <avr/io.h>

int main(void)
{
	u8 data;
	SPI_MasterInit();
	UART_Init();
	
	
    /* Replace with your application code */
    while (1) 
    {
		data = UART_ReadData();
		//UART_SendData(data);
		SPI_SendData(data);
		
		
    }
}

