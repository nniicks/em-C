#include <stdio.h>
#include <stdlib.h>

void leitura(int **M, int l , int c);

void imprime(int **M, int l, int c);

int quadrado_magico(int **M, int l, int c);

int main(){
    int **M, l, c, **i, flag;
    
    scanf("%d %d", &l, &c);
    
    M = (int **) malloc(l * sizeof(int *));
    if(M == NULL){
        return 0;
    }
    for(i = M; i < M + l; i++){
        *i = (int *) malloc(c * sizeof(int));
        if(*i == NULL){
            return 0;
        }
    }
    
    printf("Entre com os valores da matriz A:\n");
    leitura(M, l, c);
    
    printf("Matriz A:\n");
    imprime(M, l, c);
    
    flag = quadrado_magico(M, l, c);
    
    if(flag == 0){
        printf("A matriz em questao eh superquadrada!\n");
    }else{
        printf("A matriz nao eh superquadrada!\n");
    }
    
    for(i = M; i < M + l; i++){
        free(*i);
    }
    free(M);
    
    return 0;
    
}

void leitura(int **M, int l , int c){
    int i, j, **p;
    
    p = M;
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            scanf("%d", (*(p+i)+j));
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

int quadrado_magico(int **M, int l, int c){
    int i, j, soma = 0, soma_l, soma_c, soma_dp, soma_ds, **p;
    
    //definindo a minha referencia
    p = M;
    for(i = 0; i < l; i++){
        for(j = 0; j < 1; j++){
            soma += *(*(p+i)+j);
        }
    }
    
    printf("%d\n", soma);
    
    //vefificando a soma das linhas e das colunas
    p = M;
    for(i = 0; i < l; i++){
        soma_l = 0;
        soma_c = 0;
        for(j = 0; j < c; j++){
            soma_l += *(*(p+i)+j);
            soma_c += *(*(p+j)+i);
        }
        if(soma_l != soma || soma_c != soma){
            return -1;              //n tem como ele ser quadrado perfeito
        }
    }
    
    //verificando a diagonal principal e secundaria
    p = M;
    soma_dp = 0;
    soma_ds = 0;
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if(i == j){
                soma_dp += *(*(p+i)+j);
            }
            
            if(i + j == l - 1){
                soma_ds += *(*(p+i)+j);
            }
        }
    }
    if(soma_dp != soma || soma_ds != soma){
        return -1;
    }
    
    return 0;
}