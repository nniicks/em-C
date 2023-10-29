/*ler varios numeros e inserir no inicio da lista ate que o valor -1 
seja lido. o -1 nao eh para entrar na lista*/

#include <stdio.h>
#include <stdlib.h>

struct celula{
    int chave;
    struct celula *proximo;
};

void leitura(int numero, struct celula* &lst);

void imprime(struct celula *lst);

int main(){
    struct celula *lista = NULL;
    int numero;
    
    printf("Entre com um valor inteiro:\n");
    scanf("%d", &numero);
    
    while(numero != -1){
        leitura(numero, lista);
        
        printf("Entre com um valor inteiro:\n");
        scanf("%d", &numero);
    }
    
    printf("Elementos presentes na lista:\n");
    imprime(lista);
    
    return 0;
    
}

void leitura(int numero, struct celula* &lst){
    struct celula *nova;
    
    nova = (struct celula *) malloc(sizeof(struct celula));
    
    nova->chave = numero;
    nova->proximo = lst;
    lst = nova;

}

void imprime(struct celula *lst){
    struct celula *p;
    
    for(p = lst; p!= NULL; p = p->proximo){
        printf("%d\n", p->chave);
    }
}