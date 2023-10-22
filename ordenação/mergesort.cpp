#include <stdio.h>
#include <stdlib.h>

void leitura(int *v, int n);

void imprime(int *v, int comeco, int fim);

void mergesort(int *v, int comeco, int fim);

void intercala(int *v, int p, int q, int r);

int main(){
    int *vetor, n, p, r;
    
    printf("Informe o tamanho do vetor:\n");
    scanf("%d", &n);
    
    vetor = (int *) malloc(n * sizeof(int));
    if(vetor == NULL){
        return 0;
    }
    
    printf("Entre com os valores do vetor:\n");
    leitura(vetor, n);
    
    printf("Informe o intervalo no qual voce deseja ordenar o vetor: (comeco/fim\n");
    scanf("%d %d", &p, &r);
    
    mergesort(vetor, p, r);
    
    printf("Parte que foi ordenada do vetor:\n");
    imprime(vetor, p, n);
    
    free(vetor);
    
    return 0;
    
}

void leitura(int *v, int n){
    
    for(int i = 0; i < n; i++){
        scanf("%d", (v+i));
    }
}

void imprime(int *v, int comeco, int fim){
    
    for(int i = comeco; i < fim; i++){
        printf("%d ", *(v+i));
    }
}


void intercala(int *v, int p, int q, int r){
    int i, j, k, W[r];
    
    i = p;
    j = q;
    k = 0;
    while(i < q && j < r){ //enquanto eu estiver com indices validos no vetor
        if(*(v+i) < *(v+j)){
            *(W+k) = *(v+i);
            i++;
        }else{
            *(W+k) = *(v+j);
            j++;
        }
        k++;
    }
    
    while(i < q){  //sobrou valores na primeira parte do vetor
        *(W+k) = *(v+i);
        i++;
        k++;
    }
    
    while(j < r){  //sobrou valores na segunda parte do vetor
        *(W+k) = *(v+j);
        j++;
        k++;
    }
    
    //copia do auxiliar (W) para o vetor original
    for(i = p; i < r; i++){
        *(v+i) = *(W+i-p);
    }
}

void mergesort(int *v, int comeco, int fim){
    
    int particao;
    
    if(comeco < fim - 1){
        particao = (comeco + fim) / 2;
        mergesort(v, comeco, particao);
        mergesort(v, particao, fim);
        intercala(v, comeco, particao, fim);
    }
}