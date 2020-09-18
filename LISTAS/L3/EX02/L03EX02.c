/* ================================================================== *
   Universidade Federal de Sao Carlos - UFSCar, Sorocaba

   Disciplina: Algoritmos e Programação 2

   Lista 03 - Exercício 02 - Troca Valores

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

/* comprimento maximo da cadeia de caracteres para troca */
#define MAX 20


// declaracoes das funcoes
/* <<< DECLARE OS PROTOTIPOS DAS FUNCOES AQUI >>> */

int *verificaOrdenacao(int a, int b, int c,int *ordenado,int *desordenado);

void trocaValores(int *a, int *b, int *c, char trocas[], int total_char);

/* ------------------------------ */
/* ROTINA PRINCIPAL - NAO ALTERAR */
/* ------------------------------ */
int main()
{

   // variaveis utilizadas para entrada
   char trocas[MAX];
   int a,b,c,total_char;
   int i;

   // variaveis de ordenacao
   int ordenado = 1;
   int desordenado = -1;
   int *status;

   // faz leitura dos dados de entrada
   scanf("%d %d %d %d", &a, &b, &c, &total_char);
   for(i=0; i<total_char; i++) {
      do { 
         scanf("%c", &trocas[i]); 
      } while (trocas[i] == ' ');
   }
   
   // faz a troca dos valores conforme a regra
   trocaValores(&a, &b, &c, trocas, total_char);

   // verifica se as variaveis ficaram com valores ordenados
   // --> este metodo retorna ponteiro para a variavel ordenado se a, b e c estiverem
   //     na seguinte condicao: a eh menor ou igual a b e b eh menor ou igual a c;
   //     senao, o metodo retorna ponteiro para a variavel desordenado.
   status = verificaOrdenacao(a,b,c,&ordenado,&desordenado);

   // imprime resultado apos a troca
   printf("%d %d %d (%d)", a, b, c, *status);

   return 0;
}


/* ------------------------- */
/* IMPLEMENTACAO DAS FUNCOES */
void trocaValores(int *a, int *b, int *c, char trocas[], int total_char){

        int aux;
        
        for (int i = 0; i < total_char - 1; i ++){ //Vai até a posição final do vetor
                                                   //total_char -1 para os if's não acessarem um posição inválida
                                                   //através do i+1

                if(trocas[i] == 'A' && trocas[i+1] == 'B' || //Faz a troca, como AB e BA
                trocas[i] == 'B' && trocas[i+1] == 'A'){     //São equivalentes, não precisamos diferenciá-los
                aux = *a;
                *a = *b;
                *b = aux;
                }
                else if(trocas[i] == 'A' && trocas[i+1] == 'C' || //Daqui em diante é a mesma lógica
                trocas[i] == 'C' && trocas[i+1] == 'A'){
                aux = *a;
                *a = *c;
                *c = aux;
                }
                else if(trocas[i] == 'B' && trocas[i+1] == 'C' ||
                trocas[i] == 'C' && trocas[i+1] == 'B'){
                aux = *b;
                *b = *c;
                *c = aux;
                }
        
        }

}

int *verificaOrdenacao(int a, int b, int c,int *ordenado,int *desordenado){
        
        if(a <= b && b <= c){ //A<=B<=C 
        return ordenado; //retorna o endereço
        }
        
        return desordenado;//retorna o endeço
        
}

/* ------------------------- */

/* <<< IMPLEMENTE AS FUNCOES AQUI >>> */

