#include <stdio.h>
#include <stdlib.h>

void leitura(int *v, int n);

void imprime(int *v, int comeco, int fim);

void ordena(int *v, int comeco, int fim);

void intercala(int *v, int p, int q, int r);

int main(){
    int *vetor, n, particao;
    
    printf("Informe o tamanho do vetor:\n");
    scanf("%d", &n);
    
    vetor = (int *) malloc(n * sizeof(int));
    if(vetor == NULL){
        return 0;
    }
    
    printf("Entre com os valores do vetor:\n");
    leitura(vetor, n);
    
    printf("Informe o indice no qual deseja partir o vetor em duas partes:\n");
    scanf("%d", &particao);
    
    ordena(vetor, 0, particao);
    ordena(vetor, particao, n);
    
    printf("Ordenacao do comeco do vetor ate o indice %d\n", particao);
    imprime(vetor, 0, particao);
    
    printf("\nOrdenacao apartir do indice %d ate o final do vetor:\n", particao);
    imprime(vetor, particao, n);
    
    printf("\nIntercalacao ordenada do vetor original, dado que ele foi ordenada em duas partes separadamentes:\n");
    intercala(vetor, 0, particao, n);
    imprime(vetor, 0, n);
    
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

void ordena(int *v, int comeco, int fim){
    int i, j, aux;
    
    for(i = fim-1; i > comeco - 1; i--){
        for(j = comeco; j < i; j++){
            if(*(v+j) > *(v+j+1)){
                aux = *(v+j);
                *(v+j) = *(v+j+1);
                *(v+j+1) = aux;
            }
        }
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