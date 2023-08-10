#include <stdio.h>

/*
int main(){
    
    int n, digito, quant_par = 0, soma_par = 0, quant_dig = 0;
    
    scanf("%d", &n);
    
    int aux = n;
    
    while(n != 0){
        digito = n % 10;
        if(digito % 2 == 0){
            quant_par++;
            soma_par = soma_par + digito;
        }
        
        quant_dig++;
        n = n / 10;
        
    }
    
    printf("O numero %d eh formado por %d digitos\n", aux,quant_dig);
    
    if (quant_par != 0){
        
        printf("A media dos digitos pares do numero %d eh: %.2f", aux, (float)soma_par / quant_par);
    }else{
        printf("O numero %d nao possui digitos pares!", aux);
    }
    return 0;
}
*/

int le_valor(){
    int x;

    scanf("%d", &x);

    return x;
}

int att_valor(int num){
    num = num / 10;

    return num;
}

int ult_dig(int num){
    num = num % 10;

    return num;
}
int main(){

    int n, digito, quant_par = 0, soma_par = 0, quant_dig = 0;
    
    n = le_valor();
    
    int aux = n;
    
    while(n != 0){
        digito = ult_dig(n);

        if(digito % 2 == 0 && digito != 0){
            quant_par++;
            soma_par = soma_par + digito;
        }
        
        quant_dig++;
        n = att_valor(n);
        
    }
    
    printf("O numero %d eh formado por %d digitos\n", aux,quant_dig);
    
    if (quant_par != 0){
        
        printf("A media dos digitos pares do numero %d eh: %.2f", aux, (float)soma_par / quant_par);
    }else{
        printf("O numero %d nao possui digitos pares!", aux);
    }
    
    
    return 0;
}

    