1. Com relação às conexões GPIO do modelo de Raspberry Pi que você usará no projeto, responda:

(a) Quais pinos podem ser utilizados como entradas e saídas digitais comuns?  
GPIO 4, 17, 27, 22, 5, 6, 13, 26, 18, 23, 24, 25, 12, 16.

(b) Quais pinos possuem resistores de pull-up e pull-down?

(c) Quais formas de comunicação serial são suportados pelos pinos GPIO?  
UART (TXD no GPIO14, RXD no GPIO15); SPI, duas unidades, SPI0 (MOSI no GPIO10,
MISO no GPIO9, SCLK no GPIO11, CE0 no GPIO8, CE1 no GPIO7), SPI1 (MOSI no GPIO20
, MISO no GPIO19, SCLK no GPIO21); duas unidades I2C, I2C0 (ID_SC no GPIO1,
ID_SD no GPIO1), I2C1 (SDA no GPIO2, SCL no GPIO3).

2. Apresente outras 3 bibliotecas de acesso I/O em C para o Raspberry Pi.  
pigpio, WiringPi, sysfs.
