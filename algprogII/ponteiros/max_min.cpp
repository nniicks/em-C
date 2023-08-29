#include <stdio.h>
#define MAX 100

void min_max(int n, int v[MAX], int *max, int *min);

int main(){
    int n, v[MAX], maximo, minimo, *p;
    
    scanf("%d", &n);
    for(p = v; p < v + n; p++){
        scanf("%d", p);
    }
    
    min_max(n, v, &maximo, &minimo);
    
    printf("%d\n", maximo);
    printf("%d", minimo);
    
    return 0;
}

void min_max(int n, int v[MAX], int *max, int *min){
    int *pont;
    *max = *v, *min = *v;
    
    for(pont = v; pont < v + n; pont++){
        if(*pont > *max){
            *max = *pont;
        }
        
        if(*pont < *min){
            *min = *pont;
        }
    }
    
}

/*#include <stdio.h>
#define MAX 100

void min_max(int n, int v[MAX], int &max, int &min);

int main(){
    int n, v[MAX], maximo, minimo, *p;
    
    scanf("%d", &n);
    for(p = v; p < v + n; p++){
        scanf("%d", p);
    }
    
    min_max(n, v, maximo, minimo);
    
    printf("%d\n", maximo);
    printf("%d", minimo);
    
    return 0;
}

void min_max(int n, int v[MAX], int &max, int &min){
    int *pont;
    max = *v, min = *v;
    
    for(pont = v; pont < v + n; pont++){
        if(*pont > max){
            max = *pont;
        }
        
        if(*pont < min){
            min = *pont;
        }
    }
    
}*/