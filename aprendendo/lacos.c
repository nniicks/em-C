/*--- WHILE ---

inicializacao de uma ou mais variaveis de controle
definicao de uma condicao de parada (flag)
    enquanto for verdadeira: repete
atualizacao da(s) variavel(eis) de controle  

SINTAXE

while (<condicao>) {

    <bloco_de_comandos>

}

exemplo:
    int i = 0;

    while(i <= 10){

        printf("%d\n", i);
        
        i++;
    }

--- DO-WHILE ---

eh tipo o while true. aqui a condicao eh avaliada apenas no final, ou seja, ele executa
um bloco de comandos e depois verifica se vai continuar repetindo ou nao.
oq faz com que o bloco de comandos seja executado pelos menos uma vez.

SINTAXE

do{
    <bloco_de_comandos>

}while (<condicao>);

exemplo:
    int i = 0;

    do{
        printf("%d ", i);
        i++;

    }while(i <= 10);


--- FOR ---
similar ao while
inicializacao, condicao, atualizacao
diferença crucial:
    sintaxe mais complexa
    tudo fica embutido no comando

SINTAXE

for(<ini.>; <cond.>; <incr.>) {

    <bloco_de_comandos>
}

exemplo:
    int i;

    for (i = 1; i <= 10; i++){
        
        printf("%d ", i);
    }

comandos de controle de desvio
break: utilizado para encerrar por completo uma seq de repetcoes
continue: usado para pular a interacao atual, passando assim
para a proxima iteracao

*/

#include <stdio.h>

int main(){
    int i;

    for (i = 1; i <= 10; i++){

        if (i == 5){
            continue;/*daqui eu vo pro i++ dentro do for. ou seja, n vou imprimir o 5*/
        }

        printf("%d ", i);
    }

}