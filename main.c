#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "funcoes.h"
#include "mapa.h"
#include "jogador.h"
#include "colors.c"

//Define o tamanho da matriz (mapa)
#define largura 19
#define altura 21


//Removendo o Cursor piscando
CONSOLE_CURSOR_INFO cursor = {1, FALSE};

int main()
{
    //Removendo o Cursor piscando
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

    //Mapa do jogo
    char **mapa, **mapa_fantasma;

    //Variaveis auxiliares
    bool colideFantasma = false;
    int *pPacMan;
    int *pFantasma;
    int i,j;
    int vidas = 2;
    int pontos =0;
    int andar_F1 = 4;
    int andar_F2 =3;
    int andar_F3 =4;
    int andar_F4 =3;
    int tempo = 0,tempo2 =0;

    //Movimento do Pacman
    char tecla;

    //Menu principal
    iniciar();
    system("cls");

    //Animação Inicial do PacMan

    animacao();

    //Cria o mapa do jogo
    mapa = criar_mapa(altura,largura);
    mapa_fantasma = criar_mapa(altura,largura);

    //Inicializa o mapa gerando as bordas e o mapa vazio
    inicializa_mapa(altura,largura,mapa);
    inicializa_mapa(altura,largura,mapa_fantasma);

    //Adiciona as bolinhas
    adiciiona_bolinha(altura,largura,mapa);

    //Struct PacMan adicionando a posição inicial
    struct jogador pacman;
    pacman.pAltura =15;
    pacman.pLargura =9;

    //Adiciona a posiciao do PacMan ao mapa
    posicao_pacman(pacman.pAltura,pacman.pLargura,mapa);

    //Criando os fantasmas e adicionando-os ao mapa
    struct jogador fantasma1;
    fantasma1.pAltura =7;
    fantasma1.pLargura =9;
    posicao_fantasma(fantasma1.pAltura,fantasma1.pLargura,mapa_fantasma);

    struct jogador fantasma2;
    fantasma2.pAltura =9;
    fantasma2.pLargura =8;
    posicao_fantasma(fantasma2.pAltura,fantasma2.pLargura,mapa_fantasma);

    struct jogador fantasma3;
    fantasma3.pAltura =9;
    fantasma3.pLargura =9;
    posicao_fantasma(fantasma3.pAltura,fantasma3.pLargura,mapa_fantasma);

    struct jogador fantasma4;
    fantasma4.pAltura =9;
    fantasma4.pLargura =10;
    posicao_fantasma(fantasma4.pAltura,fantasma4.pLargura,mapa_fantasma);

    //Enquanto o PacMan nao comer todas as bolinhas o jogo nao acaba
    while(pontos != 1520){

        //Imprime o mapa na tela
        foreground(BLUE);
        for(i = 0; i< altura; i++){
            for(j = 0; j< largura; j++){
                 //Adiciona cor ao PACMAN
                 if(mapa[i][j] == 'C'){
                    foreground(YELLOW);
                    printf("%c",mapa[i][j]);
                 }
                 else if(mapa_fantasma[i][j] == 77){
                    //Adiciona cor aos FANTASMAS
                    if(fantasma1.pAltura == i && fantasma1.pLargura == j){
                        foreground(RED);
                        printf("M",mapa[i][j]);
                    }
                    else if(fantasma2.pAltura == i && fantasma2.pLargura ==j){
                        foreground(MARGENTA);
                        printf("M",mapa[i][j]);
                    }
                    else if(fantasma3.pAltura == i && fantasma3.pLargura ==j){
                        foreground(CYAN);
                        printf("M",mapa[i][j]);
                    }
                    else if(fantasma4.pAltura == i && fantasma4.pLargura ==j){
                        foreground(YELLOW);
                        printf("M",mapa[i][j]);
                    }
                 }
                 else if(mapa[i][j] == -6){
                    //Adiciona cor as bolinhas
                    foreground(WHITE);
                    printf("%c",mapa[i][j]);
                 }else{
                    //Adiciona cor ao MAPA
                    foreground(BLUE);
                    printf("%c",mapa[i][j]);
                 }
            }printf("\n");
        }printf("\n");
        style(RESETALL);
        printf("Score:");
        foreground(YELLOW);
        printf("%d",pontos);
        style(RESETALL);
        printf("\n\nLifes:");
        foreground(YELLOW);
        for(i =0; i < vidas; i++){
            printf("c ");
        }
        printf("\n\n\n\n\n");

        //Trata caso o usuario nao digite a tecla de movimento
        do{
            //Captura a telca e verifica se ela é corrsponde ao movimento
            tecla = getch();
            //Movimentação do PACMAN
            if(tecla == 'w' || tecla == 's' || tecla == 'a' || tecla == 'd'){

                //Caso especial em uqe o pacman esta para sair do outor lado do mapa
                if(tecla == 'a' && pacman.pAltura == 9 && pacman.pLargura == 0) {
                    pacman.pAltura = 9;
                    pacman.pLargura = 18;
                    posicao_pacman(pacman.pAltura,pacman.pLargura,mapa);
                    mapa[9][0] = 0;
                }
                else if(tecla == 'd' && pacman.pAltura == 9 && pacman.pLargura == 18) {
                    pacman.pAltura = 9;
                    pacman.pLargura = 0;
                    posicao_pacman(pacman.pAltura,pacman.pLargura,mapa);
                    mapa[9][18] = 0;
                }
                else {
                    pPacMan = movimento(pacman.pAltura,pacman.pLargura,tecla,mapa,pontos);
                    pacman.pAltura = pPacMan[0];
                    pacman.pLargura = pPacMan[1];
                    pontos = pPacMan[2];
                    //Adiciona a nova posicao do PacMan ao mapa
                    posicao_pacman(pacman.pAltura,pacman.pLargura,mapa);
                }
            }else{
                //enquanto o usuario nao digitar uma tecla permitida o cilo continuara
                tecla = 'x';
            }
        }while(tecla == 'x');

        //Tempo serve para adicioanr novos fantasmas
        //Cada vez que o ciclo é reiniciado (tempo chega no 12)
        //Um novo fantasma é adicionado (tempo2 +=1)
        if(tempo <= 12){
            //Realiza o movimento do fantasma
            pFantasma = movimento_fantasma(andar_F1,fantasma1.pAltura,fantasma1.pLargura,pacman.pAltura,pacman.pLargura,mapa_fantasma);
            fantasma1.pAltura = pFantasma[0];
            fantasma1.pLargura = pFantasma[1];
            andar_F1 = pFantasma[2];
            //Libera o fantasma 2
            if(tempo2 >0){
                if(tempo == 0 && tempo2 ==1){
                    mapa_fantasma[9][8] =0;
                    fantasma2.pAltura = 7;
                    fantasma2.pLargura = 9;
                }
                pFantasma = movimento_fantasma(andar_F2,fantasma2.pAltura,fantasma2.pLargura,pacman.pAltura,pacman.pLargura,mapa_fantasma);
                fantasma2.pAltura = pFantasma[0];
                fantasma2.pLargura = pFantasma[1];
                andar_F2 = pFantasma[2];
            }
            //Libera o fantasma 3
            if(tempo2 >1){
                if(tempo == 0 && tempo2 ==2){
                    mapa_fantasma[9][9] =0;
                    fantasma3.pAltura = 7;
                    fantasma3.pLargura = 9;
                }
                pFantasma = movimento_fantasma(andar_F3,fantasma3.pAltura,fantasma3.pLargura,pacman.pAltura,pacman.pLargura,mapa_fantasma);
                fantasma3.pAltura = pFantasma[0];
                fantasma3.pLargura = pFantasma[1];
                andar_F3 = pFantasma[2];
            }
            //Libera o fantasma 4
            if(tempo2 >2){
                if(tempo == 0 && tempo2 ==3){
                    mapa_fantasma[9][10] =0;
                    fantasma4.pAltura = 7;
                    fantasma4.pLargura = 9;
                }
                pFantasma = movimento_fantasma(andar_F4,fantasma4.pAltura,fantasma4.pLargura,pacman.pAltura,pacman.pLargura,mapa_fantasma);
                fantasma4.pAltura = pFantasma[0];
                fantasma4.pLargura = pFantasma[1];
                andar_F4 = pFantasma[2];
            }
            tempo++;
        }else{
            //Deixa os fantasmas parados
            //Para recriar o efeito do jogo original
            tempo++;
            if(tempo == 15){
                tempo = 0;
                tempo2 += 1;
            }
        }

        //Adiciona a nova posicao do Fantasma1 ao mapa
        posicao_fantasma(fantasma1.pAltura,fantasma1.pLargura,mapa_fantasma);
        //Adiciona a nova posicao do Fantasma2 ao mapa
        posicao_fantasma(fantasma2.pAltura,fantasma2.pLargura,mapa_fantasma);
        //Adiciona a nova posicao do Fantasma3 ao mapa
        posicao_fantasma(fantasma3.pAltura,fantasma3.pLargura,mapa_fantasma);
        //Adiciona a nova posicao do Fantasma4 ao mapa
        posicao_fantasma(fantasma4.pAltura,fantasma4.pLargura,mapa_fantasma);

        //Verifica se huve colisao com um fantasma
        colideFantasma = verifica_fantasma(pacman.pAltura,pacman.pLargura,mapa_fantasma,mapa,vidas,pontos);
        if(colideFantasma == true){

            //Reporta o pacman as condicoes originais
            pacman.pAltura = 15;
            pacman.pLargura =9;
            posicao_pacman(pacman.pAltura,pacman.pLargura,mapa);

            //Limpa a atual posicao do fantasma
            mapa_fantasma[fantasma1.pAltura][fantasma1.pLargura] =0;
            mapa_fantasma[fantasma2.pAltura][fantasma2.pLargura] =0;
            mapa_fantasma[fantasma3.pAltura][fantasma3.pLargura] =0;
            mapa_fantasma[fantasma4.pAltura][fantasma4.pLargura] =0;

            //reseta os fantasmas para as condicoes iniciais
            fantasma1.pAltura  =7;
            fantasma1.pLargura =9;
            andar_F1 =3;
            fantasma2.pAltura  =9;
            fantasma2.pLargura =8;
            andar_F2 =3;
            fantasma3.pAltura  =9;
            fantasma3.pLargura =9;
            andar_F3 =4;
            fantasma4.pAltura  =9;
            fantasma4.pLargura =10;
            andar_F4 =3;

            //Adiciona a posicao inicial dos fantasmas ao mapa
            posicao_fantasma(fantasma1.pAltura,fantasma1.pLargura,mapa_fantasma);
            posicao_fantasma(fantasma2.pAltura,fantasma2.pLargura,mapa_fantasma);
            posicao_fantasma(fantasma3.pAltura,fantasma3.pLargura,mapa_fantasma);
            posicao_fantasma(fantasma4.pAltura,fantasma4.pLargura,mapa_fantasma);

            //reseta o tempo
            tempo =0;
            tempo2 =0;
            vidas --;
        }

    }
    Sleep(1000);
    system("cls");
    foreground(WHITE);
    printf("\n\n\n\t\t Parabens Voce ganhou !\n\n\n\n");
    system("pause");
    adiciona_pontuacao(pontos);

    //Destroi o Mapa
    destroi_mapa(mapa);
    //Destroi vetor auxiliar
    free(pFantasma);
    free(pPacMan);

    main();

    return 0;
}
