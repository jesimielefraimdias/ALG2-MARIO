


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


        
                        


typedef struct _no{ 

	int ra;
	char nome[TAM_NOME];
        int ano; 

	struct _no *proximo; 
	struct _no *antecessor;
	
}no;

typedef struct { 
	
	no *primeiro; 

        no *ultimo; 

	
	int quantidade; 

} lista;





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
	
	int ra, ano; 
	char nome[TAM_NOME];
	int opcao;
        int i;
        no* aux = NULL;

                
	do {
		scanf("%d",&opcao);

		switch(opcao){

			case INSERIR:
			
	                        scanf("%d", &ra);
	                        scanf(" %[^\n]s", nome);
	                        
	                        scanf("%d", &ano);
	                        
	                        inserir_ordem(&m, ra, nome, ano);
			break;


			case PROCURAR1:
			
				scanf("%d",&ra);

		                aux = procurar_ra(&m, ra);

		                
		                if(aux != NULL) {

				        printf("%s %d\n", aux->nome, aux->ano);
			        } else {

	        		        printf("INEXISTENTE\n");
			        }
			        
			break;
                        
                        case PROCURAR2:
				scanf(" %[^\n]s",nome);
				
				
	                        procurar_nome(&m, nome);
			break;        

                	case PROCURAR3:
			
				scanf("%d",&ra);
				
				i = procurar_indice(&m, ra);
				
				if(i == -1){
				       printf("INEXISTENTE\n");
				} else {
				       printf("%d\n",i); 
				} 
			break;

			case REMOVER:
				scanf("%d",&ra);
                                remover(&m,ra);
			break;


			case IMPRIMIR:
                                imprimir(&m);
			break;			
		}	
		
	} while(opcao != 0);
		
	return 0;
}


void inicializa( lista* l ) {

        

	l->primeiro = NULL;  
	l->ultimo = NULL;                    
	
        l->quantidade = 0; 
}

void inserir_ordem( lista* l, int ra, char nm[], int ano) { 
	
	no *p = (no*)malloc(sizeof(no)); 
	
	if(p){
	
		p->ra = ra;
		strcpy(p->nome,nm);
		p->ano = ano; 
		
                no *pp = l->primeiro; 
        
		if(pp == NULL || p->ra < pp->ra){

		
		        
		        l->primeiro = p;
		
		        if(pp == NULL){ l->ultimo = p; }

		
		        else { 

		                p->proximo = pp;
		                pp->antecessor = p; 
	                }
		        
	                l->quantidade++; 	
	                              
		} else { 

		                
		        while(pp){             
		             
		             if(p->ra == pp->ra || p->ra == pp->proximo->ra){
                                        
                                        free(p);
		                        printf("REPETIDO\n"); 
		                        return;
		                
		             }
		             
		             

		             else if((p->ra > pp->ra && pp->proximo == NULL)
		             
		             || (p->ra > pp->ra && p->ra < pp->proximo->ra)){
		             


		                        if(pp->proximo == NULL){
		                                l->ultimo  = p; 

		                        }
		                        
		                        else{pp->proximo->antecessor = p; }
   

		                        p->antecessor = pp;
		                        p->proximo = pp->proximo;
		                        
		                        pp->proximo = p;
                                
                                        l->quantidade++;
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
		        return p;
		}
				
	        else if(r == pp->ra){
		        return pp;
		}
		p = p->proximo;
		pp = pp->antecessor;
	} 
	return NULL; 
}


void procurar_nome( lista* l, char n[]) {
        
        no *p = l->primeiro;	
        int i = 0;
                
	while(p) {
		

	        
	        
	        
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
        
        int aux = 1; 
        int aux2 = l->quantidade;
        
        no *p = l->primeiro;
        no *pp = l->ultimo;	
        
	while( p && pp) {
		
		if(r == p->ra){
		        return aux;
		}
		if(r == pp->ra){
		        return aux2;
		}
		
	        aux++;	
	        aux2--;
	        
	        pp = pp->antecessor;
		p = p->proximo;
	}       
	return -1; 
}

void imprimir( lista *l ) { 

        no *p = l->primeiro; 

	
	
	
 
	
	while(p) {
 
	
		printf("%d ", p->ra); 
		
		p = p->proximo;

	}
	printf("\n");
}


void remover( lista *l, int r ) {
	
        
	no *p = l->primeiro;
        no *z = l->ultimo; 
        no *aux, *aux1;
        
        no *pp;
                
        if(l->primeiro->ra == r){ 

                
                pp = p->proximo;

                
                if(pp == NULL){

                        inicializa(l);
                } else{ 
                        pp->antecessor = NULL; 
                        l->primeiro = pp; 
                }

                l->quantidade--;                             
                free(p);                                  
                return;
        }

        else if(l->ultimo->ra == r){ 
                       
                        pp = z->antecessor;

                        pp->proximo = NULL; 

                        
                        l->ultimo = pp;
                    
                        l->quantidade--;
                        free(z);
                        
                        
                        return;
        }
            
        else{        
	        while(p != NULL && z != NULL) {
	                
		        if(p->ra == r){
		        
		                

		                pp = p->antecessor; 
		                pp->proximo = p->proximo;
		                
		                p->proximo->antecessor = pp;

		                
		                l->quantidade--;
		                free(p);
		                return;      
		        }
		        else if(z->ra == r){
		        
		                pp = z->antecessor; 
		                pp->proximo = z->proximo;
		                
		                
		                z->proximo->antecessor = pp;

		                
		                l->quantidade--;
		                free(z);
		                return;       
		        }
		        
		        p = p->proximo;
	                z = z->antecessor;
	                
	        } 
        }
}



