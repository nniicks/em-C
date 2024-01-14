//gerando uma lista par e uma lista impar a partir de uma primera lista
#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int dado;
    struct cel *proximo;
}celula;

void imprime(celula *lista);

void insere_inicio(celula **lista, int numero);

void insere_final(celula **lista, int numero);

void divide_par_impar(celula **lista, celula **l_par, celula **l_impar);

int main(){
    celula *lista = NULL, *lista_par = NULL, *lista_impar = NULL;
    int opc, numero;
    
    do{
        printf("\n0 - Sair\n1 - Insere no inicio\n2 - Insere no final\n3 - Imprime as listas\n4 - Dividir\n");
        scanf("%d", &opc);
        
        if(opc == 1){
            printf("Entre com um numero inteiro:\n");
            scanf("%d", &numero);
            
            insere_inicio(&lista, numero);
        }else if(opc == 2){
            printf("Entre com um numero inteiro:\n");
            scanf("%d", &numero);
            
            insere_final(&lista, numero);
        }else if(opc == 3){
            
            printf("\n---- LISTA COMO UM TODO ----\n");
            imprime(lista);
            
            printf("\n---- LISTA DOS PARES ----\n");
            imprime(lista_par);
            
            printf("\n---- LISTA DOS IMPARES ----\n");
            imprime(lista_impar);
        }else if(opc = 4){
            divide_par_impar(&lista, &lista_par, &lista_impar);
            printf("\nDivisao realizada!!\n");
        }
    }while(opc != 0);
    
    return 0;
}
void imprime(celula *lista){
    
    while(lista != NULL){
        printf("%d\n", lista->dado);
        lista = lista->proximo;
    }
}

void insere_inicio(celula **lista, int numero){
    celula *nova = malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->dado = numero;
        nova->proximo = *lista;
        *lista = nova;
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

void insere_final(celula **lista, int numero){
    celula *aux, *nova = malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->dado = numero;
        nova->proximo = NULL;
        
        if(*lista == NULL){
            *lista = nova;
        }else{
            aux = *lista;
            while(aux != NULL){
                aux = aux->proximo;
            }
            aux->proximo = nova;
        }
    }
}

void divide_par_impar(celula **lista, celula **l_par, celula **l_impar){
    celula *aux = *lista;
    
    while(aux != NULL){
        if(aux->dado > 0){
            if(aux->dado % 2 == 0){
                insere_inicio(l_par, aux->dado);
            }else{
                insere_inicio(l_impar, aux->dado);
            }
        }
        aux = aux->proximo;  
    }
}