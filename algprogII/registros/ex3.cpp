/*Faça um programa que controla o consumo de energia dos eletrodomésticos de uma casa e:
• Crie e leia 5 eletrodomésticos que contém nome (máximo 15 letras), potência (real, em kW) e 
tempo ativo por dia (real, em horas).
• Leia um tempo t (em dias), calcule e mostre o consumo total na casa e o consumo relativo de cada 
eletrodoméstico (consumo/consumo total) nesse período de tempo. Apresente este último dado em porcentagem.

Dica: utilize %.2f para impressão dos valores reais com duas casas decimais.*/



#include <stdio.h>
#define MAX 5
#define TAM 15

struct novo_tipo{
    char nome[TAM];
    float potencia, tempo;
};

int main(){
    novo_tipo eletro[MAX];
    int dias;
    float consumoT = 0, consumoR;
    
    for(int i = 0; i < MAX; i++){
        scanf("%s", eletro[i].nome);
        scanf("%f", &eletro[i].potencia);
        scanf("%f", &eletro[i].tempo);
    
        consumoT += eletro[i].potencia * eletro[i].tempo;
    }
    
    scanf("%d", &dias);
    consumoT = consumoT * dias;
    printf("%.2f\n", consumoT);
    
    for(int i = 0; i < MAX; i++){
        consumoR = eletro[i].potencia * eletro[i].tempo * dias;
        
        printf("%.2f\n", (consumoR/consumoT)*100);
    }
    
    return 0;
}