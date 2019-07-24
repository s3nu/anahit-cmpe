
//SPI Lab2
class lab2: public scheduler_task {
public:
	lab2() :
		scheduler_task("lab2", 2000, PRIORITY_LOW) {
	}

	void spi1_Init() {
		LPC_SC->PCONP |= (1 << 10);   	 		// SPI1 Power Enable
		LPC_SC->PCLKSEL0 &= ~(3 << 20); 		// Clear clock Bits
		LPC_SC->PCLKSEL0 |= (1 << 20); 		// CLK / 1

		// Select MISO, MOSI, and SCK pin-select functionality
		LPC_PINCON->PINSEL0 &= ~((3 << 14) | (3 << 16) | (3 << 18));
		LPC_PINCON->PINSEL0 |= ((2 << 14) | (2 << 16) | (2 << 18));
		LPC_SSP1->CR0 = 7;          			// 8-bit mode
		LPC_SSP1->CR1 = (1 << 1);  				// Enable SSP as Master
		LPC_SSP1->CR1 &= ~(1<<2)					//Master mode
		LPC_SSP1->CPSR = 8;         			// SCK speed = CPU / 8
		//		LPC_PINCON->PINSEL0 &= ~( (1 << 13)|(1 << 12) ); //Select CS
		LPC_PINCON->PINSEL0 &= ~(3 << 13); //Select CS
		LPC_GPIO0->FIODIR |= (1 << 6); 		//CS output
		LPC_GPIO0->FIOSET = (1 << 6); 			//CS high (not selected)
	}

	bool run(void *p) {
		/*
		 * Main task for Lab2 handler
		 */
		vTaskDelay(1000); 						//Delay

		printf("\nDevice ID\n");
		LPC_GPIO0->FIOCLR = (1 << 6); 			//CS low
		spi1_ExchangeByte(0x9F); 				//Opcode for Device ID
		for (int i = 0; i < 5; i++) {
			printf("\n %d\t %x", i, spi1_ExchangeByte(0x00));
		}
		LPC_GPIO0->FIOSET = (1 << 6);				//CS high
		vTaskDelay(1000); 						//Delay
		printf(
				"\n******************************************************************************\n");

		printf("Memory's Status Register\n");
		LPC_GPIO0->FIOCLR = (1 << 6); 			//CS low
		spi1_ExchangeByte(0xD7); 				//Opcode for Status Register
		uint16_t temp, temp1;
		temp = spi1_ExchangeByte(0x00);
		printf("\n %x\t", temp);
		temp1 = spi1_ExchangeByte(0x00);
		printf("\n %x\t", temp1);
		LPC_GPIO0->FIOSET = (1 << 6);				//CS high
		vTaskDelay(1000); 						//Delay
		return true;
	}

	char spi1_ExchangeByte(char out) {
		LPC_SSP1->DR = out;
		while (LPC_SSP1->SR & (1 << 4))
			; // Wait until SSP is busy
		return LPC_SSP1->DR;
	}
};