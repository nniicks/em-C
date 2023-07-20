/*dados de texto - strings. se vc precisar armazenar 10 letras em um vetor de char, vc vai ter que 
ter nesse vetor 11 posicoes, pois aqui em C vc precisa informar quando acaba uma palavra/texto.
e vc faz isso usando o "\0" na ultima posicao

scanf()
especificador de formato: %s  /  sintaxe geral: scanf("%s", <str>);
essa sintaxe geral n permite armazenar um frase por exemplo, ja q ele ignora oq vem depois do espaço
outra coisa tbm eh q o scanf perimite q vc acesse espaço de memoria n informada. por exemplo,
se eu declarar um vetor char de tamanho 5, e usar o scanf para guardar nele uma seq de palavras, de
modo q eu tenha mais do q 5 palavras, eu n vou ter um erro de compilaçao. mas isso eh obviamente problematico 

sintaxe aprimorada: scanf("%<tam.-1[^\n]s", <str>);

printf()
especificador de formato: %s
sintaxe: printf("<texto>", <str1>, <str2>, ..., <strn>);

------ outras funcoes de estrada de dados via teclado -------

gets() -----> gets(<string>);
limitacoes: estouro do limite do vetor

fgets() -----> fgets(<string>, <tam>, stdin);
ultimo caracter sempre fica reservado ao "\0"
entrada padrao: stdin

------ outras funcoes de saida de dados na tela -------

puts() ------> puts(<string>);
imprime uma string diretamente na tela
n admite variaveis de outros tipos como argumento

fflush(stdin): chamar sempre depois de uma entrada

para usar essas func tem q incluir string.h
obs: aqui, string n se altera com =, assim como uma var do tipo int ou float. aqui, vc altera 
uma string com strcpy(<destino>,<origem>);.
strlen(<string>); mostra o tamanho de uma string
strcmp(<string1>, <string2>); retorna o valor "0" se as duas strings forem iguais
strcat(<destino>, <origem>); eh tipo uma concatenaçao

*/



#include <stdio.h>

int main(){
    char nome[10];

    printf("Digite algo (scanf convencional):\n");
    scanf("%s", nome);
    fflush(stdin);

    printf("Resultado: %s\n\n", nome);

    printf("Digite algo (scanf aprimorado): \n");
    scanf(" %[^\n]", nome);
    fflush(stdin);

    printf("Resultado: %s\n\n", nome);
}

