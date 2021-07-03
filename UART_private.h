#ifndef        UART_private_h 
#define        UART_private_h 

#define        UDR_REG          *( (volatile u8*) 0x2C )
#define        UCSRA_REG        *( (volatile u8*) 0x2B )
#define        UCSRB_REG        *( (volatile u8*) 0x2A )
#define        UCSRC_REG        *( (volatile u8*) 0x40 )
#define        UBRRL_REG        *( (volatile u8*) 0x29 )
#define        UBRRH_REG        *( (volatile u8*) 0x40 )

#endif