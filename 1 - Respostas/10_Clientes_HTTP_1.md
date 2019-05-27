1. Especifique algumas portas importantes pré-definidas para o protocolo TCP/IP.

	Porta 1 - TCPMUX (Serviço de porta TCP multiplexador)
	Porta 5 - RJE (Remote Job Entry - Entrada de trabalho remoto) 
	Porta 7 - ECHO protocol
	Porta 22 - SSH (Secure Shell - Shell seguro)

2. Com relação a endereços IP, responda:

(a) Qual é a diferença entre endereços IP externos e locais?

	Endereços externos são aqueles que são indexados diretamente na rede mundiais de computadores, sendo este unico e dinamico, sendo controlado por um servidor. Já o endereço interno é aquele utilizado por redes de acesso locais mais conhecidos como Intranet, sendo controlado por um roteador.

(b) Como endereços IP externos são definidos? Quem os define?

	Os endereços IP são definidos através de moldens que definem o caminho de dados de um IP ao outro dentro da rede de computadores.

(c) Como endereços IP locais são definidos? Quem os define?

	São definidos pelo modem local que estabelece a rede.

(d) O que é o DNS? Para que ele serve?

	O DNS nomeia os endereços IP sendo possivel acessalos de modo que não seja necessario decorar seu endereço IP.

3. Com relação à pilha de protocolos TCP/IP, responda:

(a) O que são suas camadas? Para que servem?

	Camadas são como pacotes de dados onde se envia determinadas caracteristicas de uma informação onde elas comunicão-se entre si através de protocolos. Um desses possiveis tipo protocolo é o TCP/IP separado em 4 camadas.

(b) Quais são as camadas existentes? Para que servem?

	-Aplicação: Interface entre o software e o usúario.
	-Transporte: Realiza o empacotamento e verificação da menssagem.
	-Rede: Determina o caminho utilizado para enviar a mensagem de um IP ao outro.
	-Enlace: Roteamento dos pacotes.
	-Fisíca: Realiza a modulação da menssagem e transmissão de acordo com o meio. 

(c) Quais camadas são utilizadas pela biblioteca de sockets?

	As camadas de aplicação e transporte.

(d) As portas usadas por servidores na função bind() se referem a qual camada?

	Aplicação.

(e) Os endereços usados por clientes na função connect() se referem a qual camada?

	Transporte.

4. Qual é a diferença entre os métodos `GET` e `POST` no protocolo HTTP?

	-GET: Anexada junto a URL, possui limitação de caracteres e só envia texto.
	-POST: Enviada no corpo do HTTP, logo nao possui limitação de caracteres e pode ser enviada em texto ou em formato binário.




