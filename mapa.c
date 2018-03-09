#include "colors.c"
//Cria o Mapa (Matriz 21,19)
char **criar_mapa(int altura, int largura){

    char **mapa = malloc(sizeof(char*)*altura);

    int i;
    for (i = 0; i < altura; i++) {
        mapa[i] = malloc(sizeof(char) * largura);
    }

    return mapa;
}

//Inicializa o mapa criando os detalhes do mapa
void inicializa_mapa(int altura, int largura, char **mapa){
    int i,j;
    int vertical = 186; // parede vertical
    int horizontal = 205; // parede horizontal

    int ct_sup_eqd = 201;//canto superior esquerdo
    int ct_sup_dto = 187;// canto superior direito
    int ct_inf_dto = 188;// canto inferior esquerdo
    int ct_inf_eqd = 200;// canto inferior ireito

    for(i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            mapa[i][j] = horizontal;
        }
    }

    //      -- Arrumando mapa --
    //Cantos do mapa
    mapa[0][0]  = ct_sup_eqd;
    mapa[0][18] = ct_sup_dto;
    mapa[20][0] = ct_inf_eqd;
    mapa[20][18]= ct_inf_dto;
    //parede direita e esquerda do mapa
    for(i = 1; i < 20; i++){
        mapa[i][0] = vertical;
        mapa[i][18] = vertical;
    }


    //     --Ajustando bordas--
    //Lado esquerdo
    mapa[6][0] = ct_inf_eqd;
    mapa[6][3] = ct_sup_dto;
    mapa[7][3] = vertical;
    mapa[8][3] = ct_inf_dto;
    mapa[8][0] = horizontal;
    mapa[10][0] = horizontal;
    mapa[10][3] = ct_sup_dto;
    mapa[11][3] = vertical;
    mapa[12][3] = ct_inf_dto;
    mapa[12][0] = ct_sup_eqd;

    //Lado direito
    mapa[6][18] = ct_inf_dto;
    mapa[6][15] = ct_sup_eqd;
    mapa[7][15] = vertical;
    mapa[8][15] = ct_inf_eqd;
    mapa[8][18] = horizontal;
    mapa[10][18] = horizontal;
    mapa[10][15] = ct_sup_eqd;
    mapa[11][15] = vertical;
    mapa[12][15] = ct_inf_eqd;
    mapa[12][18] = ct_sup_dto;

    //       --Ajustando linhas e colunas --
    //Ordenado em ordem crescente, linhas depois colunas

    //linhas 1 e 13
    for(i = 1; i < 18; i++){
        if(i != 9){
            mapa[1][i] = 0;
            mapa[13][i] = 0;
        }
    }
    //linha 2
    mapa[2][8] =0;
    mapa[2][10] =0;
    //linhas 3 e 19
    for(i = 1; i < 18; i++){
        mapa[3][i] = 0;
        mapa[19][i] = 0;
    }
    //linha 4
    mapa[4][6] =0;
    mapa[4][12] =0;
    //linha 5
    for(i =1; i <18; i++){
        if(i !=5 && i != 9 && i != 13){
            mapa[5][i] = 0;
        }
    }
    //linha 6
    mapa[6][8] =0;
    mapa[6][10] =0;
    mapa[6][5] = 204;
    mapa[6][13] = 185;
    //linha 7 e 11
    for(i = 0 ; i <19; i++){
        if(i!= 3 && i!= 5 && i!= 13 && i!= 15){
            mapa[7][i] =0;
            mapa[11][i] =0;
        }
    }
    //linha 8
    mapa[8][9] = 196;
    //linha 9
    for(i =0 ; i < 19; i++){
        if(i != 7 && i != 11){
            mapa[9][i] =0;
        }
    }
    //linha 9
    mapa[9][7] = vertical;
    mapa[9][11] = vertical;
    //linha 10
    mapa[8][11] = ct_sup_dto;
    mapa[10][11]= ct_inf_dto;
    //linha 12
    mapa[12][9] = 203;
    //linha 13
    mapa[13][9] = vertical;
    //linha14
    mapa[14][1]  =0;
    mapa[14][8]  =0;
    mapa[14][10] =0;
    mapa[14][14] =0;
    mapa[14][17] =0;
    mapa[14][9]  =vertical;
    mapa[14][3]  =ct_sup_dto;
    mapa[14][15] =ct_sup_eqd;
    //linha 15
    mapa[15][3]= vertical;
    mapa[15][15]= vertical;
    for(i =1; i<18;i++){
        if(i != 3 && i!= 15){
            mapa[15][i]= 0;
        }
    }
    //linha 16
    mapa[16][0] = 204;
    mapa[16][2] = 0;
    mapa[16][3] = vertical;
    mapa[16][4] = 0;
    mapa[16][6] = 0;
    mapa[16][12]= 0;
    mapa[16][14]= 0;
    mapa[16][15]= vertical;
    mapa[16][16]= 0;
    mapa[16][18]= 185;
    mapa[16][9] = 203;
    //linha 17
    for(i =1; i<18;i++){
        if(i!= 5 && i!= 9 && i!= 13){
            mapa[17][i] = 0;
        }
    }
    mapa[17][9] = vertical;
    //linha18
    mapa[18][1]  = 0;
    mapa[18][8]  = 0;
    mapa[18][10] = 0;
    mapa[18][17] = 0;
    mapa[18][9]  = vertical;
    //coluna 1 e 17
    for(i = 1; i <6; i++){
        mapa[i][1] =0;
        mapa[i][17] =0;
    }
    //coluna 4 e 14
    for(i = 1; i <20; i++){
        if(i !=18){
            mapa[i][4] =0;
            mapa[i][14] =0;
        }
    }
    //coluna 5 e 13
    mapa[16][5] = vertical;
    mapa[17][5] = vertical;
    mapa[18][5] = 202;
    for(i = 4; i < 9; i++){
        mapa[i][5] = vertical;
        mapa[i][13] = vertical;
    }
    for(i = 10; i < 13; i++){
        mapa[i][5] = vertical;
        mapa[i][13] = vertical;
    }

    mapa[6][5] = 204;
    mapa[6][13] = 185;
    //coluna 6
    for(i =8 ; i <14; i++){
        mapa[i][6] =0;
        mapa[i][12] =0;
    }
    //coluna 7
    mapa[8][7] = ct_sup_eqd;
    mapa[10][7]= ct_inf_eqd;
    //coluna 9
    mapa[0][9] = 203;
    mapa[4][9] = 203;
    mapa[5][9] = vertical;
    mapa[6][9] = vertical;
    mapa[1][9] = vertical;
    mapa[2][9] = vertical;
    //coluna 13
    mapa[16][13] = vertical;
    mapa[17][13] = vertical;
    mapa[18][13] = 202;
}

//Adiciona a bolinha onde o mapa esta zerado (nas "ruas")
void adiciiona_bolinha(int altura,int largura,char **mapa){
    int i,j;
    int bolinha = 250; // add bolinha

    //Onde for vazio preencher com as bolinhas
    for(i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            if(mapa[i][j] == 0){
                mapa[i][j] = bolinha;
            }
        }
    }

    //Ajusta sa bolinhas
    for(i =0; i < 19; i++){
        if(mapa[7][i] == -6){
            if(i != 4 && i!= 14){
                mapa[7][i] = 0;
                mapa[11][i] = 0;
            }
        }
    }
    for(i =0; i < 19; i++){
        if(mapa[9][i] == -6){
            if(i != 4 && i!= 7 && i!=11 && i!= 14){
                mapa[9][i] = 0;
            }
        }
    }
    for(i =0; i < 19; i++){
        if(mapa[12][i] == -6){
            if(i == 6 || i == 12){
                mapa[12][i] = 0;
                mapa[10][i] = 0;
                mapa[8][i] = 0;
            }
        }
    }

}

//Destro o mapa
void destroi_mapa(char **mapa) {
    int i;
    for (i = 0; i < 19; i++) {
        free(mapa[i]);
    }
    free(*mapa);
}
//Imprime o mapa quando o pacman é pego por um fantasma
void imprime_mapa(int altura,int largura,char **mapa){

    int i,j;
    for(i = 0; i< altura; i++){
        for(j = 0; j< largura; j++){

            //Adiciona as cores igual no Main
            if(mapa[i][j] == 'C'){
                foreground(RED);
                mapa[i][j] = 77;
                printf("%c",mapa[i][j]);
                mapa[i][j] = 0;
            }else if(mapa[i][j] == 77){
                foreground(RED);
                printf("%c",mapa[i][j]);
            }else if(mapa[i][j] == -6){
                //Adiciona cor as bolinhas
                foreground(WHITE);
                printf("%c",mapa[i][j]);
            }else{
                //Adiciona cor ao MAPA
                foreground(BLUE);
                printf("%c",mapa[i][j]);
            }
        }printf("\n");
    }
}
