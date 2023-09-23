#include <stdio.h>
#include <stdlib.h>
#define T 10

int main(){
    int v[T], *p, num1, num2, flag1 = 0, flag2 = 0 ,posi1, posi2, dist;
    
    printf("Insira os valores do vetor:\n");
    for(p = v; p < v + T; p++){
        scanf("%d", p);
    }
    
    printf("Digite um numero:\n");
    scanf("%d", &num1);
    printf("Digite um segundo numero:\n");
    scanf("%d", &num2);
    
    for(p = v; p < v + T; p++){
        if(num1 == *p){
            posi1 = p - v;  // posicao do primeiro numero no vetor
            flag1 = 1;
        }
        
        if(num2 == *p){
            posi2 = p - v;  // posicao do segundo numero no vetor
            flag2 = 1;
        }
    }
    
    if(flag1 == 1 && flag2 == 1){
        dist = abs(posi1 - posi2);  // distancia entre os numeros no vetor
        printf("A distancia entre %d e %d no vetor eh %d", num1, num2, dist);
    }else if(flag1 == 1 && flag2 == 0){
        printf("O numero %d nao esta no vetor", num2);
    }else{
        printf("O numero %d nao esta no vetor", num1);
    }
    
    return 0;
}