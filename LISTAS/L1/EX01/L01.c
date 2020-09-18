/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Lista 01 - Exercício 01 - Caça-palavras

	Instrucoes
	----------

	Este arquivo contem o codigo que auxiliara no desenvolvimento do
	exercicio. Voce precisara completar as partes requisitadas.

* ================================================================== *
	Dados do aluno:

	RA:
	Nome: Jesimiel Efraim Dias

* ================================================================== */

#include <stdio.h>
#include <string.h>


/* máximo de linhas (m) e colunas (n) */


#define MAX 10

/* constantes booleanas */	
#define VERDADEIRO	1
#define FALSO		0


/* Protótipos das funções */
void lerGrade(char grade[][MAX], int m, int n);
void imprimirGrade(char grade[][MAX], int m, int n);
/* <<< ESCREVA OS PROTOTIPOS DAS DEMAIS FUNCOES AQUI >>> */
void esconderMarcas(char grade[][MAX], int marcas[][MAX], int m, int n);
void inverterString(char palavra[MAX]);
int procurarHorizontal(char palavra[MAX], char grade[][MAX], int marcas[][MAX], int m, int n);
int procurarVertical(char palavra[MAX], char grade[][MAX], int marcas[][MAX], int m, int n);
int procurarDPrincipal(char palavra[MAX], char grade[][MAX], int marcas[][MAX], int m, int n);
int procurarDSecundaria(char palavra[MAX], char grade[][MAX], int marcas[][MAX], int m, int n);

/* ------------------------------ */
/* ROTINA PRINCIPAL - NAO ALTERAR */
/* ------------------------------ */

int main(void)
{
	char grade[MAX][MAX]; 	/* matriz de letras do caça-palavras */
	int marcas[MAX][MAX]; 	/* cada posição vale 1 se é para esconder a letra na resposta, ou 0 caso contrário */
	int num_palavras;		/* qtde de palavras que usuário deseja procurar na grade */
	char palavra[MAX];		/* palavra que o usuário deseja buscar */
	int m, n;				/* dimensões da grade de letras */ 
	int i, j;				/* iteradores para percorrer linhas e colunas */
	int achou;				/* variavel que indica se palavra foi encontrada na grade (achou=1) ou não (achou=0)*/
	

	scanf("%d %d", &m, &n);
  //      }while(m > 10|| n > 10);
	lerGrade(grade, m, n);

	
	/* marca todas as posições da grade como fora da resposta final */
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			marcas[i][j] = 1;
		}
	}


	/* lê número de palavras e procura cada uma delas na grade */
	scanf("%d", &num_palavras);

	/* para cada palavra desejada */
	for(i = 0; i < num_palavras; i++) {
		scanf("%s", palavra); // le a palavra desejada
		
		// procura em todas as linhas da grade
		achou = procurarHorizontal(palavra, grade, marcas, m, n);

		if (achou == FALSO) {
		
			// procura em todas as colunas da grade
			achou = procurarVertical(palavra, grade, marcas, m, n);
		
		        if (achou == FALSO) {
				
				// procura na diagonal principal
				achou = procurarDPrincipal(palavra, grade, marcas, m, n);
                        
				if (achou == FALSO) {
					
					// procura na diagonal secundária
					achou = procurarDSecundaria(palavra, grade, marcas, m, n);
					if (achou == FALSO) {
                                        
						// Inverte a palavra e reinicias as buscas
						inverterString(palavra);
                                        
						// procura em todas as linhas da grade
						achou = procurarHorizontal(palavra, grade, marcas, m, n);

						if (achou == FALSO)	{

							// procura em todas as colunas da grade
							achou = procurarVertical(palavra, grade, marcas, m, n);

							if (achou == FALSO) {

								// procura na diagonal principal
								achou = procurarDPrincipal(palavra, grade, marcas, m, n);
								
								if (achou == FALSO) {

									// procura na diagonal secundária
									achou = procurarDSecundaria(palavra, grade, marcas, m, n);
								}
							}
						}
					}
				}
			}
		}
	}
	
	// coloca '#' na grade no lugar de letras não usadas
	esconderMarcas(grade, marcas, m, n);
	// imprime a grade final
	imprimirGrade(grade, m, n);
		
	//imprimir(marcas, m, n);
	
	return 0;
}



/* ------------------------- */
/* IMPLEMENTACAO DAS FUNCOES */
/* ------------------------- */

/* lerGrade: preenche grade lendo do teclado cada caractere */
void lerGrade(char grade[][MAX], int m, int n)
{
	int i, j;
	
	for (i = 0; i < m; i++)	{
		for (j = 0; j < n; j++) {
			
			do {
			
				scanf("%c", &grade[i][j]);
			/* ignora espaços e quebras de linha */
			} while (grade[i][j] == ' ' || grade[i][j] == '\n');
		}
	}
}


/* imprimirGrade: imprime a grade de caracteres */
void imprimirGrade(char grade[][MAX], int m, int n)
{
	int i, j;
	
	for (i = 0; i < m; i++) {
	 	for (j = 0; j < n; j++) {
			printf("%c ", grade[i][j]);
		}
		printf("\n");
	}
}

void imprimir(int marcas[][MAX], int m, int n)
{
	int i, j;
	
	for (i = 0; i < m; i++) {
	 	for (j = 0; j < n; j++) {
			printf("%d ", marcas[i][j]);
		}
		printf("\n");
	}
}
/* <<< IMPLEMENTE AS DEMAIS FUNCOES AQUI >>> */

/* inverterString: inverte a ordem da string, p. ex, troca "AMOR" por "ROMA" */
void inverterString(char palavra[MAX]){


char palavra2[MAX];
int tmnPalavra, i = 0;

tmnPalavra = strlen(palavra) - 1;


strcpy(palavra2,palavra);


        while(tmnPalavra >= 0){
        
        palavra[i] = palavra2[tmnPalavra];
        tmnPalavra--;       
        i++;        
        }
        
}

/* procurarHorizontal: procura a palavra nas linhas da grade. Remove as marcas, se a palavra for 
encontrada e retorna TRUE ou FALSE se a palavra foi encontrada ou nao */

int procurarHorizontal(char palavra[MAX], char grade[][MAX], int marcas[][MAX], int m, int n){

        int tmnPalavra = 0, add = 0;
        tmnPalavra = strlen(palavra);
        
        for (int i = 0;i < m; i++) {
	 	for (int j = 0;j < n - tmnPalavra + 1; j++) {        
	                
	                        for(int v = j; v < n; v++){
	                                                            
	                                if(palavra[add] == grade[i][v]){
	                                add++;
	                                }
	                                
	                                else {
	                                add = 0;
	                                v = n;
	                                }
	                                
	                                if(add == tmnPalavra){
                                                for(int k = j; k <= v ;k++){ marcas[i][k] = 0; }
	                                
	                                return VERDADEIRO;
	                                }
	                                
	                             
	                        }    
	                
	     
	                
	     
	                
	        }  
        }       
        return FALSO;
} 
	
	


/* procurarVertical: procura a palavra nas colunas da grade. Remove as marcas, se a palavra for 
encontrada e retorna TRUE ou FALSE se a palavra foi encontrada ou nao */
int procurarVertical(char palavra[MAX], char grade[][MAX], int marcas[][MAX], int m, int n){

        int tmnPalavra = 0, add = 0;
        char palavra2[MAX];        
        tmnPalavra = strlen(palavra);
        
                
        for (int i = 0;i < n; i++) {
	 	for (int j = 0;j < m - tmnPalavra + 1; j++) {        
	        
	                        for(int v = j; v < m ; v++){
	                                
	                                if(palavra[add] == grade[v][i]){
	                                add++;
	                                }
	                                
	                                else {
	                                add = 0;
	                                v = m;
	                                }
	                                
	                                if(add == tmnPalavra){
	                                        for(int k = j; k <= v ;k++){ marcas[k][i] = 0; }
	                                return VERDADEIRO;
	                                }
	                                
	                                
	                        }    
	        
	        }  
        }       
        return FALSO;
} 

/* procurarDPrincipal: procura a palavra na diagonal principal da grade. Remove as marcas, se a palavra for 
encontrada e retorna TRUE ou FALSE se a palavra foi encontrada ou nao */
int procurarDPrincipal(char palavra[MAX], char grade[][MAX], int marcas[][MAX], int m, int n){

        int tmnPalavra = strlen(palavra), add = 0, aux = 0;
        
        for (int i = 0;i < m; i++) { // o "i" vai até m linhas da matriz
                for (int j = 0;j <= i-tmnPalavra+1; j++) { // o "j" vai até aonde a palavra cabe na diagonal
                //e caso uma letra não esteja de acordo, adiciona mais um e continua verificando apartir daquele ponto
                //através da "v=j"       
	                for(int o = i; o >= 0; o--){       //o "o" iniciará no "i" e irá até o 0 que será a última 
	                //linha da matriz         
	                        for(int v = j; v <= i; v++){//enquanto o "v" iniciará em "j" e irá até o "i" 
	                                if(palavra[add] == grade[o-add][v]){//O add inicia em "0" e o "o" em "i",
	                                //Logo, cada vez que o add soma 1, subtraimos do "o" p/ que desça cada vez
	                                //mais sua posição que em dado momento, será 0.
	                                add++;
	                                }
	                                        
	                                else { //cancela o for atual e reinicia variaveis
	                                add = 0;
	                                v = i;
	                                }
	                                        
	                                if(add == tmnPalavra){ //em dado momento se acharmos as palavras na diagonal principal
	                                //já passamos os respectivos valores e iniciamos as marcas na matriz
	                                        for(int k = j; k <= v ;k++){ marcas[o - aux][k] = 0; aux++; }// O "k" recebe "j"
	                                        //que é a primeira posição da palavra na matriz e vai até "v" que é a última
	                                        //letra da palavra na matríz enquanto o "aux" 
	                                return VERDADEIRO;
	                                }
	                         }    
	                } 
                }  
        }
        
        

          
        return FALSO;
} 


/* procurarDSecundaria: procura a palavra na diago
nal secundaria da grade. Remove as marcas, se a palavra for 
encontrada e retorna TRUE ou FALSE se a palavra foi encontrada ou nao */

int procurarDSecundaria(char palavra[MAX], char grade[][MAX], int marcas[][MAX], int m, int n){

        int tmnPalavra = strlen(palavra), add = 0,aux = 0;
        char palavra2[MAX];

        strcpy(palavra2,palavra);                        
        inverterString(palavra2);
        
        for (int i = 0;i < m; i++) { // o "i" vai até m linhas da matriz
                for (int j = n - 1; j >= 0; j--) { // o "j" iniciará em n-1 e irá até 0
                //e caso uma letra não esteja de acordo, adiciona mais um e continua verificando apartir daquele ponto
                //através da "v=j"       
	                for(int o = i; o >= 0; o--){       //o "o" iniciará no "i" e irá até o 0 que será a última 
	                //linha da matriz         
	                        for(int v = j; v >= 0; v--){//enquanto o "v" iniciará em "j" e irá até o "i" 
	                                if(palavra2[add] == grade[o-add][v]){//O add inicia em "0" e o "o" em "i",
	                                //Logo, cada vez que o add soma 1, subtraimos do "o" p/ que desça cada vez
	                                //mais sua posição que em dado momento, será 0.
	                                add++;
	                                }
	                                        
	                                else { //cancela o for atual e reinicia variaveis
	                                add = 0;
	                                v = 0;
	                                }
	                                        
	                                if(add == tmnPalavra){ //em dado momento se acharmos as palavras na diagonal principal
	                                //já passamos os respectivos valores e iniciamos as marcas na matriz
	                                        for(int k = j; k >= v ;k--){ marcas[o - aux][k] = 0; aux++; }// O "k" recebe "j"
	                                        //que é a primeira posição da palavra na matriz e vai até "v" que é a última
	                                        //letra da palavra na matríz enquanto o "aux" 
	                                return VERDADEIRO;
	                                }
	                         }    
	                } 
                }  
        }
           
/* esconderMarcas: substitui caracteres da grade por '#' onde estiver marcado */
}
void esconderMarcas(char grade[][MAX], int marcas[][MAX], int m, int n){

        for (int i = 0; i < m; i++) {
	 	for (int j = 0; j < n; j++) {
			
			if(marcas[i][j] == VERDADEIRO){
			grade[i][j] = '#';
			}
			
		}
	}	
			
}	
	
	



