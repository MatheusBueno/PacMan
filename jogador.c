//Usado por causa da funcao do tipo bool
#include <stdbool.h>
#include "colors.c"
#include "funcoes.h"

//Adiciona a posicao do PacMan ao mapa
void posicao_pacman(int y,int x, char **mapa){
    mapa[y][x] = 'C';
}

//Realiza o movimento do PacMan
int *movimento(int y,int x,char tecla, char ** mapa, int pontos){

    int *posicao = malloc(sizeof(int)* 3);
    posicao[2] = pontos;

    //Caso seja uma posicao vazia ou uma bolinha o PacMan pode andar
    //Onde o PacMan passar sera zerado o valor da casa, assim comendo as bolinhas
    //Caso seja uma parede ele retorna a mesma posicao, assim não havendo movimento
    switch(tecla){
    //Movimento para cima
    case 'w':
        mapa[y][x] = 0;
        y -= 1;
        if(mapa[y][x] == -6 ||mapa[y][x] == 0){
            if(mapa[y][x] == -6){
                posicao[2] += 10;
            }
            posicao[0] = y;
            posicao[1] = x;
            return posicao;
        }else{
            posicao[0] = y+1;
            posicao[1] = x;
            return posicao;
        }
    break;
    //Movimento para baixo
    case 's':
        mapa[y][x] = 0;
        y += 1;
         if(mapa[y][x] == -6 ||mapa[y][x] == 0){
            if(mapa[y][x] == -6){
                posicao[2] += 10;
            }
            posicao[0] = y;
            posicao[1] = x;
            return posicao;
        }else{
            posicao[0] = y-1;
            posicao[1] = x;
            return posicao;
        }
    break;
    //Movimento para Direita
    case 'd':
        mapa[y][x] = 0;
        x += 1;
         if(mapa[y][x] == -6 || mapa[y][x] == 0){
            if(mapa[y][x] == -6){
                posicao[2] += 10;
            }
            posicao[0] = y;
            posicao[1] = x;
            return posicao;
        }else{
            posicao[0] = y;
            posicao[1] = x-1;
            return posicao;
        }
    break;
    //Movimento para baixo
    case 'a':
        mapa[y][x] = 0;
        x -= 1;
        if(mapa[y][x] == -6 ||mapa[y][x] == 0){
           if(mapa[y][x] == -6){
                posicao[2] += 10;
            }
            posicao[0] = y;
            posicao[1] = x;
            return posicao;
        }else{
            posicao[0] = y;
            posicao[1] = x+1;
            return posicao;
        }
     break;
    }
}

//Posicao do fantasma no mapaFantasma
void posicao_fantasma(int y,int x, char **mapa){
    mapa[y][x] = 'M';
}

//Verifica se houve colisao com um fantasma
bool verifica_fantasma(int y,int x, char **mapa,char ** mapaFim,int vidas,int pontos){

    if(mapa[y][x] == 77 || mapa[y-1][x] == 77 || mapa[y+1][x] == 77 || mapa[y][x+1] == 77 || mapa[y][x-1] == 77 ){

        Sleep(300);
        system("cls");
        Sleep(600);
        imprime_mapa(21,19,mapaFim);
        Sleep(700);
        system("cls");
        imprime_mapa(21,19,mapaFim);
        Sleep(300);
        system("cls");

        if(vidas != 0){
            return 1;
        }else{
            destroi_mapa(mapa);
            destroi_mapa(mapaFim);

            fim_jogo();
            adiciona_pontuacao(pontos);
            main();
        }
    }else{
        return 0;
    }
}
