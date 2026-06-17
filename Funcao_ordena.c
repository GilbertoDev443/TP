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

////Função de Entrada dos Times
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
            i++;
            COUNT++;
        }
    }
    
    // Fechamento do Arquivo
    fclose(arq);
    
    return ;
}

//Função de Entrada dos Jogos
void lerJogos(){
    // Abertura do Arquivo para Read
    FILE *arq = fopen("jogos.txt", "r");
    
    // Confirmação para ver se o Arquivo abriu
    if(arq == NULL){
        printf("Problema ao abrir o arquivo!");
        return ;
    }   
    
    // Leitura do jogos e armazenando os dados em um vetor de struct
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
                if (strcmp(time_a, copa[i].nome) == 0){
                    // Segunda Comparação
                    for (int j = 0; j < COUNT; j++){
                        //Indentificação de qual o indice do time B
                        if (strcmp(time_b, copa[j].nome) == 0){
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
    // Fechamento do arquivo  
    fclose(arq);
    }
    
    return;
}

//Função para ordenar o vetor
void Ordena(){

// Loop para ordenação
//Variavel de controle do loop
int a;
do{
    a = 0;
    //Percorrer o vetor copa
    for (int i = COUNT - 1 ; i > 0; i--){
        //Analise se a pontuacao da direita e maior que o da esquerda
        if(copa[i].pontuacao > copa[i-1].pontuacao){
            //Troca os indices
            selecao aux = copa[i];
            copa[i] = copa[i-1];
            copa[i-1] = aux;
            a++;
        }
        //Mesma pontuacao
        else if (copa[i].pontuacao == copa[i-1].pontuacao){
            //Mesma quantidade de gols
            if (copa[i].gols == copa[i-1].gols){
                //Desampate por nome
                if (strcmp(copa[i].nome, copa[i-1].nome ) < 0){
                    selecao aux = copa[i];
                    copa[i] = copa[i-1];
                    copa[i-1] = aux;
                    a++;
                }
                //Nome de i-1 vem primerio
                else{
                    //Manter a posicao
                    continue;
                }
            }
            //Quantidade diferente de gols
            else{
                //Gols da direita maior que o da esquerda
                if(copa[i].gols > copa[i-1].gols){
                    selecao aux = copa[i];
                    copa[i] = copa[i-1];
                    copa[i-1] = aux;
                    a++;
                }
                //Gols da esquerda maior que o da direita
                else{
                    //Manter a posicao
                    continue;
                }
            }
        }
        //Pontuacao da Esquerda e maior que o da direita
        else{
            //Manter posicao
            continue;
        }
    }
}while (a > 0);

}