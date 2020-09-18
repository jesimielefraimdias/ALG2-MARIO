#include<stdio.h>

#define MAXI 10000
void copiarConteudo(FILE *arq1, FILE *arq2);


int main(){
        
        FILE *arq1, *arq2;
        
        arq1 = fopen("L05EX01.c","r");//Coloque o arquivo.c para retirar comentários
        arq2 = fopen("testando.c","w");//E o novo arquivo.c.
        
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
        int flag = 0;
        
        leitor = fgetc(arq1);//Pega o primeiro caracter do arquivo
        
        while(leitor != EOF){ 
        
         
                if(leitor == '/'){/*Acha o primeiro "/" q é a condição inicial
                                tanto para "//" quanto para o "/*". */
       
                                 aux = fgetc(arq1);/*Passa o segundo para uma aux, pois se o 
                                 próximo não for o "*" do "/*" ou o "/" do "//" nós não teremos
                                 alterado o .c*/
                                 
                                if(aux == '*'){                                  
                                        do{
                                                leitor = fgetc(arq1);
                                          
                                        }while(leitor != '/');//Verifico até achar o "/" do "*/".
                                        fputc('\n',arq2); 
                                        leitor = fgetc(arq1); /*Após achar, pulamos ele e copiamos o próximo caracter
                                        para o novo .c*/
                                     
                                
                                }
                                                 
                                else if(aux == '/'){
                                
                                         do{
                                                 leitor = fgetc(arq1);
                                         }while(leitor != '\n');/*Como o comentário do // só acaba após uma quebra de linha
                                         fazer a condição do while como até encontrar o primeiro \n irá servir.*/
                                          fputc('\n',arq2);        
                                          leitor = fgetc(arq1); 
                                }
                                else{ flag = 1; } /*E caso não entre nos if's, tenho que corrigir pq o curso
                                                  foi está um caracter a frente do leitor, e como não lembro 
                                                  como manipula o cursor essa gamb vai servir.*/      
                }                 
                fputc(leitor,arq2);
                leitor = fgetc(arq1);
                if(flag){
                        fputc(aux,arq2);
                        flag = 0;
                }//Parte da gamb
                
        }
}
       
