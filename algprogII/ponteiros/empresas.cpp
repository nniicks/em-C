#include <stdio.h>
#define M 30
#define Q 10

struct loc{
    char cidade[M], estado[M];
};

struct novoTipo{
    char nome[M];
    int cnpj;
    loc localizacao;
};

int main(){
    
    novoTipo empresas[Q], *p;
    int n;
    
    scanf("%d", &n);
    getchar();
    
    for(p = empresas; p < empresas + n; p++){
        printf("Informe o nome da empresa:\n");
        scanf("%[^\n]", p->nome);
        getchar();
        
        printf("Informe o CNPJ da empresa:\n");
        scanf("%d", &p->cnpj);
        getchar();
        
        printf("Informe em qual Estado empresa fica lozalizada:\n");
        scanf("%[^\n]", p->localizacao.estado);
        getchar();
        
        printf("Infome o nome da cidade onde a empresa esta localizda:\n");
        scanf("%[^\n]", p->localizacao.cidade);
        getchar();
        
    }

    printf("\n");
    for(p = empresas; p < empresas + n; p++){
        printf("Nome da empresa: %s\n", p->nome);
        printf("CNPF da empresa: %d\n", p->cnpj);
        printf("Estado de localizacao: %s\n", p->localizacao.estado);
        printf("Cidade de localizacao: %s\n", p->localizacao.cidade);
        
        
    }
    
    return 0;
}