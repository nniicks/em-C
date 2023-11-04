#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

void insere_fim(celula **lst, int numero);

void imprime(celula *lst);

int ocorrencia(celula *lst, int numero);

int main(){
    celula *lista = NULL;
    int numero;
    
    printf("Entre com inteiros e insira 0 caso queira parar com a insercao:\n");
    scanf("%d", &numero);
    
    while(numero != 0){
        insere_fim(&lista, numero);
        
        printf("Entre com inteiros e insira 0 caso queira parar com a insercao:\n");
        scanf("%d", &numero);
        
    }
    
    printf("Digite um inteiro qualquer:\n");
    scanf("%d", &numero);
    
    printf("Lista como um todo:\n");
    imprime(lista);
    
    printf("\nO numero de ocorrencias do numero %d na lista eh: %d", numero, ocorrencia(lista, numero));

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

void imprime(celula *lst){
    celula *p;
    
    for(p = lst; p != NULL; p = p->proximo){
        printf("%d ", p->chave);
    }
}

int ocorrencia(celula *lst, int numero){
    celula *p;
    int contador = 0;
    
    for(p = lst; p != NULL; p = p->proximo){
        if(p->chave == numero){
            contador++;
        }
    }
    
    return contador;
}