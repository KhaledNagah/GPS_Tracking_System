#include "UART.h"
float lat_arr[1000]; //array for the latitude
float long_arr[1000];//array for the longitude

void UARTInit(){
	//UART1 Init
	SYSCTL_RCGCGPIO_R|=0x00000004;
	while((SYSCTL_PRGPIO_R&0x00000004) == 0){}; 
	SYSCTL_RCGCUART_R|=0x00000002;
	UART1_CTL_R&=~0x00000001;
	UART1_IBRD_R=520;
	UART1_FBRD_R=53;
	UART1_LCRH_R=0x00000070;
	UART1_CTL_R|=0x00000001;
	GPIO_PORTC_AFSEL_R|=0x30;
	GPIO_PORTC_DEN_R|=0x30;
	GPIO_PORTC_PCTL_R=(GPIO_PORTC_PCTL_R&0xFF00FFFF)+0x00220000;
	GPIO_PORTC_AMSEL_R&=~0x30;
	
	
	//UART0 Init
	SYSCTL_RCGCGPIO_R|=0x00000001;
	while((SYSCTL_PRGPIO_R&0x00000001) == 0){}; 
	SYSCTL_RCGCUART_R|=0x00000001;
	UART0_CTL_R&=~0x00000001;
	UART0_IBRD_R=520;
	UART0_FBRD_R=53;
	UART0_LCRH_R=0x00000070;
	UART0_CTL_R|=0x00000001;
	GPIO_PORTA_AFSEL_R|=0x02;
	GPIO_PORTA_DEN_R|=0x02;
	GPIO_PORTA_PCTL_R=(GPIO_PORTC_PCTL_R&0xFFFFFF00)+0x00000011;
	GPIO_PORTA_AMSEL_R&=~0x02;	
	
}
char UART1Recieve(){
	while((UART1_FR_R&0x100)!=0);
	return UART1_DR_R&0xFF;
}