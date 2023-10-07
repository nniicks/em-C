//intercalando dois vetores de dimensoes diferentes(ou iguais tbm)

#include <stdio.h>
#include <stdlib.h>

void leitura(int *v, int n);
void imprime(int *v, int n);
void intercala(int *v1, int *v2, int *v3, int n, int m);  //n=tamanho do primeiro vetor, m= tamanho do segundo vetor

int main(){
    int *v1, *v2, *v3, tam1, tam2;

    printf("Informe a dimensao do primeiro vetor:\n");
    scanf("%d", &tam1);

    printf("Informe a dimensao do segundo vetor:\n");
    scanf("%d", &tam2);

    v1 = (int *) malloc(tam1 * sizeof(int));
    v2 = (int *) malloc(tam2 * sizeof(int));

    if(v1 == NULL || v2 == NULL){
        printf("Impossivel alocar na memoria os veteros!");
        return 0;
    }
    v3 = (int *) malloc((tam1+tam2) * sizeof(int));

    if(v3 == NULL){
        printf("Nao foi possivel alocar o vetor resultante!");
        return 0;
    }

    printf("Entre com os valores do primeiro vetor:\n");
    leitura(v1, tam1);

    printf("Entre com os valores do segundo vetor:\n");
    leitura(v2, tam2);
    
    intercala(v1, v2, v3, tam1, tam2);
    printf("Vetor intercalado:\n");
    imprime(v3, tam1+tam2);

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

void imprime(int *v, int n){
    int *p;

    for(p = v; p < v + n; p++){
        printf("%d ", *p);
    }
}

void intercala(int *v1, int *v2, int *v3, int n, int m){
    int *p1, *p2, *q;

    p1 = v1;
    p2 = v2;
    q = v3;
    while(p1 < v1 + n && p2 < v2 + m){
        *q = *p1;
        q++;
        *q = *p2;
        q++;
        p1++;
        p2++;
    }

    if(p1 < v1 + n){    //v1 ainda possui indices validos de acesso, ou seja, ele eh maior do que o v2
        while(p1 < v1 + n){
            *q = *p1;
            q++;
            p1++;
        }
    }else{
        while(p2 < v2 + m){    //agr o v2 ainda tem indices validos
            *q = *p2;
            q++;
            p2++;
        }
    }
}