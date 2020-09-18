#include<stdio.h>
#define MULT 0.1

int soma(int n);

int main(){

        int n;
        
        scanf("%d",&n);
        
        printf("A soma é: %d\n",soma(n));
              
        return 0;
}


int soma(int n){
        
        if(n < 10){
        return n;
        } 

        return 10*((n*MULT) - (int)(n*MULT)) + soma(n*MULT); 
}        
