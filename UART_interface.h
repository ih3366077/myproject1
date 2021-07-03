
#ifndef        UART_interface_h 
#define        UART_interface_h 

void UART_Init(void);
void UART_SendData(u8 Data);
u8 UART_ReadData(void);

#endif