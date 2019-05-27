1. Cite as vantagens e desvantagens das comunicação serial:

(a) Assíncrona (UART).  
A comunicação via UART necessita de menos pinos, apenas dois, e é fácil de
implementar e trabalhar, pois ambos dispositivos precisam apenas de combinar a
velocidade de transmissão dos dados. Há também a possibilidade de verificar os
dados enviados por meio de um bit de paridade. Em contrapartida, é muito mais
lenta que ascomunicações síncronas e a adição de mais dispositivos reduz ainda
mais a taxade transmissão dos dados para uma mesma _baud rate_, pois será
necessário transmitir o endereço e um bit para verificar se a informação
transmitida diz sobre dados ou endereços.

(b) SPI.
A comunicação SPI é extremamente rápida e não sofre com grandes diminuições na
taxa de transferência de dados quando são adicionados mais dispositivos. As
desvantagens são devido ao alto número de fios, geralmente quatro (MISO, MOSI,
CLK e SS) e a ausência de uma forma nativa de verificar os dados enviados, como
o bit de paridade do UART.

2. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, e que a comunicação entre os dois é UART. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?  
Sim, não é necessário que o MSP430 aguarde, pois o protocolo UART é assíncrono,
portanto é possível que haja envio e recepção de dados ao mesmo tempo.

3. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, que a comunicação entre os dois seja SPI, e que o MSP430 seja o escravo. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?  
O MSP430 deve esperar a ativação da Raspberry Pi através do _Chip Select_ e
ainda deve esperar o envio dos dados a partir da Raspberry, o que depende do
período do clock.

4. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via UART, como executar a comunicação com o segundo dispositivo?  
A comunicação pode ser feita de maneira que se envie primeiro o enddereço do
dispositivo ao qual o dado é destinado, então envie-se o bit AD antes dos bits
de parada. Deste modo cada dispositivo só recebe a comunicação com os dados, a
qual será enviada após o endereço, quando for solicitado.

5. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via SPI, como executar a comunicação com o segundo dispositivo?  
A comunicação SPI com dois dispositivos será feita pela utilização dos pinos de
_chip select_, na qual cada dispositivo extra é acessado de uma vez, ou através
de uma conexão _daisy chain_, na qual os dados dos dispositivos vãao fluindo
entre os registradores de deslocamento até atingirem o mestre.
