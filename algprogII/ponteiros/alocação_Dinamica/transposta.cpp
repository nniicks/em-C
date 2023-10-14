#include <stdio.h>
#include <stdlib.h>

void leitura(int **M, int l, int c);

void imprime(int **M, int l, int c);

void transposta(int **MatA, int **MT, int l, int c);

int main(){
    int **MatA, **MatT, l, c;
    
    printf("Informe a dimensao da matriz A:\n");
    scanf("%d %d", &l, &c);
    
    MatA = (int **) malloc(l * sizeof(int *));
    if(MatA == NULL){
        printf("Nao foi possivel alocar a matriz\n");
        return 0;
    }
    for(int i = 0; i < l; i++){
        MatA[i] = (int *) malloc(c * sizeof(int));
        if(MatA[i] == NULL){
            printf("Nao foi possivel alocar a matriz\n");
            return 0;
        }
    }
    
    MatT = (int **) malloc(c * sizeof(int *));
    if(MatT == NULL){
        printf("Nao foi possivel alocar a matriz\n");
        return 0;
    }
    for(int i = 0; i < c; i++){
        MatT[i] = (int *) malloc(l * sizeof(int));
        if(MatT[i] == NULL){
            printf("Nao foi possivel alocar a matriz\n");
            return 0;
        }
    }
    
    printf("Insira os valores da matriz A:\n");
    leitura(MatA, l, c);
    
    printf("Matriz A:\n");
    imprime(MatA, l, c);
    
    transposta(MatA, MatT, l, c);
    
    printf("Matriz transposta de A:\n");
    imprime(MatT, c, l);
    
    for(int i = 0; i < l; i++){
        free(MatA[i]);
    }
    free(MatA);
    
    for(int i = 0; i < c; i++){
        free(MatT[i]);
    }
    free(MatT);
    
    return 0;
    
}

void leitura(int **M, int l, int c){
    int **i, *j;
    
    for(i = M; i < M + l; i++){
        for(j = *i; j < *i + c; j++){
            scanf("%d", j);
        }
    }
    
}

void imprime(int **M, int l, int c){
    int **i, *j;
    
    for(i = M; i < M + l; i++){
        for(j = *i; j < *i + c; j++){
            printf("%d ", *j);
        }
        printf("\n");
    }
}

void transposta(int **MatA, int **MT, int l, int c){
    int **i, *j, coluna = 0, linha = 0;
    
    for(i = MatA; i < MatA + l; i++){
        for(j = *i; j < *i + c; j++){
            MT[linha][coluna] = *j;
            linha++;
        }
        coluna++;
        linha = 0;
    }
    
}