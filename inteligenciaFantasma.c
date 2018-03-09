#include <math.h>

//Calcula a distancia do fantasmas e o pacman
float distancia(int ghostY,int ghostX,int pacY, int pacX) {
    float caminho;
    int dx;
    int dy;
    dx = (pacX -ghostX)*(pacX -ghostX);
    dy = (pacY -ghostY)*(pacY -ghostY);
    caminho = sqrt(dx + dy);
    return caminho;
}
//O fantasma seguira a menor distancia ate o PacMan
int *movimento_fantasma(int andar,int y,int x,int pacY, int pacX,char **mapa_fantasma) {
    int *posicao = malloc(sizeof(int)* 3);

    float dist_p_cima;
    float dist_p_baixo;
    float dist_p_direita;
    float dist_p_esquerda;

    //andar 1 = CIMA
    //andar 2 = BAIXO
    //andar 3 = DIREITA
    //andar 4 = ESQUERDA
    mapa_fantasma[y][x] =0;



    //Verificando linha 1
    if(y ==1){

        if(x == 1){
            dist_p_baixo = distancia(2,1,pacY,pacX);
            dist_p_direita = distancia(1,2,pacY,pacX);
            if(dist_p_baixo < dist_p_direita){andar =2;}
            else{andar =3;}
        }
        else if(x == 4){
            dist_p_baixo = distancia(2,4,pacY,pacX);
            dist_p_esquerda = distancia(1,3,pacY,pacX);
            dist_p_direita = distancia(1,5,pacY,pacX);
            if((dist_p_baixo < dist_p_direita) && (dist_p_baixo < dist_p_esquerda)){andar =2;}
            else if((dist_p_direita < dist_p_baixo) && (dist_p_direita < dist_p_esquerda)) {andar =3;}
            else{andar =4;}
        }
        else if(x == 8){
            dist_p_baixo = distancia(2,8,pacY,pacX);
            dist_p_esquerda = distancia(1,7,pacY,pacX);
            if(dist_p_baixo < dist_p_esquerda){andar =2;}
            else{andar =4;}
        }
        else if(x == 10){
            dist_p_baixo = distancia(2,10,pacY,pacX);
            dist_p_direita = distancia(1,11,pacY,pacX);
            if(dist_p_baixo < dist_p_direita){andar =2;}
            else{andar =3;}
        }
        else if(x == 14){
            dist_p_baixo = distancia(2,14,pacY,pacX);
            dist_p_esquerda = distancia(1,13,pacY,pacX);
            dist_p_direita = distancia(1,15,pacY,pacX);
            if((dist_p_baixo < dist_p_direita) && (dist_p_baixo < dist_p_esquerda)){andar =2;}
            else if((dist_p_direita < dist_p_baixo) && (dist_p_direita < dist_p_esquerda)) {andar =3;}
            else{andar =4;}
        }
        else if(x == 17){
            dist_p_baixo = distancia(2,17,pacY,pacX);
            dist_p_esquerda = distancia(1,16,pacY,pacX);
            if(dist_p_baixo < dist_p_esquerda){andar =2;}
            else{andar =4;}
        }
    }

    //Verificando linha 3
    if(y ==3){

        if(x == 1){
            dist_p_baixo = distancia(4,1,pacY,pacX);
            dist_p_cima = distancia(2,1,pacY,pacX);
            dist_p_direita = distancia(3,2,pacY,pacX);
            if((dist_p_baixo < dist_p_direita) && (dist_p_baixo < dist_p_cima)){andar =2;}
            else if((dist_p_direita < dist_p_baixo) && (dist_p_direita < dist_p_cima)) {andar =3;}
            else{andar =1;}
        }
        else if(x == 4){
            dist_p_cima = distancia(2,4,pacY,pacX);
            dist_p_baixo = distancia(4,4,pacY,pacX);
            dist_p_esquerda = distancia(3,3,pacY,pacX);
            dist_p_direita = distancia(3,5,pacY,pacX);
            if((dist_p_baixo < dist_p_cima) && (dist_p_baixo < dist_p_direita) && (dist_p_baixo < dist_p_esquerda)){andar =2;}
            else if((dist_p_direita < dist_p_cima) && (dist_p_direita < dist_p_baixo) && (dist_p_direita < dist_p_esquerda)) {andar =3;}
            else if((dist_p_esquerda < dist_p_cima) && (dist_p_esquerda < dist_p_baixo) && (dist_p_esquerda < dist_p_direita)) {andar =4;}
            else{andar =1;}
        }
        else if(x == 6){
            dist_p_baixo = distancia(4,6,pacY,pacX);
            dist_p_esquerda = distancia(3,5,pacY,pacX);
            dist_p_direita = distancia(3,7,pacY,pacX);
            if((dist_p_baixo < dist_p_direita) && (dist_p_baixo < dist_p_esquerda)){andar =2;}
            else if((dist_p_direita < dist_p_baixo) && (dist_p_direita < dist_p_esquerda)) {andar =3;}
            else{andar =4;}
        }
        else if(x == 8){
            dist_p_cima = distancia(2,8,pacY,pacX);
            dist_p_esquerda = distancia(3,7,pacY,pacX);
            dist_p_direita = distancia(3,9,pacY,pacX);
            if((dist_p_cima < dist_p_direita) && (dist_p_cima < dist_p_esquerda)){andar =1;}
            else if((dist_p_direita < dist_p_cima) && (dist_p_direita < dist_p_esquerda)) {andar =3;}
            else{andar =4;}
        }
        else if(x == 10){
            dist_p_cima = distancia(2,10,pacY,pacX);
            dist_p_esquerda = distancia(3,9,pacY,pacX);
            dist_p_direita = distancia(3,11,pacY,pacX);
            if((dist_p_cima < dist_p_direita) && (dist_p_cima < dist_p_esquerda)){andar =1;}
            else if((dist_p_direita < dist_p_cima) && (dist_p_direita < dist_p_esquerda)) {andar =3;}
            else{andar =4;}
        }
        else if(x == 12){
            dist_p_baixo = distancia(4,12,pacY,pacX);
            dist_p_esquerda = distancia(3,11,pacY,pacX);
            dist_p_direita = distancia(3,13,pacY,pacX);
            if((dist_p_baixo < dist_p_direita) && (dist_p_baixo < dist_p_esquerda)){andar =2;}
            else if((dist_p_direita < dist_p_baixo) && (dist_p_direita < dist_p_esquerda)) {andar =3;}
            else{andar =4;}
        }
        else if(x == 14){
            dist_p_cima = distancia(2,14,pacY,pacX);
            dist_p_baixo = distancia(4,14,pacY,pacX);
            dist_p_esquerda = distancia(3,13,pacY,pacX);
            dist_p_direita = distancia(3,15,pacY,pacX);
            if((dist_p_baixo < dist_p_cima) && (dist_p_baixo < dist_p_direita) && (dist_p_baixo < dist_p_esquerda)){andar =2;}
            else if((dist_p_direita < dist_p_cima) && (dist_p_direita < dist_p_baixo) && (dist_p_direita < dist_p_esquerda)) {andar =3;}
            else if((dist_p_esquerda < dist_p_cima) && (dist_p_esquerda < dist_p_baixo) && (dist_p_esquerda < dist_p_direita)) {andar =4;}
            else{andar =1;}
        }
        else if(x == 17){
            dist_p_baixo = distancia(4,17,pacY,pacX);
            dist_p_cima = distancia(2,17,pacY,pacX);
            dist_p_esquerda= distancia(3,16,pacY,pacX);
            if((dist_p_baixo < dist_p_esquerda) && (dist_p_baixo < dist_p_cima)){andar =2;}
            else if((dist_p_esquerda < dist_p_baixo) && (dist_p_esquerda < dist_p_cima)) {andar =4;}
            else{andar =1;}
        }
    }

    //Verificando linha 5
    if(y ==5){

        if(x == 1){
            dist_p_cima = distancia(4,1,pacY,pacX);
            dist_p_direita = distancia(5,2,pacY,pacX);
            if(dist_p_cima < dist_p_direita){andar =1;}
            else{andar =3;}
        }
        else if(x == 4){
            dist_p_cima = distancia(4,4,pacY,pacX);
            dist_p_baixo = distancia(6,4,pacY,pacX);
            dist_p_esquerda = distancia(5,3,pacY,pacX);
            if((dist_p_cima < dist_p_baixo) && (dist_p_cima < dist_p_esquerda)){andar =1;}
            else if((dist_p_baixo < dist_p_cima) && (dist_p_baixo < dist_p_esquerda)) {andar =2;}
            else{andar =4;}
        }
        else if(x == 6){
            dist_p_cima = distancia(4,6,pacY,pacX);
            dist_p_direita = distancia(5,7,pacY,pacX);
            if(dist_p_cima < dist_p_direita){andar =1;}
            else{andar =3;}
        }
        else if(x == 8){
            dist_p_baixo = distancia(6,8,pacY,pacX);
            dist_p_esquerda = distancia(5,7,pacY,pacX);
            if(dist_p_baixo < dist_p_esquerda){andar =2;}
            else{andar =4;}
        }
        else if(x == 10){
            dist_p_baixo = distancia(6,10,pacY,pacX);
            dist_p_direita = distancia(5,11,pacY,pacX);
            if(dist_p_baixo < dist_p_direita){andar =2;}
            else{andar =3;}
        }
        else if(x == 12){
            dist_p_cima = distancia(4,12,pacY,pacX);
            dist_p_esquerda = distancia(5,11,pacY,pacX);
            if(dist_p_cima < dist_p_esquerda){andar =1;}
            else{andar =4;}
        }
        else if(x == 14){
            dist_p_cima = distancia(4,14,pacY,pacX);
            dist_p_baixo = distancia(6,14,pacY,pacX);
            dist_p_direita = distancia(5,15,pacY,pacX);
            if((dist_p_cima < dist_p_baixo) && (dist_p_cima < dist_p_direita)){andar =1;}
            else if((dist_p_baixo < dist_p_cima) && (dist_p_baixo < dist_p_direita)) {andar =2;}
            else{andar =3;}
        }
        else if(x == 17){
            dist_p_cima = distancia(4,17,pacY,pacX);
            dist_p_esquerda = distancia(5,16,pacY,pacX);
            if(dist_p_cima < dist_p_esquerda){andar =1;}
            else{andar =4;}
        }
    }

    //Verificando linha 7
    if(y ==7){

        if(x == 6){
            dist_p_baixo = distancia(8,6,pacY,pacX);
            dist_p_direita = distancia(7,7,pacY,pacX);
            if(dist_p_baixo < dist_p_direita){andar =2;}
            else{andar =3;}
        }
        else if(x == 8){
            dist_p_cima = distancia(6,8,pacY,pacX);
            dist_p_direita = distancia(7,9,pacY,pacX);
            dist_p_esquerda = distancia(7,7,pacY,pacX);
            if((dist_p_cima < dist_p_direita) && (dist_p_cima < dist_p_esquerda)){andar =1;}
            else if((dist_p_direita < dist_p_cima) && (dist_p_direita < dist_p_esquerda)) {andar =3;}
            else{andar =4;}
        }
        else if(x == 10){
            dist_p_cima = distancia(6,10,pacY,pacX);
            dist_p_direita = distancia(7,11,pacY,pacX);
            dist_p_esquerda = distancia(7,9,pacY,pacX);
            if((dist_p_cima < dist_p_direita) && (dist_p_cima < dist_p_esquerda)){andar =1;}
            else if((dist_p_direita < dist_p_cima) && (dist_p_direita < dist_p_esquerda)) {andar =3;}
            else{andar =4;}
        }
        else if(x == 12){
            dist_p_baixo = distancia(8,12,pacY,pacX);
            dist_p_esquerda= distancia(7,11,pacY,pacX);
            if(dist_p_esquerda < dist_p_baixo){andar =4;}
            else{andar =2;}
        }
    }

    //Verificando linha 9
    if(y ==9){

        if(x == 4){
            dist_p_baixo = distancia(10,4,pacY,pacX);
            dist_p_cima = distancia(8,4,pacY,pacX);
            dist_p_direita = distancia(9,5,pacY,pacX);
            if((dist_p_baixo < dist_p_direita) && (dist_p_baixo < dist_p_cima)){andar =2;}
            else if((dist_p_direita < dist_p_baixo) && (dist_p_direita < dist_p_cima)) {andar =3;}
            else{andar =1;}
        }
        else if(x == 6){
            dist_p_baixo = distancia(10,6,pacY,pacX);
            dist_p_cima = distancia(8,6,pacY,pacX);
            dist_p_esquerda= distancia(9,5,pacY,pacX);
            if((dist_p_baixo < dist_p_esquerda) && (dist_p_baixo < dist_p_cima)){andar =2;}
            else if((dist_p_esquerda < dist_p_baixo) && (dist_p_esquerda < dist_p_cima)) {andar =4;}
            else{andar =1;}
        }
        else if(x == 12){
            dist_p_baixo = distancia(10,12,pacY,pacX);
            dist_p_cima = distancia(8,12,pacY,pacX);
            dist_p_direita = distancia(9,13,pacY,pacX);
            if((dist_p_baixo < dist_p_direita) && (dist_p_baixo < dist_p_cima)){andar =2;}
            else if((dist_p_direita < dist_p_baixo) && (dist_p_direita < dist_p_cima)) {andar =3;}
            else {andar =1;}
        }
        else if(x == 14){
            dist_p_baixo = distancia(10,14,pacY,pacX);
            dist_p_cima = distancia(8,14,pacY,pacX);
            dist_p_esquerda = distancia(9,13,pacY,pacX);
            if((dist_p_baixo < dist_p_esquerda) && (dist_p_baixo < dist_p_cima)){andar =2;}
            else if((dist_p_esquerda < dist_p_baixo) && (dist_p_esquerda < dist_p_cima)) {andar =4;}
            else{andar =1;}
        }
    }

    //Verificando linha 11
    if(y ==11){

        if(x == 6){
            dist_p_baixo = distancia(12,6,pacY,pacX);
            dist_p_cima = distancia(10,6,pacY,pacX);
            dist_p_direita = distancia(11,7,pacY,pacX);
            if((dist_p_baixo < dist_p_direita) && (dist_p_baixo < dist_p_cima)){andar =2;}
            else if((dist_p_direita < dist_p_baixo) && (dist_p_direita < dist_p_cima)) {andar =3;}
            else{andar =1;}
        }
        else if(x == 12){

            dist_p_baixo = distancia(12,12,pacY,pacX);
            dist_p_cima = distancia(10,12,pacY,pacX);
            dist_p_esquerda= distancia(11,11,pacY,pacX);
            if((dist_p_baixo < dist_p_esquerda) && (dist_p_baixo < dist_p_cima)){andar =2;}
            else if((dist_p_esquerda < dist_p_baixo) && (dist_p_esquerda < dist_p_cima)) {andar =4;}
            else{andar =1;}
        }
    }

    //Verificando linha 13
    if(y ==13){

        if(x == 1){
            dist_p_baixo = distancia(14,1,pacY,pacX);
            dist_p_direita = distancia(13,2,pacY,pacX);
            if(dist_p_baixo < dist_p_direita){andar =2;}
            else{andar =3;}
        }
        else if(x == 4){
            dist_p_cima = distancia(12,4,pacY,pacX);
            dist_p_baixo = distancia(14,4,pacY,pacX);
            dist_p_esquerda = distancia(13,3,pacY,pacX);
            dist_p_direita = distancia(13,5,pacY,pacX);
            if((dist_p_baixo < dist_p_cima) && (dist_p_baixo < dist_p_direita) && (dist_p_baixo < dist_p_esquerda)){andar =2;}
            else if((dist_p_direita < dist_p_cima) && (dist_p_direita < dist_p_baixo) && (dist_p_direita < dist_p_esquerda)) {andar =3;}
            else if((dist_p_esquerda < dist_p_cima) && (dist_p_esquerda < dist_p_baixo) && (dist_p_esquerda < dist_p_direita)) {andar =4;}
             else if((dist_p_cima < dist_p_baixo) && (dist_p_cima < dist_p_direita) && (dist_p_cima < dist_p_esquerda)) {andar =1;}
        }
        else if(x == 6){
            dist_p_cima = distancia(12,6,pacY,pacX);
            dist_p_esquerda = distancia(13,5,pacY,pacX);
            dist_p_direita = distancia(13,7,pacY,pacX);
            if((dist_p_cima < dist_p_direita) && (dist_p_cima < dist_p_esquerda)){andar =1;}
            else if((dist_p_direita < dist_p_cima) && (dist_p_direita < dist_p_esquerda)) {andar =3;}
            else{andar =4;}
        }
        else if(x == 8){
            dist_p_baixo = distancia(14,8,pacY,pacX);
            dist_p_esquerda = distancia(13,7,pacY,pacX);
            if(dist_p_baixo < dist_p_esquerda){andar =2;}
            else{andar =4;}
        }
        else if(x == 10){
            dist_p_baixo = distancia(14,10,pacY,pacX);
            dist_p_direita = distancia(13,11,pacY,pacX);
            if(dist_p_baixo < dist_p_direita){andar =2;}
            else{andar =3;}
        }
        else if(x == 12){
            dist_p_cima = distancia(12,12,pacY,pacX);
            dist_p_esquerda = distancia(13,11,pacY,pacX);
            dist_p_direita = distancia(13,13,pacY,pacX);
            if((dist_p_cima < dist_p_direita) && (dist_p_cima < dist_p_esquerda)){andar =1;}
            else if((dist_p_direita < dist_p_cima) && (dist_p_direita < dist_p_esquerda)) {andar =3;}
            else{andar =4;}
        }
        else if(x == 14){
            dist_p_cima = distancia(12,14,pacY,pacX);
            dist_p_baixo = distancia(14,14,pacY,pacX);
            dist_p_esquerda = distancia(13,13,pacY,pacX);
            dist_p_direita = distancia(13,15,pacY,pacX);
            if((dist_p_baixo < dist_p_cima) && (dist_p_baixo < dist_p_direita) && (dist_p_baixo < dist_p_esquerda)){andar =2;}
            else if((dist_p_direita < dist_p_cima) && (dist_p_direita < dist_p_baixo) && (dist_p_direita < dist_p_esquerda)) {andar =3;}
            else if((dist_p_esquerda < dist_p_cima) && (dist_p_esquerda < dist_p_baixo) && (dist_p_esquerda < dist_p_direita)) {andar =4;}
            else{andar =1;}
        }
        else if(x == 17){
            dist_p_baixo = distancia(14,17,pacY,pacX);
            dist_p_esquerda = distancia(13,16,pacY,pacX);
            if(dist_p_baixo < dist_p_esquerda){andar =2;}
            else{andar =4;}
        }
    }

    //Verificando linha 15
    if(y ==15){

        if(x == 1){
            dist_p_cima = distancia(14,1,pacY,pacX);
            dist_p_direita = distancia(15,2,pacY,pacX);
            if(dist_p_cima < dist_p_direita){andar =1;}
            else{andar =3;}
        }
        if(x == 2){
            dist_p_baixo = distancia(16,2,pacY,pacX);
            dist_p_esquerda = distancia(15,1,pacY,pacX);
            if(dist_p_baixo < dist_p_esquerda){andar =2;}
            else{andar =4;}
        }
        else if(x == 4){
            dist_p_cima = distancia(14,4,pacY,pacX);
            dist_p_baixo = distancia(16,4,pacY,pacX);
            dist_p_direita = distancia(15,5,pacY,pacX);
            if((dist_p_cima < dist_p_baixo) && (dist_p_cima < dist_p_direita)){andar =1;}
            else if((dist_p_baixo < dist_p_cima) && (dist_p_baixo < dist_p_direita)) {andar =2;}
            else{andar =3;}
        }
        else if(x == 6){
            dist_p_esquerda = distancia(15,5,pacY,pacX);
            dist_p_baixo = distancia(16,6,pacY,pacX);
            dist_p_direita = distancia(15,7,pacY,pacX);
            if((dist_p_esquerda < dist_p_baixo) && (dist_p_esquerda < dist_p_direita)){andar =4;}
            else if((dist_p_baixo < dist_p_esquerda) && (dist_p_baixo < dist_p_direita)) {andar =2;}
            else{andar =3;}
        }
        else if(x == 8){
            dist_p_esquerda = distancia(15,7,pacY,pacX);
            dist_p_cima = distancia(14,8,pacY,pacX);
            dist_p_direita = distancia(15,9,pacY,pacX);
            if((dist_p_esquerda < dist_p_cima) && (dist_p_esquerda < dist_p_direita)){andar =4;}
            else if((dist_p_cima < dist_p_esquerda) && (dist_p_cima < dist_p_direita)) {andar =1;}
            else{andar =3;}
        }
        else if(x == 10){
            dist_p_esquerda = distancia(15,9,pacY,pacX);
            dist_p_cima = distancia(14,10,pacY,pacX);
            dist_p_direita = distancia(15,11,pacY,pacX);
            if((dist_p_esquerda < dist_p_cima) && (dist_p_esquerda < dist_p_direita)){andar =4;}
            else if((dist_p_cima < dist_p_esquerda) && (dist_p_cima < dist_p_direita)) {andar =1;}
            else{andar =3;}
        }
        else if(x == 12){
            dist_p_esquerda = distancia(15,11,pacY,pacX);
            dist_p_baixo = distancia(16,12,pacY,pacX);
            dist_p_direita = distancia(15,13,pacY,pacX);
            if((dist_p_esquerda < dist_p_baixo) && (dist_p_esquerda < dist_p_direita)){andar =4;}
            else if((dist_p_baixo < dist_p_esquerda) && (dist_p_baixo < dist_p_direita)) {andar =2;}
            else{andar =3;}
        }
        else if(x == 14){
            dist_p_cima = distancia(14,14,pacY,pacX);
            dist_p_baixo = distancia(16,14,pacY,pacX);
            dist_p_esquerda = distancia(15,13,pacY,pacX);
            if((dist_p_cima < dist_p_baixo) && (dist_p_cima < dist_p_esquerda)){andar =1;}
            else if((dist_p_baixo < dist_p_cima) && (dist_p_baixo < dist_p_esquerda)) {andar =2;}
            else{andar =4;}
        }
        else if(x == 16){
            dist_p_baixo = distancia(16,16,pacY,pacX);
            dist_p_direita = distancia(15,15,pacY,pacX);
            if(dist_p_baixo < dist_p_direita){andar =2;}
            else{andar =3;}
        }
        else if(x == 17){
            dist_p_cima = distancia(14,17,pacY,pacX);
            dist_p_esquerda = distancia(15,16,pacY,pacX);
            if(dist_p_cima < dist_p_esquerda){andar =1;}
            else{andar =4;}
        }
    }

    //Verificando linha 17
    if(y ==17){

        if(x == 1){
            dist_p_baixo = distancia(18,1,pacY,pacX);
            dist_p_direita = distancia(17,2,pacY,pacX);
            if(dist_p_baixo < dist_p_direita){andar =2;}
            else{andar =3;}
        }
        else if(x == 2){
            dist_p_esquerda = distancia(17,1,pacY,pacX);
            dist_p_cima = distancia(16,2,pacY,pacX);
            dist_p_direita = distancia(17,3,pacY,pacX);
            if((dist_p_esquerda < dist_p_cima) && (dist_p_esquerda < dist_p_direita)){andar =4;}
            else if((dist_p_cima < dist_p_esquerda) && (dist_p_cima < dist_p_direita)) {andar =1;}
            else{andar =3;}
        }
        else if(x == 4){
            dist_p_cima = distancia(16,4,pacY,pacX);
            dist_p_esquerda = distancia(17,3,pacY,pacX);
            if(dist_p_cima < dist_p_direita){andar =1;}
            else{andar =4;}
        }
        else if(x == 6){
            dist_p_cima = distancia(16,6,pacY,pacX);
            dist_p_direita = distancia(17,7,pacY,pacX);
            if(dist_p_cima < dist_p_direita){andar =1;}
            else{andar =3;}
        }
        else if(x == 8){
            dist_p_baixo = distancia(18,8,pacY,pacX);
            dist_p_esquerda = distancia(17,7,pacY,pacX);
            if(dist_p_baixo < dist_p_esquerda){andar =2;}
            else{andar =4;}
        }
        else if(x == 10){
            dist_p_baixo = distancia(18,10,pacY,pacX);
            dist_p_direita = distancia(17,11,pacY,pacX);
            if(dist_p_baixo < dist_p_direita){andar =2;}
            else{andar =3;}
        }
        else if(x == 12){
            dist_p_cima = distancia(16,12,pacY,pacX);
            dist_p_esquerda = distancia(17,11,pacY,pacX);
            if(dist_p_cima < dist_p_esquerda){andar =1;}
            else{andar =4;}
        }
        else if(x == 14){
            dist_p_cima = distancia(16,14,pacY,pacX);
            dist_p_direita = distancia(17,15,pacY,pacX);
            if(dist_p_cima < dist_p_direita){andar =1;}
            else{andar =3;}
        }
        else if(x == 16){
            dist_p_esquerda = distancia(17,15,pacY,pacX);
            dist_p_cima = distancia(16,16,pacY,pacX);
            dist_p_direita = distancia(17,17,pacY,pacX);
            if((dist_p_esquerda < dist_p_cima) && (dist_p_esquerda < dist_p_direita)){andar =4;}
            else if((dist_p_cima < dist_p_esquerda) && (dist_p_cima < dist_p_direita)) {andar =1;}
            else{andar =3;}
        }
        else if(x == 17){
            dist_p_cima = distancia(4,17,pacY,pacX);
            dist_p_esquerda = distancia(5,16,pacY,pacX);
            if(dist_p_cima < dist_p_esquerda){andar =1;}
            else{andar =4;}
        }
    }

    //Verificando linha 19
    if(y ==19){

        if(x == 1){
            dist_p_cima = distancia(18,1,pacY,pacX);
            dist_p_direita = distancia(19,2,pacY,pacX);
            if(dist_p_cima < dist_p_direita){andar =1;}
            else{andar =3;}
        }
        else if(x == 8){
            dist_p_esquerda = distancia(19,7,pacY,pacX);
            dist_p_cima = distancia(18,8,pacY,pacX);
            dist_p_direita = distancia(19,9,pacY,pacX);
            if((dist_p_esquerda < dist_p_cima) && (dist_p_esquerda < dist_p_direita)){andar =4;}
            else if((dist_p_cima < dist_p_esquerda) && (dist_p_cima < dist_p_direita)) {andar =1;}
            else{andar =3;}
        }
        else if(x == 10){
            dist_p_esquerda = distancia(19,9,pacY,pacX);
            dist_p_cima = distancia(18,10,pacY,pacX);
            dist_p_direita = distancia(19,11,pacY,pacX);
            if((dist_p_esquerda < dist_p_cima) && (dist_p_esquerda < dist_p_direita)){andar =4;}
            else if((dist_p_cima < dist_p_esquerda) && (dist_p_cima < dist_p_direita)) {andar =1;}
            else{andar =3;}
        }
        else if(x == 17){
            dist_p_cima = distancia(18,17,pacY,pacX);
            dist_p_esquerda = distancia(19,16,pacY,pacX);
            if(dist_p_cima < dist_p_esquerda){andar =1;}
            else{andar =4;}
        }
    }

    //Anda para CIMA
    if(andar == 1){
        posicao[0] = y-1;
        posicao[1] = x;
        posicao[2] = 1;
        return posicao;

    }
    //Anda para BAIXO
    else if(andar == 2){
        posicao[0] = y+1;
        posicao[1] = x;
        posicao[2] = 2;
        return posicao;

    }
    //Anda para DIREITA
    else if(andar == 3){
        posicao[0] = y;
        posicao[1] = x+1;
        posicao[2] = 3;
        return posicao;

    }
    //Anda para ESQUERDA
    else if(andar == 4){
        posicao[0] = y;
        posicao[1] = x-1;
        posicao[2] = 4;
        return posicao;
    }

}
