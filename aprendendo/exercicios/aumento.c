#include <stdio.h>

int main(){
    float salario, ganho, novo_salario, aumento;
    

    printf("Informe o salario: ");
    scanf("%f", &salario);

    printf("Informe o aumento em porcentagem: ");
    scanf("%f", &aumento);

    ganho = salario * (aumento / 100);
    novo_salario = (aumento + 100)/100 * salario;

    printf("Salario antes do aumento: R$%.2f\n", salario);
    printf("Ganho salarial: R$%.2f\n", ganho);
    printf("Novo salario: R$%.2f\n", novo_salario);



}