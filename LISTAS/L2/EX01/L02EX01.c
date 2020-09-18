/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Algoritmos e Programação 2

	Lista 02 - Exercício 01 - Coeficiente Binomial

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

double fatorial (double x);


int main(){

double n,k;

do{
scanf("%lf %lf",&n, &k);
}while(k < 0 || n > 100 || n < k || k > n);

printf("%.0lf\n", fatorial(n)/(fatorial(k)*fatorial(n-k)));


return 0;
}
  

double fatorial (double x){

        if(x == 0){
        return 1; 
        }
        else { return x * fatorial (x - 1); }
}


