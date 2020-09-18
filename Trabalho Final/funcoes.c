#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include "funcoes.h"



int inserir(RANKING *r, Jogador jg){

        if(procurar(r, jg.posicao) == NULL){/*Se o procurar voltar NULL significa que
                                              não encontrou nenhum nó com está posição para retornar, logo,
                                              a posição não existe.*/
                
                no *novo = (no*)malloc(sizeof(no));//armazenamento.      
                
                if(novo){//Se voltar NULL não entrará no if.
                
                        novo->jgd = jg;//A struct "jgd" recebe os dados.           
                        no *end = r->sent->proximo;//"end" recebe o nó que vem após o sentinela.                        
                        novo->proximo = r->sent->proximo;/*O "novo" será inserido na frente do "sent",
                        logo, ele recebe o proximo de "sent".*/
                        novo->anterior = r->sent;//O anterior do primeiro nó será sempre o "sent".
                        r->sent->proximo = novo;//"sent" aponta para seu novo sucessor que no caso é o "novo".
                        end->anterior = novo;//"end" aponta para seu antecessor que neste caso será o "novo".
                        r->quantidade++;//Incrementa
                       
                        while(end != r->sent){//COMPARA ATÉ O SENTINELA
                        
                        
                                if(novo->jgd.posicao > end->jgd.posicao){
                                /*Como já sabemos que "novo" > "aux", basta fazermos a troca.*/ 
         
                                       novo->proximo = end->proximo;//"novo" atualiza seu próximo.
                                       end->proximo = novo;//"novo" será inserido a frente do "end", logo, atualiza o "end".
                                       end->anterior = novo->anterior;//"end" atualiza seu anterior.
                                       novo->anterior->proximo = end;/*O anterior do "novo" deverá apontar 
                                       para seu novo próximo, que no caso é o "end".*/
                                       novo->proximo->anterior = novo;/*O próximo do "novo" terá de atualizar seu antecessor
                                       , pois antes estava como "end" e agora será o "novo".*/
                                       novo->anterior = end;//Por fim, o "novo" anterior recebe "end".
               
                                } else { break; }/*reak, pois se for menor, o lugar que o nó se encontra
                                 já está correto.*/
                                end = novo->proximo;/*Como o "novo" está a frente de "end", teremos de passar o próximo do "novo"
                                para darmos continuidade as comparações.  */
                       }          
                        
                       return 0;//caso ocorra tudo bem retorna 0.
                 }
        } return 1;//Se der algo errado retorna 1.
}




no *procurar( RANKING *r, int psc) {
        
        no *aux = r->sent->proximo;//Inicializa "aux" com o próximo de "sent".
        
	while(aux != r->sent ) {//Avança até "sent" por causa de ser circular.
		
		if(aux->jgd.posicao == psc){//Verifica se a posição foi encontrada.
        		return aux;//Se sim, retorna o nó em questão.
		}
		aux = aux->proximo;
	}
	return NULL; //Se não achar, retorna NULL.
}

int excluir( RANKING *r, int psc) {
        
        no *aux = procurar(r,psc);/*Usamos o procurar para achar o nó a ser excluído
        e retorna-lo para a "aux".*/
        
        if(aux != NULL){//Se o retorno for diferente de NULL quer dizer que encontramos.
        
        /*Caso encontrado, precisamos apenas indicar que seu antecessor deverá apontar para
        seu próximo, e, que seu próximo deverá apontar para o novo anterior.*/
                aux->anterior->proximo = aux->proximo;  
                aux->proximo->anterior = aux->anterior;
                free(aux);
                return 0;
        }                                
        return 1;
}



void imprimir(RANKING *r) {
        
        no *end = r->sent->proximo; 

	while(end != r->sent ) {/*Verificamos até chegar no "sent".*/ 
	
                printf("Rank: %d\nNome: %s\nPais: %s\nIdade: %d\n\n",
                end->jgd.posicao,end->jgd.nome,end->jgd.pais,end->jgd.idade);
		end = end->proximo;
	}
	printf("\n");
}


int procurar_nome(RANKING *r, char n[]) {
                
        no *aux = r->sent->proximo;//Inicializa "aux" com o próximo do "sent".
        RANKING x;//Criamos um RANKING "x" que terá todos os nós compativeis.
        int flag = 0;
        
        if(criar(&x)){//Se não inicializar o "x", a função retorna 0 e não entra no if.
                
	        while(aux != r->sent ) {//"aux" vai até chegar no "sent".
		  
		        if(strncmp(aux->jgd.nome,n,strlen(n)) == 0){/*
		        Verifica de acordo com o número de caracteres digitado.
		        */
		        
                                /*Insere no novo RANKING as informações encontradas e que futuramente
                                irá ser passado como parametro para imprimir.*/                       		
		                if(inserir(&x,aux->jgd)){/*Se a inserção deu errado, a função retorna 1
		                 e entra no if de erro.*/
		                        limpar(&x);
		                        return -1;//Volta o valor de erro.
		                }
		                flag++;//Para verificar se encontrou um nó com o nome.
		        }
		        aux = aux->proximo;
	        }
	        if(flag){ //Se encontrou algum nó passa o RANKING "x" como parametro para imprimir.
	                imprimir(&x);
	        } 
        } 
        
	limpar(&x);//Por sim, limpa todos os nós criados.
        return 0;   
}
		
void limpar(RANKING *r){
        
        no *aux = r->sent->proximo;
             
        while(aux != r->sent){ /*
        Libera todos os nós criados*/
                no *ajdt = aux;
                aux = aux->proximo;
                free(ajdt);//Libera os nó's
        }
        /*Reinicia tudo, é como se fosse o criar, porém, sem alocar o nó
        sentinela.*/
        r->quantidade = 0;
        r->sent->proximo = r->sent;
        r->sent->anterior = r->sent;
}


int exportar_bin(RANKING *r, char nomearq[]){

	no *aux = r->sent->proximo;//Recebe o próximo de sent.        
        char arq[NOMEARQ_SIZE];//Cria uma string para armazenar o nome arquivo.
        
        strcpy(arq,nomearq);//Copia o nome para ela.
        strcat(arq,".bin");//Recebe o .bin no final.
        
	FILE *e_arq = fopen(arq, "wb"); //cria novo arquivo binario aberto para escrita
               
        if(e_arq){       
        	fwrite(&r->quantidade, sizeof(int), 1, e_arq);//Escreve o número de registros.

        	while(aux != r->sent){
        		fwrite(&aux->jgd, sizeof(Jogador), 1, e_arq);//Escreve a struct.
                        aux = aux->proximo;//Avança para o próximo.
                }
                return fclose(e_arq);//Retorna 0 em caso de sucesso.
        }
        
        return 1;//1 para erro.
}


int exportar_csv(RANKING *r, char nomearq[]){
        
        //mesma lógia do .bin, porém, coloca .csv a frente.
        char arq[NOMEARQ_SIZE];
        strcpy(arq,nomearq);
        strcat(arq,".csv");
        
        FILE *e_arq = fopen(arq,"w");// Cria o arquivo para escrever.
        
        no *end = r->sent->proximo;//Próximo de "sent".
        
        if(e_arq){//Se for NULL retorna 1;                        
                fprintf(e_arq, "%d\n", r->quantidade); //Escreve primeira linha com o número de registros.
                while (end != r->sent) {/*Enquanto o "end" for diferente "sent"*/ 
                
                        fprintf(e_arq,"%d@%s@%s@%d\n",end->jgd.posicao, end->jgd.nome, end->jgd.pais,end->jgd.idade);
                        /*Passa os dados.*/
                        
                        end = end->proximo;
                }
                
                return fclose(e_arq);//retorna 0 em caso de sucesso e qualquer outro em erro.
        } 


        return 1;//erro.
}

int importar_csv(RANKING *r, char nomearq[]){
        
        /*Mesma lógica de sempre, coloca o .csv na frente.*/
        char arq[NOMEARQ_SIZE];
        strcpy(arq,nomearq);
        strcat(arq,".csv");
        Jogador jgd;
        FILE *i_arq = fopen(arq,"r");//AbreCria o arquivo para escrever.
        
        if(i_arq){//Se for NULL retorna 1;        
                
                fscanf(i_arq, "%d\n", &r->quantidade); /*Recebe a primeira linha por cortezia, pois ao reutilizar o inserir
                                                        estaremos contando o número de nós.*/
                limpar(r);//Limpa os valores antigos.
                
                //Recebe com a struct "jgd" e passa para o inserir ir alocando os dados.
                while(fscanf(i_arq, "%d@%[^@]@%[^@]@%d\n", &jgd.posicao, jgd.nome, jgd.pais, &jgd.idade) != EOF){
                        inserir(r, jgd);
                }
                
                return fclose(i_arq);
        } 
        return 1; 
}




int criar(RANKING *r){
        
 		
      r->quantidade = 0;//Inicializamos como 0 pois o nó cabeça não contará.       
      r->sent = (no*)malloc(sizeof(no));//Alocamos a memória.
        
      if(r->sent != NULL){//Verificamos se alocou.
        
                r->sent->proximo = r->sent;//Não tem primeiro ou último, o nó cabeça será a referência.
                r->sent->anterior = r->sent;
                
               return 1;             
        }        
      return 0;

}


//Para ajudar na manipulação, fiz uma função para apagar arquivos.
int apagar_arquivo(char nomearq[]){
        
        char arq[NOMEARQ_SIZE];
        char arq2[NOMEARQ_SIZE];
      
        //Recebem suas devidas extensões.
        strcpy(arq,nomearq);
        strcat(arq,".csv");
        strcpy(arq2,nomearq);
        strcat(arq2,".bin");
        
        //Caso uma retorne erro entramos no if e retorna 1, ao contrário, retorna 0.
        if(remove(arq2) + remove(arq)){
                return 1;
        } else { 
                return 0;
        }       
              
}

