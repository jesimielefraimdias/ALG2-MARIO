//jesimiel
#include<stdio.h>

#define MAXI 10000
void copiarConteudo(FILE *arq1, FILE *arq2);


int main(){
        
        FILE *arq1, *arq2;
        
        arq1 = fopen("arquivo1.txt","r");//Leitura 
        arq2 = fopen("arquivo2.txt","w");//Escrita
        
        if(arq1 == NULL || arq2 == NULL){
                 perror("Deu erro vacilão\n");
                 return 0;
        }
       
        copiarConteudo(arq1,arq2);//Chama a função para copiar.
        
        //Fecha os arquivos.
        fclose(arq1);
        fclose(arq2);
        
        return 0;
}



void copiarConteudo(FILE *arq1, FILE *arq2){
         char aux,leitor;
        
        leitor = fgetc(arq1);
        
        while(leitor != EOF){ //Leitor recebe a string do arquivo.
                //fputs mandar a string do leitor para o arq.
                fputc(leitor,arq2);
                leitor = fgetc(arq1);
                
        }
}        

