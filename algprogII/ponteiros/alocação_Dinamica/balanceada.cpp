#include <stdio.h>
#include <stdlib.h>

void leitura(int *vetor, int n);

void imprime(int *vetor, int n);

void ordena(int *vetor, int n);

int balanceada(int *vetor, int n);

int main(){
    int *vetor, n, flag = 0;
    
    printf("Informe o tamanho do vetor:\n");
    scanf("%d", &n);
    
    vetor = (int *) malloc(n * sizeof(int));
    if(vetor == NULL){
        return 0;
    }
    
    leitura(vetor, n);
    
    ordena(vetor, n);
    
    flag = balanceada(vetor, n);
    
    if(flag == 0){
        printf("\nEssa lista eh balanceada!");
    }else{
        printf("\nEssa lista NAO eh balanceada!");
    }
    
    free(vetor);
    
    return 0;
}

void leitura(int *vetor, int n){
    int i;
    
    for(i = 0; i < n; i++){
        scanf("%d", (vetor+i));
    }
}

void ordena(int *vetor, int n){
    int i, j, aux;
    
    for(i = n - 1; i > -1; i--){
        for(j = 0; j < i; j++){
            if(*(vetor+j) > *(vetor+j+1)){
                aux = *(vetor + j);
                *(vetor + j) = *(vetor + j + 1);
                *(vetor + j + 1) = aux;
            }
        }
    }
}

void imprime(int *vetor, int n){
    int i;
    
    for(i = 0; i < n; i++){
        printf("%d ", *(vetor+i));
    }
}

int balanceada(int *vetor, int n){
    int i, j, soma, aux;
    
    if(n % 2 != 0){
        return -1;
    }
     soma = *(vetor) + *(vetor + n - 1);
     
     j = n - 2;
     for(i = 1; i < n - 2; i++){
         aux = *(vetor + i) + *(vetor + j);
         
         if(aux != soma){
             return -1;
         }
         j--;
     }
     
     return 0;
   
}