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
    int tempo1, tempo2;
    
    scanf("%d:%d:%d", &t1.hh, &t1.mm, &t1.ss);
    scanf("%d:%d:%d", &t2.hh, &t2.mm, &t2.ss);
    
    tempo1 = t1.hh * 3600;
    tempo2 = t2.hh * 3600;
    
    tempo1 += t1.mm * 60;
    tempo2 += t2.mm * 60;
    
    tempo1 += t1.ss;
    tempo2 += t2.ss;
    
    if (tempo1 > tempo2){
        aux.ss = tempo1 - tempo2;
        
        aux.hh = aux.ss / 3600;
        
        aux.ss = aux.ss - (3600*aux.hh);
        
        aux.mm = aux.ss / 60;
        
        aux.ss = aux.ss - (60 * aux.mm);
        
        printf("%02d:%02d:%02d\n", aux.hh, aux.mm, aux.ss);
        
    }else{
        aux.ss = tempo2 - tempo1;
        
        aux.hh = aux.ss / 3600;
        
        aux.ss = aux.ss - (3600*aux.hh);
        
        aux.mm = aux.ss / 60;
        
        aux.ss = aux.ss - (60 * aux.mm);
        
        printf("%02d:%02d:%02d\n", aux.hh, aux.mm, aux.ss);
        
    }
    
    
    return 0;
    
}