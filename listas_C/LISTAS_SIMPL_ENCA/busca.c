#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct cel{
    int chave;
    char nome[MAX];
    struct cel *proximo;
}celula;

void imprime(celula *lista);

void insere_final(celula **lista, int numero, char nome[]);

celula* busca(celula **lista, int chave);

int main(){
    celula *aux, *lista = NULL;
    int numero;
    char nome[MAX];
    
    printf("Entre com inteiros e digite 0 para sair:\n");
    scanf("%d", &numero);
    getchar();
    
    while(numero != 0){
        printf("Digite o nome da pessoa:\n");
        scanf("%49[^\n]", nome);
        
        getchar();
        
        insere_final(&lista, numero, nome);
        printf("Entre com inteiros e digite 0 para sair:\n");
        scanf("%d", &numero);
        getchar();
    }
    
    
    imprime(lista);
    
    printf("\nDigite um numero para ser buscado na lista:\n");
    scanf("%d", &numero);
    
    aux = busca(&lista, numero);
    if(aux == NULL){
        printf("A chave %d nao foi encontrada na lista!!\n", numero);
    }else{
        printf("A chave %d pertence a pessoa de nome: %s\n", aux->chave, aux->nome);
    }
    
    return 0;
}

void imprime(celula *lista){
    
    printf("\n---------- LISTA ----------\n");
    while(lista != NULL){
        printf("Nome: %s, chave associada: %d\n", lista->nome, lista->chave);
        lista = lista->proximo;
    }
}

void insere_final(celula **lista, int numero, char nome[]){
    celula *aux, *nova = malloc(sizeof(celula));
    
    if(aux != NULL){
        nova->chave = numero;
        strcpy(nova->nome, nome);
        nova->proximo = NULL;
        
        if(*lista == NULL){
            *lista = nova;
        }else{
            aux = *lista;
            while(aux->proximo != NULL){
                aux = aux->proximo;
            }
            aux->proximo = nova;
        }
    }else{
        printf("Erro na alocaçao de memoria!\n");
    }
}

celula* busca(celula **lista, int chave){
    celula *aux, *chave_buscada = NULL;
    
    aux = *lista;
    while(aux != NULL && aux->chave != chave){
        aux = aux->proximo;
    }
    
    if(aux != NULL){ //chave foi encontrada
        chave_buscada = aux;
    }
    
    return chave_buscada;
}