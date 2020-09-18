#include<stdio.h>
#include<stdlib.h>



void troca (int *i, int *j) {
        
        int a;
        int *temp//Primeiro.
        //temp = &a; //Segundo.
        
        /*Irá dar erro porque o temp é apenas um ponteiro que não aponta para ninguém
        ou seja, impossibilitado de receber dados, porém, se eu alocar o endereço do 
        "a" e tentar fazer a troca, ela irá funcionar perfeitamente. "Retire o parenteses do //segundo para testar"*/
        
        *temp = *i; *i = *j; *j = *temp;
         printf("%d %d\n",*i,*j);
        
}

int main(){

        int i = 2 ,j = 3;
        troca(&i,&j);

        return 0;
}
