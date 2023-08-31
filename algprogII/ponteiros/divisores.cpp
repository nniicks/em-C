#include <stdio.h>
#define MAX 100

void divs(int *p, int *quant, int D[MAX]);
void imprime(int *quantos, int D[MAX]);

int main(){
    int n, quanT = 0, D[MAX];
    
    scanf("%d",&n);
    divs(&n, &quanT, D);
    printf("O numero %d possuem %d divisores, que são eles:\n", n, quanT);
    imprime(&quanT, D);
    
    return 0;
}

void divs(int *p, int *quant, int D[MAX]){
    int *q;
    
    q = D;
    for(int i = 1; i < *p / 2 + 1; i++){
        if(*p % i == 0){
            *q++ = i;
            *quant+= 1;
        }
    }
}

void imprime(int *quantos, int D[MAX]){
    int *p;
    
    for(p = D; p < D + *quantos; p++){
        printf("%d ", *p);
    }
}