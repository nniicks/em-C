#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define T 2
#define M 50

struct novoT{
    char nome[M];
    float salario;
    
};

void cadastro(novoT *V);
void ordenar(novoT *P);
void imposto(novoT *v);
void imprimir(novoT *i);
void busca (novoT *I);

int main(){
    novoT lista[T];
    
    cadastro(lista);
    ordenar(lista);
    imposto(lista);
    imprimir(lista);
    busca(lista);
    
}


void cadastro(novoT *V){
    novoT *ptaux;
    
    for(ptaux = V; ptaux < V + T; ptaux++){
        printf("Informe o nome:\n");
        scanf("%[^\n]", ptaux->nome);
        getchar();
        
        printf("Informe o salario:\n");
        scanf("%f", &ptaux->salario);
        getchar();
    }
}

void ordenar(novoT *P){
    novoT *p, *q;
    float aux;
    char nomeaux[M];
    
    for(p = &P[T - 1]; p > P; p--){
        for(q = P; q < p; q++){
            if(q->salario > (q + 1)->salario){
                aux = q->salario;
                q->salario = (q + 1)->salario;
                (q + 1)->salario = aux;
                
                strcpy(nomeaux, q->nome);
                strcpy(q->nome, (q+1)->nome);
                strcpy((q+1)->nome, nomeaux);
            }
        }
    }
    
}

void imposto(novoT *v){
    novoT *vaux;
    
    for(vaux = v; vaux < v + T; vaux++){
        printf("\n");
        printf("Nome: %s\n", vaux->nome);
        
        if(vaux->salario <= 850){
            printf("Insento!\n");
            printf("Salario: %.2f\n", vaux->salario);
        }else if(vaux->salario > 850 && vaux->salario < 1200){
            printf("Imposto: %.2f\n", vaux->salario*0.1);
            printf("Valor a receber: %.2f\n", vaux->salario*0.9);
        }else{
            printf("Imposto: %.2f\n", vaux->salario*0.2);
            printf("Valor a receber: %.2f\n", vaux->salario*0.8);
        }
    }
}


void imprimir(novoT *i){
    novoT *j;
    
    
    printf("----- ORDEM CRESCENTE DE SALARIO -----\n");
    for(j = i; j < i + T; j++){
        printf("\n");
        printf("Nome: %s\n", j->nome);
        printf("Salario: %.2f\n", j->salario);
    }
    
    printf("----- ORDEM DESCRESCENTE DE SALARIO -----\n");
    for(j = &i[T-1]; j > i - 1; j--){
        printf("\n");
        printf("Nome: %s\n", j->nome);
        printf("Salario: %.2f\n", j->salario);
    }
}


void busca (novoT *I){
    novoT *jaux;
    char letra, *pletra;
    
    printf("Informe uma letra:\n");
    scanf("%c", &letra);
    getchar();
    
    printf("---- LISTA DE NOMES QUE COMEÇAM COM A LETRA %c\n", letra);
    for(jaux = I; jaux < I + T; jaux++){
        pletra = jaux->nome;
        
        // converte as duas letras para minusculo antes de comparalas
        if(tolower(letra) == tolower(*pletra)){
        printf("Nome: %s\n", jaux->nome);
        printf("Salario: %.2f\n", jaux->salario);
        }
    
    }
}
