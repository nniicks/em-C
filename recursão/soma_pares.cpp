#include <stdio.h>
#include <stdlib.h>

void leitura(int *vetor, int n);

float media(int *vetor, int n);

int main(){
    int *vetor, n;
    
    scanf("%d", &n);
    
    vetor = (int *) malloc(n * sizeof(int));
    if(vetor == NULL){
        return 0;
    }
    
    leitura(vetor, n);
    
    printf("%.2f", media(vetor, n));
    
    return 0;
    
}

void leitura(int *vetor, int n){
    int *p;
    
    for(p = vetor; p < vetor + n; p++){
        scanf("%d", p);
    }
}

float media(int *vetor, int n){
    
    if(n == 0){
        return 0.0;
    }else{
        if(vetor[n-1] % 2 == 0){
            return vetor[n-1] + media(vetor, n - 1);
        }else{
            return media(vetor, n-1);
        }
    }
}