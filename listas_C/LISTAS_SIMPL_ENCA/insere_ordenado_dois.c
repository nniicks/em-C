#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

typedef struct{
    celula *inicio;
    int tam;
}Lista;

void criar_lista(Lista *lista);

void insere_ordenado(Lista *lista, int numero);

void imprime(Lista lista);

int main(){
    Lista lista;
    int numero;
    
    criar_lista(&lista);
    
    do{
        printf("Entre com um inteiro e digite 0 para sair:\n");
        scanf("%d", &numero);
        
        insere_ordenado(&lista, numero);
    }while(numero != 0);
    
   
    imprime(lista);
    
    return 0;
}

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

void imprime(Lista lista){
    celula *aux = lista.inicio;
    
     printf("\n--- LISTA ORDENADA: %d ELEMENTOS ----\n", lista.tam);
    while(aux != NULL){
        printf("%d\n", aux->chave);
        aux = aux->proximo;
    }
}

void insere_ordenado(Lista *lista, int numero){
    celula *aux, *nova = malloc(sizeof(celula ));
    
    if(nova != NULL){
        nova->chave = numero;
        
        if(lista->inicio == NULL){ //lista vazia
            nova->proximo = NULL;
            lista->inicio = nova;
        }else if(nova-> chave < lista->inicio->chave){ //a nova chave é menor?
            nova->proximo = lista->inicio;
            lista->inicio = nova;
        }else{
            aux = lista->inicio;
            while(aux->proximo != NULL && nova->chave > aux->proximo->chave){
                aux = aux->proximo;
            }
            nova->proximo = aux->proximo;
            aux->proximo = nova;
        }
        lista->tam++;
    }else{
        printf("\nNao foi possivel fazer a aloçao de memoria!\n");
    }
}