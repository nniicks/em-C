#include <stdio.h>
#define MAX 60
#define TAM 5

struct tipo_data{
    int dia, mes, ano;
};

struct novo_tipo{
    char compromisso[MAX];
    tipo_data data;
};

int main(){
    novo_tipo agenda[TAM];
    int m, a;
    
    for(int i = 0; i < TAM ; i++){
        scanf("%s", agenda[i].compromisso);
        scanf("%d/%d/%d", &agenda[i].data.dia, &agenda[i].data.mes, &agenda[i].data.ano);
    }
    do{
        scanf("%d/%d", &m, &a);
        
        for(int i = 0; i < TAM ; i++){
            if(agenda[i].data.mes == m && agenda[i].data.ano == a){
                printf("%s\n", agenda[i].compromisso);
            }
        }
           
    }while(m != 0);
    
    return 0;
}