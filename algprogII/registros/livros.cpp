/*/*Faca um programa que leia um vetor com os dados de N (N <= 10)livros: 
titulo (maximo de 30 letras), autor (maximo de 30 letras) e ano. Leia um valor P e 
mostre as informacoes de todos os livros com ano abaixo de P. Repita este processo ate que seja lido 
um valor P = 0 seja informado. 

Crie uma funcao para fazer a leitura dos N livros, armazenando-os em um vetor de 
registros. A funcao deve receber como parametro o valor de N e o vetor para armazenar
os dados.

Crie uma funcao para fazer a listagem dos livros com ano menor que P.*/

#include <stdio.h>
#define MAX 30
#define N 10

struct tipo_livro{
    char titulo[MAX], autor[MAX];
    int ano;
};

void leitura(int n, tipo_livro livros[MAX]);

void listagem(tipo_livro l[MAX], int n, int p);



int main(){
    tipo_livro livros[N];
    int p, quantL;

    printf("Informe a quantidade de livros desejados (um valor entre 0 e 10):\n");
    scanf("%d", &quantL);

    leitura(quantL, livros);

    do{
        printf("Informe um ano qualquer:\n");
        scanf("%d", &p);

        listagem(livros, quantL, p);


    }while(p != 0);


}

void leitura(int n, tipo_livro l[MAX]){
    printf("%d\n", n);
    for(int i = 0; i < n; i++){
        printf("Informe o titulo do livro de numero %d:\n", i+1);
        scanf("%s", l[i].titulo);
        printf("Informe o nome do autor do livro de numero %d\n", i+1);
        scanf("%s", l[i].autor);
        printf("Informe o ano de publicacao do livro de numero %d\n", i+1);
        scanf("%d", &l[i].ano);
    }

}

void listagem(tipo_livro l[MAX], int n, int p){

    for(int i = 0; i < n; i++){
        if(l[i].ano < p){
            printf("Livro %s, de autoria de %s --- ano de publicacao: %d\n", l[i].titulo, l[i].autor, l[i].ano);
        }
    }
}