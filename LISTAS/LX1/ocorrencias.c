#include<stdio.h>
#include<string.h>

#define MAX 150

int repetido ( int rep, char aux[], int i);
void ocorrencias(char string[],char aux[]);

int main(){

        char string[MAX];
        char aux[MAX];
        printf("Digite os caracteres: ");
        scanf("%s",&string);
        
        ocorrencias(string,aux);

return 0;
}

void ocorrencias(char string[],char aux[]){
        
        int add = 1;
                
        for(int i = 0; i < strlen(string); i++){         
                              
               if(repetido(string[i],aux,i) == 0){                
                        for(int j = i+1; j < strlen(string); j++){                              
                                if(string[i] == string[j]){
                                add++;    
                                } 
                        }
                        printf("Letra: %c e ocorrências %d\n", string[i], add);
                        aux[i] = string[i];
               }
               add = 1;
        }
}

int repetido ( int rep, char aux[], int i){

        for(int j = 0; j <= i; j++){
                if(rep == aux[j]){
                        return 1; 
                }
        }
        
        return 0;

}



