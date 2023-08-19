/******************************************************************************
Dados dois hor´arios de um mesmo dia, expressos no formato
hh:mm:ss, calcule o tempo decorrido entre estes dois hor´arios,
apresentando o resultado no mesmo formato hh:mm:ss.
Exemplo:
Se os dois hor´arios fornecidos s˜ao 07:13:22 e 13:05:56, a resposta tem de ser 05:52:34.

*******************************************************************************/

#include <stdio.h>

int main()
{   
    struct{
        int hi, mi, si;
        
    }tI;
    
    struct{
        int hf, mf, sf;
        
    }tF;
    
    struct{
        int hora, minuto, segundo;
    }resposta;
    
    printf("Informe o horario de inicio (hora(a)/minuto(s)/segundo(s)): ");
    scanf("%d/%d/%d", &tI.hi, &tI.mi, &tI.si);
    
    printf("Informe o horario de termino (hora(s)/minuto(s)/segundo(s)): ");
    scanf("%d/%d/%d", &tF.hf, &tF.mf, &tF.sf);
    
    if(tI.si > tF.sf){
        tF.sf += 60;
        tF.mf -= 1;
        resposta.segundo = tF.sf - tI.si;
        
    }else{
        resposta.segundo = tF.sf - tI.si;
    }
    
    if(tI.mi > tF.mf){
        tF.mf += 60;
        tF.hf -= 1;
        resposta.minuto = tF.mf - tI.mi;
        
    }else{
        resposta.minuto = tF.mf - tI.mi;
    }
    
    resposta.hora = tF.hf - tI.hi;

    printf("O tempo transcorrido foi de: %d hora(s), %d minuto(s) e %d segundo(s)!",resposta.hora, resposta.minuto, resposta.segundo);
    

    return 0;
}
