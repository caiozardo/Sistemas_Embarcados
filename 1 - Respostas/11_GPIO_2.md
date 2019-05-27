1. Escreva um código em C para gerar uma onda quadrada de 1 Hz em um pino GPIO do Raspberry Pi.

	#include "gpio_sysfs.h"
	#include <unistd.h>
	
	//Compilar junto com o sysfs.c
	int main()
	{
		int pin=18;
		if(setGPIO_Out(pin))
			return -1;
		if (GPIO_Write(pin,1))
			return 1;
		sleep(0.5);
		if(unsetGPIO(pin))
			return 2;
		return 0;
	}

2. Generalize o código acima para qualquer frequência possível.

	#include "gpio_sysfs.h"
	#include <unistd.h>
	
	//Compilar junto com o sysfs.c
	int main()
	{
		int pin=18;
		float f = 0, t = 0;
	
		printf("freq:\n");
        	scanf("%f", &f);
        	
		t = (1/(2*f));
		
		if(setGPIO_Out(pin))
			return -1;
		if (GPIO_Write(pin,1))
			return 1;
		sleep(t);
		if(unsetGPIO(pin))
			return 2;
		return 0;
	}

3. Crie dois processos, e faça com que o processo-filho gere uma onda quadrada, enquanto o processo-pai lê um botão no GPIO, aumentando a frequência da onda sempre que o botão for pressionado. A frequência da onda quadrada deve começar em 1 Hz, e dobrar cada vez que o botão for pressionado. A frequência máxima é de 64 Hz, devendo retornar a 1 Hz se o botão for pressionado novamente.



