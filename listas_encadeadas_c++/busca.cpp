#include <stdio.h>
#include <stdlib.h>

struct celula{
    int chave;
    struct celula *proximo;
};

void leitura(struct celula* &lst, int numero);

void imprime(struct celula *lst);

celula *busca(int numero, struct celula *lst, int *posicao);

int main(){
    struct celula *lista = NULL, *p;
    int numero, aux = 0;
    
    printf("Entre com um numero inteiro:\n");
    scanf("%d", &numero);
    
    while(numero != -1){
        leitura(lista, numero);
        
        printf("Entre com um inteiro:\n");
        scanf("%d", &numero);
    }
    
    printf("Digite um numero qualquer ai:\n");
    scanf("%d", &numero);
    
    p = busca(numero, lista, &aux);
    
    printf("Lista como um todo:\n");
    imprime(lista);
    if(p == NULL){
        printf("\nO numero %d nao foi encontrado na lista!\n", numero);
    }else{
        printf("\nO numero %d foi encontrado na posicao %d da lista!\n", numero, aux);
    }
    
    return 0;
}

void leitura(struct celula* &lst, int numero){
    struct celula *nova;
    
    nova = (struct celula *) malloc(sizeof(struct celula));
    
    nova->chave = numero;
    nova->proximo = lst;
    lst = nova;
    
}

void imprime(struct celula *lst){
    struct celula *p;
    
    for(p = lst; p != NULL; p = p->proximo){
        printf("%d ", p->chave);
    }
}

struct celula *busca(int numero, struct celula *lst, int *posicao){
    struct celula *p;
    
    p = lst;
    while(p != NULL && p->chave != numero){
        p = p->proximo;
        (*posicao)++;
        
    }
   
    return p;
}