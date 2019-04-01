1. Como se utiliza o comando ps para:
(a) Mostrar todos os processos rodando na m�quina?
> `ps -e` ou `ps -A`

(b) Mostrar os processos de um usu�rio?
> `ps -u usuario` ou `ps --user usuario` ou `ps -U usuario`

(c) Ordenar todos os processos de acordo com o uso da CPU?
> Para ordernar todos os processos em ordem crescente `ps -e --sort=pcpu` Para ordem 
decrescente, `ps -e --sort=-pcpu`.

(d) Mostrar a quanto tempo cada processo est� rodando?
> A flag `--sort=cputime` pode ser inclu�da para mostrar o tempo em ordem crescente.

2. De onde vem o nome fork()?
> Do ingl�s bifurca��o ou ramifica��o. Esse nome � dado porque ao usarmos o comando fork, podemos criar um processo filho de um processo pai.

3. Quais s�o as vantagens e desvantagens em utilizar:

(a) system()?
> Vantagens: Permite executar um comando dentro de um programa (sub-processo). � mais simples.
Desvantagens: Depende muito do sistema operacional, dando muita brecha para poss�veis falhas de execu��o. N�o � indicado para a maioria dos casos.

(b) fork() e exec()?
> Vantagens: � mais robusto.
Desvantagens: Um pouco mais complexo; n�o h� uma fun��o que crie e execute um novo processo em um �nico passo. � necess�rio escolher corretamente o a fun��o da fam�lia de `exec()` em caso de uso de argumentos.

4. � poss�vel utilizar o exec() sem executar o fork() antes?
> Sim, no entanto o processo que estiver em execu��o no momento ser� alterado pelo `exec()`, sem criar um novo processo.

5. Quais s�o as caracter�sticas b�sicas das seguintes fun��es:

(a) execp()?
> Executa o processo no diret�rio corrente, sem ser necess�rio colocar o caminho do programa.

(b) execv()?
```C

int execv(const char *path, char *const argv[]);
```

A lista de argumentos � passada como um vetor de ponteiros.

(c) exece()?
> Aceita um argumento adicional.

(d) execvp()?
> ```C

int execvp(const char *file, char *const argv[]);
```  

Recebe argumentos como vetor de ponteiros e aceita caminhos relativos, pois 
procura no diret�rio corrente (current path).

(e) execve()?
> ```C

int execve(const char *filename, char *const argv[], char *const envp[]);
```  

Essa fun��o recebe o programa a ser executado, que pode ser um bin�rio ou um script; o vetor de
 argumentos e o vetor de configura��es para o ambiente do programa.


(f) execle()?
> ```C

int execle(const char *path, const char *arg, ..., (char *) NULL,
char * const envp[]);
```  

Essa fun��o recebe o caminho do programa a executar, os argumentos como uma lista e o vetor 
para vari�veis de ambiente.
