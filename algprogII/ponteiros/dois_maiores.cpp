#include <stdio.h>
#define MAX 100

void dois_maiores(int n, int v[MAX], int *pri, int *seg);

int main(){
    int n, primeiro, segundo, *p, v[MAX];
    
    scanf("%d", &n);
    
    for(p = v; p < v + n; p++){
        scanf("%d", p);
    }
    
    dois_maiores(n, v, &primeiro, &segundo);
    
    printf("%d\n", primeiro);
    printf("%d", segundo);
    
    
    return 0;
}

void dois_maiores(int n, int v[MAX], int *pri, int *seg){
    int *pont;
    *pri = *v;
    *seg = *(v+1);
    
    
    for(pont = (v+1); pont < v + n; pont++){
        if(*pont > *pri){
            *seg = *pri;
            *pri = *pont;
        }else if(*pont > *seg){
            *seg = *pont;
            
        }
        
    }
}

/*essa comparcao ai parte do principio que o maior elemento eh o primeiro. se ele ja eh o 
meu maior valor, eu vou tentar achar o segundo maior, porem eu começo 1 posicao a mais que o meu primeiro
elemento(ja que ele eh, em teoria, o maior). nesse caso, achar o segundo maior aqui equivale a mesma ideia
de achar o maior num vetor de tamanho n, por isso eu começo justamento na posicao do segundo (pois o meu
primeiro ja foi descartado). porem, a cada elemento eu comparo se ele eh meior que o meu maior, se ele for, 
eu atualizo o meu maior, mas antes eu faço o meu segundo maior receber o primeiro maior que eu tinha definido,
pois agr ele eh o segundo maior. se o elemento atual n eh maior que o meu maior de todos, eu vejo se ele eh maior
que o segundo, se for eu atualizo o meu segundo maior.*/
