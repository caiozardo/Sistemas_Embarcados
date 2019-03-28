1. Considerando a biblioteca-padrão da linguagem C, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

Para abertura de arquivos: fopen

	FILE *fopen(const char *filename, const char *mode)
 
Para fechar arquivos: fclose

	int fclose(FILE *stream)



(b) Quais são as funções (e seus protótipos) para escrever em arquivos?

Função: fwrite

	size_t fwrite(const void *pointer, size_t size, size_t number_menb, FILE *stream);


(c) Quais são as funções (e seus protótipos) para ler arquivos?

Função: fread

	size_t fread(void *pointer, size_t size, size_t number_menb, FILE *stream);
	

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?

Função: fseek

	int fseek(FILE *stream, long int offset, int whence);


(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?

	stdio.h e stdlib.h	


2. O que é a norma POSIX?

	É a norma que especifica as interfaces do utilizador e do software ao sistemas operativo em 15 documentos


3. Considerando a norma POSIX, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

Para abertura de arquivos: open

	int open(const char* path, int oflag);
 
Para fechar arquivos: close

	int close(int file);


(b) Quais são as funções (e seus protótipos) para escrever em arquivos?

Função: write

	ssize_t write(int file, const void *buf, size_t nbyte);


(c) Quais são as funções (e seus protótipos) para ler arquivos?

Função: read

	ssize_t read(int file, void *buf, size_t nbyte);


(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?

Função: lseek

	off_t lseek(int file, off_t offset, int whence);



(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?

	fcntl.h, unistd.h, stdio.h, stdlib.h e sys/types.h

