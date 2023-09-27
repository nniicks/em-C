/*
-----  ACHANDO O MAIOR ELEMENTO DE UM VETOR  ------

#include <stdio.h>
#include <stdlib.h>

int MAIOR(int n, int *vetor, int maior);

int main(){
    int *vetor, *p, tamanho, aux;
    
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    vetor = (int *) malloc(tamanho * sizeof(int));
    if(vetor == NULL){
        printf("Nao foi possivel alocar o vetor na memoria!");
        return 0;
    }else{
        printf("Entre com os valores para o vetor:\n");
        for(p = vetor; p < vetor + tamanho; p++){
            scanf("%d", p);
        }
        
        aux = MAIOR(tamanho, vetor, vetor[0]);
        
        printf("O maior elemento do vetor eh: %d", aux);
    }
    
    free(vetor);
    
    return 0;
}

int MAIOR(int n, int *vetor, int maior){
    
    if(n == 0){
        return maior;    //n=0 vetor tem tamnho 1, logo o vetor[0] ja eh o maior elemento. esse valor foi justamente oq eu passei como maior la na main
    }else{
        if(vetor[n-1] > maior){
            return MAIOR(n-1, vetor, vetor[n-1]);
        }else{
            return MAIOR(n-1, vetor, maior);
        }
    }
}
------------------------------------------------------------------------------

aqui eu passo o vetor como um todo, ou seja, o n na primeira chamada da funcao equivale ao tamanho
do vetor. posteriormente eu vou diminuido ele e comparando o meu ultimo elemento do vetor atual com
o meu maior elemento. ent n = 5, tem no indice 4 o meu ultimo elemnto. ai eu comparo ele com o meu maior,
que definine como sendo o v[0]. a cada vez que eu chamo a funcao, eu passo a olhar para um vetor de tamanho
menor(tamanho n-1).

*/