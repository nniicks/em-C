#include <stdio.h>
#define MAX 100

int *maximo(int n, int v[MAX]);

int main(){
    int N, v[MAX], endereco, *pnt;
    
    scanf("%d", &N);
    
    for(pnt = v; pnt < v + N; pnt++){
        scanf("%d", pnt);
    }
    
    endereco = *maximo(N, v);
    printf("%d", endereco);
    
    return 0;
    
}

int *maximo(int n, int v[MAX]){
    int *ind_maior = v, *p;
    
    for(p = v; p < v + n; p++){
        if(*p > *ind_maior){
            ind_maior = p;
        }
    }
    return ind_maior;
}

/*#define MAX 100

int &maximo(int n, int v[MAX]);

int main(){
    int N, v[MAX], *endereco, *pnt;
    
    scanf("%d", &N);
    
    for(pnt = v; pnt < v + N; pnt++){
        scanf("%d", pnt);
    }
    
    endereco = &maximo(N, v);
    printf("%p", endereco);
    
    return 0;
    
}

int &maximo(int n, int v[MAX]){
    int *ind_maior = v, *p;
    
    for(p = v; p < v + n; p++){
        if(*p > *ind_maior){
            ind_maior = p;
        }
    }
    return *ind_maior;
}*/
