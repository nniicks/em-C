/* --- VETORES ---
- estruturas de dados unidemensionais
- indice unico controla as posicoes

SINTAXE de declaração
<tipo> <nome>[<tamanho>];

acesso a uma posicao:
    NAO eh possivel acessar um vetor todo
    sintaxe: <nome>[<indice>]

lista de inicializacao: preenche um vetor todo, de uma vez so
<tipo> <nome>[<tam.>] = {<v1>, <v2>, ..., <vn>};

exemplo tbm de atribuiçao de valores no vetor

int v[5];

v[0] = 100;
v[1] = 200;
v[2] = 300;
v[3] = 400;
v[4] = 500;

---------------------

int i, vetor[5] = {10, 20, 30, 40, 50};
    float soma = 0;

    for(i = 0; i < 5; i++){   
        soma += vetor[i];
    }
    
    printf("%f\n", soma/5);

*/

#include <stdio.h>

int main(){
    int vetor[5], i;

    for(i = 0; i < 5; i++){
        printf("Insira um valor: ");
        scanf("%d", &vetor[i]);
    }

    printf("Valores inseridos:\n");
    for(i = 0; i < 5; i++){
        printf("%d ", vetor[i]);

    }
}