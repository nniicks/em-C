/*
-----  ACHANDO O MAIOR ELEMENTO DE UM VETOR  ------

#include <stdio.h>
#include <stdlib.h>

int MAIOR(int n, int *vetor, int maior);

int main(){
    int *vetor, *p, tamanho, aux;
    
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    vetor = (int *) malloc(tamanho * sizeof(int));
    if(vetor == NULL){
        printf("Nao foi possivel alocar o vetor na memoria!");
        return 0;
    }else{
        printf("Entre com os valores para o vetor:\n");
        for(p = vetor; p < vetor + tamanho; p++){
            scanf("%d", p);
        }
        
        aux = MAIOR(tamanho, vetor, vetor[0]);
        
        printf("O maior elemento do vetor eh: %d", aux);
    }
    
    free(vetor);
    
    return 0;
}

int MAIOR(int n, int *vetor, int maior){
    
    if(n == 0){
        return maior;    //n=0 vetor tem tamnho 1, logo o vetor[0] ja eh o maior elemento. esse valor foi justamente oq eu passei como maior la na main
    }else{
        if(vetor[n-1] > maior){
            return MAIOR(n-1, vetor, vetor[n-1]);
        }else{
            return MAIOR(n-1, vetor, maior);
        }
    }
}

aqui eu passo o vetor como um todo, ou seja, o n na primeira chamada da funcao equivale ao tamanho
do vetor. posteriormente eu vou diminuido ele e comparando o meu ultimo elemento do vetor atual com
o meu maior elemento. ent n = 5, tem no indice 4 o meu ultimo elemnto. ai eu comparo ele com o meu maior,
que definine como sendo o v[0]. a cada vez que eu chamo a funcao, eu passo a olhar para um vetor de tamanho
menor(tamanho n-1).

-----------------------------------------------------------------------------------------------------------

------- BUSCA SEQUENCIAL EM UM VETOR NAO ORDENADO -------

#include <stdio.h>
#include <stdlib.h>

int busca(int n, int *v, int numero);

int main(){
    int *vetor, *p, n, num, aux;
    
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);
    
    vetor = (int *) malloc(n * sizeof(int));
    
    if(vetor != NULL){
        //consehuir alocar o vetor na memoria
        printf("Entre com os valores do vetor:\n");
        for(p = vetor; p < vetor + n; p++){
            scanf("%d", p);
        }
        
        printf("Informe um numero:\n");
        scanf("%d", &num);
        
        aux = busca(n, vetor, num);
        
        if(aux == -1){
            printf("O numero %d nao foi encontrado no vetor!", num);
        }else{
            printf("O numero %d foi encontrado na posicao %d do vetor!", num, aux);
        }
        
    }else{
        printf("Nao foi possivel alocar o vetor na memoria!");
        return 0;
    }
    
    free(vetor);
    
    return 0;
}

int busca(int n, int *v, int numero){
    
    if(n == 0){
        
        if(numero == v[n]){
            return 0;      //numero esta no vetor, na posicao 0 (poderia ter colocado v[n] no return ou tbm *v no lugar de v[n])
        }else{
            return -1 ;    //numero nao esta no vetor
        }
    }else{
        
        if(numero == v[n-1]){
            return n-1;     //numero esta no vetor, na posicao n-1
        }else{
            busca(n-1, v, numero);
        }
    }
    
}

---------------------------------------------------------------------------------------------------


--------   ACHANDO O TERMO DE ORDEM N DA SEQ DE FIBONACCI ---------

#include <stdio.h>
#include <stdlib.h>

int F(int n);

int main(){
    int numero, fib;
    
    printf("Informe um numero inteiro positivo: ");
    scanf("%d", &numero);
    
    fib = F(numero);
    
    printf("Fibonacci de %d eh: %d", numero, fib);
    
    return 0;
}

int F(int n){
    
    if(n == 0){
        return 0;
        
    }else if(n == 1){
        return 1;
            
    }else{
        return F(n - 2) + F(n - 1);
    }
    
}

------------------------------------------------------------------------------------------------------------------

---------- TRANSFORMANDO UM INT N POSITIVO EM BINARIO ----------

#include <stdio.h>

void binario(int n);

int main(){
    int numero;
    
    printf("Informe um numero inteiro positivo:\n");
    scanf("%d", &numero);
    
    printf("O numero %d em binario eh:\n", numero);
    binario(numero);
    
    return 0;
}

void binario(int n){
    
    if(n / 2 != 0){
        binario(n / 2);
    }
    
    printf("%d ", n % 2);
}


------------ SOMA DE 1 + 1/2 + ... + 1/N --------

#include <stdio.h>

float soma(int n);

int main(){
    int n;
    float resultado;
    
    printf("Informe um numero inteiro positivo:\n");
    scanf("%d", &n);
    
    resultado = soma(n);
    
    printf("A soma de 1 + 1/2 + ... + 1/%d eh: %f", n, resultado);
    
    return 0;
}


float soma(int n){
    
    if(n == 1){
        return 1.0;
    }else{
        return 1.0/n + soma(n-1);
    }
}


------------ CALCULO DO FATORIAL DE UM NUMERO N --------

#include <stdio.h>

int fat(int n);

int main(){

    int n, resultado;

    scanf("%d", &n);
    
    resultado = fat(n);

    printf("%d", resultado);

}

int fat(int n){

    if(n <= 1){
        return 1;
    }else{
        n = n * fat(n-1);
    }

    return n;

}

----------- SOMA DE TODOS OS NUMEROS ATE N --------

#include <stdio.h>

int soma(int n);

int main(){
    int n, resultado;

    scanf("%d", &n);

    resultado = soma(n);
    
    printf("%d", resultado);

    return 0;
}

int soma(int n){

    if(n == 1){
        return 1;
    }else{
        n = n + soma(n - 1);
    }

    return n;

}
*/