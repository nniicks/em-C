//INCLUIR DEOOIS A FUNCAO QUE INSERE ANTES DA CHAVE

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

void imprime(celula *lista);

void insere_inicio(celula **lista, int numero);

void insere_fim(celula **lista, int numero);

void insere_apos_chave(celula **lista, int numero, int chave);

int main(){
    celula *lista = NULL;
    int opc, numero, chave;
    
    do{
        printf("\n\n0 - SAIR\n1 - IMPRIME\n2 - INSERE NO INICIO\n3 - INSERE NO FIM\n4 - INSERE APOS A CHAVE\n\n");
        scanf("%d", &opc);
        
        if(opc == 1){
            imprime(lista);
        }else if(opc == 2){
            printf("Entre com um numero inteiro:\n");
            scanf("%d", &numero);
            
            insere_inicio(&lista, numero);
        }else if(opc == 3){
            printf("Entre com um numero inteiro:\n");
            scanf("%d", &numero);
            
            insere_inicio(&lista, numero);
        }else if(opc == 4){
            printf("Entre com um inteiro e com um valor de referencia:\n");
            scanf("%d %d", &numero, &chave);
            
            insere_apos_chave(&lista, numero, chave);
        }
    }while(opc != 0);
    
    return 0;
    
}

void imprime(celula *lista){
    printf("\n------ LISTA -------\n");
    while(lista != NULL){
        printf("%d\n", lista->chave);
        lista = lista->proximo;
    }
    printf("\n------ FIM LISTA -------\n");
}

void insere_inicio(celula **lista, int numero){
    celula *nova = malloc(sizeof(celula));
    
    if(nova !=  NULL){
        nova->chave = numero;
        nova->proximo = *lista;
        *lista = nova;
    }else{
        printf("Erro na alocaçao de memoria!\n");
    }
}

void insere_fim(celula **lista, int numero){
    celula *aux, *nova = malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        nova->proximo = NULL;
        
        if(*lista == NULL){
            *lista = nova;
        }else{
            aux = *lista;  //faz aux apontar para o inicio da lista
            while(aux->proximo != NULL){
                aux = aux->proximo;
            }
            aux->proximo = nova;
        }
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

void insere_apos_chave(celula **lista, int numero, int chave){
    celula *aux, *nova = malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        //caso seja o primeiro:
        if(*lista == NULL){
            nova->proximo = NULL;
            *lista = nova;
        }else{
            
            aux = *lista;
            while(aux->chave != chave && aux->proximo != NULL){
                aux = aux->proximo;
            }
            nova->proximo = aux->proximo;
            aux->proximo = nova;
        }
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}