/* Escreva um programa que cadastre vários produtos (código, nome, preço). Em seguida,
imprima uma lista com o código e nome da cada produto (tamanho máximo 50). Por último,
consulte o preço de um produto através de seu código (informado pelo usuário). Permita
que várias consultas sejam realizadas até que se digite um código igual a 0 (zero).*/

#include <stdio.h>
#define M 50
#define T 20

struct novoT{
    int codigo;
    char nome[M];
    float preco;
};

void cadastro(novoT *p, int *quant);

void imprimir(novoT *pont, int *quant);

void busca(novoT *q, int *quant);

int main(){
    novoT lista[T];
    int n;
    
    printf("Informe quantos produtos voce deseja cadastrar:\n");
    scanf("%d", &n);
    
    cadastro(lista, &n);
    
    imprimir(lista, &n);
    
    busca(lista, &n);
    
}

void cadastro(novoT *p, int *N){
    novoT *pontAux; // pra deixar p fixo na primeira posicao do vetor
    
    for(pontAux = p; pontAux < p + *N; pontAux++){
        printf("Informe o codido do produto:\n");
        scanf("%d", &pontAux->codigo);
        getchar();
        
        printf("Informe o nome do produto:\n");
        scanf("%s", pontAux->nome);
        getchar();
        
        printf("Informe o preco do produto:\n");
        scanf("%f", &pontAux->preco);
        getchar();
    }
    
}

void imprimir(novoT *pont, int *quant){
    novoT *i; // o ponteiro pont ficar fixo na primeira posicoa do vetor lista
    
    printf("----- LISTA DOS PRODUTOS CADASTRADOS -----");
    for(i = pont; i < pont + *quant; i++){
        printf("\n");
        printf("Nome: %s\n", i->nome);
        printf("Codigo: %d\n", i->codigo);
        printf("Preco: %.2f\n", i->preco);
    }
    
}

void busca(novoT *q, int *quant){
    novoT *qAux; // pra q ficar fixo na primeira posicao do vetor lista
    int codInformado;
    
    printf("Informe o codido de um produto para busca-lo na lista. Informe 0 caso queira para a busca:\n");
    scanf("%d", &codInformado);
    
    while(codInformado != 0){
        for(qAux = q; qAux < q + *quant; qAux++){
            if(qAux->codigo == codInformado){
                printf("Preco do produto de codigo %d eh: %.2f\n\n", qAux->codigo, qAux->preco);
            }
        }
         printf("Informe o codido de um produto para busca-lo na lista. Informe 0 caso queira para a busca:\n");
         scanf("%d", &codInformado);
    }
    
    
}