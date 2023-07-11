#include <stdio.h>

/*atribuição de contuúdos a variáveis - SINTAXE -:
<variavel> = <informação>;

declaração de constantes - SINTAXE -:
#define <nome> <valor>

*/

#define texto "entrada e saida de dados."
#define pi 3.14

int main(){
    printf("%s\n", texto);
    printf("%.2f\n", pi);

    int idade = 0;
    float peso = 0.0;
    char nome[20] = "";

    printf("Informe o nome: ");
    scanf("%s", &nome);

    printf("Informe a idade: ");
    scanf("%d", &idade);

    printf("Informe o peso: ");
    scanf("%f", &peso);


    printf("Dados informados:\n");
    printf("Nome: %s.\n", nome);
    printf("Idade: %d.\n", idade);
    printf("Peso: %.2fKg.\n", peso);

}

