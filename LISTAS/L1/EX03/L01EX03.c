/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Lista 01 - Exercício 03 - Validacao de e-mails

	Instrucoes
	----------

	Este arquivo contem o codigo que auxiliara no desenvolvimento do
	exercicio. Voce precisara completar as partes requisitadas.

* ================================================================== *
	Dados do aluno:

	RA: 726544
	Nome: Jesimiel Efraim Dias

* ================================================================== */

#include <stdio.h>
#include <string.h>

int email_valido(char email[]);

int main() {
    int tamanho;
    char email[51];
    
    while (scanf("%d", &tamanho) && tamanho > 0) {
        scanf(" %50[^\n]", email);
        
        if (email_valido(email))
            printf("Valido\n");
        else
            printf("Invalido\n");
    }
    
    return (0);
}

int email_valido(char email[]) {
        int i,k,j,aux;
        int tmn = strlen(email);
        char antes[50];
        char apos[50];
        
    /* IMPLEMENTE SEU CODIGO AQUI */
    
        for(i = 0; i <= tmn; i++){
        
                if(email[i] != '@'){
                antes[i] = email[i];
                }             
                else { break; } 
                
        }
        
         antes[i] = '\0';
         aux = strlen(antes);
         
        if(i == tmn || antes[0] == '.' || antes[0] == ',' || antes[0] == '-' || antes[0] == '_'
        || antes[aux] == '.' || antes[aux] == ',' || antes[aux] == '-' 
        || antes[aux] == '_'){ 
        return 0;
        }
        
        for(k = 1; k < aux - 1; k++){
                
                if(((antes[k-1] == '.' || antes[k-1] == ',' || antes[k-1] == '-' || antes[k-1] == '_')&&
                (antes[k] == '.'|| antes[k] == ',' || antes[k] == '-' || antes[k] == '_'))||
                
                ((antes[k] == '.' || antes[k] == ',' || antes[k] == '-' || antes[k] == '_')&&
                (antes[k+1] == '.'|| antes[k+1] == ',' || antes[k+1] == '-' || antes[k+1] == '_'))||
                
                ((antes[k-1] == '.' || antes[k-1] == ',' || antes[k-1] == '-' || antes[k-1] == '_')&&
                (antes[k] == '.'|| antes[k] == ',' || antes[k] == '-' || antes[k] == '_')&&
                (antes[k+1] == '.'|| antes[k+1] == ',' || antes[k+1] == '-' || antes[k+1] == '_')))        
                {
                return 0;
                }       
        }

//Após o arroba//             
                
        for(j = 0; j <= tmn; j++){
        i++;
        apos[j] = email[i];
        }
        apos[j+1] = '\0';                
        
        if(strcmp(apos,"email.abc, email.abc.br") != 0|| strcmp(apos,"abcmail.xyz.br") != 0 
        || strcmp(apos,"email.abc.br") != 0 || strcmp(apos,"abcweb.asd.br") != 0
        || strcmp(apos,"asdmail.xyz") != 0){
        return 0;
        }         
    
    
    /* Esta funcao deve retornar 1 caso o e-mail seja valido e 0 caso contrario */
    /* É permitido criar outras funcoes para auxiliar na validacao do e-mail */
    
}
