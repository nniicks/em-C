/*) Faca um programa que leia uma matriz M de inteiros de dimensao n, para
1 < n < MAX, sendo MAX = 100, e determine a soma dos elementos da diagonal principal
e secundaria. Seu programa deve implementar as seguintes funcoes:
int LeDimensao();
void LeMatriz(int n, int M[MAX][MAX]);
int SomaDPrincipal(int M[MAX][MAX], int n);
void SomaDSecundaria(int n, int M[MAX][MAX], int &soma);
void ImprimeMatriz(int n, int M[MAX][MAX]);
void ImprimeSomas(int n, M[MAX][MAX], int somaP, int somaS);

*/

#include <stdio.h>

#define MAX 100

int le_dimensao(){
    int i;

    scanf("%d", &i);

    return i;
}

void le_matriz(int n, int Matriz[MAX][MAX]){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            scanf("%d", &Matriz[i][j]);
        }
    }
}

int soma_principal(int Matriz[MAX][MAX], int dimensao){
    int soma_P = 0;

    for(int i = 0; i < dimensao; i++){
        for (int j = 0; j < dimensao; j++){
            if(i == j){
                soma_P +=  Matriz[i][j];
            }
        }
    }

    return soma_P;
}


void soma_secundaria(int dimensao, int Matriz[MAX][MAX], int &soma){

    for(int i = 0; i < dimensao; i++){
            soma += Matriz[i][dimensao - 1 - i];
              
    }
    
}

void imprime_m(int dimensao, int Matriz[MAX][MAX]){
    for(int i = 0; i < dimensao; i++){
        for(int j = 0; j , dimensao; j++){
            printf("%d ", &Matriz[i][j]);
        }
        printf("\n");
    }
}

void imprime_somas(int d, int Matriz[MAX][MAX], int p, int s){
    p = soma_principal(Matriz, d);
    soma_secundaria(d, Matriz, s);
    printf("A soma da diagonal principal eh %d!", p);
    printf("A soma da diagonal secundaria eh %d", s);

}

int main(){
    int M[MAX][MAX], n;
    int somaP = 0, somaS = 0;
    
    do{
        n = le_dimensao();
    }while(n < 1 || n > 100);

    le_matriz(n, M); /*tenho a M*/
    imprime_m(n, M); /* imprime a matriz*/
    imprime_somas(n, M, somaP, somaS);

    return 0;
}