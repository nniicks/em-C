/*Dada uma data no formato dd/mm/aaaa, escreva um programa que
mostre a proxima data, isto e, a data que representa o dia seguinte a
data fornecida.
Exemplo:
Se a data fornecida e 30/06/2011 a saida deve ser 01/07/2011.
Importante! Nao esqueca dos anos bissextos. Lembre-se que um ano
e bissexto se e divisıvel por 400 ou, em caso negativo, se e divisıvel
por 4 mas nao por 100.
*/

#include <stdio.h>

int main(){
       struct{
        int dia, mes, ano;
        
    }tempo;
    
    printf("Informe a data atual (dia/mes/ano): ");
    scanf("%d/%d/%d", &tempo.dia, &tempo.mes, &tempo.ano);
    
    tempo.dia++;
    
    if (tempo.dia > 31 || (tempo.mes == 4 || tempo.mes == 6 || tempo.mes == 9 || tempo.mes == 11) || (tempo.dia == 30 && tempo.mes == 2) || (tempo.dia == 29 && tempo.mes == 2 && (tempo.ano % 400 != 0 && (tempo.ano % 4 != 0 || tempo.ano % 100 == 0)))){
        tempo.dia = 1;
        
        tempo.mes++;
        
        if (tempo.mes > 12){
            tempo.mes = 1;
            tempo.ano++;
        }
    }

    printf("A nova data eh %d/%d/%d", tempo.dia, tempo.mes, tempo.ano);

    return 0;
    
    
}