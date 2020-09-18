/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Algoritmos e Programação 2

	Lista 02 - Exercício 02 - Conjectura de Collatz

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
void conjectura(int n);

int main(){

int n;

        do{
        
        scanf("%d",&n);
        
        }while(n>=1000);


        conjectura(n);        
        
        return 0;
}


void conjectura(int n){

printf("%d ",n);

        if(n>1){
                if(n%2 == 0){
                conjectura(n/2);
                }
                else{
                conjectura(3*n+1);
                }
        }        

}
