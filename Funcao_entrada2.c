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

void lerJogos(){
    // Abertura do Arquivo para Read
    FILE *arq = fopen("jogos.txt", "r");
    
    // Confirmação para ver se o Aqrquivo abriu
    if(arq == NULL){
        printf("Problema ao abrir o arquivo!");
        return ;
    }   
    
    // Leitura do jogos em EOF e armazenando os daos em um vetor de struct
    else{
        char time_a[50];
        int time_ga = 0;
        char time_b[50];
        int time_gb = 0;
        
        //Primeira leitura para comparar se os dois times estão na variavel copa.nome
        while (fscanf(arq,"%s %d x %d %s", time_a, &time_ga, &time_gb, time_b) == 4){
            // Primeira comparação
            for (int i = 0;i < COUNT; i++){
                //Indentificação de qual o indice do time A
                if (time_a == copa[i].nome){
                    // Segunda Comparação
                    for (int j = 0; j < COUNT; j++){
                        //Indentificação de qual o indice do time B
                        if (time_b == copa[i].nome){
                            //Time A ganhou
                            if(time_ga > time_gb){
                                copa[i].pontuacao += 3;
                            }
                            //Time B ganhou
                            else if (time_gb > time_ga){
                                copa[j].pontuacao += 3;
                            }
                            //Empate
                            else{
                                copa[i].pontuacao += 1;
                                copa[j].pontuacao += 1;
                            }
                            //Adição dos gols do time A e B
                            copa[i].gols += time_ga;
                            copa[j].gols += time_gb;
                        }
                         //Se o Time B não está no arquivo selecao.txt
                        else{
                            continue;
                        }
                    }
                }
                //Se o Time A não está no arquivo selecao.txt
                else{
                    continue;
                }
            }
        }
        
    }
    
    return;
}

