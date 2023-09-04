#include <stdio.h>
#define M 5

void eh_primo(int v[M], int num, int *q);

int main(){
    int v[M], *p;
    
    for(p = v; p < v + M; p++){
        scanf("%d", p);
    }
    
    for(p = v; p < v + M; p++){
        eh_primo(v,*p, p);
    }
    
    return 0;
}

void eh_primo(int v[M], int num, int *q){
    int flag = 0, posicao;
    
    posicao = q - v;
    
    for(int i = 2; i < num / 2 + 1; i++){
        if(num % i == 0){
            flag = 1;
            break;
        }
        
    }
    
    if(flag == 0 && num > 1){
        printf("o numero %d eh primo, e sua posicao no vetor eh %d\n", num, posicao);
    }
    
}