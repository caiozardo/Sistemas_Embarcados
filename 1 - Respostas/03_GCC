Para todas as questões, compile-as com o gcc e execute-as via terminal.

1. Crie um "Olá mundo!" em C.

	#include <stdio.h>
	#include <stdlib.h>

	int main(void)
	{
		printf("Ola mundo!");
	}	


2. Crie um código em C que pergunta ao usuário o seu nome, e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Ola Eu
```

	#include<stdio.h>
	#include<stdlib.h>

	int main(void)
	{
		char nome[61];
		printf("Digite seu nome: ");
		scanf("%s",nome);
		printf("Ola %s \n", nome);
 
		return 0;
	}


3. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu Mesmo
```

	arthur@pctutu:~/Área de Trabalho$ ./exerc3
	Digite seu nome: Eu Mesmo
	Ola Eu


(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
```bash
$ ./ola_usuario_1
$ Digite o seu nome: "Eu Mesmo"
```

	arthur@pctutu:~/Área de Trabalho$ ./exerc3
	Digite seu nome: "Eu Mesmo"
	Ola "Eu 


(c) Se é usado um pipe. Por exemplo:
```bash
$ echo Eu | ./ola_usuario_1
```

	arthur@pctutu:~/Área de Trabalho$ echo Eu | ./exerc3 
	Digite seu nome: Ola Eu 


(d) Se é usado um pipe com mais de um nome. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_1
```

	arthur@pctutu:~/Área de Trabalho$ echo Eu Mesmo | ./exerc3 
	Digite seu nome: Ola Eu


(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
```bash
$ echo "Eu Mesmo" | ./ola_usuario_1
```

	arthur@pctutu:~/Área de Trabalho$ echo "Eu Mesmo" | ./exerc3 
	Digite seu nome: Ola Eu


c(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_1 < ola.txt
```
	arthur@pctutu:~/Área de Trabalho$ echo Ola mundo cruel! > ola.txt
	arthur@pctutu:~/Área de Trabalho$ ./exerc3 < ola.txt
	Digite seu nome: Ola Ola



4. Crie um código em C que recebe o nome do usuário como um argumento de entrada (usando as variáveis argc e *argv[]), e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu
$ Ola Eu
```

	#include <stdio.h>
	#include <stdlib.h>
	
	int main(int argc, char **argv)
	{
		printf("Ola %s\n", argv[1]);
		
		return 0;
	}


5. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
```bash
$ ./ola_usuario_2 Eu Mesmo
```

	arthur@pctutu:~/Área de Trabalho$ ./exerc5 Eu Mesmo
	Ola Eu


(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
```bash
$ ./ola_usuario_2 "Eu Mesmo"
```

	arthur@pctutu:~/Área de Trabalho$ ./exerc5 "Eu Mesmo"
	Ola Eu Mesmo


(c) Se é usado um pipe. Por exemplo:
```bash
$ echo Eu | ./ola_usuario_2
```

	arthur@pctutu:~/Área de Trabalho$ echo Eu | ./exerc5
	Ola (null)


(d) Se é usado um pipe com mais de um nome. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_2
```

	arthur@pctutu:~/Área de Trabalho$ echo Eu Mesmo | ./exerc5
	Ola (null)


(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
```bash
$ echo "Eu Mesmo" | ./ola_usuario_2
```

	arthur@pctutu:~/Área de Trabalho$ echo "Eu Mesmo" | ./exerc5
	Ola (null)


(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_2 < ola.txt
```

	arthur@pctutu:~/Área de Trabalho$ echo Ola mundo cruel! > ola.txt
	arthur@pctutu:~/Área de Trabalho$ ./exerc5 < ola.txt
	Ola (null)


6. Crie um código em C que faz o mesmo que o código da questão 4, e em seguida imprime no terminal quantos valores de entrada foram fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_3':

```bash
$ ./ola_usuario_3 Eu
$ Ola Eu
$ Numero de entradas = 2
```

	#include <stdio.h>
	#include <stdlib.h>

	int main(int argc, char **argv)
	{
		printf("Ola %s\n", argv[1]);
		printf("%d\n", argc);

		return 0;
	}


7. Crie um código em C que imprime todos os argumentos de entrada fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_argumentos':

```bash
$ ./ola_argumentos Eu Mesmo e Minha Pessoa
$ Argumentos: Eu Mesmo e Minha Pessoa
```

	#include <stdio.h>
	#include <stdlib.h>

	int main(int argc, char **argv)
	{
		int i;
		printf("Argumentos: ");
		for(i=1;i<argc;i++){
		printf("%s ", argv[i]);
		}
		printf("\n");
	
		return 0;
	}	



8. Crie uma função que retorna a quantidade de caracteres em uma string, usando o seguinte protótipo:
`int Num_Caracs(char *string);` Salve-a em um arquivo separado chamado 'num_caracs.c'. Salve o protótipo em um arquivo chamado 'num_caracs.h'. Compile 'num_caracs.c' para gerar o objeto 'num_caracs.o'.



9. Re-utilize o objeto criado na questão 8 para criar um código que imprime cada argumento de entrada e a quantidade de caracteres de cada um desses argumentos. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_1':

```bash
$ ./ola_num_caracs_1 Eu Mesmo
$ Argumento: ./ola_num_caracs_1 / Numero de caracteres: 18
$ Argumento: Eu / Numero de caracteres: 2
$ Argumento: Mesmo / Numero de caracteres: 5
```



10. Crie um Makefile para a questão anterior.



11. Re-utilize o objeto criado na questão 8 para criar um código que imprime o total de caracteres nos argumentos de entrada. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_2':

```bash
$ ./ola_num_caracs_2 Eu Mesmo
$ Total de caracteres de entrada: 25
```



12. Crie um Makefile para a questão anterior.


.
