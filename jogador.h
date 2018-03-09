//Usado por causa da funcao do tipo bool
#include <stdbool.h>

struct jogador{
    int pAltura;
    int pLargura;
};
void posicao_pacman(int y, int x,char **mapa);

void posicao_fantasma(int y, int x,char **mapa);

int *movimento(int x,int y,char tecla,char **mapa, int pontos);

bool verifica_fantasma(int y,int x,char **mapa,char ** mapaFim,int vidas,int pontos);
