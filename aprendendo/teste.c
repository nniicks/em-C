#include <stdio.h>

int main(){
   int i, ac=0;
   float n1;
   
   for (i = 0; i < 6; i++){

    scanf("%f", &n1);

    if(n1 > 0){
      ac++;
    }

   }

   printf("%d valores positivos\\n",ac);

}