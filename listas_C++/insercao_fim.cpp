/*recebe um numero e inseri ele no fim da lista*/
#include <stdio.h>
#include <stdlib.h>

struct celula{
    int chave;
    struct celula *proximo;
};


void imprime(struct celula *lst);

void insere_fim(struct celula* &lst, int numero);

int main(){
    struct celula *lista = NULL;
    int numero;
    
    printf("Entre com um numero ai:\n");
    scanf("%d", &numero);
    
    while(numero != -1){
        insere_fim(lista, numero);
        
        printf("Entre com um numero ai:\n");
        scanf("%d", &numero);
    }
    
    printf("Lista como um todo:\n");
    imprime(lista);
    
    return 0;
}

void imprime(struct celula *lst){
    struct celula *p;
    
    for(p = lst; p != NULL; p = p->proximo){
        printf("%d ", p->chave);
    }
}

void insere_fim(struct celula * &lst, int numero){
    
    struct celula *p;
    struct celula *nova = (struct celula *) malloc(sizeof(struct celula));
    
    nova->chave = numero;
    nova->proximo = NULL;
    
    if(lst == NULL){
        lst = nova;
    }else{
        p = lst;
        while(p->proximo != NULL){
            p = p->proximo;
        }
        p->proximo = nova;
    }
}