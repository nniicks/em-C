#include <stdio.h>

#define M 30
#define L 20

struct tipo_h{
    int hh, mm, ss;
};

struct tipo_d{
    int dia, mes, ano;
};

struct tipo_compr{
    tipo_h hora;
    tipo_d data;
    char descricao[M];
};

void preencher(tipo_compr v[L], int *q);

void busca(tipo_compr v[L], int m, int *q);

int main(){
    tipo_compr compromisso[L], *p;
    int n, mes;
    
    
    printf("Informe quantos compromissos voce deseja adcionar:\n");
    scanf("%d", &n);
    
    preencher(compromisso, &n);
    
    printf("Informe a um mes:\n");
    scanf("%d", &mes);
    
    busca(compromisso, mes, &n);
    
    return 0;
}

void preencher(tipo_compr v[L], int *q){
    
    tipo_compr *p;
    
     for(p = v; p < v + *q; p++){
    
        printf("Digite a data do compromisso:\n");
        scanf("%d/%d/%d", &p->data.dia, &p->data.mes, &p->data.ano);
        getchar();
        
        printf("Digite o horario do compromisso:\n");
        scanf("%d:%d:%d", &p->hora.hh, &p->hora.mm, &p->hora.ss);
        getchar();
        
        printf("Por fim, digite a descricao do compromisso:\n");
        scanf("%[^\n]", p->descricao);
        getchar();
        
    }
    
}

void busca(tipo_compr v[L], int m, int *q){
    tipo_compr *p;
    
    printf("No mes %02d, voce tem os seguintes compromissos:\n", m);
    
    for(p = v; p < v + *q; p++){
        if(p->data.mes == m){
            printf("\n");
            printf("descricao: %s\n", p->descricao);
            printf("Data: %d/%d/%d\n", p->data.dia, p->data.mes, p->data.ano);
            printf("horario: %d:%02d:%02d\n", p->hora.hh, p->hora.mm, p->hora.ss);
        }
        
    }
}
