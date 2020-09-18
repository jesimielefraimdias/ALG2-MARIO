#include<stdio.h>
#include<string.h>

#define MAX 100

int palindrome(char palavra[]);

int main(){

        char palavra[MAX];
        
        printf("Digite uma palavra: ");
        scanf("%s",&palavra);
        
        if(palindrome(palavra) == 0){
        printf("%s é um palindrome\n",palavra);
        }
        else{
        printf("\n%s não é um palindrome\n",palavra);
        }        
        
        return 0;
}


int palindrome(char palavra[]){

        int j = 0;
        
        for(int i = strlen(palavra) - 1; j < i; i--){
     
                if(palavra[j] != palavra[i]){
                return 1;
                }
        j++;        
        }
        
        return 0;
                
}

