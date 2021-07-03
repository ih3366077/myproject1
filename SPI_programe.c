#include "STD_TYPES.h"
#include "BIT_MATH.h" 
		 
#include "DIO_interface.h"
#include "SPI_private.h"
#include "SPI_interface.h" 
 
void SPI_MasterInit(void)
{	  
   SET_BIT(SPCR_REG, PIN6);	  // Enable SPI.
   //SET_BIT(SPCR_REG, PIN5);  // LSB TO BE SENT FIRST
   SET_BIT(SPCR_REG, PIN4);    // select Master mode.
   //SET_BIT(SPCR_REG, PIN3);    // IDLE CLK POLARITY HIGH.
   //SET_BIT(SPCR_REG, PIN2);    // SAMPLE AT RISING CLK EDGE .
   // Clock INITIL rate IS fso/4, TO MODIFY Set SPCR-pins1,0 and SPSR-pin0
  
  //Configure SPI PINS
   DIO_voidSetPinDirection(PORTB, PIN7, OUTPUT) ; /*  MOSI Pin output  */
   DIO_voidSetPinDirection(PORTB, PIN6, INPUT)  ; /*  MISO Pin input.  */
   DIO_voidSetPinDirection(PORTB, PIN5, OUTPUT) ; /*  SS Pin output.   */
   DIO_voidSetPinDirection(PORTB, PIN4, OUTPUT) ; /*  SCK Pin output   */
}
	
void SPI_SlaveInit(void)
{  
  SET_BIT(SPCR_REG, PIN6);	//Enable SPI.
    // TO SENd LSB FIRST ( SET_BIT(SPCR_REG, PIN5); )
    // to select Master mode. ( SET_BIT(SPCR_REG, PIN4); )
    // to set IDLE CLK POLARITY HIGH. ( SET_BIT(SPCR_REG, PIN3); )
    // to SAMPLE AT RISING CLK EDGE . ( SET_BIT(SPCR_REG, PIN2); )
    // Clock INITIL rate IS fso/4, TO MODIFY Set SPCR-pins1,0 and SPSR-pin0
  
    //Configure SPI PINS
	DIO_voidSetPinDirection(PORTB, PIN7, INPUT) ; /* SET MOSI PIN AS INPUT  */
	DIO_voidSetPinDirection(PORTB, PIN6, OUTPUT); /* SET MISO PIN AS OUTPUT */
	DIO_voidSetPinDirection(PORTB, PIN5, INPUT) ; /* SET CLK PIN AS INPUT   */
	DIO_voidSetPinDirection(PORTB, PIN4, INPUT) ; /* SET SS PIN AS INPUT    */
  
}
	
void SPI_SendData(u8 Data)
{
	//send data by SPI
    SPDR_REG = Data ;
	
	//wait until SPI interrupt flag=1 (data is sent correctly)
    while( (GET_BIT(SPSR_REG, PIN7)==0 ) ) {}
}

u8  SPI_ResieveData(void)
{
  //wait until SPI interrupt flag=1(data is receive correctly)
  while( (GET_BIT(SPSR_REG, PIN7)==0 ) ) {} 
 
  //return the received byte from SPI data register
  return SPDR_REG ;
}	

void SPI_SendLongData(u8* Data)
{
	u8 index=0 ;                 /*     initiate index to increment inside function     */
	SPI_SendData(0xFF);       /* Send a preDefined CMD to slave to recieve long Data */
							   
   while( index <= '\0' )       /*               long data sending loop                */
   {
     SPI_SendData(Data[index]);
     index++ ;
   }		
}