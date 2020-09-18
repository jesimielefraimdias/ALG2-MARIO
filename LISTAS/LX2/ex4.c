#include<stdio.h>
#include<stdlib.h>



void imprimeMatriz(int *m, int l, int c) {
        int i, j;
        for (i=0; i<l; i++) {
                for (j=0; j<c; j++){
                printf("%d ", *(m + (i * c) + j));//A mesma operação de aritimetica da função leitura, porém, com o * a frente
                //para imprimir os valores corretos.
                }
        printf("\n");
        }
}


int *leitura(int l, int c) {
       
        int *m; //Crie um ponteiro pra voltar o endereço de matriz.
        int i, j;//Auxiliares.
        m = (int *)malloc(l * c * sizeof(int));//Aloca dinamicamente uma matriz mult l*c.
         
        if (m == NULL) {//Se não alocou.
                printf("Nao foi possivel alocar a matriz\n");
                exit(0);
        }
        
        for (i=0; i<l; i++){
                for (j=0; j<c; j++) {
                printf("Entre m[%d][%d]: ", i, j);
                scanf("%d", (m + (i * c) + j));/*Faz aritimetica para simular um vetor
                 e depois soma com o endereço "m".*/
                }
                
       }
       
               
return m;//Volta o primeiro endereço
}

int main(void){
 
        int *m;//Cria um ponteiro que receberá o primeiro endereço da matriz.
        int nlin, ncol;//Número de linhas e colunas
 
        printf("Entre o numero de linhas e colunas: ");
        scanf("%d %d", &nlin, &ncol);
 
        m = leitura(nlin, ncol);
        imprimeMatriz(m, nlin, ncol);

}
