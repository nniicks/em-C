/*void LeValor(int &n);
void UltimoDigito(int n, int &digito);
void AtualizaValor(int &n);*/

#include <stdio.h>

void le_valor(int &x){

    scanf("%d", &x);
}


void ult_dig(int x, int &dig){

    dig = x % 10;
}

void att_valor(int &x){

    x = x / 10;
}

int main(){
    int n, digito, quant_par = 0, soma_par = 0, quant_dig = 0;
    int aux;

    le_valor(n);
    aux = n;

    while(n != 0){
        ult_dig(digito, digito);
        if(digito % 2 == 0){
            quant_par++;
            soma_par = soma_par + digito;
        }

        quant_dig++;
        att_valor(n);

    }

    printf("o numero %d possui %d digitos\n",aux, quant_dig);

    if(quant_par != 0){
        printf("A media dos digitos pares do numero %d eh: %.1f", aux, (float)soma_par/quant_par);
    }else{
        printf("O numero %d nao possui digitos pares!", aux);
    }

    return 0;

}