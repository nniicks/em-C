//intercalacao de 2 vetores de mesma dimensao

#include <stdio.h>
#include <stdlib.h>

void leitura(int *vetor, int n);
void imprime(int *vetor, int n);

void intercala(int *v1, int *v2, int *v3, int n);

int main(){
    int *v1, *v2, *v3, n;

    printf("Informe a dimensao do vetor:\n");
    scanf("%d", &n);

    v1 = (int *) malloc(n * sizeof(int));   //alocacao dinamica do primeiro vetor
    v2 = (int *) malloc(n * sizeof(int));   //alocacao dinamica do segundo vetor

    if(v1 == NULL || v2 == NULL){
        printf("Nao foi possivel alocar os vetores na memoria!");
        return 0;
    }
    // se eu entrar no if eu ja encerro o programa, logo nao precida de um else

    v3 = (int *) malloc((n+n) * sizeof(int));
    if(v3 == NULL){
        printf("Nao foi possivel alocar o vetor resultante na memoria!");
        return 0;
    }

    printf("Entre com os valores do primeiro vetor:\n");
    leitura(v1, n);
    printf("Entre com os valores do segundo vetor:\n");
    leitura(v2, n);

    intercala(v1, v2, v3, n);
    printf("Vetor resultante da intercalacao:\n");
    imprime(v3, n+n);

    free(v1);
    free(v2);
    free(v3);

    return 0;

}

void leitura(int *vetor, int n){
    int *p;

    for(p = vetor; p < vetor + n; p++){
        scanf("%d", p);
    }
}

void imprime(int *vetor, int n){
    int *p;

    for(p = vetor; p < vetor + n; p++){
        printf("%d ", *p);
    }
}

void intercala(int *v1, int *v2, int *v3, int n){
    int *p1, *p2, *q;

    p2 = v2;
    q = v3;
    for(p1 = v1; p1 < v1 + n; p1++){
        *q = *p1;
        q++;
        *q = *p2;
        q++;
        p2++;
    }
}