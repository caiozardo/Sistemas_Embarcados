1. O que é memória virtual?

	Memória virtual é uma técnica que usa a memória secundária como uma cache para armazenamento secundário. Houve duas motivações principais: permitir o compartilhamento seguro e eficiente da memória entre vários programas e remover os transtornos de programação de uma quantidade pequena e limitada na memória principal.

2. Qual é a diferença entre o user space e o kernel space?
	
	User space - É um conjunto de locais onde os processos normais do usuário são executados. Esses processos não podem acessar o espaço kernel diretamente. Alguma parte do espaço do kernel pode ser acessada por meio de chamadas do sistema. Essas chamadas do sistema atuam como interrupções de software no espaço do kernel.
	Kernel Space - o kernel corre na parte dedicada da memória. A função do kernel space é gerenciar aplicativos / processos em execução no espaço do usuário. Pode acessar toda a memória. Se um processo executar uma chamada de sistema, uma interrupção de software é enviada para o kernel, que então despacha um manipulador de interrupção apropriado.

3. Qual é a diferença de acesso à memória virtual entre o user space e o kernel space?

	Um sistema operacional moderno geralmente segrega a memória virtual no espaço do kernel e no espaço do usuário . Primeiramente, essa separação serve para fornecer proteção de memória e proteção de hardware contra comportamento de software malicioso ou errôneo.
	O espaço do kernel é estritamente reservado para a execução de um kernel de sistema operacional privilegiado , extensões de kernel e a maioria dos drivers de dispositivo . Em contraste, o espaço do usuário é a área de memória na qual o software do aplicativo e alguns drivers são executados.

4. Em termos práticos, por que é feita esta distinção entre user space e kernel space?

	Essa separação serve para fornecer proteção de memória e proteção de hardware contra comportamento de software malicioso ou errôneo.
 
5. Qual é a diferença entre Linux e GNU/Linux?

	Linux é o núcleo (kernel): o programa no sistema que aloca os recursos do sistema para outros programas que você utiliza. O núcleo é uma parte essencial de um sistema operacional, mas inútil por si só; ele pode apenas funcionar no contexto de um sistema operacional completo. Linux é normalmente usado em combinação com o sistema operacional GNU: todo o sistema é basicamente GNU com Linux adicionado, ou GNU/Linux. Todas as distribuições chamadas de “Linux” são, na verdade, GNU/Linux.
 
6. O que é um Linux Kernel Module (LKM)? Quais são suas vantagens?

	Um módulo de kernel carregável ( LKM ) é um mecanismo para adicionar código ou remover código do kernel do Linux em tempo de execução. Eles são ideais para drivers de dispositivos, permitindo que o kernel se comunique com o hardware sem precisar saber como o hardware funciona. 
	Vantagens: Sem módulos carregáveis do núcleo, um sistema operacional teria de incluir todos as possíveis funcionalidades antecipadamente e já compiladas diretamente no núcleo base. Muitas dessas funcionalidades iria residir na memória sem serem utilizados, desperdiçando memória, e exigiria que os usuários reconstruíssem e reiniciassem o núcleo base toda vez que necessitassem de novas funcionalidades. A maioria dos sistemas operacionais que suportam os módulos carregáveis do núcleo incluirão módulos para suportar as funcionalidades mais desejadas.
 
7. O que são device drivers?

	No contexto da informática, a função de um driver de dispositivo ou controlador de dispositivo é aceitar requerimentos abstratos do software independente do dispositivo acima dele e cuidar para que a solicitação seja executada, permitindo que o software interaja com o dispositivo.
 
8. Cite uma situação prática em que vale a pena desenvolver um device driver.

	Um projeto onde você implementará um hardware novo com um software dedicado, para prover uma camada de interface entre sua aplicação e o hardware.
  
9. O que é a General Public License (GPL)? Quais são suas características?

	É a designação da licença de software para software idealizada por Richard Matthew Stallman em 1989, no âmbito do projeto GNU da Free Software Foundation (FSF). Richard Stallman originalmente criou a licença para o Projeto GNU de acordo com as definições de software livre da Free Software Foundation.
	Características:
	- A liberdade de executar o programa, para qualquer propósito (liberdade nº 0)
	- A liberdade de estudar como o programa funciona e adaptá-lo às suas necessidades (liberdade nº 1). O acesso ao código-fonte é um pré-requisito para esta liberdade.
	- A liberdade de redistribuir cópias de modo que você possa ajudar ao seu próximo (liberdade nº 2).
	- A liberdade de aperfeiçoar o programa e liberar os seus aperfeiçoamentos, de modo que toda a comunidade beneficie deles (liberdade nº 3). O acesso ao código-fonte é um pré-requisito para esta liberdade.
