#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

void insere_inicio(celula **lst, int numero);

void imprime(celula *lst);

int main(){
    celula *lista = NULL;
    int numero;
    
    printf("Digite um numero:\n");
    scanf("%d", &numero);
    
    while(numero != -1){
        insere_inicio(&lista, numero);
        
        printf("Digite um numero:\n");
        scanf("%d", &numero);
    }
    
    printf("Lista como um todo:\n");
    imprime(lista);
}

void insere_inicio(celula **lst, int numero){
    celula *nova;
    
    nova = (celula *) malloc(sizeof(celula));
    
    nova->chave = numero;
    nova->proximo = *lst;
    *lst = nova;
}

void imprime(celula *lst){
    celula *p;
    
    for(p = lst; p != NULL; p = p->proximo){
        printf("%d ", p->chave);
    }
}