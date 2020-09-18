#include<stdio.h>
#include<stdlib.h>

int alocarMemoria(int *v, int *f);


int main(){


      
        int flag = 2, num, i = 0;
        
        int *v = (int*)malloc(2*sizeof(int)); //Cria um vetor com 2 posições.
                
        while(num != -1){//Enquanto for diferente de -1.
                   
                scanf("%d",&num);
                
                if(num != -1){
                        v[i] = num; 
                        if(i == flag){//Sem memória.
                                
                                if(alocarMemoria(v,&flag)){
                                        printf("Deu bosta\n");
                                        break;
                                }
                        }   
                }
                i++; 
        }        
        
                for(i = 0; i < flag; i++){
                        printf("%d ",v[i]);
                }
                printf("\n");

        return 0;        
}

int alocarMemoria(int *v, int *f){
        
        
        int *aux = (int*)realloc(v, 2*(*f)*sizeof(int) ); //Cria um vetor com 2 posições e coloca o endeço em aux.               
        
        if(aux == NULL){//Se aux for NULL não conseguiu alocar, porém, não vai alterar o v;
                free(aux);
                return 1;
        }
        
        else{
                v = aux;//Se aux alocou "atualizamos" o v.
                *f = (*f)*2;//A flag é incrementada.
                return 0;
        }
}




