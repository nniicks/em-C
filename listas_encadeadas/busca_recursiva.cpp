#include <stdio.h>
#include <stdlib.h>

struct celula{
    int chave;
    struct celula *proximo;
};

void leitura(struct celula* &lst, int numero);

void imprime(struct celula *lst);

celula *buscaR(int numero, struct celula *lst);

int main(){
    struct celula *lista = NULL, *p;
    int numero;
    
    printf("Entre com um numero inteiro:\n");
    scanf("%d", &numero);
    
    while(numero != -1){
        leitura(lista, numero);
        
        printf("Entre com um inteiro:\n");
        scanf("%d", &numero);
    }
    
    printf("Digite um numero qualquer ai:\n");
    scanf("%d", &numero);
    
    p = buscaR(numero, lista);
    
    printf("Lista como um todo:\n");
    imprime(lista);
    if(p == NULL){
        printf("\nO numero %d nao foi encontrado na lista!\n", numero);
    }else{
        printf("O numero %d foi encontrado na lista!", numero);
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

/*recebe um inteiro qualquer e uma lista encadeada sem cabeça lst e devolve o endereço da celula 
que contém o numero buscado ou NULL se tal celula nao existe*/
struct celula *buscaR(int numero, struct celula *lst){
    
    if(lst == NULL){
        return NULL;
    }
    if(lst->chave == numero){
        return lst;
    }
    return buscaR(numero, lst->proximo);
}

/*util pq digamos que eu quero alterar a nota de um aluno, 
mas dai faço a busca para encontralo com base no rga. ou seja, 
achando o endereço da celula que contem o rga, eu tenho obviamente o acesso a todos os 
outros campos que esta celula possui: notas, nome, cpf etc*/