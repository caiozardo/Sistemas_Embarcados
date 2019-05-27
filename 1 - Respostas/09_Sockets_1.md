1. Com relação ao modelo cliente-servidor, responda:

(a) Quais são as características básicas deste modelo?

	Basicamente, para qualquerpar de aplicações que se comunicam, um dos lados deve iniciar a execução e esperar (indefinidamente) até ser contactado pelo outro lado.

(b) Quais são as características básicas do servidor?

	Um servidor é um programa que espera por requisições de um cliente. Ou seja, ele:
	- Aguarda passivamente
	- Responde aos clientes
	- Socket passivo

(c) Quais são as características básicas do cliente?

	Um cliente é uma aplicaça~que inicia uma comunicação par-a-par. Ou seja, ele:
	- Inicia a comunicação
	- Deve saber o endereço e a porta do servidor
	- Socket ativo


2.  Com relação ao protocolo de comunicação da internet, responda:

(a) O que são protocolos de comunicação?

	Um protocolo é um método que possibilita a comunicação entre processos (eventualmente executados em diferentes máquinas), ou seja, um conjunto de regras e procedimentos a serem respeitados para emitir e receber dados numa rede. Existem vários deles, utilizados dependendo do que se espera da comunicação. Certos protocolos, por exemplo, são especializados na troca de arquivos (FTP), outros servem apenas para gerir o estado da transmissão e seus erros (ICMP).


(b) Quais são as características básicas de protocolos de comunicação?

	- Cria um socket
	- Associaçao de	um socket de um	servidor um endereço.
	- Recebe dados (sem conexão estabelecida)
	- Envia dados (sem conexão estabelecida)
	

3. Com relação ao protocolo TCP, responda:

(a) O que são portas no protocolo TCP?

	Vários programas TCP/IP (Transmission Control Protocol/Internet Protocol - Protocolo de Controle de Transmissão), podem ser executados simultaneamente na Internet (ex.: é possível abrir vários navegadores simultaneamente ou navegar em páginas HTML baixando, ao mesmo tempo, um arquivo por FTP - Protocolo de transferência de arquivos). Cada um destes programas trabalha com um protocolo, contudo o computador deve poder distinguir as diferentes fontes de dados. Assim, para facilitar este processo, cada uma destas aplicações recebe um endereço único na máquina, codificada em 16 bits: uma porta.

(b) Para que servem estas portas?

	Para que o computador possa distinguir as diferentes fontes de dados. 

