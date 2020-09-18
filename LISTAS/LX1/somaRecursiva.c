#include<stdio.h>
#define MAX 50

int soma(int n, int vetor[]);
void impressaoCont(int n, int vetor[]);

int main(){
        
        int vetor[MAX];
        int n;
        
        do{
        scanf("%d",&n);
        }while(n > MAX);
        
        for(int i = 0; i < n; i++){
        scanf("%d",&vetor[i]);
        }
        
        printf("%d\n",soma(n - 1,vetor));

        impressaoCont(n - 1,vetor);
        printf("\n");
return 0;
}


int soma(int n, int vetor[]){

        if(n == 0){
        return vetor[0];
        }
        
        return vetor[n] + soma(n-1,vetor);       
}

void impressaoCont(int n, int vetor[]){

        if(n == 0) {
        printf("%d ", vetor[0]);
        }
 
        else {
        printf("%d ",vetor[n]);
        impressaoCont(n-1, vetor);
        }              
}
