#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct cel{
    int chave;
    char nome[MAX];
    struct cel *proximo;
}celula;

typedef struct{
    celula *inicio;
}Lista;

void criar_lista(Lista *lista);

void imprime(Lista lista);

void insere_final(Lista *lista, int numero, char nome[]);

celula* busca(Lista *lista, int chave);

int main(){
    celula *aux;
    Lista lista;
    int numero;
    char nome[MAX];
    
    criar_lista(&lista);
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

void criar_lista(Lista *lista){
    lista->inicio = NULL;
}

void imprime(Lista lista){
    celula *aux = lista.inicio;
    
    printf("\n---------- LISTA ----------\n");
    while(aux != NULL){
        printf("Nome: %s, chave associada: %d\n", aux->nome, aux->chave);
        aux = aux->proximo;
    }
    
}

void insere_final(Lista *lista, int numero, char nome[]){
    celula *aux, *nova = malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        strcpy(nova->nome, nome);
        nova->proximo = NULL;
        
        if(lista->inicio == NULL){
            lista->inicio = nova;
        }else{
            aux = lista->inicio;
            while(aux->proximo != NULL){
                aux = aux->proximo;
            }
            aux->proximo = nova;
        }
    }else{
        printf("Erro na alocaçao de memoria!\n");
    }
}

celula* busca(Lista *lista, int chave){
    celula *aux, *chave_buscada = NULL;
    
    aux = lista->inicio;
    while(aux != NULL && aux->chave != chave){
        aux = aux->proximo;
    }

    if(aux != NULL){ //chave foi encontrada
        chave_buscada = aux;
    }
    
    return chave_buscada;
}