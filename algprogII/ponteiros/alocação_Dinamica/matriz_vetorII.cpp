#include <stdio.h>
#include <stdlib.h>

void leitura_v(float *vetor, int n);

void leitura_m(float **M, int m, int n);

void multiplica(float **M, float *vetor, float *vr, int m, int n);

void imprimir(float *vetor, int m);    

int main(){
    float **MAT, *vetor, *vr, **i;
    int m, n;
    
    scanf("%d %d", &m, &n);
    
    MAT = (float **) malloc(m * sizeof(float *));
    if(MAT == NULL){
        return 0;
    }
    for(i = MAT; i < MAT + m; i++){
        *i = (float *) malloc(n * sizeof(float));
        if(*i == NULL){
            return 0;
        }
    }
    
    vetor = (float *) malloc(n * sizeof(float));
    if(vetor == NULL){
        return 0;
    }
    
    vr = (float *) malloc(m * sizeof(float));
    if(vr == NULL){
        return 0;
    }
    
    printf("Entre com os valores da matriz:\n");
    leitura_m(MAT, m, n);
    
    printf("Entre com os valores do vetor:\n");
    leitura_v(vetor, n);
   
    multiplica(MAT, vetor, vr, m, n);
    
    printf("Resultando da multiplicacao da matriz com o vetor:\n");
    imprimir(vr, m);
    
    for(i = MAT; i < m; i++){
        free(*i);
    }
    free(MAT);
    free(vetor);
    free(vr);
    
    return 0;
    
}

void leitura_v(float *vetor, int n){
    int i;
    
    for(i = 0; i < n; i++){
        scanf("%f", (vetor+i));
    }
}

void leitura_m(float **M, int m, int n){
    int i, j;
    float **p;
    
    p = M;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%f", (*(p+i)+j));
        }
    }
}

void multiplica(float **M, float *vetor, float *vr, int m, int n){
    int i, j;
    float **p, *q, *k, aux;
    
    p = M;
    q = vr;
    for(i = 0; i < m; i++){
        k = vetor;
        aux = 0.0;
        for(j = 0; j < n; j++){
            aux+= *(*(p+i)+j) * *k;
            k++;
        }
        *q = aux;
        q++;
        
    }
}

void imprimir(float *vetor, int m){
    int i;
    
    for(i = 0; i < m; i++){
        printf("%.2f ", *(vetor+i));
    }
}