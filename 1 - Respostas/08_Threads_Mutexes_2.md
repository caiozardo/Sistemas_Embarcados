1. Crie um programa em C que cria uma thread, e faça com que o programa principal envie os valores 1, 2, 3, 4, 5, 6, 7, 8, 9 e 10 para a thread, com intervalos de 1 segundo entre cada envio. Depois de o programa principal enviar o número 10, ele aguarda 1 segundo e termina a execução. A thread escreve na tela cada valor recebido, e quando ela receber o valor 10, ela termina a execução.
``````````
	#include <stdio.h>
	#include <stdlib.h>
	#include <pthread.h>
	#include <unistd.h>
	
	int parametro[20];
	int i;
	
	void *print_thread(void *parameters)
	{
		int *p = (int *)parameters;
	
	 	for(int n = 1; n < 11 ; n++)
	 	{
	        	printf("Recebi %d\n", parametro[i - 1]);
			sleep(1);
		}
		return NULL;
	}

	int main()
	{
		pthread_t thread_1;
		pthread_create(&thread_1,NULL, &print_thread, &thread_1);
   	 	for(i = 1; i < 11 ; i++)
 		{
   			printf("Enviando %d\n", i);
 			parametro[i - 1] = i;
 			sleep(1);
 		}
 	
 		pthread_join(thread_1,NULL);
 		return 0;
	}
`````````````````

2. Crie um programa em C que preenche o vetor `long int v[50000]` completamente com valores aleatórios (use a função `random()`), e que procura o valor máximo do vetor por dois métodos:

(a) Pela busca completa no vetor `v[]`;

	#include <pthread.h> 
	#include <stdio.h> 
	#include <stdlib.h> 
	#include <time.h>
	
	void* max_vetor( void*v)
	{ 
		int i=0; 
		int max=0; 
		long int vetor[50000]; 
		for(i=0;i<50000;i++)
		{ 
			if(vetor[i]>max)
			{	 
				max=vetor[i];
			}
		} 
		printf("\nValor máximo do vetor é: %d\n", max); 
		return NULL; 
	}
	
	int main()
	{ 
		pthread_t thread_id1; 
		long int v[50000]; 
		int j=0; 
		srand(time(NULL)); 
		for(j=0; j<50000;j++)
		{ 
			v[j]= rand(); 
		} 
		pthread_create(&thread_id1, NULL, &max_vetor, &v); 
		pthread_join(thread_id1, NULL); 
		return 0; 
	}

(b) Separando o vetor em 4 partes, e usando 4 threads para cada uma encontrar o máximo de cada parte. Ao final das threads, o programa principal compara o resultado das quatro threads para definir o máximo do vetor.

	#include <pthread.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	
	void* max_vetor( void*v)
	{
		int i=0;
		int max=0;
		long int *vetor= (long int*)v;
		for(i=0;i<12500;i++)
		{
			if(vetor[i]>max)
			{
				max=vetor[i];
			}
		}
		printf("\nValor máximo do vetor é: %d\n", max);
		return NULL;
	}
	
	int main()
	{
		pthread_t thread_id[4];
		long int v[50000];
		long int vetores[12500];
		int i=0, maxmesmo=0;
			srand(time(NULL));
			for(i=0; i<50000;i++)
			{
				v[i]= rand();
			}

		// forma paralela
		system("date +%s%3N");
		for(i=0; i<4; i++)
		{
			vetores[i] = &(v[i*12500]);
			pthread_create(&(thread_id[i]), NULL, &max_vetor, &(vetores[i]));
		}
		for(i=0; i<4; i++)
		{
			pthread_join(thread_id[i], NULL);
		}
		return 0;
	}

Ao final do programa principal, compare os resultados obtidos pelos dois métodos.



3. Repita o exercício anterior, mas calcule a média do vetor ao invés do valor máximo.
```````````````````
	#include <pthread.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	
	#define TAM 100000
	
	struct vector_calcs
	{
		int *v;
		int N;
		long int soma;
	};
	
	void* calc_media_local(void* parameters)
	{
		struct vector_calcs* p = (struct vector_calcs*) parameters;
		int i;
		p->soma = 0;
		for(i = 0; i < p->N; ++i)
			p->soma += (long int)p->v[i];
		return NULL;
	}
	
	int main ()
	{
	
		pthread_t threads[4];
		struct vector_calcs vecs[4];
		int v[TAM];
		int i, medias[2];
		long int soma;
		
		// Preenche o vetor
		srand(time(NULL));
		for(i=0; i<TAM; i++)
			v[i] = rand()%1000;
	
		// Calcula a media de forma serial
		system("date +%s%3N");
		for(soma=0,i=0; i<TAM; i++)
			soma += (long int)v[i];
		soma /= TAM;
		medias[0] = (int)soma;
		system("date +%s%3N");
	
		// Calcula a media de forma paralela
		system("date +%s%3N");
		for(i=0; i<4; i++)
		{
			vecs[i].v = &(v[i*(TAM/4)]);
			vecs[i].N = (TAM/4);
			vecs[i].soma = 0;
			pthread_create(&(threads[i]), NULL, &calc_media_local, &(vecs[i]));
		}
		medias[1] = 0;
		for(i=0; i<4; i++)
		{
			pthread_join(threads[i], NULL);
			medias[1] += vecs[i].soma;
		}
		medias[1] /= TAM;
		system("date +%s%3N");
	
		printf("Medias = %d, %d\n", medias[0], medias[1]);
		return 0;
	}
```````````````````

4. Repita o exercício anterior, mas calcule a variância do vetor ao invés da média.
`````````````````````````
	#include <stdio.h>
	#include <stdlib.h>
	#include <pthread.h>
	#include <unistd.h>
	#include <string.h>
	
	long int v[50000], soma = 0, variancia = 0, media = 0, variancia_numerador = 0, aux_variancia;
	int i;
	int parametro[30];
	    
	
	int main()
	{
		for(i = 0; i < 50000 ; i++)
		{
			v[i] = random();
		}
   
		for(i = 0; i < 50000 ; i++)
		{
			soma = v[i] + soma;
		}
		media = (soma/50000);

		for(i = 0; i < 50000 ; i++)
		{
			aux_variancia = ( v[i] - media);
			variancia = variancia_numerador + (aux_variancia)*(aux_variancia)/50000;
		}
    
		printf("Soma: %ld\n", soma); 	
		printf("Valor media: %ld\n", soma/50000); 
		printf("variancia: %ld\n", variancia); 	
		return 0;
	}

```````````````


***Questões extra somente para estudo

5. Crie um programa em C que preenche matrizes `long int A[60][60]` e `long int B[60][60]` completamente com valores aleatórios (use a função `random()`), e que calcula a soma das duas matrizes por dois métodos:

(a) De forma sequencial;



(b) De forma paralela.



Ao final do programa principal, compare os resultados obtidos pelos dois métodos.



6. Repita o exercício anterior, mas calcule o produto matricial A*B.



7. Repita o exercício anterior, mas calcule o produto da matriz `long int A[60][60]` por um escalar `long int x`.



