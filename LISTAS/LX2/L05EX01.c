/* ================================================================== *
   Universidade Federal de Sao Carlos - UFSCar, Sorocaba

   Disciplina: Algoritmos e Programação 2

   Lista 05

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
#include <string.h>

#define INSERIR 			1
#define PROCURAR1 			2
#define PROCURAR2 			3
#define PROCURAR3 			4
#define REMOVER 			5
#define IMPRIMIR 			6
#define SAIR 				0

#define TAM_NOME                      200


        
                        /*Declaração de struct's*/

typedef struct _no{ //Aqui recebe o RA, nome e a struct data.

	int ra;//Cria-se o campo do RA.
	char nome[TAM_NOME];//Uma string com tamanho de 200 caracteres.
        int ano; //E a data de ingresso.        	

	struct _no *proximo; //Cria-se um apontador para o pŕoximo nó.
	struct _no *antecessor;//Cria-se um apontador para o nó anterior.
	
}no;

typedef struct { //Agora, cria-se uma nova struct que será chamada lista.
	
	no *primeiro; /*E cria-se na lista um indicador que 
	apontara para o primeiro da lista*/
        no *ultimo; /*E cria-se na lista um indicador que 
	apontara para o último da lista*/
	
	int quantidade; //E cria uma variável quantidade.

} lista;

/*----------------------------------------------------------------------------*/


void inicializa( lista* l );
void inserir_ordem( lista* l, int r, char n[], int a);
no* procurar_ra( lista* l, int r);
void procurar_nome( lista* l, char n[]);
int procurar_indice( lista* l, int r);
void imprimir( lista *l );
void remover( lista *l, int r );





int main() {

	lista m; 
	inicializa(&m);
	
	int ra, ano; //ra e ano;
	char nome[TAM_NOME];//Nome;
	int opcao;//Opções;
        int i;//Variável para receber o retorno do "procurar_indice()".
        no* aux = NULL;/*um "no" ponteiro para receber o endereço de um no
        de retorno de alguma função*/
                
	do {
		scanf("%d",&opcao);

		switch(opcao){

			case INSERIR:
			
	                        scanf("%d", &ra);//Recebe o ra.
	                        scanf(" %[^\n]s", nome);//Recebe o nome.
	                        //getchar();
	                        scanf("%d", &ano);//Recebe o ano.
	                        
	                        inserir_ordem(&m, ra, nome, ano);//Insere na lista ligada..
			break;


			case PROCURAR1:
			
				scanf("%d",&ra);//Recebe o ra para fazer a busca.

		                aux = procurar_ra(&m, ra);/*Após a busca o endereço do
		                nó encontrado é recebido pelo nó "aux".*/
		                
		                if(aux != NULL) {/*Se o nó for diferente de NULL
		                sabemos que foi encontrado.*/
				        printf("%s %d\n", aux->nome, aux->ano);
			        } else {/*Se for igual, a função não encontrou nada.*/
	        		        printf("INEXISTENTE\n");
			        }
			        
			break;
                        
                        case PROCURAR2:
				scanf(" %[^\n]s",nome);//Recebemos o nome para fazer a busca.
				//getchar();
				
	                        procurar_nome(&m, nome);//Recebe o endereço da lista e o nome a ser procurado.       
			break;        

                	case PROCURAR3:
			
				scanf("%d",&ra);//Recebe o RA.
				
				i = procurar_indice(&m, ra);//O indice é retornado para o "i".
				
				if(i == -1){//Caso a função seja retornada -1, sabemos que o RA nãO existe.  
				       printf("INEXISTENTE\n");
				} else {//Se não, printamos o RA achado.
				       printf("%d\n",i); 
				} 
			break;

			case REMOVER:
				scanf("%d",&ra);//Recebemos o RA do nó que será excluído.        
                                remover(&m,ra);
			break;


			case IMPRIMIR:
                                imprimir(&m);//Lista todos os RA'S na ordem crescente.
			break;			
		}	
		
	} while(opcao != 0);//Caso seja "0" o programa é encerrado.
		
	return 0;
}


void inicializa( lista* l ) {

        /*O primeiro e último serão inicializados com NULL.*/
	l->primeiro = NULL;  
	l->ultimo = NULL;                    
	
        l->quantidade = 0; //E a quantidade inicial será zero.
}

void inserir_ordem( lista* l, int ra, char nm[], int ano) { 
	
	no *p = (no*)malloc(sizeof(no)); //Alocação dinâmica.
	
	if(p){//Verifica se alocou memória.
	
		p->ra = ra;// "p->ra" recebe o "ra".
		strcpy(p->nome,nm);//"p->nome" recebe o "nm" digitado.
		p->ano = ano; //"p->ano" recebe "ano";
		
                no *pp = l->primeiro; //O nó "pp" recebe o primeiro nó da lista.				
        
		if(pp == NULL || p->ra < pp->ra){/*Verificamos se é ou se será o "l->primeiro".*/
		
		        
		        l->primeiro = p;//Indicamos o novo "l->primeiro".
		
		        if(pp == NULL){ l->ultimo = p; }/*Agora se for o primeiro da lista também
		        será o último.*/
		
		        else { /* Se não for o primeiro da lista temos de deixar o antigo primeiro como segundo.  */
		                p->proximo = pp;
		                pp->antecessor = p; 
	                }
		        
	                l->quantidade++; 	
	                              
		} else { /*Agora que sabemos que nao é o menor da lista e nem o único da lista, podemos começar
		a inserir na posição correta, ou seja, na ordem crescente.*/
		                
		        while(pp){             
		             
		             if(p->ra == pp->ra || p->ra == pp->proximo->ra){
                                        
                                        free(p);
		                        printf("REPETIDO\n"); 
		                        return;
		                
		             }
		             
		             /*Se for maior e o próximo for NULL é o último, então 
		             temos de indicar o novo l->ultimo.*/
		             else if((p->ra > pp->ra && pp->proximo == NULL)
		             
		             || (p->ra > pp->ra && p->ra < pp->proximo->ra)){
		             /*Ou se for maior e menor que seu sucessor, temos de indicar
		             para quem os novos pp->proximo e o pp->proximo->antecessor.*/

		                        if(pp->proximo == NULL){
		                                l->ultimo  = p; /*Se for NULL, temos de indicar o novo último.*/
		                        }
		                        
		                        else{pp->proximo->antecessor = p; }/*Se não for NULL 
		                        indicamos o antecessor do próximo do pp que agora é p.*/   

		                        p->antecessor = pp;//O novo antecessor de "p".
		                        p->proximo = pp->proximo;/*O próximo de "p" será 
		                        o de "pp".*/		                        
		                        pp->proximo = p;//O próximo do "pp" agora será "p".
                                
                                        l->quantidade++;//Incrementa.
		                        return;
	                     }   
                              
		               
		                pp = pp->proximo;
		        }      
		               
		}	
			
        }
        
}


no* procurar_ra( lista* l, int r) {
        
        no *p = l->primeiro;	
        no *pp = l->ultimo;
        
	while(p != NULL && pp != NULL) {
		
		if(r == p->ra){
		        return p;//Quando achar retorna a lista em questão.
		}
				
	        else if(r == pp->ra){
		        return pp;//Quando achar retorna a lista em questão.
		}
		p = p->proximo;
		pp = pp->antecessor;
	} 
	return NULL; //Se não achar retorna NULL;
}


void procurar_nome( lista* l, char n[]) {
        
        no *p = l->primeiro;	
        int i = 0;
                
	while(p) {
		/*Procura por palavras existentes no nome
		if(strncmp(n,p->nome,strlen(n)) == 0){
		        printf("%d ", p->ra);                        
		        v++;
		}
		
		p = p->proximo;
	        */
	        
	        //Procura por nome
	        
		if(strcmp(n,p->nome) == 0){
		        if(i > 0){ printf(" "); } 
		        printf("%d", p->ra);      
	                i++;                       
		}
		
		p = p->proximo;
	                


	} 
	if(i==0){printf("INEXISTENTE");}
	printf("\n");
}


int procurar_indice( lista* l, int r) {
        
        int aux = 1; //Como a lista "inicia" no 0, apenas colocamos um contador.
        int aux2 = l->quantidade;
        
        no *p = l->primeiro;
        no *pp = l->ultimo;	
        
	while( p && pp) {
		
		if(r == p->ra){
		        return aux;//Quando achar retorna o contador que será a "posição" da lista.
		}
		if(r == pp->ra){
		        return aux2;//Quando achar retorna o contador que será a "posição" da lista.
		}
		
	        aux++;	
	        aux2--;
	        
	        pp = pp->antecessor;
		p = p->proximo;
	}       
	return -1; //Se não achar, retorna o -1;
}

void imprimir( lista *l ) { 

        no *p = l->primeiro; /*Cria-se um no ponteiro "p" que recebe o "primeiro" que é
	o primeiro da lista*/
	
	
	/*while(p) {Verificamos se é nulo, pois neste caso se for, quer dizer
	que não tem nenhuma lista criada, ou seja, nada para imprimir 
	
		printf("%d ", p->ra); Aqui imprimimos o item que está na lista.
		
		p = p->antecessor;E depois, "p" recebe aquele no qual aponta 
		para imprimir o próximo caso não seja nulo.
	}
	printf("\n");
        
	no *p = l->primeiro; Cria-se um no ponteiro "p" que recebe o "primeiro" que é
	o primeiro da lista*/ 
	
	while(p) {/*Verificamos se é nulo, pois neste caso se for, quer dizer
	que não tem nenhuma lista criada, ou seja, nada para imprimir*/ 
	
		printf("%d ", p->ra); //Aqui imprimimos o item que está na lista.
		
		p = p->proximo;/*E depois, "p" recebe aquele no qual aponta 
		para imprimir o próximo caso não seja nulo.*/
	}
	printf("\n");
}


void remover( lista *l, int r ) {
	
        
	no *p = l->primeiro;//Aponta para o primeiro.	
        no *z = l->ultimo; //Aponta para o último.
        no *aux, *aux1;
        
        no *pp;//E um nó para auxiliar.
                
        if(l->primeiro->ra == r){ /*Se for o primeiro a ser excluido, 
        temos indicar o novo "l->primeiro".*/
                
                pp = p->proximo;/*Por isso, precisamos saber quem indicar, logo, 
                o próximo.*/
                
                if(pp == NULL){/*Se o próximo for NULL então devemos excluir o 
                devemos inicializar novamente.*/
                        inicializa(l);
                } else{ 
                        pp->antecessor = NULL; 
                        l->primeiro = pp; 
                }

                l->quantidade--;                             
                free(p);                                  
                return;
        }

        else if(l->ultimo->ra == r){ //Se for o último a ser excluido, temos indicar o novo "l->ultimo".
                       
                        pp = z->antecessor;/*Usaremos o "pp" como auxiliar recebendo
                        o penúltimo.*/
                        pp->proximo = NULL; /*Como o anterior estava apontando para o próximo
                        no qual vai ser excluído, temos de indicar que, como último, ele 
                        apontará para o NULL.*/
                        
                        l->ultimo = pp;//Indicamos o novo último.
                    
                        l->quantidade--;
                        free(z);//Excluímos.
                        
                        
                        return;
        }
            
        else{        
	        while(p != NULL && z != NULL) {
	                
		        if(p->ra == r){
		        
		                /*O nó "pp" recebe o antecessor e o proximo de "p".*/
		                pp = p->antecessor; 
		                pp->proximo = p->proximo;
		                
		                p->proximo->antecessor = pp;/*E temos de reescrever o próximo do "p"
		                par não apontar para um endereço já excluído.*/
		                
		                l->quantidade--;
		                free(p);
		                return;      
		        }
		        else if(z->ra == r){//Exatamente a mesma lógica.
		        
		                pp = z->antecessor; 
		                pp->proximo = z->proximo;
		                
		                
		                z->proximo->antecessor = pp;/*E temos de reescrever o próximo do "p"
		                par não apontar para um endereço já excluído.*/
		                
		                l->quantidade--;
		                free(z);
		                return;       
		        }
		        
		        p = p->proximo;
	                z = z->antecessor;
	                
	        } 
        }
}



