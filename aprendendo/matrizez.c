/*matrizes podem ter varias dimensoes
dois ou mais indices para o acesso as dimensoes

sintaxe:
<tipo> <nome>[<dim1>][<dim2>]...[<dimn>];

sintaxe de acesso a posicao:
<nome>[<i1>][<i2>]...[<in>]

sintaxe de inicializacao:
<declaracao> = {{<l1>}, {<l2>}, ..., {<l3>}};

exemplo:
int m[2][2];

m[0][0] = 100;
m[0][1] = 300;
m[1][0] = 500;
m[1][1] = 600;*/

#include <stdio.h>

int main(){
    int m[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int i,j;

    for(i = 0; i < 3; i++){
	    for(j = 0; j < 3; j++){
		    printf("%d ", m[i][j]);

	    }
	    printf("\n");	
    }
}