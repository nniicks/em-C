#include <stdio.h>

/* if - SINTAXE -:
if(<condicional>){

    <bloco_de_comandos>

} 


IF-ELSE - SINTAXE -:
if(<condicional>){

    <bloco_de_comandos1
}

else {
    <bloco_de_comandos2
}

ESTUTURA DE DECISÃO MULTIPLAS:

SWITCH-CASE: eh como se fosse varios if em sequencia
- util para comparar uma unica variavel
- SOMENTE  comparacoes de IGUALDADE
-caso seja igual a 1 dos valoes:
- executa o respectivo bloco
- ignora todos os outros blocos

SINTAXE

switch(<var>){
        case <v1>:
                <bloco_de_comandos1>
                break;
        case <v2>:
                <bloco_de_comandos2>
                break;
        ...

        case <vn>:
                <bloco_de_comandosn>
                break;

        default: 
                <bloco_de_comandos_padrao>
                break;                        
}

#esse valor padrao n eh necessario.mas se vc quer pegar um valor diferente dos listados eh uma boa

-------------------------------------------------

- OPERADORES LÓGICOS -:
-CONJUNÇÃO ("e" lógico): &&
    eh vrdd quando tudo for vrdd
    
-DISJUNÇÃO ("ou" lógico): ||
    eh vrdd se ao menos 1 for vrdd
    
-INVERSÃO (negação -"não lógico"): !
    eh vrdd quando o operando é falso        */


int main(){
    int num;
/*
    printf("Informe um valor: ");
    scanf("%d", &num);

    if (num % 2 == 0){
        printf("O numero %d eh par!", num);
    }

    else {
        printf("O numero %d eh impar!", num);
    }
*/

    printf("Insira um valor entre 1 e 7:\n");
    scanf("%d", &num);

    switch(num){
        case 1:
            printf("Domingo\n");
            break;

        case 2:
            printf("Segunda-feira\n");
            break;

        case 3:
            printf("Terca_feira\n");
            break;

        case 4:
            printf("Quarta-feira\n");
            break;

        case 5:
            printf("Quinta-feira\n");
            break;

        case 6:
            printf("Sexta-feira\n");
            break;

        case 7:
            printf("Sábado\n");
            break;                        

        default:
            printf("Valor invalido\n");
            break;
    }






}