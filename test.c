#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    int pontuacao;
    int gols;
}selecao;

selecao copa[3];

int main(){
    
    strcpy(copa[0].nome, "Brasil");
    copa[0].pontuacao = 3;
    copa[0].gols = 20;

    strcpy(copa[1].nome, "Argentina");
    copa[1].pontuacao = 2;
    copa[1].gols = 10;

    strcpy(copa[2].nome, "Chile");
    copa[2].pontuacao = 1;
    copa[2].gols = 5;
    
    
    for (int i = 0; i < 40; i++){
        printf("=");
    }
    printf("\n\n");

    printf("CLASSIFICACAO FINAL DA COPA DO MUNDO\n\n");

    for (int i = 0; i < 40; i++){
        printf("=");
    }
    printf("\n\n");

    printf("PODIO DOS CAMPEOES:\n\n");

    for(int i = 0; i < 3; i++){
        printf("%do Lugar: %s - %d Pontos (%d Gols)\n", i+1, copa[i].nome, copa[i].pontuacao, copa[i].gols);
    }
    return 0;
}