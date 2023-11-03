#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

void insere_fim(celula **lst, int numero);

void imprime(celula *lst);

void apaga(celula *lst);

int main(){
    celula *lista = NULL;
    int numero;
    
    printf("Entre com um numero:\n");
    scanf("%d", &numero);
    
    while(numero != 0){
        insere_fim(&lista, numero);
        
        printf("Entre com um numero:\n");
        scanf("%d", &numero);
    }
    
    printf("Lista como um todo:\n");
    imprime(lista);
    
    //desalocando a lista da memoria
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