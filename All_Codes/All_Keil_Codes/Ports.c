#include "Ports.h"
void PortsInit(){
	//PORTF_INIT TO USE THE GREEN LED
	SYSCTL_RCGCGPIO_R|=0X20;
	while((SYSCTL_PRGPIO_R&0x00000020) == 0){}; 
	GPIO_PORTF_AMSEL_R&=~0X08;
	GPIO_PORTF_AFSEL_R&=~0X08;
	GPIO_PORTF_PCTL_R&=~0X0000FFF0;
	GPIO_PORTF_DIR_R|=0X08;
	GPIO_PORTF_DEN_R|=0X08;
	GPIO_PORTF_DATA_R&=~0X08;
  //PORTB_INIT TO USE 7 SEG
	SYSCTL_RCGCGPIO_R|=0X02;
		while((SYSCTL_PRGPIO_R&0x00000002) == 0){}; 
	GPIO_PORTB_AMSEL_R&=~0XFF;
	GPIO_PORTB_AFSEL_R&=~0XFF;
	GPIO_PORTB_PCTL_R&=~0X0000FFF0;
	GPIO_PORTB_DIR_R|=0XFF;
	GPIO_PORTB_DEN_R|=0XFF;
	GPIO_PORTB_DATA_R&=0XFF;
		return;
}
		