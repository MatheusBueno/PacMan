#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct pontos{
    int colocacao;
    int pontuac;
    char nome[3];
};

//Verefica e adiciona o jogador ao rank
void adiciona_pontuacao(int score){

    system("cls");
    FILE *arq_pontos;
    arq_pontos = fopen("pontuacao.txt", "r+");

    unsigned int colocacao=0,ponto=0;
    char nome[3];
    int ok =0;

    //char buffer[100];

    //fgets(buffer,100,arq_pontos);

    //printf("%s\n", buffer);

    setbuf(arq_pontos,NULL);
    fscanf(arq_pontos, "%i %i %s", &colocacao, &ponto, nome);

    printf("%i\n", colocacao);
    printf("%i\n", ponto);
    printf("%s\n", nome);

    fclose(arq_pontos);

    /*
    int colocacao=0,ponto=0,encontrou =0;
    char nome[3];

    struct pontos str_ponto[9];

    if( arq_pontos == NULL ){
        printf("Erro ao abrir pontuacao");
    }else{
        int i=0;
        while( fscanf(arq_pontos,"%d %d %s\n",&colocacao,&ponto,nome) != EOF){
                str_ponto[i].colocacao = colocacao;
                str_ponto[i].pontuac = ponto;
                strcpy(str_ponto[i].nome, nome);
                printf("%d",str_ponto[i].colocacao);
                printf(" %i",ponto);
                printf(" %s\n",str_ponto[i].nome);
                i++;
        }
    }
    */
}

int main () {

    adiciona_pontuacao(800);

    return 0;
}
