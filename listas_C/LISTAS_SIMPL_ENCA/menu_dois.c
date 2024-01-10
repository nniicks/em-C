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

void imprime(Lista lista);

void insere_inicio(Lista *lista, int numero);

void insere_fim(Lista *lista, int numero);

void insere_apos_chave(Lista *lista, int numero, int chave);

int main(){
    Lista lista;
    int opc, numero, chave;
    
    criar_lista(&lista);
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
            
            insere_fim(&lista, numero);
        }else if(opc == 4){
            printf("Entre com um inteiro e com um valor de referencia:\n");
            scanf("%d %d", &numero, &chave);
            
            insere_apos_chave(&lista, numero, chave);
        }
    }while(opc != 0);
    
    return 0;
    
}

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

void imprime(Lista lista){
    celula *aux = lista.inicio;
    
    printf("\n------ LISTA: %d -------\n", lista.tam);
    while(aux != NULL){
        printf("%d\n", aux->chave);
        aux = aux->proximo;
    }
    printf("\n------ FIM LISTA -------\n");
}

void insere_inicio(Lista *lista, int numero){
    celula *nova = malloc(sizeof(celula));
    
    if(nova !=  NULL){
        nova->chave = numero;
        nova->proximo = lista->inicio; //o proximo da nova celula tem que apontar para o incio da lista
        lista->inicio = nova;  //atualiza o inicio
        lista->tam++;
    }else{
        printf("Erro na alocaçao de memoria!\n");
    }
}

void insere_fim(Lista *lista, int numero){
    celula *aux, *nova = malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        nova->proximo = NULL; //como a inserçao eh sempre no final, o proximo sempre sera NULL
        
        if(lista->inicio == NULL){//lista esta vazia?
            lista->inicio = nova;
        }else{
            aux = lista->inicio;  //faz aux apontar para o inicio da lista
            while(aux->proximo != NULL){
                aux = aux->proximo;
            }
            aux->proximo = nova;
        }
        lista->tam++;
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

void insere_apos_chave(Lista *lista, int numero, int chave){
    celula *aux, *nova = malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        //caso seja o primeiro:
        if(lista->inicio == NULL){
            nova->proximo = NULL;
            lista->inicio = nova;  //atualiza o inicio da lista
        }else{
            
            aux = lista->inicio;
            while(aux->chave != chave && aux->proximo != NULL){
                aux = aux->proximo;
            }
            nova->proximo = aux->proximo;
            aux->proximo = nova;
        }
        lista->tam++;
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}