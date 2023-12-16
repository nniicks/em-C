/*fazendo operaçoes basicas em uma PILHA: empilhando (colocando elementos
na pilha) e desempilhando (removendos os elementos de uma pilha)*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *prox;
}celula;

void empilhar(int x, celula **lst);

int desempilha(celula **lst);

void imprime(celula *lst);

int main(){
    celula *t;
    t = NULL;
    int n, aux;
    
    printf("Entre com os valores na pilha:\n");
    scanf("%d", &n);
    while(n != 0){
        empilhar(n, &t);
        
        scanf("%d", &n);
    }
    
    printf("PILHA:\n");
    imprime(t);
    
    aux = desempilha(&t);
    
    printf("PILHA (apos a remocao da chave %d):\n", aux);
    imprime(t);
    
    return 0;
}

void empilhar(int x, celula **lst){
    celula *nova;
    
    nova = (celula *) malloc(sizeof(celula));
    
    nova->chave = x;
    nova->prox = *lst;
    *lst = nova;
}

int desempilha(celula **lst){
    
    celula *aux;
    int num;
    
    if(*lst == NULL){
        return 0;
    }else{
        num = (*lst)->chave;
        aux = *lst;
        *lst = (*lst)->prox;
        free(aux);
        return num;
    }
}

void imprime(celula *lst){
    celula *p;
    
    for(p = lst; p != NULL; p = p->prox){
        printf("%d ", p->chave);
    }
}