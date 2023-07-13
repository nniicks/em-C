/*desenvolva um algortimo que simule uma calculadora.
voce deve dar a opçao de o usuario escolher entre 1-somar;
2-subtrair; 3-multiplicar; 4-dividir. o usuario so conseguira processar
dois valores inteitos por vez*/

#include <stdio.h>

int main(){
    int opcao;
    float resultado, n1, n2;

    printf("Digite 1 para somar;\n");
    printf("Digite 2 para subtrair;\n");
    printf("Digite 3 para multiplicar;\n");
    printf("Digite 4 para dividir;\n");
    
    scanf("%d", &opcao);

    switch (opcao){
        case 1:
            printf("Insira o primeiro valor: ");
            scanf("%f", &n1);

            printf("Insira o segundo valor: ");
            scanf("%f", &n2);
            
            resultado = n1 + n2;
           
            printf("Soma: %.1f", resultado);
            
            break;

        case 2:
            printf("Insira o primeiro valor: ");
            scanf("%f", &n1);

            printf("Insira o segundo valor: ");
            scanf("%f", &n2);
            
            resultado = n1 - n2;
            
            printf("Subtracao: %.1f", resultado);
            break;

        case 3:
            printf("Insira o primeiro valor: ");
            scanf("%f", &n1);

            printf("Insira o segundo valor: ");
            scanf("%f", &n2);
           
            resultado = n1 * n2;
           
            printf("Multiplicacao: %.1f", resultado);
            break; 

        case 4:
            printf("Insira o primeiro valor: ");
            scanf("%f", &n1);

            printf("Insira o segundo valor: ");
            scanf("%f", &n2);

            if (n2 != 0){
                resultado = n1 / n2;
                printf("Divisao: %.1f", resultado);
            }
           
           else{
            printf("Divisao por zero.");
           }
            break;

        default:
            printf("opçao invalida!");
            break;               
    }
}