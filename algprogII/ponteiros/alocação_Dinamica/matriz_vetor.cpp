#include <stdio.h>
#include <stdlib.h>

// tem mt coisa errada aqui ainda;-;

void mult(float **m_aux, float *v_aux, float *p_aux, int l, int c);

int main(){
    float *vetor, **matriz, **p, *pt, *q; //q vai guardar o resultado da mult da matriz pelo vetor
    int l, c;
    
    printf("Informe as dimensoes da matriz: ");
    scanf("%d %d", &l, &c);
    
    vetor = (float *) malloc(c * sizeof(float));
    if(vetor == NULL){
        printf("Não foi possivel alocar o vetor na memoria!");
        return 0;
    }else{
        printf("Informe os %d valores do vetor:\n", c);
        for(pt = vetor; pt < vetor + c; pt++){
            scanf("%f", pt);
        }
    }
    
    matriz = (float **) malloc(l * sizeof(float *));
    if(matriz != NULL){
        for(p = matriz; p < matriz + l; p++){
            *p = (float *) malloc(c * sizeof(float *));
            if(*p == NULL){
                printf("Não foi possivel alocar a matriz na memoria!");
                return 0;
            }
        }
        // consegui alocar toda a matriz
        printf("Informe os valores da matriz:\n");
        for(p = matriz; p < matriz + l; p++){
            for(pt = *p; pt < *p + c; pt++){
                scanf("%f", pt);
            }
        }
        
    }else{
        printf("Não foi possivel alocar a matriz na memoria!");
        return 0;
    }
    
    q = (float *) malloc(l * sizeof(float));
    if(q == NULL){
        printf("Não foi possivel alocar o vetor resultante!");
        return 0;
    }else{
        mult(matriz, vetor, q, l, c);
        
        for(pt = q; pt < q + c; pt++){
            printf("%f ", *pt);
        }
    }
    
    
}


void mult(float **m_aux, float *v_aux, float *p_aux, int l, int c){
    
    float **matriz, *pt_linha, aux = 0;
    
    for(matriz = m_aux; matriz < m_aux + l; matriz++){
        
        for(pt_linha = *matriz; pt_linha < *matriz + c; pt_linha++){
            aux+= *pt_linha * *v_aux;
            v_aux++;
        }
        *p_aux = aux;
        p_aux++;
    }
}

