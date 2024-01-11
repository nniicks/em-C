#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

void imprime(celula *lista);

void insere_inicio(celula **lista, int numero);

void copiar_lista(celula **listaA, celula **listaB);

int main(){
    celula *listaA, *listaB, *listaC;
    int numero;
    listaA = NULL;
    listaB = NULL;
    listaC = NULL;
    
    printf("Insira inteiros na lista A e digite 0 para sair:\n");
    scanf("%d", &numero);
    while(numero != 0){
        insere_inicio(&listaA, numero);
        printf("Insira inteiros na lista A e digite 0 para sair:\n");
        scanf("%d", &numero);
    }
    
    printf("Insira inteiros na lista B e digite 0 para sair:\n");
    scanf("%d", &numero);
    while(numero != 0){
        insere_inicio(&listaB, numero);
        printf("Insira inteiros na lista A e digite 0 para sair:\n");
        scanf("%d", &numero);
    }
    
    printf("\n------ LISTA A ------\n");
    imprime(listaA);
    printf("\n------ LISTA B ------\n");
    imprime(listaB);
    
    copiar_lista(&listaA, &listaC);
    copiar_lista(&listaB, &listaC);
    
    printf("\n------ LISTA RESULTANTE DA COPIA ------\n");
    imprime(listaC);
    
    return 0;
    
}

void imprime(celula *lista){
    
    while(lista != NULL){
        printf("%d ", lista->chave);
        lista = lista->proximo;
    }
}

void insere_inicio(celula **lista, int numero){
    celula *nova = malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        nova->proximo = *lista;
        *lista = nova;
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

void copiar_lista(celula **listaA, celula **listaB){
    celula *aux = *listaA;
    
    while(aux != NULL){
        insere_inicio(listaB, aux->chave);
        aux = aux->proximo;
    }
}