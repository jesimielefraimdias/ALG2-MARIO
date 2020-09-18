#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int exportar_bin(RANKING *r, char nomearq[]);		
void limpar(RANKING *r);
int criar(RANKING *r);
int inserir(RANKING *r, Jogador jg);
no *procurar( RANKING *r, int psc);
int procurar_nome(RANKING *r, char n[]);
void imprimir(RANKING *r);
int excluir(RANKING *r, int psc);
int exportar_csv(RANKING *r, char nomearq[]);
int importar_csv(RANKING *r, char nomearq[]);        
int apagar_arquivo(char nomearq[]);
        


int main(){

        //"i" usado para busca por nome, "open" para verificar se tem arquivo aberto e "opcao" para usar no switch.
        int i,open = 0,opcao;

	char confirma;//Para confirmar com 's'.
	char nomearq[NOMEARQ_SIZE - 5];// -4, pois irá receber .csv e .bin nas funções.
	RANKING rank;//cria o rank.
        Jogador jgd; //para passagem de dados.
        no *aux; //Para receber nó do procurar.        
        
    if(criar(&rank)){//Retorna 1 se conseguir criar e entra no if.    
              do{    					      //primeiro looping
                                          //menu principal
                      printf("********************************************************************************");
                      puts  ("\n\n\t\t********** P R O G R A M A   M E N U **********");
                      printf("\n\n********************************************************************************");
                      puts("\n\n \tEscolha a opcao desejada:");
                      
                      puts("\n\t 1 - Cadastrar novo jogador");
                      puts("\t 2 - Buscar jogador"); 
                      puts("\t 3 - Editar jogador");
                      puts("\t 4 - Excluir jogador");
                      puts("\t 5 - Importar/Exportar dados");
                      puts("\t 6 - Limpar ranking");
                      puts("\t 7 - Apagar arquivo");
                      puts("\t 8 - Imprimir ranking");
                      puts("\t 9 - Atualizar arquivo");
                      puts("\t 10 - Sair");
                      printf("\n\t\t\t\tOpcao: "); 
                      scanf ("%d", &opcao);

                      switch (opcao){  //escolha da opção do menu principal. 
         
                                case 1: 		
                                        printf("********************************************************************************");
                     		        puts("\n\n\t\t********** CADASTRAR JOGADOR **********");
                     		        printf("\n\n********************************************************************************");
                      		        puts("\n\n \tEscolha a opcao desejada:");
                      
                         		 puts("\n\t 1 - Cadastrar novo jogador");
                         		 puts("\t 0 - Retornar menu principal");
                         		 
                                               
                            	        do{        	//segundo looping
                                                    	//menu CADASTRO
                                                printf("\n\t\t\t\tOpcao: "); 
                                                scanf ("%d", &opcao);
                            	        	switch (opcao){
                                                               
                            	        	case 0: break; //Para
                                                       	        	
					                case 1:  // A struc jgd recebe os dados para passagem de parametro.
						                puts("\n\tCadastrar novo jogador");
			                                        printf("Digite a posição do ranking do novo jogador: ");
	                        		                scanf("%d",&jgd.posicao);
	                        		                printf("Digite o nome do novo jogador: ");
	                        		                scanf("%s",jgd.nome);
	                        		                printf("Digite o pais do novo jogador: ");
	                        		                scanf("%s",jgd.pais);
	                        		                printf("Digite a idade do novo jogador: ");
	                        		                scanf("%d",&jgd.idade);

						                printf("\n");
						                printf("Confirma o cadastro do novo jogador (S/N)\n");
						                getchar();
						                scanf("%c",&confirma);/*Após receber os dados, verificamos se
						                realmente vai querer incluir.*/
                                                                getchar();


						                if (confirma == 'S' || confirma == 's'){//Confirma.
						                
						                        /*Retorna 1 se der erro e entra no if ou 
						                        retorna 0 e entra no else.*/
                                                                        if(inserir(&rank, jgd)){
                                                                                printf("Não foi possível inserir\n");
                                                                        } else { printf("Inserido com sucesso\n\n"); }//CONFIRMA INSERÇÃO.
                                                                        							
						                }
					                break;  
						
					                default:
						                printf ("\n\n ******************************* opcao invalida ********************************");
                             			printf ("Pressione <ENTER> para retornar ao menu");
                //             			confirma = getch();
                            	        	}
                                	}while(opcao != 0);  //fecha o segundo looping
                      	        break;                //vai direto para o fim do primeiro switch sem testar os demais case
                            
                                case 2: 
                                        printf("********************************************************************************");
                     		        puts("\n\n\t\t********** BUSCAR JAGADOR **********");
                     			printf("\n\n********************************************************************************");
                      			puts("\n\n \tEscolha a opcao desejada:");
                      
                      			puts("\n\t 1 - Buscar jogador por ranking");
                      			puts("\t 2 - Buscar jogador por nome");
                      			puts("\t 0 - Retornar menu principal");
                      			
                            	        do{ //terceiro looping 
                            			//Menu Buscar Jogador 
                                                
                                                printf("\n\t\t\t\tOpcao: ");	 
                      				scanf ("%d", &opcao);

                            	        	switch (opcao){
                            	        		case 0: break;
		                        		case 1:	
		                        		        //Busca o jogador de acordo com a posição digitada. 
                                                                printf("Digite a posição do ranking do jogador: ");
                                                                scanf("%d",&jgd.posicao);
                                                                aux = procurar(&rank, jgd.posicao);//Retorna o nó com a posição
                                                                
                                                                if(aux != NULL){//Se retorna != NULL encontrou o nó.
                                                                        //Exibe os dados.
                                                                        printf("nome:  %s\n",aux->jgd.nome);
                                                                        printf("pais:  %s\n",aux->jgd.pais);
                                                                        printf("idade: %d\n\n",aux->jgd.idade);
                                                                                
                                                                } else { printf("Não foi encontra nó com está posição de rank\n"); }//Exibe msg de erro.                
                                                                aux = NULL;                  
                                                        break;
                                                                
					                case 2: //Busca por String 
		                                        
		                                                printf("Digite o nome do jogador: ");
				                                scanf("%s",jgd.nome);
                                                                i = procurar_nome(&rank, jgd.nome);
                                                                if(i == -1){
                                                                        printf("Ocorreu um erro\n");
                                                                } else if(i == 1){
                                                                        printf("Não achou resultados semelhantes\n");
                                                                }
                                                        break;
                                                                         
					                default:
					                        printf ("\n\n ******************************* opcao invalida ********************************");
                             				printf ("Pressione <ENTER> para retornar ao menu");
                  //           				confirma = getch();
                            		}	
                            	}while(opcao != 0); //fim do terceiro looping
                            break;					//volta menu 
                            
                            case 3:
                            							//Menu EDITAR JOGADOR 
                                printf("********************************************************************************");
                     	        puts  ("\n\n\t\t********** EDITAR JOGADOR **********");
                     	        printf("\n\n********************************************************************************");
                      		puts("\n\n \tEscolha a opcao desejada:");
                      		puts("\n\t 1 - Editar jogador");
                      		puts("\t 0 - Retornar menu principal");
                      		
                                do{						//quarto looping				        
                                        printf("\n\t\t\t\tOpcao: "); 
                      			scanf ("%d", &opcao);
                      				
                            		switch(opcao){
                            			case 0: break;
                            			case 1: 
                            			        printf("Digite a posição do ranking do jogador: ");
                            			        scanf("%d",&jgd.posicao);//Recebe a posição para procura.
                                                        aux = procurar(&rank, jgd.posicao);/*Se achar retorna o nó ou
                                                        NULL se não achar.*/        
                                                        
                                                        if(aux != NULL){//Verifica se achou.
                                                                
                                                                //Altera os dados com excção da chave primária.
                                                                
			                                        printf("Digite o nome do novo jogador: ");
			                                        scanf("%s",jgd.nome);
			                                        printf("Digite o pais do novo jogador: ");
			                                        scanf("%s",jgd.pais);
			                                        printf("Digite a idade do novo jogador: ");
			                                        scanf("%d",&jgd.idade);
                                                                
                                                                printf("Confirme se realmente deseja editar(S/N)\n");
	                                                        getchar();
	                                                        scanf("%c",&confirma);
	                                                        getchar();
	                                                        if(confirma == 's' || confirma == 'S'){
	                                                                aux->jgd = jgd;//Passa os dados alterados.
	                                                                printf("Alterado com sucesso\n");
	                                                        }
                                                        
                                                } else { printf("Não foi localizado\n"); }                
                                                        aux = NULL;
                            			break;//Editar 
                            			
                            			default:
		                                        printf ("\n\n ******************************* opcao invalida ********************************");
                             				printf ("Pressione <ENTER> para retornar ao menu");
                    //         				getch();
                            		}

                            	}while(opcao != 0); //fim do quarto looping
                            break;					//volta menu 

                            case 4:
                            //MENU EXCLUIR JOGADOR 
                            	        
                            	printf("********************************************************************************");
                     		puts("\n\n\t\t********** EXCLUIR JAGADOR **********");
                     		printf("\n\n********************************************************************************");
                      		puts("\n\n \tEscolha a opcao desejada:");
                      		puts("\n\t 1 - Excluir jogador");
                      		puts("\t 0 - Retornar menu principal");
                      		
                                do{							//quinto looping 	
                            	        
                            	        printf("\n\t\t\t\tOpcao: ");         
                      			scanf ("%d", &opcao);
                            		
                            		switch(opcao){
                            		        case 0: break;
                            			case 1:         
                                      		        
                                      		        printf("Digite a posição do ranking do jogador: "); 
                                      		        scanf("%d", &jgd.posicao);
                                      		        
                                      		        printf("Confirme se realmente deseja editar(S/N)\n");
                                 
                                                        getchar();
	                                                scanf("%c",&confirma);
	                                                getchar();
	                                                if(confirma == 's' || confirma == 'S'){
	                                                        if(excluir(&rank, jgd.posicao)){/*Excluir retorna 1 
	                                                        em caso de erro ou entra no else em caso de sucesso.*/
                                                                printf("Ocorreu um erro");
                                                                } else { printf("Excluído com sucesso\n"); }
	                                                }
                                                                   
                            			break;// Excluir jogador 
                            			default:
				                        printf ("\n\n ******************************* opcao invalida ********************************");
                             				printf ("Pressione <ENTER> para retornar ao menu");
                      //       				confirma = getch();
                            		}

                            	}while(opcao != 0);			//fim do quinto looping 
                            break;							//volta menu
                            
                            case 5:							
                                                //IMPORTAR/EXPORTAR DADOS
                            	
                                printf("********************************************************************************");
                     		puts  ("\n\n\t\t********** IMPORTAR/EXPORTAR DADOS  **********");
                     		printf("\n\n********************************************************************************");
                      		puts("\n\n \tEscolha a opcao desejada:");
                      
                      		puts("\n\t 1 - IMPORTAR DADOS");
                      		puts("\t 2 - EXPORTAR DADOS");
                      		puts("\t 0 - Retornar menu principal");
                      		
                      		do{
                      		        printf("\n\t\t\t\tOpcao: "); 
                      		       	scanf ("%d", &opcao);
                            	
                            		        switch(opcao){
                            			        case 0:break;
                            			        case 1: //Importar 
                            			        
                            			                confirma = 's';//Inicia com 's'.
                            			        
                            			                if(rank.quantidade){//Verifica se não possui dados no RANKING.
                            			                        printf("Você já possui dados pretende sobrescrever os atuais? (S/N) \n");                                               //Caso possua, avisa o usuário e pede sua confirmação.
                            			                        getchar();
                            			                        scanf("%c",&confirma);
                            			                        getchar();
                            			                }
                            			        
                            			                if (confirma == 'S' || confirma == 's'){/*Após a confirmação ou
                            			                caso não tenha dados, pede o nome do arquivo.*/

                                                                        printf("Digite o nome do arquivo para importar\n");
                                                                        scanf("%s",nomearq);//Recebe o nome.
                                  
                                                                        /*Passa como parametro o RANKING e o nome do arquivo
                                                                        que será importado para a função.*/
                                                                        if(importar_csv(&rank, nomearq)){
                                                                                printf("Ocorreu um erro\n");
                                                                        } else {
                                                                                printf("Importado com sucesso\n");
                                                                                open = 1;/*Para avisar que tem um arquivo
                                                                                que está sendo trabalhado*/        
                                                                        }
                                                                
                                                                }		        
                                                break;

                            			case 2: //Exportar 
                        
                            			        printf("Digite o nome do arquivo para exportar\n");
                                                        getchar();
                                                        scanf("%s",nomearq);
                                                        getchar();
                                                                //Exporta em bin e csv.
                                                                /*Caso tenha dado algo errado entra no if, 
                                                                ao contrário, retornam 0 e entra no else. */
                                                                if(exportar_bin(&rank,nomearq) + exportar_csv(&rank,nomearq)){
                                                                        printf("Ocorreu um erro\n");
                                                                } else {
                                                                        printf("Exportado com sucesso\n");        
                                                                }
                                                       
                                                                                                
                                                         		        
                                                                
                            			break;
                            			default:
				                        printf ("\n\n ******************************* opcao invalida ********************************");
                             				printf ("Pressione <ENTER> para retornar ao menu");
                                                          		
                            		}

                                }while(opcao != 0);
                            break;
                          	
                            case 6:
                                                                     			                
                                printf("Confirme se realmente deseja limpar seu RANKING (S/N)\n");
	                        getchar();
	                        scanf("%c",&confirma);
	                        getchar();                        
	                                                        
	                        if (confirma == 'S' || confirma == 's'){           
                                        limpar(&rank);
                                        printf("Ranking limpo com sucesso\n"); 
                                }
                                                      
                             break;        
                                   
                           case 7: 
                                //Menu limpar ranking
                                printf("********************************************************************************");
                     	        puts  ("\n\n\t\t********** APAGAR ARQUIVO **********");
                     		printf("\n\n********************************************************************************");
                      		puts("\n\n \tEscolha a opcao desejada:");
                      		puts("\n\t 1 - Apagar arquivo");
                      		puts("\t 0 - Retornar menu principal");
                      		do{				 
                            	        
                                        printf("\n\t\t\t\tOpcao: "); 
                      	                scanf ("%d", &opcao);              	
                                       
	                    	
                            		        switch(opcao){
                                                        
                            			        case 0:break;
                            			        case 1:
                                                                
                                                                
                            			                printf("Digite o nome do arquivo que será apagado\n");
                                                                scanf("%s",nomearq);         
                                                                printf("Confirme se realmente deseja apagar (S/N)\n");
	                                                        getchar();
	                                                        scanf("%c",&confirma);
	                                                        getchar();
	                                                        if (confirma == 'S' || confirma == 's'){           
                                                                        if(apagar_arquivo(nomearq)){
                                                                                printf("Ocorreu um erro\n");
                                                                        } else { printf("Arquivo apagado com sucesso\n"); }
                                                                }
                                                        break;        
                            			        //Importar 
                            			        	default:
				                        printf ("\n\n ******************************* opcao invalida ********************************");
                                                        printf ("Pressione <ENTER> para retornar ao menu");
                                               	        
                                                }
                                        }while(opcao != 0);            
                                
                                               
                           break;
                           
                           case 8: 
                                 imprimir(&rank);
                           break;
                           
                           case 9:
                                
                                if(open){
                                        printf("Confirme se realmente desaja atualizar o arquivo (S/N)\n");
                                        getchar();
                                        scanf("%c",&confirma);//Para confirmar.
                                        getchar();
                                  
                                        if(confirma == 's' || confirma == 'S'){
                                                if(exportar_bin(&rank,nomearq) + exportar_csv(&rank,nomearq)){/*
                                                Se alguma das funções retornarem != exibe a msg de erro.*/
                                                        printf("Não foi possível atualizado\n");
                                                } else { printf("Atualizado com sucesso\n"); }
                                        }
                                } else {
                                        printf("Não possui arquivo aberto\n");
                                }
                           break; 
                           
                           case 10: break;
                               
                        default:
                     	
                                printf ("\n\n ******************************* opcao invalida ********************************");
                             	printf ("Pressione <ENTER> para retornar ao menu");
                        }
                    				//fecha o primeito switch
                     
                }while (opcao!=10); //fecha o primeiro looping 
        }
               
	return 0;
}

