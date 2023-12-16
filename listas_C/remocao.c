#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

void insere_inicio(celula **lst, int numero);

void insere_fim(celula **lst, int numero);

void imprime(celula *lst);

void apaga(celula *lst);

void busca_R(celula **lst, int x);

int main(){
    celula *lista1 = NULL;
    celula *lista2 = NULL;
    int numero, x;
    
    printf("Entre com inteiros e digite 0 caso queira parar a insercao:\n");
    scanf("%d", &numero);
    
    while(numero != 0){
        insere_inicio(&lista1, numero);
        insere_fim(&lista2, numero);
        
        printf("Entre com inteiros e digite 0 caso queira parar a insercao:\n");
        scanf("%d", &numero);
    }
    
    printf("Insira um numero para a remocao da lista:\n");
    scanf("%d", &x);
    
    printf("Lista 1 antes da remocao:\n");
    imprime(lista1);
    
    printf("\nLista 2 antes da remocao:\n");
    imprime(lista2);
    
    
    busca_R(&lista1, x);
    busca_R(&lista2, x);
    
    printf("\nLista 1 apos a remocao de %d:\n", x);
    imprime(lista1);
    
    printf("\nLista 2 apos a remocao de %d:\n", x);
    imprime(lista2);
    
    apaga(lista1);
    apaga(lista2);
    
    return 0;
    
}

void insere_inicio(celula **lst, int numero){
    celula *nova;
    nova = (celula *) malloc(sizeof(celula));
    
    nova->chave = numero;
    nova->proximo = *lst;
    *lst = nova;
}

void insere_fim(celula **lst, int numero){
    celula *p;
    celula *nova = (celula *) malloc(sizeof(celula *));
    
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

void busca_R(celula **lst, int x){
    celula *p, *q;
    p = NULL;
    q = *lst;
    while(q != NULL && q->chave != x){
        p = q;
        q = q->proximo;
    }
    if(q != NULL){
        if(p != NULL){
            p->proximo = q->proximo;
            free(q);
        }else{
            *lst = q->proximo;
            free(q);
        }
    }
}