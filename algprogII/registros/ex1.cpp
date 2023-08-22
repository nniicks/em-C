/*Faça um programa para simular uma agenda de compromissos e:
 • Crie e leia um vetor de 5 estruturas de dados com: compromisso (máximo 60 letras) e data, nesta ordem. 
 A data deve ser outra estrutura de dados contendo dia, mês e ano. 
• Leia dois inteiros M e A e mostre todos os compromissos do mês M do ano A. 
Repita o procedimento até ler M = 0.
Dica: utilize  scanf("%d/%d/%d", &variavel_dia, &variavel_mes, &variavel_ano); para 
leitura formatada da data.*/

#include <stdio.h>
#define MAX 60
#define TAM 5

struct tipo_data{
    int dia, mes, ano;
};

struct novo_tipo{
    char compromisso[MAX];
    tipo_data data;
};

int main(){
    novo_tipo agenda[TAM];
    int m, a;
    
    for(int i = 0; i < TAM ; i++){
        scanf("%s", agenda[i].compromisso);
        scanf("%d/%d/%d", &agenda[i].data.dia, &agenda[i].data.mes, &agenda[i].data.ano);
    }
    do{
        scanf("%d/%d", &m, &a);
        
        for(int i = 0; i < TAM ; i++){
            if(agenda[i].data.mes == m && agenda[i].data.ano == a){
                printf("%s\n", agenda[i].compromisso);
            }
        }
           
    }while(m != 0);
    
    return 0;
}