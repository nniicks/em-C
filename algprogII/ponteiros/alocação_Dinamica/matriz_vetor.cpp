#include <stdio.h>
#include <stdlib.h>

void mult(float **matriz, float *vetor, float *resultado, int l, int c);

int main(){
    float **matriz, **q, *vetor, *p, *resultado;
    int l, c;
    
    printf("Informe as dimensoes da matriz: ");
    scanf("%d %d", &l, &c);
    
    matriz = (float **) malloc(l * sizeof(float *));  //tentativa de alocar um vetor que contem o endereço de cada um das l linhas
    
    if(matriz != NULL){
        for(q = matriz; q < matriz + l; q++){   //percorro cada umas das linhas
            *q = (float *) malloc(c * sizeof(float));
            if(*q == NULL){
                printf("Nao foi possivel alocar a matriz!");
                return 0;
            }
        }
        
        // consegui alocar toda a matriz
        printf("Informe os valores da matriz:\n");
        for(q = matriz; q < matriz + l; q++){
            for(p = *q; p < *q + c; p++){  //*q é um vetor normal (no sentido de ser engual aos vetores que eu ja trabalhei)
                scanf("%f", p);
            }
        }
        
    }else{
        printf("Nao foi possivel alocar a matriz!");
        return 0;
    }
    
    vetor = (float *) malloc(c * sizeof(float));
    if(vetor != NULL){
        //consegui alocar o vetor na memoria
        
        printf("Informe os valores do vetor:\n");
        for(p = vetor; p < vetor + c; p++){
            scanf("%f", p);
        }
    }else{
        printf("Não foi possivel alocar o vetor na memoria!");
        return 0;
    }
    
    resultado = (float *) malloc(l * sizeof(float));
    /*vai ser matriz * vetor. eu vou enxergar  o vetor aqui na vertical
    ou seja, ele sempre vai ter apenas uma coluna. a quantidade de elemntos no vetor(ou matriz) 
    resultante sera igual a quant de linhaa da matriz (l) * a quant de coluna do vetor(1). ou seja,
    so sera l elemntos*/
    
    if(resultado == NULL){
        printf("Não consegui alocar o vetor resultante na memoria!");
        return 0;
    }else{
        mult(matriz, vetor, resultado, l, c);
        
        for(p = resultado; p < resultado + l; p++){
            printf("%.2f ", *p);
        }
    }

    free(vetor);
    free(resultado);

    for(q = matriz; q < matriz + l; q++){
        free(*q);
    }
    free(matriz);

    return 0;
    
}


void mult(float **matriz, float *vetor, float *resultado, int l, int c){
    float **q, *p, *v, aux;
    
    for(q = matriz; q < matriz + l; q++){
        
        aux = 0;
        v = vetor;
        
        for(p = *q; p < *q + c; p++){
            aux+= *p * *v;
            v++;
        }
        *resultado = aux;
        resultado++;
    }
    
}