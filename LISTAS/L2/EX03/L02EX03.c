/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Algoritmos e Programação 2

	Lista 02 - Exercício 03 - Conversao Binaria

	Instrucoes
	----------

	Este arquivo contem o codigo que auxiliara no desenvolvimento do
	exercicio. Voce precisara completar as partes requisitadas.

* ================================================================== *
	Dados do aluno:

	RA: 726544
	Nome: Jesimiel Efraim Dias

* ================================================================== */

/* <<< ESCREVA SEU CODIGO AQUI >>> */
	
#include<stdio.h>
void converterDecimal(int n);

int main(){

int n;

scanf("%d",&n);
converterDecimal(n);

return 0;
}


void converterDecimal(int n){

        if(n/2 != 0){
        converterDecimal(n/2); 
        }
        printf("%d",n%2);

}




	
