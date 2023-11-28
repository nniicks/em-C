#include <stdio.h>
#include <stdlib.h>

void leitura(int n, int *v);

void imprime(int p, int r, int *v);

int separa(int p, int r, int *v);

void quicksort(int p, int r, int *v);

int main(){
    int *vetor, n, p, r;
    
    printf("Informe o tamanho do vetor:\n");
    scanf("%d", &n);
    
    vetor = (int *) malloc(n * sizeof(int));
    
    printf("Entre com os valores do vetor:\n");
    leitura(n, vetor);
    
    printf("Informe o intervalo que voce deseja onrdenar o vetor: (comeco/fim)\n");
    
    scanf("%d %d", &p, &r);
    
    quicksort(p, r, vetor);
    
    printf("Parte do vetor que foi ordenada:\n");
    imprime(p, r, vetor);
    
    free(vetor);
    
    return 0;
    
}

void leitura(int n, int *v){
    
    for(int i = 0; i < n; i++){
        scanf("%d", (v+i));
    }
}

void imprime(int p, int r, int *v){
    
    for(int i = p; i <= r; i++){
        printf("%d ", *(v+i));
    }
}

int separa(int p, int r, int *v){
    int x, i, j;
    
    x = *(v+p);
    i = p - 1;
    j = r + 1;
    
    while(1){
        do{
            j--;
        }while(*(v+j) > x);
        
        do{
            i++;
        }while(*(v+i) < x);
        
        if(i < j){
            int aux = *(v+i);
            *(v+i) = *(v+j);
            *(v+j) = aux;
        }else{
            return j;
        }
    }
    
}

void quicksort(int p, int r, int *v){
    int q;
    
    if(p < r){
        q = separa(p,  r,  v);
        quicksort(p,  q,  v);
        quicksort(q+1, r, v);
        
    }
}