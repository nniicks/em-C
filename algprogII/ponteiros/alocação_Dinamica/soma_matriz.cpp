#include <stdio.h>
#include <stdlib.h>

void leitura(int **M, int l, int c);

void imprime(int **M, int l, int c);

void soma(int **MA, int **MB, int **MS, int l, int c);

int main(){
    int **MA, **MB, **MS, l, c, **i;
    
    printf("Informe as dimensoes da matriz: (linha/coluna)\n");
    scanf("%d %d", &l, &c);
    
    MA = (int **) malloc(l * sizeof(int *));
    if(MA == NULL){
        return 0;
    }
    for(i = MA; i < MA + l; i++){
        *i = (int *) malloc(c * sizeof(int));
        if(*i == NULL){
            return 0;
        }
    }
    
    MB = (int **) malloc(l * sizeof(int *));
    if(MB == NULL){
        return 0;
    }
    for(i = MB; i < MB + l; i++){
        *i = (int *) malloc(c * sizeof(int));
        if(*i == NULL){
            return 0;
        }
    }
    
    MS = (int **) malloc(l * sizeof(int *));
    if(MS == NULL){
        return 0;
    }
    for(i = MS; i < MS + l; i++){
        *i = (int *) malloc(c * sizeof(int));
        if(*i == NULL){
            return 0;
        }
    }
    
    printf("Entre com os elementos da matriz A:\n");
    leitura(MA, l, c);
    
    printf("Entre com os elementos da matriz B:\n");
    leitura(MB, l, c);
    
    printf("Matriz A:\n");
    imprime(MA, l, c);
    
    printf("Matriz B:\n");
    imprime(MB, l, c);
    
    soma(MA,MB, MS, l, c);
    
    printf("Matriz resulante da soma da matriz A com a matriz B:\n");
    imprime(MS, l, c);
    
    for(i = MA; i < MA + l; i++){
        free(*i);
    }
    free(MA);
    
    for(i = MB; i < MB + l; i++){
        free(*i);
    }
    free(MB);
    
    for(i = MS; i < MS + l; i++){
        free(*i);
    }
    free(MS);
    
    return 0;
    
}

void leitura(int **M, int l, int c){
    int i, j, **p;
    
    p = M;
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            scanf("%d",(*(p+i)+j));
        }
    }
}

void imprime(int **M, int l, int c){
    int i, j, **p;
    
    p = M;
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("%d ", *(*(p+i)+j));
        }
        printf("\n");
    }
}

void soma(int **MA, int **MB, int **MS, int l, int c){
    int i, j, **p, **q, **s;
    
    p = MA;
    q = MB;
    s = MS;
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            *(*(s+i)+j) = *(*(p+i)+j) + *(*(q+i)+j);
        }
    }
}