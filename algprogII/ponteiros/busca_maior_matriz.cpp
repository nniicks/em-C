#include <stdio.h>
#define L 100
#define C 100

void cria_M(int *pt_aux, int *l, int *c);
int busca_Maior(int *pt_aux, int *aux, int *l, int *c);

int main(){
    int A[L][C], linha, coluna, maior;
    
    printf("Informe, na mesma linha, as dimensoes da matriz: ");
    scanf("%d %d", &linha, &coluna);
    
    cria_M(A[0], &linha, &coluna);
    
    maior = A[0][0];
    maior = busca_Maior(A[0], &maior, &linha, &coluna);
    
    printf("E seu valor eh: %d", maior);
    
    return 0;
}


void cria_M(int *pt_aux, int *l, int *c){
    int *p;
    
    for(p = pt_aux; p < pt_aux + *l * *c; p++){
        scanf("%d", p);
    }
    
}

int busca_Maior(int *pt_aux, int *aux, int *l, int *c){
    int *p, linha = 0, coluna = 0, distancia;
    
    for(p = pt_aux; p < pt_aux + *l * *c; p++){
        if(*p > *aux){
            *aux = *p;
            distancia = p - pt_aux;
            
            if(distancia >=*c){
                linha = distancia / *c; 
                coluna = distancia % *c;
            }
        }
    }
    
    printf("O maior elemento esta na posicao A%d%d da matriz\n", linha+1, coluna+1);
    return *aux;
}