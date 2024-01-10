#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

void insere_inicio(celula **lista, int numero);

void imprime(celula *lista);

celula* remover_celula(celula **lista, int chave);

int main(){
    celula *aux, *lista = NULL;
    int numero, chave, opc;
    
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

void imprime(celula *lista){
    printf("\n----- LISTA -----\n");
    while(lista != NULL){
        printf("%d\n", lista->chave);
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

celula* remover_celula(celula **lista, int chave){
    celula *aux, *remover = NULL;
    
    //lista nao é vazia?
    if(*lista != NULL){
        if((*lista)->chave == chave){ //chave esta na 1° celula
            remover = *lista; //faz remover apontar para o inicio da lista
            *lista = remover->proximo; //atualiza o inicio da lista
        }else{ //chave nao esta na 1° celula da lista
            aux = *lista;
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