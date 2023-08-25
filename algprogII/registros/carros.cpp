/*Faca um programa para cadastrar carros com os seguintes dados: 
marca (maximo de 15 letras), ano e preço. Suponha que no maximo serao cadastrados
30 carros. O seu programa deve possuir o seguinte menu:

1 - Cadastrar um carro: nesta opcao o usuario informa os dados de APENAS UM CARRO, que 
deverão ser armazenados num vetor de registros.

2 - Listar carros: lista os dados de todos os carros cadastrados

3 - Media de precos: calcula e imprime a media dos precos dos carros de um determinado
ano. O usuario informa um ano e a media dos precos dos carros deste ano
deve ser impressa.

FUNCOES A CRIAR:
1 - Uma funcao para cadastrar um carro: recebe o vetor e o numero de carros cadastrados 
ate o momento. Atencao: nesta funcao o numero de carros deverá aumentar em uma unidade.
2 - Uma funcao para listar os dados de todos os carros: recebe o vetor e o numero de carros
cadastrados ate o momento
3 - Uma funcao para calcular e retornar a media dos precos dos carros de um determinado ano 
informado pelo usuario: recebe o vetor, o numero de carros
cadastrados ate o momento e um ano, retorna a media.
*/

#include <stdio.h>
#define MAX 15
#define MAX_C 30

struct tipo_carro{
    char marca[MAX];
    int ano;
    float preco;
};

void menu(); /*prototipo da funcao menu*/

int cad(int num_carros, tipo_carro c[MAX_C]){
    /*esse vetor c q eu criei eh so um nome diferente do vetor carro que eu 
    declarei na main, pq eles sao o mesmo vetor. ent n precisava ter dado outro nome pra ele*/
    
    printf("Informe a marca do carro de numero  %d:\n", num_carros+1);
    scanf("%s", c[num_carros].marca);
    printf("Informe o ano do carro de numero %d:\n", num_carros+1);
    scanf("%d", &c[num_carros].ano);
    printf("Informe o preco do carro de numero %d:\n", num_carros+1);
    scanf("%f", &c[num_carros].preco);

    return num_carros+1;

}

void listar(int num_carros, tipo_carro c[MAX_C]){

    for(int i = 0; i < num_carros; i++){
        printf("-----------------------------------\n");
        printf("Marca: %s\n", c[i].marca);
        printf("Ano: %d\n", c[i].ano);
        printf("Preco: %.2f", c[i].preco);
        printf("\n");
    }

    
}

float media(int num_carros, tipo_carro c[MAX_C], int ano){
    float soma = 0;
    int aux = 0; /*pra controlar a qant de carros que sao do ano informado*/

    for(int i = 0; i < num_carros; i++){
        if(c[i].ano == ano){
            soma+= c[i].preco;
            aux++;
        }
    }

    return soma / aux;

}


int main(){

    int opcao, quant_carro = 0, ano_media;
    tipo_carro carro[MAX_C];
    float m;

    do{

        menu();/*chama a funcao menu*/
        scanf("%d", &opcao);
        
        if(opcao == 1){
            /*ler os dados de um carro - funcao*/
            quant_carro = cad(quant_carro, carro);
    
        }
        else if(opcao == 2){
            /*imprimir todos os carros cadastrados - funcao*/
            listar(quant_carro, carro);

        }
        else if(opcao == 3){
            /*ler um ano e imprimir a media dos precos dos carros do ano*/
            printf("Informe o ano desejado:\n");
            scanf("%d", &ano_media);
            m = media(quant_carro, carro, ano_media);
            printf("A media dos precos do ano %d eh:\n%.2f", ano_media, m);
            printf("\n");

        }
    }while(opcao != 4);

    return 0;
}


void menu(){
    printf("\n[1] cadastrar um carro\n");
    printf("[2] listar carros\n");
    printf("[3] media dos carros\n");
    printf("opcao: ");
}