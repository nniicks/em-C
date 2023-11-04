#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

void insere_fim(celula **lst, int numero);

int quant_chaves(celula *lst);

int main(){
    celula *lista = NULL;
    int numero;
    
    printf("Entre com inteiros e digite 0 caso queira parar com a insercao:\n");
    scanf("%d", &numero);
    
    while(numero != 0){
        insere_fim(&lista, numero);
        
        printf("Entre com inteiros e digite 0 caso queira parar com a insercao:\n");
        scanf("%d", &numero);
    }
    
    printf("A quantidade de chaves que essa lista possui eh: %d", quant_chaves(lista));
    
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

int quant_chaves(celula *lst){
    celula *p;
    int contador = 0;
    
    for(p = lst; p != NULL; p = p->proximo){
        contador++;
    }
    
    return contador;
}