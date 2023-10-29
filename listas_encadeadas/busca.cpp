/*bunscando em uma litsa. os elementos foram
todos inseridos no comeco da lista*/
#include <stdio.h>
#include <stdlib.h>

struct celula{
    int chave;
    int posicao;
    struct celula *proximo;
};

void leitura(int numero, struct celula* &lst, int posicao);

void imprime(struct celula *lst);

celula *busca(int numero, struct celula *lst);

int main(){
    struct celula *lista = NULL, *p;
    int numero, aux = 0;
    
    printf("Entre com um valor inteiro:\n");
    scanf("%d", &numero);
    
    while(numero != -1){
        leitura(numero, lista, aux);
        aux++;
        
        printf("Entre com um valor inteiro:\n");
        scanf("%d", &numero);
    }
    
    printf("Digite um inteiro ai:\n");
    scanf("%d", &numero);
    
    p = busca(numero, lista);
    if(p == NULL){
        printf("O numero %d nao foi encontrado na lsita!\n", numero);
    }else{
        printf("O numero %d foi encontrado na posicao %d da lista", p->chave, p->posicao);
    }
    
    printf("\n\nElementos da lista:\n");
    imprime(lista);
    
    return 0;
    
}

void leitura(int numero, struct celula* &lst, int posicao){
    struct celula *nova;
    
    nova = (struct celula *) malloc(sizeof(struct celula));
    
    nova->chave = numero;
    nova->posicao = posicao;
    nova->proximo = lst;
    lst = nova;
}

void imprime(struct celula *lst){
    struct celula *p;
    
    for(p = lst; p != NULL; p = p->proximo){
        printf("%d ", p->chave);
    }
}

celula *busca(int numero, struct celula *lst){
    struct celula *p;
    
    p = lst;
    while(p != NULL && p->chave != numero){
        p = p->proximo;
    }
    
    return p;
}