/*Escreva uma funcao para retornar SIM, caso uma chave x exista em uma lista encadeada p ou NAO
caso contrario.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

void insere_fim(celula **lst, int numero);

char* busca(celula *lst, int chave);

void apaga(celula *lst);

int main(){
    celula *lista = NULL;
    int numero, chave;
    char *resultado;
    
    printf("Entre com inteiros e digite 0 caso queira parar com a insercao:\n");
    scanf("%d", &numero);
    
    while(numero != 0){
        insere_fim(&lista, numero);
        
        printf("Entre com inteiros e digite 0 caso queira parar com a insercao:\n");
        scanf("%d", &numero);
    }
    
    printf("Entre com uma chave (numero inteiro):\n");
    scanf("%d", &chave);
    
    resultado = busca(lista, chave);
    printf("A chave foi encontrada na lista? %s", resultado);
    
    free(resultado);
    apaga(lista);
    
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

char* busca(celula *lst, int chave){
    celula *p;
    p = lst;
    while(p != NULL && p->chave != chave){
        p = p->proximo;
    }
    
    if(p == NULL){
        char *nao = (char *) malloc(4);
        strcpy(nao, "NAO");
        return nao;
    }else{
        char *sim = (char *) malloc(4);
        strcpy(sim, "SIM");
        return sim;
    }
}

void apaga(celula *lst){
    celula *p;
    while(lst != NULL){
        p = lst;
        lst = lst->proximo;
        free(p);
    }
}
