#include <stdio.h>

#define MAX 100
#define MIN 1


int main(){

    int L, C, somaL,somaC, quantL = 0, quantC = 0;
    int i, j;
    int M[MAX][MAX];

    do{
        printf("Informe as dimensoes da matriz (em linha e coluna), que nao sejam maiores do que 100 ou menores do que 1: ");
        scanf("%d %d", &L, &C);
    }while(L < MIN || C < MIN || L > MAX || C > MAX );

    for(i = 0; i < L; i++){
        for(j = 0; j < C; j++){
            printf("Informe o valor de M[%d][%d]: ", i+1, j+1);
            scanf("%d", &M[i][j]);
        }

    }

    /*somando os valores de cada linha e de cada coluna*/
    for(i = 0; i < L; i++){
         somaL = 0;
         somaC = 0;
        for(j = 0; j < C; j++){
            somaL = somaL + M[i][j];
            somaC = somaC + M[j][i];
        }
        
        if (somaL == 0){
            quantL++;
        }

        if (somaC == 0){
            quantC++;
        }
    }
    

    printf("Essa matriz possui %d linha(s) e %d coluna(s) nularias!", quantL, quantC);

}