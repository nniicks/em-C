#include <stdio.h>
#include <stdlib.h>

void leitura(int *vetor, int n);

float media(int *vetor, int n, float soma, int quant);

int main(){
    int *vetor, n;
    
    scanf("%d", &n);
    
    vetor = (int *) malloc(n * sizeof(int));
    if(vetor == NULL){
        return 0;
    }
    
    leitura(vetor, n);
    
    printf("%.2f", media(vetor, n, 0.0, 0));
    
    free(vetor);
    
    return 0;
    
}

void leitura(int *vetor, int n){
    int *p;
    
    for(p = vetor; p < vetor + n; p++){
        scanf("%d", p);
    }
}

float media(int *vetor, int n, float soma, int quant){
    
    if(n == 0){
        return soma/quant;
    }else{
        if(vetor[n-1] % 2 == 0){
            return media(vetor, n - 1, soma + vetor[n-1], quant+= 1);
            
        }else{
            return media(vetor, n - 1, soma, quant);
        }
    }
}