/*Dados dois horários de um mesmo dia, expressos no formato hh:mm:ss, 
calcule o tempo decorrido entre estes dois horários,apresentando o resultado no mesmo formato hh:mm:ss. 

Exemplo: 

 Se os dois horários fornecidos são 07:13:22 e 13:05:56, a resposta tem de ser 05:52:34.*/

#include <stdio.h>

struct novo_tipo{
    int hh, mm, ss;
};

int main(){
    novo_tipo t1, t2, aux;
    
    scanf("%d:%d:%d", &t1.hh, &t1.mm, &t1.ss);
    scanf("%d:%d:%d", &t2.hh, &t2.mm, &t2.ss);
    
    if(t2.ss >= t1.ss){
        aux.ss = t2.ss - t1.ss;
    }else{
        t2.ss += 60;
        t2.mm--;
        aux.ss = t2.ss - t1.ss;
    }
    if(t2.mm >= t1.mm){
        aux.mm = t2.mm - t1.mm;
    }else{
        t2.mm += 60;
        t2.hh--;
        aux.mm = t2.mm - t1.mm;
    }
    aux.hh = t2.hh - t1.hh;
    
    printf("%d:%d:%d", aux.hh, aux.mm, aux.ss);
    
    return 0;
    
}