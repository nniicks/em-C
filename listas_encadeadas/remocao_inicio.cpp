#include <stdio.h>
#include <stdlib.h>

struct celula{
    int chave;
    struct celula *proximo;
};

void leitura(struct celula* &lst, int numero);

void imprime(struct celula *lst);

void remocao(struct celula* &lst);

int main(){
    struct celula *lista = NULL;
    int numero;
    
    printf("Entre com um numero:\n");
    scanf("%d", &numero);
    
    while(numero != -1){
        leitura(lista, numero);
        
        printf("Entre com um numero inteiro:\n");
        scanf("%d", &numero);
    }
    
    printf("Lista antes da remocao do primeiro elemento:\n");
    imprime(lista);
    
    remocao(lista);
    printf("\nLista depois da remocao do primeiro elemento:\n");
    imprime(lista);
    
    return 0;
    
}

void imprime(struct celula *lst){
    struct celula *p;
    
    for(p = lst; p != NULL; p = p->proximo){
        printf("%d ", p->chave);
    }
}

void leitura(struct celula* &lst, int numero){
    struct celula *nova;
    
    nova = (struct celula *) malloc(sizeof(struct celula));
    
    nova->chave = numero;
    nova->proximo = lst;
    lst = nova;
}

void remocao(struct celula* &lst){
    
    if(lst != NULL){
        
        struct celula *p = lst;
        
        lst = lst->proximo;
        free(p);
    }
}