#include <stdio.h>
#define MAX 10

int main(void){
    int v[MAX], N;
    int *p, *q = &v[N - 1], aux;

    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        scanf("%d", &v[i]);
    }
    
    for(p = v; p < q ; p++){
        aux = *p;
        *p = *q;
        *q-- = aux;
    }
    
    for(p = v; p < v + N; p++){
        printf("%d ", *p);
    }
}
