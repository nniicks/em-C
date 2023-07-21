/*structs(registro) -----> permite vc crie um novo tipo de dado. nesse caso, vc tem um dado composto, ou seja, vc
consegue determinar quais sao os tipos de dados(campos) que compoem esse novo tipo q esta sendo criado. ou seja,
com isso vc consegue ter uma variavel que armazena int, float, chat e etc...

sintaxe de definiçao
struct <novo_tipo>{
	<tipo1> <campo1>;
	<tipo2> <campo2>;
	...
	<tipon> <campon>;

};

sintaxe de declaracao de variavel struct:
struct <novo_tipo> <nome_variavel>;
	<novo_nome> <nome_variavel>;

comando typedef: renomeia um indetificador(?)
sintaxe: typedef <tipo> <novo_nome>;

acessando os membros de uma struct: antes de mais nada, eh preciso haver
uma variavel desse tipo declarada
sintaxe: <variavel>. <campo>  (esse campo eh o tipo)*/

#include <stdio.h>
#include <string.h>

#define t 50

struct tipo_pessoa{
	int idade;
	float peso;
	char nome[t];

};

typedef struct tipo_pessoa tipo_pessoa;

int main(){
	//criando uma var do tipo_pessoa
	tipo_pessoa pes = {0, 0.0, "teste"};

	printf("inicio:\n");
	printf("pes.idade: %d\n", pes.idade);
	printf("pes.peso: %.2f\n", pes.peso);
	printf("pes.nome: %s\n", pes.nome);


	//atribuindo valores aos campos
	pes.idade = 10;
	pes.peso = 100.57;
	strcpy(pes.nome, "jhonathan");


	printf("\nalterando os campos via codigo:\n");
	printf("pes.idade: %d\n", pes.idade);
	printf("pes.peso: %.2f\n", pes.peso);
	printf("pes.nome: %s\n", pes.nome);

	//solicitando insercoes via teclado
	printf("\ninsira um numero inteiro:\n");
	scanf("%d", &pes.idade);
	
	printf("insira um numero real:\n");
	scanf("%f", &pes.peso);
	fflush(stdin);
	
	printf("insira uma palavra:\n");
	scanf("%s", &pes.nome);


	printf("\nalterando com dados do usuario:\n");
	printf("pes.idade: %d\n", pes.idade);
	printf("pes.peso: %.2f\n", pes.peso);
	printf("pes.nome: %s\n", pes.nome);

 
}