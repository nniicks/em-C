#include <stdio.h>
#define M 15
#define CAR 2


struct novoTipo{
    char marca[M];
    int ano;
    float preco;
};

void cadastro(novoTipo carros[CAR]);
void menores(novoTipo c[CAR], int *valor);


int main(){
    int n;
    novoTipo carros[CAR];
    
    cadastro(carros);
    
    printf("Informe um preco:\n");
    scanf("%d", &n);
    
    menores(carros, &n);;
    
    return 0;

}

void cadastro(novoTipo carros[CAR]){
    novoTipo *p;
    
    for(p = carros; p < carros + CAR; p++){
        printf("Digite a marca do carro:\n");
        scanf("%s", p->marca);
        
        printf("Digite o ano do carro: \n");
        scanf("%d", &p->ano);
        
        printf("Digite o preco do carro: \n");
        scanf("%f", &p->preco);
        
        
    }
}


void menores(novoTipo c[CAR], int *valor){
    novoTipo *p;
    
    for(p = c; p < c + CAR; p++){
        if(p->preco < *valor){
            printf("\n\n");
            printf("Marca: %s\n", p->marca);
            printf("Ano: %d\n", p->ano);
            printf("Preco: %.2f\n", p->preco);
            
        }
        
    }
}