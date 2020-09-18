/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 
    Disciplina: Algoritmos e Programação 2
 
    Lista 03 - Exercício 03 - Imagem em Escala de Cinza
 
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
#include <math.h>

/* Ordem máxima da matriz */
#define MAX 100

/* Variaveis globais */
int *maior, *menor;

/* Opcoes do menu */
enum opcoes {SAIR = 0, CLAREAR, ESCURECER, DIAGONAL, TRANSPOSTA, BINARIA, MAIOR_MENOR};

/* ------------------------------ */
/*    FUNCOES JÁ IMPLEMENTADAS   */
/* ------------------------------ */

/* Exibe os elementos da matriz */
void exibe_matriz(int *comeco_matriz, int dimensao);

/* Exibe o maior e o menor numero da matriz ja sendo apontados pelas variaveis global maior e menor */
void exibe_maior_menor(int *comeco_matriz,int dimensao);


/* ------------------------------ */
/*    FUNCOES NAO IMPLEMENTADAS   */
/* ------------------------------ */

/* Recebe os elementos da matriz */
void popula_matriz(int *comeco_matriz, int dimensao);

/* Recebe os valores de uma outra matriz e soma a matriz principal com a matriz informada */
void clareia(int *comeco_matriz, int dimensao);

/* Recebe os valores de uma outra matriz e subtrai a matriz principal pela matriz informada */
void escurece(int *comeco_matriz, int dimensao);

/* Retorna 1 se for uma matriz diagonal e 0 caso contrário */
int diagonal(int *comeco_matriz, int dimensao);

/* A matriz passa a ser sua matriz transposta */
void transposta(int *comeco_matriz, int dimensao);

/* Todos os numeros maiores ou iguais que num_binariza passam a ser 255
	Os outros numeros passam a ser 0 */
void binariza(int *comeco_matriz, int dimensao, int num_binariza);


/* ------------------------------ */
/* ROTINA PRINCIPAL - NAO ALTERAR */
/* ------------------------------ */

int main(){
	int dimensao, opcao, num_binariza;
	int matriz[MAX][MAX];
	int *comeco_matriz = &matriz[0][0]; // Aponta para o primeiro elemento da matriz

	scanf("%d", &dimensao);
	popula_matriz(comeco_matriz, dimensao);	
	exibe_matriz(comeco_matriz, dimensao);

	while(1){
		scanf("%d", &opcao);

		switch (opcao){
			case SAIR:
				return 0;
				break;			

			case CLAREAR:
				clareia(comeco_matriz, dimensao);
				exibe_matriz(comeco_matriz, dimensao);
				break;

			case ESCURECER:
				escurece(comeco_matriz, dimensao);
				exibe_matriz(comeco_matriz, dimensao);
				break;

			case DIAGONAL:
				if (diagonal(comeco_matriz, dimensao))
					printf("SIM\n\n");
				else
					printf("NAO\n\n");
				break;

			case TRANSPOSTA:
				transposta(comeco_matriz, dimensao);
				exibe_matriz(comeco_matriz, dimensao);
				break;

			case BINARIA:
				scanf("%d", &num_binariza);
				binariza(comeco_matriz, dimensao, num_binariza);
				exibe_matriz(comeco_matriz, dimensao);
				break;

			case MAIOR_MENOR:
				exibe_maior_menor(comeco_matriz,dimensao);
				break;

		};
	}
	return 0;
	
}


/* ------------------------------ */
/*    FUNCOES JÁ IMPLEMENTADAS   */
/* ------------------------------ */

/* Exibe os elementos da matriz */
void exibe_matriz(int *comeco_matriz, int dimensao){
	int i;
	for (i = 0; i < pow(dimensao, 2); i++){		
		printf("%03d ", *(comeco_matriz+i));
		if ((i + 1) % dimensao == 0)
			printf("\n");
	}
	printf("\n");
}

/* Exibe o maior e o menor numero da matriz ja sendo apontados pelas variaveis global maior e menor */
void exibe_maior_menor(int *comeco_matriz, int dimensao){

        maior = comeco_matriz; //Inicializa ambos ponteiros com a primeira posição da matriz
        menor = comeco_matriz;
        comeco_matriz++;

        for(int i = 1; i < pow(dimensao,2) - 1; i++){
           
                if(*maior < *(comeco_matriz+1)){ //equivalente a isto menor < matriz[i][j]
                //Se sim
                maior = comeco_matriz+1;//ponteiro maior recebe endereço da matriz
                }
                
                if(*menor > *(comeco_matriz+1)){ //Ocorre o mesmo, porém com condição para achar o menor
                
                menor = comeco_matriz+1;
                }
        comeco_matriz++; //Pula para o próximo elemento da matriz
        }

	printf("Maior -> %d\nMenor -> %d\n\n", *maior, *menor);
}



/* ------------------------------ */
/*    FUNCOES NAO IMPLEMENTADAS   */
/* ------------------------------ */

/* Recebe os elementos da matriz */
void popula_matriz(int *comeco_matriz, int dimensao){
        
        for(int i = 0; i < pow(dimensao,2); i++){
                scanf("%d",comeco_matriz); 
                        if(*comeco_matriz < 0){ *comeco_matriz = 0;}//Impedimos um valor < 0 
                        else if(*comeco_matriz > 255) { *comeco_matriz = 255;} //e também, um valor > 255
                comeco_matriz++; //Pula para o próximo elemento da matriz
        }
}


/* Recebe os valores de uma outra matriz e soma a matriz principal com a matriz informada */
void clareia(int *comeco_matriz, int dimensao){

        int matrizAux[dimensao][dimensao];//Cria-se uma matriz nova para passar como parametro p/ popula_matriz
        
        popula_matriz(&matrizAux[0][0], dimensao); //Chama a funções passando como parametro o primeiro endereço da matriz 
        
        for(int i = 0; i < dimensao; i++){ 
                for(int j = 0; j < dimensao; j++){
                        
                        if(*comeco_matriz + matrizAux[i][j] > 255){ //Verifica se a soma não ultrapassa 255 e faz a correção
                        *comeco_matriz = 255;
                        }
                        else{  //Se não ultrapassa faz a soma
                        *comeco_matriz = *comeco_matriz + matrizAux[i][j];
                        }
                                               
                        comeco_matriz++; //Pula para o próximo endereço
                       
                }
        }
        
                
}

/* Recebe os valores de uma outra matriz e subtrai a matriz principal pela matriz informada */
void escurece(int *comeco_matriz, int dimensao){

        //A mesma lógica do clareia porém com a subtração
        int matrizAux[dimensao][dimensao];
        int *aux = &matrizAux[0][0];
        
        popula_matriz(&matrizAux[0][0], dimensao);     
       
        for(int i = 0; i < dimensao; i++){ 
                for(int j = 0; j < dimensao; j++){
                        if(*comeco_matriz - matrizAux[i][j] < 0){ //Verifica se a soma não é menor que 0 e faz a correção
                        *comeco_matriz = 0;
                        }
                        else{  //Se não é menor, faz a soma
                        *comeco_matriz = *comeco_matriz - matrizAux[i][j];
                        }
                                               
                        comeco_matriz++; //Pula para o próximo endereço
                       
                }
        }         
}

/* Retorna 1 se for uma matriz diagonal e 0 caso contrário */
int diagonal(int *comeco_matriz, int dimensao){

        int matriz[dimensao][dimensao]; //Cria-se uma matriz
       
        for(int i = 0; i < dimensao; i++){ //Por ser uma matriz podemos trabalhar normalmente
                for(int j = 0; j < dimensao; j++){
                        
                        matriz[i][j] = *comeco_matriz; //A matriz recebe o valor
                        comeco_matriz++; //Pula para o próximo endereço
                       
                        if(i != j && matriz[i][j] != 0){//Se os elementos não pertencente a diagonal forem diferente de zero
                                                               //retornamos falsos
                                 return 0;               
                        }
                }
        }
        
        return 1; //caso passe por todas condições, retornamos verdadeiro
}

/* A matriz passa a ser sua matriz transposta */
void transposta(int *comeco_matriz, int dimensao){
        
        int *matriz[dimensao][dimensao]; //Declaramos uma matriz ponteiro
        int matrizAux[dimensao][dimensao]; //Declaramos uma matriz qualquer
        int aux;                           //E um auxiliar.
        
        for(int i = 0; i < dimensao; i++){ 
                for(int j = 0; j < dimensao; j++){
                        matriz[i][j] = comeco_matriz;//A matriz ponteiro recebe todos os endereços
                                                     //da outra matriz.
                        matrizAux[j][i] = *comeco_matriz; //Enquanto a matrizAux recebe sua transposta
                        comeco_matriz++; //Pula para o pŕoximo endereço.
                }
        }
        
        for(int i = 0; i < dimensao; i++){
                for(int j = 0; j < dimensao; j++){
                        *matriz[i][j] = matrizAux[i][j]; //Agora, a matriz ponteiro com os endereços
                                                        //da matriz que foi usada como parametro, recebe o valor da matriz
                                                       //transposta.
                }
        }
        
}

/* Todos os numeros maiores ou iguais que num_binariza passam a ser 255
	Os outros numeros passam a ser 0 */
void binariza(int *comeco_matriz, int dimensao, int num_binariza){

//É basicamente a mesma lógica do clareia e escurece, porém, a comparação é feita com o num_binariza
        for(int i = 0; i < pow(dimensao,2); i++){

                if(*comeco_matriz >= num_binariza){ *comeco_matriz = 255;}
                else{*comeco_matriz = 0;}
                                       
                comeco_matriz++;
        }
        
}

        
