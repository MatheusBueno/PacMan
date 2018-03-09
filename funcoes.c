#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "colors.c"

struct pontos{
    int colocacao;
    int pontuac;
    char nome[3];
};

//Inicia o menu principal
void iniciar(){
    int op;
    do{
        system("cls");
        printf("  --- Pac-Man ---\n\n");
        foreground(MARGENTA);
        printf(" 1 - Novo jogo\n");
        foreground(GREEN);
        printf(" 2 - Como jogar\n");
        foreground(YELLOW);
        printf(" 3 - Pontuacao\n");
        foreground(RED);
        printf(" 0 - Sair\n\n");
        foreground(BLUE);
        printf(" Faca sua escolha : ");
        foreground(WHITE);
        scanf("%d",&op);

        switch(op){
        case 1:
            return;
        break;
        case 2:
            system("cls");
            printf("--  COMO JOGAR  --\n\n");
            printf("Movimente o PacMan com as teclas:\n\n");
            foreground(BLUE);
            printf("w - Para cima\n");
            foreground(RED);
            printf("s - Para baixo\n");
            foreground(GREEN);
            printf("d - Para direita\n");
            foreground(YELLOW);
            printf("a - Para esquerda\n\n");
            foreground(MARGENTA);
            printf("Os melhores jogadores aparecerao no Ranking !!\n");
            printf("Boa sorte  ");
            foreground(YELLOW);
            printf("%c\n\n",1);
            style(RESETALL);
            system("pause");
        break;
        case 3:
            pontuacao();
        break;
        case 0:
            printf("\nFim de Jogo !!");
            exit(1);
        break;
        default:
            system("cls");
            printf("\n\n\n  Opcao invalida\n\n\n");
            system("pause");
        }
    }while(op != 1);
}

//Animação inicial do jogo
void animacao(){

    int i,j,tempo =25;

    //Animacao de ida
    for(i =0; i < tempo; i++){
        //Delay
        Sleep(90);
        system("cls");
        printf("\n\n");

        for (j = 0; j <= i; j++){
            printf(" ");
        }
        foreground(YELLOW);
        printf("c");
        j =0;

    }
    system("cls");
    Sleep(700);

    //Animacao de volta
    for(i = tempo; i >0; i--){
        Sleep(70);
        system("cls");
        printf("\n\n");

        for (j = 0; j <= i; j++){
            printf(" ");
        }
        foreground(YELLOW);
        printf("c");
        foreground(RED);
        printf(" M");
        foreground(MARGENTA);
        printf(" M");
        j =0;

    }
    system("cls");
    Sleep(700);

      //Animacao de ida 2
    for(i =0; i < tempo; i++){
        //Delay
        Sleep(40);
        system("cls");
        printf("\n\n");

        for (j = 0; j <= i; j++){
            printf(" ");
        }
        foreground(YELLOW);
        printf("C");
        foreground(RED);
        printf(" m");
        foreground(MARGENTA);
        printf(" m");
        j =0;

    }
    system("cls");
    Sleep(500);
    //Reseta a cor
    style(RESETALL);
    printf("\n\n\n\n        Iniciando o jogo !!");
    Sleep(600);
    system("cls");
}

//Printa a Pontuação
void pontuacao(){

    system("cls");
    foreground(YELLOW);
    printf(" ----------- PONTUACAO  -----------\n\n");
    int colocacao,pontos;
    char nome[20];
    FILE *arq_pontos;
    arq_pontos = fopen("pontuacao.txt", "r+");

    if( arq_pontos == NULL ){
        printf("Erro ao abrir pontuacao");
    }else{

        while( fscanf(arq_pontos,"%d %d %s\n",&colocacao,&pontos,nome) != EOF){

            foreground(GREEN);
            if(colocacao ==0){
                printf("   %d :",1);
            }else{
                printf("   %d :",colocacao);
            }
            foreground(CYAN);
            printf(" %d .............",pontos);
            foreground(RED);
            printf(" %s\n",nome);
        }
    }
    fclose(arq_pontos);
    style(RESETALL);
    printf("\n");
    system("pause");
}

//vERIFICA SE O NOME DIGITADO TEM 3 LETRAS
int verifica_nome(char *nome){
    int letras = strlen(nome);
    if(letras == 3){return 1;}
    else{return 0;}
}

//Verefica e adiciona o jogador ao rank
void adiciona_pontuacao(int score){

    system("cls");
    FILE *arq_pontos;
    arq_pontos = fopen("pontuacao.txt", "r+");
    int ponto =0;
    int colocacao =0;
    int encontrou =0;
    int antigo_pontos,futuro_pontos,linha =0;
    int nome_ok;
    char nome[3],antigo_nome[3],futuro_nome[3];
    char novo_nome[3];
    char teste[3];
    struct pontos str_ponto[9];
    int i=0;
    char coe[3];

    if( arq_pontos == NULL ){
        printf("Erro ao abrir pontuacao");
    }else{
        while( fscanf(arq_pontos,"%d %d %s\n",&colocacao,&ponto,nome) != EOF){
                //Adiciona os dados do txt a uma struct para tratar os dados
                str_ponto[i].colocacao = colocacao;
                str_ponto[i].pontuac = ponto;
                strcpy(str_ponto[i].nome, nome);
                i++;
        }
        int numero = 1;
        for(i =1; i<=9; i++){
            str_ponto[i].colocacao = 1+numero;
            numero++;
        }
        //Verifica se o jogador esta no rancking
        for (i =0; i<9; i++){
            if(score >= str_ponto[i].pontuac){
                do{
                    fflush(stdin);
                    printf(" ---  Parabens. Voce esta no ranking, %d posicao !!\n",i+1);
                    foreground(BLUE);
                    printf("\n\n Digite seu nome, 3 caracteres: ");
                    foreground(YELLOW);
                    gets(coe);
                    nome_ok = verifica_nome(coe);
                    if(nome_ok == 0){
                        style(RESETALL);
                        printf("\n\nDigite tres letras.\n\n");
                        system("pause");
                        system("cls");
                        strcpy(coe,"");
                    }
                }while(nome_ok == 0);
                break;
             }
        }
        //Organiza a Structr da pontuação mais alta para a mai sbaixa
        //O ultimo jogador do ranking é retirado
        for (i =0; i<9; i++){
            if(score >= str_ponto[i].pontuac){
                if(encontrou == 0){
                    antigo_pontos = str_ponto[i].pontuac;
                    strcpy(teste,str_ponto[i].nome);
                    str_ponto[i].pontuac = score;
                    strcpy(str_ponto[i].nome, coe);
                    encontrou =1;
                }else{
                    futuro_pontos = str_ponto[i].pontuac;
                    strcpy(futuro_nome, str_ponto[i].nome);
                    str_ponto[i].pontuac = antigo_pontos;
                    strcpy(str_ponto[i].nome, teste);
                    strcpy(teste ,"");
                    antigo_pontos = futuro_pontos;
                    strcpy(teste, futuro_nome);
                }
             }
        }
        //Adiciona a struct já organizada ao arquivo pontos.txt
        fseek(arq_pontos,0,SEEK_SET);
        for(i =0; i<9; i++){
            fprintf(arq_pontos,"%d ",str_ponto[i].colocacao);
            if(str_ponto[i].pontuac == 0){
                fprintf(arq_pontos,"0000 ");
            }else if(str_ponto[i].pontuac < 100){
                fprintf(arq_pontos,"00%d ",str_ponto[i].pontuac);
            }else if(str_ponto[i].pontuac < 1000){
                fprintf(arq_pontos,"0%d ",str_ponto[i].pontuac);
            }else{
                fprintf(arq_pontos,"%d ",str_ponto[i].pontuac);
            }
            strupr(str_ponto[i].nome);
            fprintf(arq_pontos,"%s\n",str_ponto[i].nome);
        }
    }

    fclose(arq_pontos);
    style(RESETALL);
    printf("\n");
    system("pause");
}
//Finaliza o jogo
void fim_jogo(){

        foreground(RED);
        printf("\n\n\n\n\n       Game Over !!\n\n\n\n\n ");
        style(RESETALL);
        system("pause");
}
