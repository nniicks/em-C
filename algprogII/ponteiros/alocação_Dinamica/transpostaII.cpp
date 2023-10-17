#include <stdio.h>
#include <stdlib.h>

void imprime(int **M, int l, int c);

void leitura(int **M, int l, int c);

void transposta(int **MA, int **MT, int l, int c);

int main(){
    int **MA, **MT, l, c, **i;
    
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
    
    MT = (int **) malloc(c * sizeof(int *));
    if(MT == NULL){
        return 0;
    }
    for(i = MT; i < MT + c; i++){
        *i = (int *) malloc(l * sizeof(int));
        if(*i == NULL){
            return 0;
        }
    }
    
    printf("Entre com os valores da matriz A:\n");
    leitura(MA, l, c);
    
    printf("Matriz A:\n");
    imprime(MA, l, c);
    
    transposta(MA, MT, l, c);
    
    printf("Transposta:\n");
    imprime(MT, c, l);
    
    for(i = MA; i < MA + l; i++){
        free(*i);
    }
    free(MA);
    
    for(i = MT; i < MT + c; i++){
        free(*i);
    }
    free(MT);
    
    return 0;
    
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

void leitura(int **M, int l, int c){
    int i, j, **p;
    
    p = M;
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            scanf("%d", (*(p+i)+j));   //o primeiro * fazia eu pegar o conteudo apontado pelo ponteiro
        }
    }
  
}

void transposta(int **MA, int **MT, int l, int c){
    int i, j, **p, **q;
    
    p = MA;
    q = MT;
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            *(*(q+j)+i) = *(*(p+i)+j);
        }
    }
}