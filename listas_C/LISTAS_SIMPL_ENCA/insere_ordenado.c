#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

void insere_ordenado(celula **lista, int numero);

void imprime(celula *lista);

int main(){
    celula *lista = NULL;
    int numero;
    
    do{
        printf("Entre com um inteiro e digite 0 para sair:\n");
        scanf("%d", &numero);
        
        insere_ordenado(&lista, numero);
    }while(numero != 0);
    
    printf("\n--- LISTA ORDENADA ----\n");
    imprime(lista);
    
    return 0;
}

void imprime(celula *lista){
    
    while(lista != NULL){
        printf("%d\n", lista->chave);
        lista = lista->proximo;
    }
}

void insere_ordenado(celula **lista, int numero){
    celula *aux, *nova = malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        
        if(*lista == NULL){ //lista vazia
            nova->proximo = NULL;
            *lista = nova;
        }else if(nova-> chave < (*lista)->chave){ //a nova chave é menor?
            nova->proximo = *lista;
            *lista = nova;
        }else{
            aux = *lista;
            while(aux->proximo != NULL && nova->chave > aux->proximo->chave){
                aux = aux->proximo;
            }
            nova->proximo = aux->proximo;
            aux->proximo = nova;
        }
    }else{
        printf("\nErro na alocaçao de memoria!!\n");
    }
}