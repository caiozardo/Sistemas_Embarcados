1. Quantos pipes serão criados após as linhas de código a seguir? Por quê?

(a)
```C
int pid;
int fd[2];
pipe(fd);
pid = fork();
```

Resposta: 

Nesse caso, o túnel é aberto antes que aconteça uma nova bifurcação. Assim, é criado apenas um pipe.

(b)
```C
int pid;
int fd[2];
pid = fork();
pipe(fd);
```

Resposta: 

Nesse código o pipe é criado após a ocorrência do fork. Assim, são criados dois pipes, sendo que não ocorrerá comunicação porque cada um criou seu próprio Pipe.

2. Apresente mais cinco sinais importantes do ambiente Unix, além do `SIGSEGV`, `SIGUSR1`, `SIGUSR2`, `SIGALRM` e `SIGINT`. Quais são suas características e utilidades?

Resposta: 

SIGSEGV: Emitido em casi de violação de segmentação. SIGUSR1 e SIGUSR2: Sinais disponíveis ao usuário para comunicação interprocessual. SIGALRM: Relógio: emitido quando o relógio de um processo pára. O relógio é colocado em fucionamento utilizando a primitiva alarm(). SIGINT: Sinal emitido aos processos do terminal quando as teclas de interrupção do teclado são acionadas. SIGHUP: Sinal emitido aos processos associados a um terminal quando este se "desconecta" (corte). SIGQUIT: Sinal emitido aos processos do terminal quando as teclas de abandono do teclado são acionadas. SIGKILL: Sinal emitido para matar processos. Não pode ser ignorado nem interceptado. SIGSYS: Sinal emitido quando é colocado argumento incorreto de uma chamada de sistema. SIGPIPE: Sinal emitido quando ocorre a escrita sobre um pipe não aberto em leitura.

3. Considere o código a seguir:

```C
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("date");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
```

Sabendo que a função `alarm()` tem como entrada a quantidade de segundos para terminar a contagem, quão precisos são os alarmes criados neste código? De onde vem a imprecisão? Este é um método confiável para desenvolver aplicações em tempo real?

Resposta:

Devido às interrupções em sua execução por outros processos paralelos no kernel, que dependem do processador da máquina (dividido entre os processos), a precisão da função alarm() é na ordem de microsegundos. Logo pode-se afirmar que para algumas aplicações em tempo real ela não é recomendada.
