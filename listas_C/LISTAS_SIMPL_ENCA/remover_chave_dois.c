#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

typedef struct{
    celula *inicio;
}Lista;

void criar_lista(Lista *lista);

void insere_inicio(Lista *lista, int numero);

void imprime(Lista lista);

celula* remover_celula(Lista *lista, int chave);

int main(){
    celula *aux;
    Lista lista;
    int numero, chave, opc;
    
    criar_lista(&lista);
    do{
        printf("\n0 - Inserir no inicio\n1 - Remover celula\n2 - Imprimir\n3 - Sair\n");
        scanf("%d", &opc);
        
        if(opc == 0){
            printf("\nEntre com um numero:\n");
            scanf("%d", &numero);
            insere_inicio(&lista, numero);
        }else if(opc == 1){
            printf("\nEntre com uma chave:\n");
            scanf("%d", &chave);
            aux = remover_celula(&lista, chave);
            
            if(aux == NULL){
                printf("A chave %d nao foi encontrada na lista!", chave);
            }else{
                printf("Chave %d removida com sucesso da lista!", chave);
            }
            
        }else if(opc == 2){
            imprime(lista);
        }
    }while(opc != 3);
    
    return 0;
}

void criar_lista(Lista *lista){
    lista->inicio = NULL;
}

void imprime(Lista lista){
    celula *aux = lista.inicio;
    
    printf("\n----- LISTA -----\n");
    while(aux != NULL){
        printf("%d\n", aux->chave);
        aux = aux->proximo;
    }
}

void insere_inicio(Lista *lista, int numero){
    celula *nova = malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        nova->proximo = lista->inicio;
        lista->inicio = nova;
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

celula* remover_celula(Lista *lista, int chave){
    celula *aux, *remover = NULL;
    
    //lista nao é vazia?
    if(lista->inicio != NULL){
        if(lista->inicio->chave == chave){ //chave esta na 1° celula
            remover = lista->inicio; //faz remover apontar para o inicio da lista
            lista->inicio = remover->proximo; //atualiza o inicio da lista
        }else{ //chave nao esta na 1° celula da lista
            aux = lista->inicio;
            while(aux->proximo != NULL && aux->proximo->chave != chave){
                aux = aux->proximo;
            }
            //o proximo existe?se sim, a chave da proxima celula eh a chave a ser removida
            if(aux->proximo != NULL){
                remover = aux->proximo;
                aux->proximo = remover->proximo; //faz o aux->proximo ser o que vem logo a pos a celula que foi removida
            }
        }
    }
    
    return remover;
}