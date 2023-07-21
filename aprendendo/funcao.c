/*funcoes de modularizacao de codigos
funcoes: resolver problemas complexos atraves da combinacao de 
solucoes menores

sintaxe de definicao: 
<tipo> <nome_da_funcao>(<parametros>){
	
	<bloco_de_comandos>
	return <informacao>;

}

sintaxe para parametros struct:
<tipo> <nome_funcao>{<tipo_struct> <param>){...}

sintaxe para vetores como parametros:
<tipo> <nome_da_funcao>(<tipo> <vet[]>, int tamanho_vetor){...}
<tipo> <nome_da_funcao>(<tipo> *<vet>, int tamanho_vetor){...}
<tipo> <nome_da_funcao>(<tipo> <vet>[<tamanho>]){...}

sintaxe para matrizes como parametros:
<tipo> <nome_da_funcao>(<tipo> m[][tam2], int tam1){...}

para vc poder usar uma funcao dentro do main, vc tem q declarar e definir 
essa funcao antes de chamar a funcao main, pois se isso n for feito vai dar erro
de compilacao. porem, vc consegue fazer um prototipo de funcao, eai vc consegue 
declarar uma funcao (apenas declarar e n definir) antes do main, e chama-la dentro
da funcao main antes mesmo de defini-la, e isso n vai dar erro de compilacao.

sintaxe de um prototipo de funcao:
<tipo> <nome_da_funcao>(<parametros>);

*/

#include <stdio.h>

int maior(int n1, int n2){
    if(n1 > n2){
        return n1;
    }
    else{
        return n2;
    }
}

int main(){
    int x, y, resultado;

    printf("Informe um numero inteiro:\n");
    scanf("%d", &x);

    printf("Informe outro numero inteiro:\n");
    scanf("%d", &y);

    resultado = maior(x, y);

    printf("O maior numero eh %d", resultado);

}