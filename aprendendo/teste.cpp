/*void LeMatriz(int n, int m, int M[MAX][MAX]);

int ContaLinhasNulas(int n, int m, int M[MAX][MAX]);

void ContaColunasNulas(int n, int m, int M[MAX][MAX], int &conta_c);*/

#include <stdio.h>
#define MAX 100

void le_M(int n, int m, int Mat[MAX][MAX]){

    for(int i = 0;  i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &Mat[i][j]);
        }

    }
}

int somaL(int n, int m, int Mat[MAX][MAX]){

   int quantZ, Lnulas = 0;

   for(int i = 0; i < n; i++){
        quantZ = 0;
        for(int j = 0; j < m; j++){
            if(Mat[i][j] == 0){
                quantZ++;
            }
        }

        if(quantZ == m){
            Lnulas++;
        }

   }

   return Lnulas;


}

void somaC(int n, int m, int Mat[MAX][MAX], int &contaC){

    int quantZ;

    for(int i = 0; i < m; i++){
        quantZ = 0;
        for(int j = 0; j < n; j++){
            if(Mat[j][i] == 0){
                quantZ++;
            }
        }
        if(quantZ == n){
            contaC++;
        }
    }  


}


int main(){

    int i, j, M[MAX][MAX];
    int L, C = 0;

    scanf("%d %d", &i, &j);
    le_M(i, j, M);
    L = somaL(i, j, M);
    somaC(i, j, M, C);

    printf("Linhas nulas = %d", L);
    printf("\nColunas nulas = %d", C);
    

   return 0; 

}
