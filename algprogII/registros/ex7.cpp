/*Escrever um programa que cadastre N produtos, onde N será fornecido pelo usuário ( N<=10). 
Cada produto tem os seguintes campos: código, nome (tamanho 30) e preço. 
Após o cadastro, seu programa deve listar o código e nome de cada produto ( um por linha). 
Por último, consulte o preço de um produto através de seu código.
Observação: suponha que o nome do produto não terá espaços.

Exemplo: Suponha que a seguinte sequência de dados tenha sido informada
5
1 laranja 1.4
2 rosquinha 3
3 leite-moca 4.5
4 farinha-de-trigo 2.7
5 coxinha 1.5
O programa deverá mostrar depois a listagem dos cadastrados e esperar que o usuário informe um número
para consulta do preço:

LISTAGEM
1 laranja 1.4
2 rosquinha 3
3 leite-moca 4.5
4 farinha-de-trigo 2.7
5 coxinha 1.5
4

O programa deverá fornecer o preço como saída (com duas casas decimais):
Preço: R$ 2.70

Se o código informado não existir, o programa deverá imprimir "Inexistente".*/

#include <stdio.h>
#define MAX 30
#define QUANT 10


struct novo_tipo{
    int codigo;
    char nome[MAX];
    float preco;
};

int main(){
    novo_tipo N[QUANT];
    int pedido, produtos;
    int flag = 0;
    
    scanf("%d", &produtos);
    
    for(int i = 0; i < produtos; i++){
        scanf("%d %s %f", &N[i].codigo, N[i].nome, &N[i].preco);

    }
    
    printf("LISTAGEM\n\n");
    for(int i = 0; i < produtos; i++){
        printf("%d %s %.1f\n", N[i].codigo, N[i].nome, N[i].preco);
        printf("\n");
    }
    
    scanf("%d", &pedido);
    
    for(int i = 0; i < produtos; i++){
        if(N[i].codigo == pedido){
            printf("Preco:RS%.2f\n", N[i].preco);
            flag = 1;
            break;
        }
    }
    
    if(flag == 0){
        printf("Inexistente\n");
    }
    
    return 0;
    
}
