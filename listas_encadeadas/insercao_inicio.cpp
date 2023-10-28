//inserindo 5 numeros no inicio de uma lista

#include <stdio.h>
#include <stdlib.h>

struct celula{
    int chave;
    struct celula *proximo;
};

void insere_inicio(int numero, struct celula* &lst);

void imprime(struct celula *lst);

int main(){
    struct celula *lista = NULL;
    int n1, n2, n3, n4, n5;
    
    printf("Insira 5 numeros inteiros:\n");
    scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
    
    insere_inicio(n1, lista); //conteudo de lista ja eh um endereço
    insere_inicio(n2, lista);
    insere_inicio(n3, lista);
    insere_inicio(n4, lista);
    insere_inicio(n5, lista);
    
    printf("Elementos da lista:\n");
    imprime(lista);
    
    return 0;
    
}

void imprime(struct celula *lst){
    
    struct celula *p;
    for(p = lst; p != NULL; p = p->proximo){
        printf("%d\n", p->chave);
    }
}

void insere_inicio(int numero, struct celula* &lst){
    struct celula *nova;
    
    nova = (celula *) malloc(sizeof(struct celula));
    
    nova->chave = numero;
    nova->proximo = lst;
    lst = nova;
}