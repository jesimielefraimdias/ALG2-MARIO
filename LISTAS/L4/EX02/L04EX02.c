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

   RA: 726544
   Nome: Jesimiel Efraim Dias

* ================================================================== */

#include <stdio.h>
#include <stdlib.h>


#define INSERIR 			1
#define PROCURAR 			2
#define REMOVER 			3
#define IMPRIMIR 			4
#define SAIR 				0


typedef int T; //Define "T" como "int".

typedef struct _no{
	T item; //Cria uma variável "T" chamada item.
	struct _no *proximo; //Cria-se uma struct ponteiro chamada "proximo".
} no; //E defino a struct _no como "no".

typedef struct { //Agora, cria-se uma nova struct que será chamada lista.
	no *primeiro; //E cria-se a struct "no" como ponteiro chamada "primeiro".
	int quantidade; //E cria uma variável quantidade.
} lista;

void inicializa( lista* l ) {

	l->primeiro = NULL; //O "primeiro" irá para o NULL, porque está lista
	                    //Será a útima.                    
        l->quantidade = 0; //E a quantidade será zero.

}

void inserir_ordem( lista* l, T valor) { 
	
	no *p = (no*)malloc(sizeof(no)); //Alocação dinâmica.
	
	if(p){//Verifica se alocou memória.
	
		p->item = valor;// p->item recebe valor do usuário.
                no *pp = l->primeiro; //Um novo no recebe o primeiro da lista.				
		
		if( pp == NULL || p->item < pp->item){/*Verificamos se é o primeiro
		da lista OU se será o primeiro da lista.*/
		        l->primeiro = p;
		        p->proximo = pp;
	                l->quantidade++; 	
	                              
		} 
	        else { /*Agora que sabemos que não é o menor da lista, podemos começar
	        a fazer a ordenação da lista.*/
	
                               
		        no *ppp = pp->proximo;/*Criamos um novo no, agora recebe para qual o
		        o "pp" aponta, pois de nada adianta fazer um troca e o próximo ainda ser menor.
		        Dado isto, temos que ter certeza que o que colocamos a "frente" é maior do que seu antecessor
		        e menor do que seu sucessor.*/
		        
		                         
		        while(pp){/*Condição do if é NULL.*/
		                
		                        
		                if((p->item > pp->item && ppp == NULL) ||
		                 (p->item > pp->item && p->item < ppp->item)){ /*Como dito acima,
		                precisamos ter certeza que é maior do que seu antecessor e menor do que seu sucessor.*/
		                         
		                        p->proximo = pp->proximo;/*o p->proximo receberá
		                        a nova variável que terá de apontar.*/
		                        pp->proximo = p;/*E como o "pp->item" é menor, agora ele estará atrás, ou seja, deverá
		                        apontar para o "p".*/                        
	                                l->quantidade++; 		                        
		                        return;/*Já podemos finalizar o loop, dado que a lista é insirida
		                        ordenadamente, discartando a possibilidade de outros sucessores serem maiores.*/       
		                }
		                else if (p->item == pp->item || p->item == ppp->item ) { //Para não repetir valores na lista. 
		                free(p);//Se o valor ser repetido, damos free no nó criado.
		                return; 
		                }
		                 
		                pp = pp->proximo; /*Feito isso, o "pp" recebe o "p->proximo" para ser feita a nova comparação.*/
		                ppp = ppp->proximo;//E o mesmo com "ppp".
		                                                          	
                        }
		}	
			
        }
        
}

int procurar( lista* l, T valor) {
        
        int aux = 0; //Como a lista "inicia" no 0, apenas colocamos um contador.
        no *p = l->primeiro;	
        
	while( p ) {
		
		if(valor == p->item){
		return aux;//Quando achar retorna o contador que será a "posição" da lista.
		}
		
		p = p->proximo;
		aux++;
	} 
	return -1; //Se não achar, retorna o -1;
}

int imprimir( lista *l ) { 

        
	no *p = l->primeiro; /*Cria-se um no ponteiro "p" que recebe o "primeiro" que é
	o primeiro da lista*/ 
	
	while( p ) {/*Verificamos se é nulo, pois neste caso se for, quer dizer
	que não tem nenhuma lista criada, ou seja, nada para imprimir*/ 
	
		printf("%d ", p->item); //Aqui imprimimos o item que está na lista.
		
		p = p->proximo;/*E depois, "p" recebe aquele no qual aponta 
		para imprimir o próximo caso não seja nulo.*/
	}
	printf("\n");
}

void remover( lista *l,T valor ) {
	

	no *pp,*p = l->primeiro;	
        
        if(p->item == valor){ //Se for o primeiro a ser excluido, temos indicar o novo "l->primeiro".
                pp = p->proximo;
                l->primeiro = pp;
                free(p);
        }
    
        else{        
	        while(p) {
		        if(p->proximo == NULL){ return; } //Para não dar erro ao passar para "pp".
		        pp = p->proximo;
		        
		        if(pp->item == valor){
		                p->proximo = pp->proximo;
		                free(pp);
		                return;      
		        }
		        p = p->proximo;
	        } 
        }
}



int main() {
	lista m; 
	inicializa(&m);
	
	int numero; 
	int opcao;
        
	do {
		scanf("%d",&opcao);

		switch(opcao){

			case INSERIR:
			
	                        scanf("%d", &numero);
	                        inserir_ordem(&m, numero);
			break;


			case PROCURAR:
			
				scanf("%d",&numero);
				printf("%d \n",procurar(&m,numero));
			break;


			case REMOVER:
				scanf("%d",&numero);        
                                remover(&m,numero);
			break;


			case IMPRIMIR:
                                imprimir(&m);
			break;			
		}	
		
	} while(opcao != 0);
		
	return 0;
}
