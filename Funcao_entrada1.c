#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criação de um novo tipo
typedef struct{
    char nome[50];
    int pontuacao;
    int gols;
}selecao;

// Criação de um vetor struct
selecao copa[48];
//Variável indicando o tamnho maximo do vetor copa
int TAM = 48;
//Contadaor de Times
int COUNT = 0;

void lerNomeselecao(){
    // Abertura do Arquivo para Read
    FILE *arq = fopen("selecao.txt", "r");
    
    // Confirmação para ver se o Aqrquivo abriu
    if(arq == NULL){
        printf("Problema ao abrir o arquivo!");
        return ;
    }   
    
    // Leitura do nome das seleções em EOF e colocando elas em um vetor de struct
    else{
        int i=0;
        while(fscanf(arq, "%s", copa[i].nome) != EOF ){
            printf("Li: %s\n", copa[i].nome);
            i++;
            COUNT++;
        }
    }
    
    // Fechamento do Arquivo
    fclose(arq);
    
    return ;
}