/*desempilhando um no/celula de uma pilha*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int dado;
    struct cel *proximo;
}celula;

void empilhar(int x, celula **pilha);

int desempilhar(celula **pilha);

void imprime(celula *pilha);

int main(){
    celula *topo = NULL;
    int numero, chave;
    
    printf("Entre com um numero e digeto 0 caso queira sair:\n");
    scanf("%d", &numero);
    
    while(numero != 0){
        empilhar(numero, &topo);
        
        printf("Entre com um numero e digeto 0 caso queira sair:\n");
        scanf("%d", &numero);
    }
    
    printf("Pilha como um todo:\n");
    imprime(topo);
    
    chave = desempilhar(&topo);
    
    if(chave == 0){
        printf("Pilha vazia:\n");
    }else{
         printf("\nPilha apos a remocao da chave %d:\n", chave);
        imprime(topo);
    }
   
    return 0;
}

void empilhar(int x, celula **pilha){
    celula *nova = (celula *) malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->dado = x;
        nova->proximo = *pilha;
        *pilha = nova;
    }else{
        printf("Nao foi possivel alocar essa estrutura na memoria!");
    }
}

int desempilhar(celula **pilha){
    celula *aux;
    int chave;     //vai guarda a chave que foi removida
    
    
    if(*pilha == NULL){
        return 0;         //pilha vazia
    }else{
        chave = (*pilha)->dado;
        aux = *pilha;
        *pilha = (*pilha)->proximo;   //atualiza o topo da pilha
        
        free(aux);                    //libera o antigo topo
        return chave;
    }
}

void imprime(celula *pilha){
    celula *p;
    
    for(p = pilha; p != NULL; p = p->proximo){
        printf("%d ", p->dado);
    }
}