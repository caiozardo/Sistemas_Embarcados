Para todas as questões, utilize as funções da biblioteca `stdio.h` de leitura e de escrita em arquivo (`fopen()`, `fclose()`, `fwrite()`, `fread()`, dentre outras). Compile os códigos com o gcc e execute-os via terminal.

1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

Resposta:
```
#include <stdio.h>

#include <stdlib.h>



int main(void)

{

	FILE * fp;

	char frase[] = "Ola mundo!";



	fp = fopen("ola_mundo.txt", "w");

	

	if(fp == NULL){

		puts("Erro ao criar o arquivo\n");

		exit(-1);

	}



	fputs(frase, fp);



	fclose(fp);



	return 0;

}
```

2. Crie um código em C que pergunta ao usuário seu nome e sua idade, e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Digite a sua idade: 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

Resposta: 

```
#include <stdio.h>

#include <stdlib.h>

#include <string.h>



int main(void)

{

	FILE *fp;

	unsigned int idade;

	char nomep[128], nomearq[128];

	char ext[] = ".txt";



	printf("Digite o seu nome: ");

	scanf("%s", nomep);



	printf("Digite a sua idade: ");

	scanf("%d", &idade);



	strcpy(nomearq, nomep);

	strcat(nomearq, ext);



	fp = fopen(nomearq, "w");



	if (fp == NULL) {

		printf("Erro ao abrir o arquivo '%s'\n", nomearq);

		exit(-1);

	}



	fprintf(fp, "Nome: %s\n", nomep);

	fprintf(fp, "Idade: %d\n", idade);



	fclose(fp);



	return 0;

}
```

3. Crie um código em C que recebe o nome do usuário e e sua idade como argumentos de entrada (usando as variáveis `argc` e `*argv[]`), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

Resposta:
```
#include <stdio.h>

#include <stdlib.h>

#include <string.h>



int main(int argc, char **argv)

{

        FILE *fp;

        unsigned int idade;

        char nomearq[128];

        char ext[] = ".txt";



	if (argc < 2) {

		printf("Uso: ./ola_usuario_2 nome idade\n");

		exit(-1);

	}



        strcpy(nomearq, argv[1]);

        strcat(nomearq, ext);



	sscanf(argv[2], "%d", &idade);



        fp = fopen(nomearq, "w");



        if (fp == NULL) {

                printf("Erro ao abrir o arquivo '%s'\n", nomearq);

                exit(-2);

        }



        fprintf(fp, "Nome: %s\n", argv[1]);

        fprintf(fp, "Idade: %d\n", idade);



        fclose(fp);

	return 0;

}
```

4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.

Resposta:

```
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "bib_arqs.h"

long tam_arq_texto(char *nome_arquivo) 
{ 
FILE *fp = fopen(nome_arquivo, "r"); 
long tamanho=0; 
if (fp != NULL)
{ 
fseek(fp, 0, SEEK_END); 
tamanho = ftell(fp); 
fseek(fp, 0, SEEK_SET); 
fclose(fp); 
} 
else{ printf("Arquivo inexistente"); 
} 
return tamanho; 
}
```

5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `char* le_arq_texto(char *nome_arquivo);` Repare que o conteúdo do arquivo é armazenado em um vetor interno à função, e o endereço do vetor é retornado ao final. (Se você alocar este vetor dinamicamente, lembre-se de liberar a memória dele quando acabar o seu uso.) Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.

Resposta: 
```
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "bib_arqs.h"
long tam_arq_texto(char *nome_arquivo) 
{ 
FILE *fp = fopen(nome_arquivo, "r"); 
long tamanho=0; if (fp != NULL){ 
fseek(fp, 0, SEEK_END); 
tamanho = ftell(fp); 
fseek(fp, 0, SEEK_SET); 
fclose(fp); } 
else{ printf("Arquivo inexistente"); } 
return tamanho; }
void le_arq_texto(char *nome_arquivo, char *conteudo) 
{ 
long tam=0; 
FILE *fp = fopen(nome_arquivo, "r"); 
tam = tam_arq_texto(nome_arquivo); 
conteudo = (char *)malloc(tam * (sizeof(char))); 
fgets(conteudo, sizeof(char)*tam, fp); 
puts(conteudo); fclose(fp); 
free(conteudo); }
long tam_arq_texto(char *nome_arquivo); 
void le_arq_texto(char *nome_arquivo, char *conteudo);
```

6. Crie um código em C que copia a funcionalidade básica do comando `cat`: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!
```
Resposta: 
```
#include <stdio.h>

#include <stdlib.h>

#include "bib_arqs.h"



int main(int argc, char **argv)

{

	char *conteudo = NULL;

	unsigned int tam;



	if (argv[1] == NULL)

		printf("Uso:\n./cat_falsificado arquivo\n");



	tam = tam_arq_texto(argv[1]);



	if (tam <= 0) {

		printf("tam_arq_texto: Erro na leitura do arquivo %s\n", argv[1]);

		exit(-1);

	}



	conteudo = malloc(sizeof(char)*tam + 1);

	le_arq_texto(argv[1], conteudo);



	printf("%s\n", conteudo);



	free(conteudo);

	conteudo = NULL;



	return 0;

}
```

7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```

Resposta: 
```
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "bib_arqs.h"



int main(int argc, char **argv)

{

	FILE *fp;

	char *conteudo = NULL;

	/*

	* Tamanho do arquivo em bytes, quantidade de vezes que o padrão

	* aparece

	*/



	unsigned int tam = 0, qtdp = 0;



	/*

	* ./busca_e_conta	padrao	arquivo	(null)

	* argv[0]		argv[1]	argv[2]	argv[3]

	* Considerando argv[argc]

	*/

	if ((argc < 2) || (argv[2] == NULL)) {

		printf("Uso:\n./busca_e_conta padrao arquivo\n");

		exit(-1);

	}



	tam = tam_arq_texto(argv[2]);



	if (tam <= 0) {

		printf("tam_arq_texto: Erro na leitura do arquivo %s\n", argv[2]);

		exit(-1);

        }



        conteudo = malloc(sizeof(char)*tam + 1);

        le_arq_texto(argv[2], conteudo);



	/* Procurar a substring argv[1] na string conteudo */

	while ((conteudo = strstr(conteudo, argv[1])) != NULL) {

		qtdp++;

		conteudo++;

	}



	printf("'%s' ocorre %d vezes no arquivo '%s'\n", argv[1],

	qtdp, argv[2]);



	free(conteudo);

	conteudo = NULL;



	return 0;

}
```
