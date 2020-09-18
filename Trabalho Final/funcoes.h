#ifndef FUNCOES_H
#define FUNCOES_H


#define NOME_SIZE       255 //tamanho maximo por nome
#define PAIS_SIZE       55  //tamanho maximo por país 
#define NOMEARQ_SIZE    500 //Tamanho máximo por arquivo.  


typedef struct _no no;

//Struc para os dados.
typedef struct player{ 
	int posicao; 
	char nome[NOME_SIZE];
	char pais[PAIS_SIZE];
	int idade;
} Jogador; 

//Duplamente encadeada.
struct _no{		
	Jogador jgd;//Crio os dados.
	no *proximo;
        no *anterior;
};

typedef struct {
        no *sent;//Nó cabeça/Sentinela.
        int quantidade;
}RANKING;


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
     
#endif


