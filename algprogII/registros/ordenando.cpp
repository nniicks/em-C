/*Dado um número inteiro n, com 1 ≤ n ≤ 100, e
n medidas de tempo dadas em horas, minutos
e segundos, distintas duas a duas, ordenar
essas medidas de tempo em ordem crescente.*/

#include <stdio.h>
#define MAX 100

struct novo_tipo{

    int hh, mm, ss;

};

int main(){

    novo_tipo lista[MAX];
    int n, aux;

    do{
        printf("Informe a quantidade de medidas de tempo (qualquer valor entre 1 e 100!):\n");
        scanf("%d", &n);
    }while(n > 100 || n < 1);

    for(int i = 0; i < n; i++){
        printf("Informe tempo de numero %d! (hh:mm:ss): ", i+1);
        scanf("%d:%d:%d", &lista[i].hh, &lista[i].mm, &lista[i].ss);
    }

    for(int i = n - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(lista[j].hh > lista[j+1].hh){
                aux = lista[j].hh;
                lista[j].hh = lista[j+1].hh;
                lista[j+1].hh = aux;
            
            }else if(lista[j].hh == lista[j+1].hh){
                if(lista[j].mm > lista[j+1].mm){
                    aux = lista[j].mm;
                    lista[j].mm = lista[j+1].mm;
                    lista[j+1].mm = aux;
                
                }else if(lista[j].mm == lista[j+1].mm){
                    if(lista[j].ss > lista[j+1].ss){
                        aux = lista[j].ss;
                        lista[j].ss = lista[j+1].ss;
                        lista[j+1].ss = aux;
                    }
                }
            }
        }
    }

    printf("O tempo em ordem crescente eh:\n");
    for(int i = 0; i < n; i++){
        printf("%d hora(s), %d minuto(s) e %d segundo(s)\n", lista[i].hh, lista[i].mm, lista[i].ss);
    }


    return 0;

    
}

  



