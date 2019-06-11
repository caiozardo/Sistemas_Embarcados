#include <stdio.h>      //  libs para printf e tals

#include <stdlib.h>     //   

#include <unistd.h>     //  biblioteca para sleep	

#include <GL/glut.h>    //  biblioteca opengl

#include <GL/gl.h>      //  biblioteca opengl

#include <math.h>       //  para simular uma senoide



#define COMP_MAX 720

#define ALTURA_MAX 480

#define MARG_ESQUERDA 50

#define MARG_DIREITA COMP_MAX-186

#define MARG_CIMA 450

#define MARG_BAIXO 58

#define pi 3.141592f



GLfloat buffer_s[500] = {0};  // Armazena os valores anteriores da tela

GLfloat Senoid[] = {

    MARG_ESQUERDA,200, // coordenada iniciais

    (MARG_ESQUERDA+1),200 

};

GLfloat amp = 1.0f;



GLfloat Background[] = {



    MARG_ESQUERDA,65,MARG_DIREITA,65,   50,MARG_BAIXO,50,MARG_CIMA, 

    MARG_ESQUERDA,113,MARG_DIREITA,113, 98,MARG_BAIXO,98,MARG_CIMA,

    MARG_ESQUERDA,161,MARG_DIREITA,161, 146,MARG_BAIXO,146,MARG_CIMA,

    MARG_ESQUERDA,209,MARG_DIREITA,209, 194,MARG_BAIXO,194,MARG_CIMA,

    MARG_ESQUERDA,256,MARG_DIREITA,256, 242,MARG_BAIXO,242,MARG_CIMA,

    MARG_ESQUERDA,257,MARG_DIREITA,257, 290,MARG_BAIXO,290,MARG_CIMA,

    MARG_ESQUERDA,305,MARG_DIREITA,305, 291,MARG_BAIXO,291,MARG_CIMA,

    MARG_ESQUERDA,353,MARG_DIREITA,353, 338,MARG_BAIXO,338,MARG_CIMA,

    MARG_ESQUERDA,401,MARG_DIREITA,401, 386,MARG_BAIXO,386,MARG_CIMA,

    MARG_ESQUERDA,449,MARG_DIREITA,449, 434,MARG_BAIXO,434,MARG_CIMA,

    MARG_ESQUERDA,258,MARG_DIREITA,258, 482,MARG_BAIXO,482,MARG_CIMA,

                                        530,MARG_BAIXO,530,MARG_CIMA,

                                        291,MARG_BAIXO,291,MARG_CIMA,

                                        289,MARG_BAIXO,289,MARG_CIMA

};



void back_setup() {

 // ------ Redimentionando a tela para unidades de pixels ---- // 

    glViewport(0.0f, 0.0f, COMP_MAX, ALTURA_MAX);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();   // update depois de mecher com a matriz 

    glOrtho(0, COMP_MAX, 0, ALTURA_MAX, 0, 1);  // setando os limites da tela

    glMatrixMode(GL_MODELVIEW); // default values

    glPushMatrix();

    glLoadIdentity();   //Sempre atualizar depois de setar funções de Matriz

// -----------------------------------------------------------//

}



int i = 0;



void main_loop(){



    glClearColor(0,0,0,0);  // Cor preta (nackgroung)

    glClear(GL_COLOR_BUFFER_BIT);   // resetando a tela(zera todas as linhas)



    glLineWidth(1); // Largura das linhas das linhas de escala

    glColor3f(1.0f,1.0f,1.0f);  // cor cinza atribuída ao background

    

    glEnable(GL_LINE_STIPPLE);  // habilita a pixelização de linha

        glLineStipple(1,0x8080); // padrão de pixels: 1000000010000000, repete até o término da linha

        glEnableClientState(GL_VERTEX_ARRAY);   // habilita a escrita de um  array    

            glVertexPointer(2,GL_FLOAT,0,Background); // Dimensão (x,y) | tipo | gap(0)| *coordenadas

            glDrawArrays(GL_LINES,0,50); // Número de pares coordenados (x,y) a ser escrito

        glDisableClientState(GL_VERTEX_ARRAY);  // Desabilita a escrita em array

    glDisable(GL_LINE_STIPPLE); //  Desabilita a função "stipple"

    

    //glFlush();  // sempre que chamar essa função a tela é atualizada

    //glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24);



    //------------ Essa rotina funcionou---------------

    glLineWidth(2); // Espessura da linha (3 pixels)

    //glColor3f(1.0f,1.0f,1.0f);  // cor branca

    //glEnableClientState(GL_VERTEX_ARRAY); 

    //i++;

    //Senoid[0] = MARG_ESQUERDA;

    //Senoid[2] = MARG_ESQUERDA+1;

    //amp = amp*0.85;

    /*

        OBS: As amostras são tradadas aos pares, visto que é necessário dois pontos para

        desenhar um segmento de reta. Dessa forma, sempre a primeira posição de um vetor

        será o valor da amostra no tempo "x" e a segunda será o valor de   sua amplitude 

        "y". O mesmo ocorre para outras posições de vetores com "N" posições.  Logo,  as

        posições pares representam dados de "tempo" e as posições ímpares de amplitude.

    */

    if( i == 124){

        i = 0;  

        Senoid[0] = MARG_ESQUERDA;   // Reinicia a escala de tempo para o início da tela

        Senoid[2] = MARG_ESQUERDA+1; // Escala do segundo ponto

        amp = amp*0.85;              // Atualiza a amplitude para testes de reescrita na tela

    }

    //for(i = 0; i < 125; i++){

        //teste com senoide

        Senoid[0] += 3;   // incrementa a escala de tempo simulando o incremento de "amostras" lidas

        Senoid[2] += 3;   

        

        // OBS: A frequencia abaixo está em função da taxa de amostragem

        Senoid[1] = (int)(100*amp*cos(2*pi*i/200)+250);     // Amplitude inicial

        Senoid[3] = (int)(100*amp*cos(2*pi*(i+1)/200)+250); // Amplitude "amostrada" a "x" ms depois



        // adicionando as 2 coordenadas (amostras) no buffer.

        buffer_s[i<<2] = Senoid[0];

        buffer_s[(i<<2)+1] = Senoid[1];

        buffer_s[(i<<2)+2] = Senoid[2]; 

        buffer_s[(i<<2)+3] = Senoid[3];

        

        //printf("senoid[0]: %.2f senoid[1]: %.2f senoid[2]: %.2f senoid[3]: %.2f\n",Senoid[0],Senoid[1],Senoid[2],Senoid[3]);

        //printf("senoid[1]: %.2f senoid[3]: %.2f\n",Senoid[1],Senoid[3]);

        //glBegin(GL_LINES);

        //printf("buffer[%d]: %.1f buffer[%d]: %.1f\n ", i*2,buffer_s[i*2],i*2+1, buffer_s[i*2-1]);

        glEnableClientState(GL_VERTEX_ARRAY);   // Escrita dos dados na tela

            glVertexPointer(2,GL_FLOAT,0,Senoid);   // constrói vértices a partir do vetor Senoid

            glDrawArrays(GL_LINES,0,2); // Desenha na tela as 2 amostras mais atuais.

            glVertexPointer(2,GL_FLOAT,0,buffer_s); 

            glDrawArrays(GL_LINES,0,249);   // Desenha os anteriores guardados no buffer.

        glEnableClientState(GL_VERTEX_ARRAY); 

        i++;

        //glDisableClientState(GL_VERTEX_ARRAY);

        

        usleep(10000);  // taxa de amostragem (10ms).

        glFlush();

        //}

        //glFlush();

        //i++; 

    glutPostRedisplay();    // Retorna ao inicio dessa função (Looping infinito)

    //while(1);  

}



void main(int argc, char**argv) {

    glutInit(&argc, argv);  // É possível alterar as configurações de execução pelos argv e argc

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Bufferização simples, RGB

    glutInitWindowPosition(300,100);    // Posição inicial da janela em relação ao lado esquerdo/cima

    glutInitWindowSize(COMP_MAX,ALTURA_MAX);    // Delimitando limites (escalas em pixels)

    glutCreateWindow("Osciloscope");    // Nome da janela

    back_setup();   // Configurações iniciais da janela

    glutDisplayFunc(main_loop); // função que comandará a atualização da tela

    glutMainLoop(); //Garante que a janela ficará aberta durante a execução do programa.

}