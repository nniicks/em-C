/*Seja N computado como na equação 1. Então, o valor D = (N − 621049) mod 7 é um número entre 0 e 6 que 
representa os dias da semana, de domingo a sábado. Dada uma data fornecida pelo usuário no formato dd/mm/aaaa,
determine o dia da semana para esta data
*/


#include <stdio.h>
#include <math.h>

struct novo_tipo{
    int dd, mm, aa;
};

int f(int ano, int mes){
    int saida;
    
    if(mes <= 2){
        saida = ano - 1;
    }else{
        saida = ano;
    }
    return saida;
}

int g(int mes){
    int saida;
    
    if(mes <= 2){
        saida = mes + 13;
    }else{
        saida = mes + 1;
    }
    return saida;
}

int main(){
    novo_tipo data;
    float n, aux1, aux2;
    
    scanf("%d/%d/%d", &data.dd, &data.mm, &data.aa);
    
    aux1 = f(data.aa, data.mm);
    aux2 = g(data.mm);
    
    n = floor((1461 * aux1)/4) + floor((153 * aux2)/5) + data.dd;
    n -= 621049;
    n = (int)n % 7;
    
    printf("%0.f\n", n);
    
    return 0;
    
}
