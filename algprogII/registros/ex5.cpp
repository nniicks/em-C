/*Dadas duas datas no formato dd/mm/aaaa, calcule o número de dias decorridos entre estas duas datas.
Exemplo:
Se as duas datas fornecidas são 01/03/2007 e 23/09/2001, a resposta deve ser 1985. 
Uma maneira provavelmente mais simples de computar essa diferença é usar a fórmula 1 para calcular um número
de dias N baseado em uma data:
Lembre-se ainda que o piso de um número real x, denotado por  ⌊ x ⌋, é o maior número inteiro menor ou igual a x. 
Ou seja,  ⌊ 5.3 ⌋= 5,  ⌊ 12.999 ⌋ = 12 e ⌊ 2 ⌋ = 2. 
Podemos calcular o valor N1 para a primeira data informada, o valor N2 para a segunda data informada e a diferença 
|N2 − N1| é o número de dias decorridos entre estas duas datas informadas.
*/

#include <stdio.h>
#include <math.h>

struct novo_tipo{
    int dd, mm, aa;
};

int f(int ano, int mes){
    int saida;
    
    if( mes <= 2){
        saida = ano - 1;
    }else{
        saida = ano;
    }
    
    return saida;
}

int g(int mes){
    int saida;
    
    if(mes <= 2){
        saida = mes +13;
    }else{
        saida = mes + 1;
        
    }
    
    return saida;
    

}

int main(){
    novo_tipo datai, dataf;
    float n1, n2, aux1, aux2, resposta;
    
    
    scanf("%d/%d/%d", &datai.dd, &datai.mm, &datai.aa);
    scanf("%d/%d/%d", &dataf.dd, &dataf.mm, &dataf.aa);
    
    aux1 = f(datai.aa, datai.mm);
    aux2 = g(datai.mm);
    
    n1 = floor((1461 * aux1)/4) + floor((153 * aux2)/5) + datai.dd;
    
    aux1 = f(dataf.aa, dataf.mm);
    aux2 = g(dataf.mm);
    
    n2 = floor((1461 * aux1)/4) + floor((153 * aux2)/5) + dataf.dd;
    
    resposta = floor(n1 - n2);
    
    
    printf("%.0f\n", resposta);
    
    
    return 0;
    
    
}