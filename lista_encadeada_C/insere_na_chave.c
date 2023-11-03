/*a funcao busca_insere recebe dois inteiros x e y e uma lista
e insere uma nova celula com chave y nessa lista antes da primeira
que contiver x; se nenhuma celula contiver x, a nova celula é inserida
no final da lista*/
#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

void insere_fim(celula **lst, int numero);

void imprime(celula *lst);

void apaga(celula *lst);

void busca_insere(celula **lst, int y, int x);

int main(){
    celula *lista = NULL;
    int numero, x, y;
    
    printf("Entre com inteiros e digite 0 caso queira parar a insercao:\n");
    scanf("%d", &numero);
    
    while(numero != 0){
        insere_fim(&lista, numero);
        
        printf("Entre com inteiros e digite 0 caso queira parar a insercao:\n");
        scanf("%d", &numero);
    }
    
    printf("Entre com um inteiro:\n");
    scanf("%d", &y);
    printf("Entre com uma chave:\n");
    scanf("%d", &x);
    
    printf("Lista antes da insercao de %d antes da chave %d:\n", y, x);
    imprime(lista);
    
    busca_insere(&lista, y, x);
    
    printf("\nLista apos a insercao de %d antes da chave %d:\n", y, x);
    imprime(lista);
    
    apaga(lista);
    
    return 0;
    
}

void insere_fim(celula **lst, int numero){
    celula *p;
    celula *nova = (celula *) malloc(sizeof(celula));
    
    nova->chave = numero;
    nova->proximo = NULL;
    
    if(*lst == NULL){
        *lst = nova;
    }else{
        p = *lst;
        while(p->proximo != NULL){
            p = p->proximo;
        }
        p->proximo = nova;
    }
}

void imprime(celula *lst){
    celula *p;
    
    for(p = lst; p != NULL; p = p->proximo){
        printf("%d ", p->chave);
    }
}

void apaga(celula *lst){
    celula *p;
    
    while(lst != NULL){
        p = lst;
        lst = lst->proximo;
        free(p);
    }
}

void busca_insere(celula **lst, int y, int x){
    celula *p, *q, *nova;
    nova = (celula *) malloc(sizeof(celula));
    nova->chave = y;
    p = NULL;
    q = *lst;
    while(q != NULL && q->chave != x){
        p = q;
        q = q->proximo;
    }
    nova->proximo = q;
    if(p != NULL){
        p->proximo = nova;
    }else{
        *lst = nova;
    }
}