/* ================================================================== *
   Universidade Federal de Sao Carlos - UFSCar, Sorocaba

   Disciplina: Algoritmos e Programação 2

   Lista 04 - Exercício 01 - Polinomio

   Instrucoes
   ----------

   Este arquivo contem o codigo que auxiliara no desenvolvimento do
   exercicio. Voce precisara completar as partes requisitadas.

* ================================================================== *
   Dados do aluno:

   RA: 
   Nome: 

* ================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Opcoes ***********************
#define SAIR               0
#define ADICIONAR_POLI     1
#define REMOVER_POLI	   2
#define SOMAR_POLI         3
#define SUBTRAIR_POLI      4
#define MULTIPLICAR_POLI   5
#define CALCULAR_POLI      6

// declaracoes de registros
/* <<< DEFINA OS REGISTROS AQUI >>> */

// declaracoes das funcoes
/* <<< DECLARE OS PROTOTIPOS DAS FUNCOES AQUI >>> */

/* ------------------------------ */
/* ROTINA PRINCIPAL - NAO ALTERAR */
/* ------------------------------ */
int main() {

   int x, coef, exp, poliEscolhido, operando1, operando2;
   Polinomio *p1 = NULL;
   Polinomio *p2 = NULL;
   Polinomio *resultado = NULL;

   scanf("%d",&x);

   int opcao = 1;
   while(opcao != 0){
      scanf("%d",&opcao);
      switch(opcao){

         case ADICIONAR_POLI:
            scanf("%d %d %d", &poliEscolhido, &coef, &exp);
            poliEscolhido == 1 ? adicionarPolinomio(&p1,coef,exp) : adicionarPolinomio(&p2,coef,exp);
         break;

         case REMOVER_POLI:
            scanf("%d %d", &poliEscolhido, &exp);
            poliEscolhido == 1 ? removerPolinomio(&p1,exp) : removerPolinomio(&p2,exp);
         break;

         case SOMAR_POLI:
            if(resultado != NULL) libera(resultado);
            resultado = somarPolinomios(p1,p2);
         break;

         case SUBTRAIR_POLI:
            scanf("%d %d", &operando1, &operando2);
            if(resultado != NULL) libera(resultado);
            resultado = subtrairPolinomios(operando1 == 1 ? p1 : p2, operando2 == 2 ? p2 : p1);
         break;

         case MULTIPLICAR_POLI:
            if(resultado != NULL) libera(resultado);
            resultado = multiplicarPolinomios(p1,p2);
         break;

         case CALCULAR_POLI:
            scanf("%d",&poliEscolhido);
            switch(poliEscolhido) {
               case 1: printf("%d\n",calcularPolinomio(p1,x)); break;
               case 2: printf("%d\n",calcularPolinomio(p2,x)); break;
               case 3: printf("%d\n",calcularPolinomio(resultado,x)); break;
            }
         break;

      }
   }

   return (0);

}

/* ------------------------- */
/* IMPLEMENTACAO DAS FUNCOES */
/* ------------------------- */

/* <<< IMPLEMENTE AS FUNCOES AQUI >>> */
