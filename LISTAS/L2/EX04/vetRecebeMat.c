#include<stdio.h>

void vRecebeM( int m, int n,int vetor[],int matriz[m][n]);
int obter_menor(int i, int vetor[]);
int obter_maior(int i, int vetor[]);

int main(){

        int n,m;

        scanf("%d %d", &n,&m);
        
        int vetor[n*m];
        int matriz[m][n];
        
        do{
                for(int i = 0; i < m; i++){
                                for(int j = 0; j < n; j++){
                                scanf("%d",&matriz[i][j]);               
                                }
                }

                vRecebeM(m,n,vetor,matriz);
                
                scanf("%d %d", &n,&m);
        
        }while(m != 0 && n != 0);
        
return 0;
}

void vRecebeM( int m, int n,int vetor[],int matriz[m][n]){
        
        int k = -1;
        
        for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                         k++;
                         vetor[k] = matriz[i][j];                                              
                         printf("%d ", vetor[k]);
                          
                }
                //k++;
        }
        
        
        printf("\n\nMenor do vetor %d\n",obter_menor(m*n,vetor));
        
        printf("\n\nMaior do vetor %d\n",obter_maior(m*n,vetor));
       
        
}

int obter_menor(int i, int vetor[]) {

       
        if(i == 1){ //Observe que o recursivo nunca bagunçara o vetor, pois a recursiva para no i==1
                return vetor[0];
        }
        
        else {
                int h = obter_menor(i - 1, vetor);
                if(h < vetor[i-1]){
                return h;
                }
                
                else { return vetor[i-1]; }

        }
}


int obter_maior(int i, int vetor[]) {

       
        if(i == 1){ //Observe que o recursivo nunca bagunçara o vetor, pois a recursiva para no i==1
                return vetor[0];
        }
        
        else {
                int h = obter_maior(i - 1, vetor);
                if(h > vetor[i-1]){
                return h;
                }
                
                else { return vetor[i-1]; }

        }
}


