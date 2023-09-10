/*. Implemente uma funcao que receba como parametro um vetor de numeros reais, seu tamanho N e
retorne quantos numeros negativos ha nesse vetor. Essa funcao deve obedecer ao prototipo:
int negativos(float *vet, int N);
e ser implementada utilizando a nota¸c˜ao de ponteiros. Crie um programa para testar sua funcao.*/

#include <stdio.h>
#define T 20

int negativos(float *v, int n);

int main(){
    float V[T];
    int tamanho, quant;
    
    scanf("%d", &tamanho);
    
    quant = negativos(V,tamanho);
    
    printf("Quantidade de valores negativos: %d", quant);
    
    return 0;
}

int negativos(float *v, int n){
    int quantidade = 0;
    float *p; // ponteiro auxiliar para eu n perder a primeira posicao do vetor V la da main
    
    printf("Informe os valores do vetor:\n");
    for(p = v; p < v + n; p++){
        scanf("%f", p);
    }
    
    for(p = v; p < v + n; p++){
        if(*p < 0){
            quantidade++;
        }
    }
    
    return quantidade;
}