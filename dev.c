#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct selecao{
    char nome[50];
    int pontuacao;
    int gols;
}selecao;

selecao copa[48];


void lerNomeselecao(){
  /**
   * a primeira comparacao do if "if(arq==NULL)" null e para caso o ponteiro nao apontar para canto nenhum, ele fica com null na memoria ai a funcao ja encerra
   * o return e para encerrar a funcao
   * while e para ler as selecoes e armazenar ela no vetor copa
   *  */  
FILE *arq;
arq = fopen("selecoes.txt","r");
if(arq==NULL){
    printf("Problema ao abrir o arquivo!");
    return ;
}else{
    int i=0;
    while(fscanf(arq, "%s", copa[i].nome) != EOF ){
        i++;
    }
}
fclose(arq);
return ;
}
/**void lerPlacar(){
FILE *arq;
arq = fopen("jogos.txt","r");
if(arq==NULL){
    printf("Problema ao abrir o arquivo!");
    return ;
}else{
    int i=0;
    selecao nomeA[50],nomeB[50];
    while(fscanf(arq, "%s %d %d %s", copa[i].nome) != EOF ){
        i++;
    }
}
fclose(arq);
return ;
}
*/








int main(){



    return 0;
}