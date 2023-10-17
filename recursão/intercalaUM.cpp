#include <stdio.h>
#include <stdlib.h>

void leitura(int *vetor, int n);

void imprime(int *vetor, int n);

void intercala(int *v1, int *v2, int *v3, int i, int j);

int main(){
    int *vetor1, *vetor2, *vetor3, n;
    
    printf("Informe o tamanho do vetor:\n");
    scanf("%d", &n);
    
    vetor1 = (int *) malloc(n * sizeof(int));
    if(vetor1 == NULL){
        return 0;
    }
    
    vetor2 = (int *) malloc(n * sizeof(int));
    if(vetor2 == NULL){
        return 0;
    }
    
    vetor3 = (int *) malloc((n+n) * sizeof(int));
    if(vetor3 == NULL){
        return 0;
    }
    
    printf("Entre com os valores do primeiro vetor:\n");
    leitura(vetor1, n);
    
    printf("Entre com os valores do segundo vetor:\n");
    leitura(vetor2, n);
    
    printf("Vetor 1:\n");
    imprime(vetor1, n);
    
    printf("\nVetor 2:\n");
    imprime(vetor2, n);
    
    intercala(vetor1, vetor2, vetor3, n, n+n);
    printf("\nVetor intercalado:\n");
    imprime(vetor3, n+n);
    
    free(vetor1);
    free(vetor2);
    free(vetor3);
    
    return 0;
    
}

void leitura(int *vetor, int n){
    int *p;
    
    for(p = vetor; p < vetor + n; p++){
        scanf("%d", p);
    }
}

void imprime(int *vetor, int n){
    int *p;
    
    for(p = vetor; p < vetor + n; p++){
        printf("%d ", *p);
    }
}

void intercala(int *v1, int *v2, int *v3, int i, int j){
    
    if(i == 0){
        return;
    }else{
        intercala(v1, v2, v3, i-1, j-2);
        //v3[j-2] = v1[i-1];
        *(v3+j-2) = *(v1+i-1);
        //v3[j-1] = v2[i-1];
        *(v3+j-1) = *(v2+i-1);
    }
}