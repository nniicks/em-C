/*emplilhando elementos na pilha*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int dado;
    struct cel *proximo;
}celula;

void empilhar(int x, celula **pilha);

void imprime(celula *pilha);

int main(){
    celula *topo = NULL;
    int numero;
    
    printf("Entre com um numero e digite 0 para sair:\n");
    scanf("%d", &numero);
    
    while(numero != 0){
        empilhar(numero, &topo);
        
        printf("Entre com um numero e digite 0 para sair:\n");
        scanf("%d", &numero);
    }
    
    printf("Pilha como um todo:\n");
    imprime(topo);
    
    return 0;
}

void empilhar(int x, celula **pilha){
    celula *nova;
    
    nova = (celula *) malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->dado = x;
        nova->proximo = *pilha;
        *pilha = nova;
    }else{
        printf("Nao foi possivel alocar essa estrutura na memoria!");
    }
}

void imprime(celula *pilha){
    celula *p;
    
    for(p = pilha; p != NULL; p = p->proximo){
        printf("%d ", p->dado);
    }
}