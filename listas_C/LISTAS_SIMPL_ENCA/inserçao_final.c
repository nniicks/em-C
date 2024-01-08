/*fazendo inserçao no final de uma lista simplesmente encadeada*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

void insere_final(celula **lista, int numero);

void imprime(celula *lista);

int main(){
    celula *lista = NULL;
    int numero, tam = 0;
    
    printf("Entre com numeros inteiros e digite 0 para sair: \n");
    scanf("%d", &numero);
    
    while(numero != 0){
        tam++;
        insere_final(&lista, numero);
        
        printf("Entre com numeros inteiros e digite 0 para sair: \n");
        scanf("%d", &numero);
    }
    
    printf("\n------ LISTA: %d --------\n",tam);
    imprime(lista);
    printf("-------- FIM LISTA ---------\n");
    
    return 0;
}

void insere_final(celula **lista, int numero){
    celula *aux, *nova = malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        nova->proximo = NULL; //ja que a inserçao eh no final, o proximo eh nulo
        
        //lista esta vazia?
        if(*lista == NULL){
            //lista vazia
            *lista = nova;
            
        }else{
            //lista n esta vazia
            aux = *lista;
            while(aux->proximo != NULL){
                aux = aux->proximo;
            }
            //quando aux->proximo for nulo, significa que o aux atual eh o ultimo da lista
            aux->proximo = nova;
        }
        
    }else{
        printf("\nErro ao alocar memoria!\n");
    }
}


void imprime(celula *lista){
    
    while(lista != NULL){
        printf("%d\n", lista->chave);
        lista = lista->proximo;
    }
}