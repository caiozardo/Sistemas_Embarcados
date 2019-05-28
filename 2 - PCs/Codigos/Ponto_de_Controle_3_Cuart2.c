// feita a comunicação UART usando os pinos 8 e 10 da rasp (que são os pinos UART)
// neste código em #C, usamos a biblioteca "wiringPi.h"
// a diferença da comunicação UART para a USB é que, a USB tem um pino de energia e um terra
// ESTE CÓDIGO SERVE PARA CAPTURAR OS DADOS DE OUTPUT DO MÓDULO AD8232

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringSerial.h>

int main ()
{
  int serial_port ;
  char dat;
  if ((serial_port = serialOpen ("/dev/ttyS0", 9600)) < 0)	/* Abrindo a Porta serial */
  {
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
    return 1 ;
  }

  if (wiringPiSetup () == -1)					/* Inicializando as configurações do WIRINGPI */
  {
    fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
    return 1 ;
  }

  while(1){
	  
	if(serialDataAvail (serial_port) )
	{ 
		dat = serialGetchar (serial_port);		/* Recebendo dados serial*/	
		printf ("%c", dat) ;
		fflush (stdout) ;
		//serialPutchar(serial_port, dat);		/* transmitindo dados serial*/
		  }
	}

}
