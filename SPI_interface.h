
#ifndef       SPI_INTERFACE_H 
#define       SPI_INTERFACE_H 

void SPI_MasterInit(void);  
void SPI_SlaveInit(void); 
void SPI_SendData(u8 Data); 
void SPI_SendLongData(u8* Data);
u8  SPI_ResieveData(void);  

#endif