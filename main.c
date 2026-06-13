#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct selecao{
    char nome[50];
    int pontuacao;
    int gols;
}selecao;

selecao copa[48];

void saida(){
    // Abertura do Arquivo para Write
    FILE *arq = fopen("classificacao.txt", "w");
    
    // Print visual
    for (int i = 0; i < 40; i++){
        fprintf(arq, "=");
    }
    fprintf(arq, "\n\n");

    fprintf(arq, "CLASSIFICACAO FINAL DA COPA DO MUNDO\n\n");

    for (int i = 0; i < 40; i++){
        fprintf(arq, "=");
    }
    fprintf(arq, "\n\n");

    fprintf(arq, "PODIO DOS CAMPEOES:\n\n");

    // Print da colocação
    // Atualmente o 1,2,3 Lugar esta no Indíce 0,1,2 respectivamente do vetor "copa"
    for(int i = 0; i < 3; i++){
        fprintf(arq, "%do Lugar: %s - %d Pontos (%d Gols)\n", i+1, copa[i].nome, copa[i].pontuacao, copa[i].gols);
    }

    //Fechamento do Arquivo
    fclose(arq);
}

int main(){




    return 0;
}