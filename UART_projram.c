#include"BIT_MATH.H"  
#include"STD_TYPES.H" 

#include "DIO_interface.h" 
#include "UART_private.h"

#include "UART_interface.h" 

void UART_Init(void)
{
	/* Enable RX And Tx  */
	SET_BIT(UCSRB_REG, 3);
	SET_BIT(UCSRB_REG, 4);
	
	/* Setting the Frame formate: 8bits, no parity, one stop bits. */
	SET_BIT(UCSRC_REG, 7);
	
	SET_BIT(UCSRC_REG, 2);
	SET_BIT(UCSRC_REG, 1);
	
	/* Setting the baud rate to 9600 */
	UBRRH_REG =  0  ;
	UBRRL_REG = 108 ;
	
	
}

void UART_SendData(u8 Data)
{
	/* wait until data register is empty. */
	while( GET_BIT(UCSRA_REG, 5)==0 ) ;
	
	/* Put the data in the transmit register */
	UDR_REG = Data ;
	
}

u8 UART_ReadData(void)
{
	/* wait until the recieve is compelete */
	while( GET_BIT(UCSRA_REG, 7)==0 ) ;
	/* return the recieved data */
	return UDR_REG ;
}