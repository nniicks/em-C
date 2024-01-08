/*funcao que insere no incio de uma lista simplesmente encadeada*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

void insere_inicio(celula **lista, int valor);

void imprime(celula *lista);

int main(){
    celula *lista = NULL;
    int numero, tam = 0;
    
    printf("Entre com varios numeros inteiros, e digite 0 para sair: \n");
    scanf("%d", &numero);
    
    while(numero != 0){
        tam++;
        insere_inicio(&lista, numero);
        
        printf("Entre com varios numeros inteiros, e digite 0 para sair: \n");
        scanf("%d", &numero);
        
    }
    
    printf("\n------ LISTA: %d -------\n", tam);
    imprime(lista);
    printf("------- FIM LISTA ---------\n");
    
    return 0;
}

void insere_inicio(celula **lista, int valor){
    celula *nova = malloc(sizeof(celula));
    
    if(nova != NULL){
        
        nova->chave = valor;
        nova->proximo = *lista;
        *lista = nova;
        
    }else{
        printf("\nErro ao alocar memoria!\n");
    }
}

void imprime(celula *lista){
    
    while(lista != NULL){
        printf("%d\n", lista->chave);
        lista = lista->proximo;
    }
}