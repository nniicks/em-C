/*Escreva uma funcao para retornar o ponteiro que aponta para a primeira ocorrencia de uma chave
x, caso esta exista em uma lista encadeada p ou NULL caso contrario.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    char nome[50];
    struct cel *proximo;
}celula;

void insere_fim(celula **lst, int numero);

celula *busca(celula *lst, int chave);

void apaga(celula *lst);

int main(){
    celula *lista = NULL, *p;
    int numero, chave;
    
    
    printf("Entre com inteiros e digite 0 caso queira parar com a insercao:\n");
    scanf("%d", &numero);
    
    while(numero != 0){
        insere_fim(&lista, numero);
        
        printf("Entre com inteiros e digite 0 caso queira parar com a insercao:\n");
        scanf("%d", &numero);
    }
    
    printf("Entre com uma chave (numero inteiro):\n");
    scanf("%d", &chave);
    
    p = busca(lista, chave);
    if(p == NULL){
        printf("Chave nao foi encontrada na lista:\n");
    }else{
        printf("Nome conitdo na chave %d: %s", chave, p->nome);
    }
    
    apaga(lista);
    
    return 0;
}

void insere_fim(celula **lst, int numero){
    celula *p;
    celula *nova = (celula *) malloc(sizeof(celula));
    
    nova->chave = numero;
    nova->proximo = NULL;
    printf("Digite o nome:\n");
    scanf("%s",nova->nome);
    
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

celula *busca(celula *lst, int chave){
    celula *p;
    p = lst;
    while(p != NULL && p->chave != chave){
        p = p->proximo;
    }
    
    return p;
}

void apaga(celula *lst){
    celula *p;
    while(lst != NULL){
        p = lst;
        lst = lst->proximo;
        free(p);
    }
}
