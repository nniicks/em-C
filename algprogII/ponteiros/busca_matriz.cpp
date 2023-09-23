#include <stdio.h>
#define L 3
#define C 3

void cria_M(int *pt_aux);
int busca(int *pt_aux, int *numero);

int main(){
    int M[L][C], num,i = 0, posicao;
    
    cria_M(M[0]);
    
    
    printf("Informe um numero inteiro:\n");
    scanf("%d", &num);
    
    do{
        posicao = busca(M[i], &num);
        i++;
        
    }while(posicao == -1 && i < L);  // se i for >= a L, signfica que eu andei a matriz inteira e nao achei o numero;
    
    if(posicao == -1){
        printf("Numero %d NAO esta na matriz\n", num);
    }else{
        printf("Numero %d esta na matriz, e ele  o A%d%d!", num, i,posicao+1);
    }
    
}


void cria_M(int *pt_aux){
    int *p;
    
    printf("Entre, seguidamente, com os valoes para a matriz\n");
    for(p = pt_aux; p < pt_aux + L*C; p++){
        scanf("%d", p);
    }
}

int busca(int *pt_aux, int *numero){
    int *q;
    
    for(q = pt_aux; q < pt_aux + C; q++){
       
        if(*q == *numero){
            
            return q - pt_aux;
        }
    }
    
    return -1; // o num buscado n esta nessa linha da matriz
}