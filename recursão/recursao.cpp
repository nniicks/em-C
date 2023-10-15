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

------------ BUSCA SEQUENCIAL EM UM VETOR ORDENADO ------------------

#include <stdio.h>
#include <stdlib.h>

void ordena(int *v, int n);

int busca(int *v, int n, int numero);

int main(){
    int *vetor, *p, n, numero, flag;
    
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);
    
    vetor = (int *) malloc(n * sizeof(int));
    if(vetor == NULL){
        printf("Nao foi possivel alocar o vetor na memoria!");
        return 0;
    }else{
        printf("Entre com os valores para o vetor\n");
        for(p = vetor; p < vetor + n; p++){
            scanf("%d", p);
        }
        
        printf("Digite um numero: ");
        scanf("%d", &numero);
        
        ordena(vetor, n);
        
        flag = busca(vetor, n, numero);
        
        if(flag == -1){
            printf("O numero %d nao esta no vetor!", numero);
        }else{
            printf("O numero %d esta na posicao %d do vetor ordenado!", numero, flag);
        }
        
        free(vetor);
        
    }
    
    return 0;
}

void ordena(int *v, int n){
    int *p, *q, aux;
    
    for(p = &v[n-1]; p > v - 1; p--){
        for(q = v; q < p; q++){
            if(*q > *(q+1)){
                aux = *q;
                *q = *(q+1);
                *(q+1) = aux;
            }
        }
    }
}

int busca(int *v, int n, int numero){
    
    if(n == 0){
        
        if(numero == *v){
            return 0;                //0 eh a posicao do numero no vetor
        }else{
            return -1;              //-1 indica que o numero nao esta no vetor
        }
        
    }else{
        
        if(numero == v[n-1]){
            
            return n-1;                //n-1 posicao do vetor
            
        }else if(numero > v[n-1]){   //vetor ordenado, e numero sendo maior que o ultimo num do vetor (atual ultimo), eh impossivel ele estar ainda mais a esquerda do vetor
            
            return -1;
        }else{
            return busca(v, n-1, numero);
        }
        
    }
        
}

----------------- BUSCA BINARIA (SEM RECURSAO!!!!!) ----------------------

#include <stdio.h>
#include <stdlib.h>

void ordena(int *v, int n);

int main(){
    int *vetor, *p, n, numero, comeco, final, medio, posicao = -1;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
    vetor = (int *) malloc(n * sizeof(int));
    if(vetor == NULL){
        printf("Nao foi possivel armazenar o vetor na memoria!");
        return 0;
    }else{
        printf("Entre com os valores do vetor!\n");
        for(p = vetor; p < vetor + n; p++){
            scanf("%d", p);
        }
        
        ordena(vetor, n);
        
        printf("Digite um numero: ");
        scanf("%d", &numero);
        
        comeco = 0;
        final = n;
        medio = (comeco + final)/2;
        do{
            if(*(vetor + medio) == numero){            //*(vetor + medio) = vetor[medio]
                posicao = medio;
                break;                            //se eu achar o numero eu ja posso sair do laço
            }else if(numero > *(vetor + medio)){
                comeco = medio + 1;
                medio = (comeco + final)/2;
                
            }else{
                final = medio - 1;
                medio = (comeco + final)/2;
            }
        }while(comeco <= final);
        
        if(posicao == -1){
            printf("O numero %d NAO esta no vetor!", numero);
        }else{
            printf("O numero %d esta na posicao %d do vetor ordenado!", numero, posicao);
        }
        
        free(vetor);
    }
    
    return 0;
}

void ordena(int *v, int n){
    int *p, *q, aux;
    
    for(p = &v[n-1]; p > v - 1; p--){
        for(q = v; q < p; q++){
            if(*q > *(q + 1)){
                aux = *q;
                *q = *(q + 1);
                *(q + 1) = aux;
            }
        }
    }
}

----------- BUSCA BINARIA COM RECURSÃO -----------  

#include <stdio.h>
#include <stdlib.h>

void ordena(int *v, int n);

int buscaBinaria(int *vetor, int numero, int comeco, int fim);

int main(){
    int *vetor, *p, n, numero, posicao = -1;
    
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);
    
    vetor =  (int *) malloc(n * sizeof(int));
    if(vetor == NULL){
        printf("Impossivel alocar o vetor!");
        return 0;
    }else{
        printf("Entre com os numeros do vetor:\n");
        for(p = vetor; p < vetor + n; p++){
            scanf("%d", p);
        }
        
        printf("Digite um numero inteiro qualquer:\n");
        scanf("%d", &numero);
        
        ordena(vetor, n);
        
        posicao = buscaBinaria(vetor, numero, 0, n);
        
        if(posicao == -1){
            printf("O numero %d NAO esta no vetor!", numero);
        }else{
            printf("O numero %d esta na posicao %d do vetor ordenado!", numero, posicao);
        }
        
        free(vetor);
    }
    
    return 0;
}

void ordena(int *v, int n){
    int *p, *q, aux;
    
    for(p = &v[n-1]; p > v - 1; p--){
        for(q = v; q < p; q++){
            if(*q > *(q + 1)){
                aux = *q;
                *q = *(q + 1);
                *(q + 1) = aux;
            }
        }
    }
}

int buscaBinaria(int *vetor, int numero, int comeco, int fim){
    int medio = (comeco + fim)/2;
    
    if(comeco > fim){
        return -1;
    }
    if(*(vetor + medio) == numero){
        return medio;              //numero esta na posicao medio do vetor!
    }else if(numero > *(vetor + medio)){
        return buscaBinaria(vetor, numero, medio + 1, fim);
    }else{
        return buscaBinaria(vetor, numero, comeco, medio - 1);
    }
    
    return -1;
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

--------- MDC ALGORITMO DE EUCLIDES ---------

#include <stdio.h>

int mdc(int a, int b);

int main(){
    int a, b, aux;
    
    printf("Informe dois numeros inteiros: ");
    scanf("%d %d", &a, &b);
    
    aux = mdc(a, b);
    
    printf("O mdc entre %d e %d eh: %d", a, b, aux);
    
    return 0;
}

int mdc(int a, int b){
    
    if(a % b == 0){
        return b;
    }else{
        return mdc(b, a % b);
    }
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

------------ CALCULO DE X ELEVADO A N ----------

#include <stdio.h>

int potencia(int x, int n);

int main(){
    int x, n, resultado;
    
    printf("Informe a base:\n");
    scanf("%d", &x);
    
    printf("Informe a potencia:\n");
    scanf("%d", &n);
    
    resultado = potencia(x, n);
    
    printf("%d\n", resultado);
    
    return 0;
}

int potencia(int x, int n){

    if(n == 0){
        return 1;
    }else if(n == 1){
        return x;
    }else{
        return x * potencia(x, n-1);
    }
    
}

OBS: essa foi a primeira impelemtaçao que fiz. mas aux eh desnecessaria
int potencia(int x, int n){
    int aux = 1;
    
    if(n == 0){
        return 1;
    }else if(n == 1){
        return x;
    }else{
        return aux = x * potencia(x, n-1);
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

------- SOMA DOS DIGITOS DE UM NUMERO INTEIRO N -------

#include <stdio.h>

int soma(int n);

int main(){
    int n, aux;
    
    printf("Digite um numero inteiro ai:\n");
    scanf("%d", &n);
    
    aux = soma(n);
    
    printf("A soma dos digitos do numero %d eh: %d", n, aux);
    
    return 0;
}

int soma(int n){
    
    if(n == 0){
        return 0;
    }else{
        return n % 10 + soma(n/10);
    }
    
}

------ QUANTIDADE DE DÍGITOS DO NÚMERO N ------
#include <stdio.h>

int soma(int n);

int main(){
    int n, aux;
    
    printf("Digite um numero inteiro ai:\n");
    scanf("%d", &n);
    
    aux = soma(n);
    
    printf("A quantidade de digitos que o numero %d possui eh: %d", n, aux);
    
    return 0;
}

int soma(int n){
    
    if(n == 0){
        return 0;
    }else{
        return 1 + soma(n/10);
    }
    
}

outra maneira de fazer essa recursao:

if(n / 10 == 0){
    return 1;
}else{
    return 1 + soma(n/10)
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
------- INVERTENDO UM VETOR ------

#include <stdio.h>
#include <stdlib.h>

void troca(int *v, int n, int primeiro);

int main(){
    int *vetor, *p, n;

    printf("Informe o tamanho do vetor:\\n");
    scanf("%d", &n);

    vetor = (int *) malloc(n * sizeof(int));
    if(vetor == NULL){
        printf("Nao foi possivel alocar o vetor na memoria!");
        return 0;
    }else{

        printf("Entre com os valores para o vetor:\\n");
        for(p = vetor; p < vetor + n; p++){
            scanf("%d", p);
        }

        printf("Vetor original:\\n");
        for(p = vetor; p < vetor +n; p++){
            printf("%d ", *p);
    }

        troca(vetor, n, 0);

        printf("\\nVetor invertido:\\n");
        for(p = vetor; p < vetor + n; p++){
            printf("%d ", *p);
        }
    }

    free(vetor);

    return 0;

}

void troca(int *v, int n, int primeiro){
    int aux;

    if(n <= primeiro){
        return;
    }else{
        aux = v[primeiro];
        v[primeiro] = v[n-1];
        v[n-1] = aux;

        return troca(v, n-1, n+1);
    }

}

------- INVERTENDO UM VETOR -------------

#include <stdio.h>
#include <stdlib.h>

void leitura(int *vetor, int n);

void imprime(int *vetor, int n);

void inverte(int *vetor1, int *vetor2, int n, int i);

int main(){
    int *vetor1, *vetor2, n;
    
    scanf("%d", &n);
    
    vetor1 = (int *) malloc(n * sizeof(int));
    if(vetor1 == NULL){
        return 0;
    }
    
    vetor2 = (int *) malloc(n * sizeof(int));
    if(vetor2 == NULL){
        return 0;
    }
    
    leitura(vetor1, n);
    
    inverte(vetor1, vetor2, n, 0);
    
    printf("Vetor original:\n");
    imprime(vetor1, n);
    
    printf("\nVetor invertido:\n");
    imprime(vetor2, n);
    
    free(vetor1);
    free(vetor2);
    
    return 0;
    
}

void leitura(int *vetor, int n){
    int *p;
    
    for(p = vetor; p < vetor + n; p++){
        scanf("%d", p);
    }
}

void imprime(int *vetor, int n){
    int *p;
    
    for(p = vetor; p < vetor + n; p++){
        printf("%d ", *p);
    }
}

void inverte(int *vetor1, int *vetor2, int n, int i){
    
    if(n == 0){
        return;
    }else{
        
        inverte(vetor1, vetor2, n-1, i+1);
        vetor2[i] = vetor1[n-1];
        
         //da pra fazer assim tbm:

        //vetor2[i] = vetor1[n-1];
        //return inverte(vetor1, vetor2, n-1, i+1);
        
        
    }
    
}


------ VERIFICANDO SE UM VETOR CONTEM PELO MENOS UM PAR --------

#include <stdio.h>
#include <stdlib.h>

bool contem_par(int *v, int n);

int main(){
    int *v, n, *p;
    bool flag;
    
    scanf("%d", &n);
    
    v = (int *) malloc(n * sizeof(int));
    if(v == NULL){
        return 0;
    }
    
    for(p = v; p < v + n; p++){
        scanf("%d", p);
    }
    
    flag = contem_par(v, n);
    
    if(flag == 1){
        printf("True");
    }else{
        printf("False");
    }
    
    return 0;
}

bool contem_par(int *v, int n){
    
    if(n == 0){
        if(v[n] % 2 == 0){
            return 1;
        }else{
            return 0;
        }
    }else{
        if(v[n-1] % 2 == 0){
            return 1;
        }else{
            return contem_par(v, n -1);
        }
    }
    
}

*/
