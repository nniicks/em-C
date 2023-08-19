#include <stdio.h>

#define MAX 100
#define MIN 1


int main(){

    int L, C, quantZ, linhasN = 0, colunasN = 0;
    int M[MAX][MAX];

    do{
        printf("Informe as dimensoes da matriz (em linha e coluna), que nao sejam maiores do que 100 ou menores do que 1: ");
        scanf("%d %d", &L, &C);
    }while(L < MIN || C < MIN || L > MAX || C > MAX );

    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++){
            printf("Informe o valor de M[%d][%d]: ", i+1, j+1);
            scanf("%d", &M[i][j]);
        }

    }

    for(int i = 0; i < L; i++){
        quantZ = 0;
        for(int j = 0; j < C; j++){
            if(M[i][j] == 0){
                quantZ++;
            }
        }

        if(quantZ == C){
            linhasN++;
        }

   }

    for(int i = 0; i < C; i++){
        quantZ = 0;
        for(int j = 0; j < L; j++){
            if(M[j][i] == 0){
                quantZ++;
            }
        }
        if(quantZ == L){
            colunasN++;
        }
    }  


    printf("Essa matriz possui %d linha(s) e %d coluna(s) nularias!", linhasN, colunasN);

    return 0;
}