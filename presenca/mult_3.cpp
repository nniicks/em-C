#include <stdio.h>

void imprimir(){

    int i = 3, flag = 0;

    while (flag < 100){
        printf("%d ", i);
        i = i + 3;
        flag++;
    }

}

int main(){

    imprimir();

    return 0;
    
}