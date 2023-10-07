//ordena dois vetores e faz a intercalaçao entre eles, de modo que o vetor resultante tbm seja ordenado

#include <stdio.h>
#include <stdlib.h>

void leitura(int *v, int n);

void ordena(int *v, int n);

void intercala(int *v1, int *v2, int *v3, int tam1, int tam2);

void imprima(int *v, int n);

int main(){
    int *v1, *v2, *v3, tam1, tam2;

    printf("Informe a dimensao do primeiro vetor:\n");
    scanf("%d", &tam1);

    printf("Informe a dimensao do segundo vetor:\n");
    scanf("%d", &tam2);

    v1 = (int *) malloc(tam1 * sizeof(int));
    v2 = (int *) malloc(tam2 * sizeof(int));

    if(v1 == NULL || v2 == NULL){
        printf("Nao foi possivel alocar os vetores na memoria!");
        return 0;
    }
    v3 = (int *) malloc((tam1+tam2) * sizeof(int));
    if(v3 == NULL){
        printf("Nao foi possivel alocar o vetor resultante na memoria!");
        return 0;
    }

    // eu so chego nessa parte do codigo se eu conseguir alocar os 3 vetores na memoria

    printf("Entre com os valores do primeiro vetor:\n");
    leitura(v1, tam1);
    printf("Entre com os valores do segundo vetor:\n");
    leitura(v2, tam2);
    
    ordena(v1, tam1);
    ordena(v2, tam2);
    
    intercala(v1, v2, v3, tam1, tam2);
            
    printf("Primeiro vetor ordenado:\n");
    imprima(v1, tam1);
    printf("Segundo vetor ordenado:\n");
    imprima(v2, tam2);
    printf("Vetor intercalado ordenado:\n");
    imprima(v3, tam1+tam2);
    
    free(v1);
    free(v2);
    free(v3);

    return 0;

}

void leitura(int *v, int n){
    int *p;
    
    for(p = v; p < v + n; p++){
        scanf("%d", p);
    }
    
}

void ordena(int *v, int n){
    int *p, *q, aux;
    
    for(p = &v[n-1]; p > v - 1; p--){
        for(q = v; q < p; q++){
            if(*q > *(q+1)){
            aux = *q;
            *q = *(q+1);
            *(q+1) = aux;
            }
        
        }
    
    }

}

void intercala(int *v1, int *v2, int *v3, int tam1, int tam2){
    int *p1, *p2, *q;
    
    p1 = v1;
    p2 = v2;
    q = v3;

    //q++ vem sempre depois da insercao de um elemento no vetor 3
    while(p1 < v1 + tam1 && p2 < v2 + tam2){
        if(*p1 <= *p2){
            *q = *p1;
            q++;
            p1++;
        }else{
            *q = *p2;
            q++;
            p2++;
        }
    }

    if(p1 < v1 + tam1){        //tem indices validos ainda no primeiro vetor
        while(p1 < v1 + tam1){
            *q = *p1;
            q++;
            p1++;
        }
    }else{                   // tem indice valido ainda no segundo vetor
        while(p2 < v2 + tam2){
            *q = *p2;
            q++;
            p2++;
        }
    }
    
}

void imprima(int *v, int n){
    int *p;
    
    for(p = v; p < v + n; p++){
        printf("%d ", *p);
    }
    printf("\n");
}