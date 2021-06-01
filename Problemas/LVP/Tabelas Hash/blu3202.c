#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "blu3202.h"

typedef struct{
   char nome[30];
   int idade; 
} pessoa;

struct hash {
   int TABLE_SIZE;
   pessoa **itens;
} typedef Hash;

/* Cria uma tabela hash de tamanho TABLE_SIZE */
Hash *criaHash(int TABLE_SIZE){
   Hash *h = malloc(sizeof(Hash));
   int i;
   h->TABLE_SIZE = TABLE_SIZE;
   h->itens = malloc(TABLE_SIZE*sizeof(pessoa));
   for (i=0;i<h->TABLE_SIZE;i++){  
      h->itens[i]=NULL;      
   }
   return h;
}


/* Retorna o número hash correspondente à cadeia de caracteres s considerando uma tabela hash de tamanhp TABLE_SIZE */
int gera_hash(char* s, int TABLE_SIZE){
	int i = 0;
	while(*s != '\0'){
		i += *s;
		s += 1;
	} return i % TABLE_SIZE;
}


/* Libera a memória ocupada pela tabela hash h */
void liberaHash(Hash *h){
   if(h!=NULL){
      int i;
      for(i=0;i<h->TABLE_SIZE;i++){
         if(h->itens[i]!=NULL)
            free(h->itens[i]);
      }
      free(h->itens);
      free(h);
   }
}


/* Insere os dados da pessoa p na tabela hash h, retornando o código hash utilizado ou -1 em caso de falha. */
int insere(Hash *h, pessoa *p){
	int posicao = gera_hash(p->nome, h->TABLE_SIZE);
	if(h->itens[posicao] != NULL) return -1;
	else{
		h->itens[posicao] = p;
		return posicao;
	}
}


/* Remove da tabela hash h a pessoa com o nome passado no parâmetro. Retorna o índice da tabela em que a pessoa se estava armazenada ou -1 em caso de falha ou caso o registro não tenha sido encontrado. */
int remover(Hash *h, char *chave){
	int posicao = gera_hash(chave, h->TABLE_SIZE);
	if(h->itens[posicao] == NULL || strcmp(h->itens[posicao]->nome, chave) != 0) return -1;
	else{
		pessoa *p = h->itens[posicao];
		h->itens[posicao] = NULL;
		free(p);
		return posicao;
	}
}


/* Busca na tabela hash o elemento com a chave passada no parâmetro. Retorna NULL caso não tenha encontrado. */
pessoa *busca_hash(Hash *h, char *nome){
	int posicao = gera_hash(nome, h->TABLE_SIZE);
	if(h->itens[posicao] == NULL || strcmp(h->itens[posicao]->nome, nome) != 0) return NULL;
	else return h->itens[posicao];
}

pessoa *cria_pessoa(){
   pessoa *p = malloc(sizeof(pessoa));
   printf("Nome: ");
   scanf("%s",p->nome);
   printf("Idade: ");
   scanf("%d", &(p->idade));
   return p;
}

void print_pessoa(pessoa *p){
   printf("%s: %d\n", p->nome, p->idade);
}

int main(){

   int tamanho = 0;
   printf("Informe o tamanho da tabela: ");
   scanf("%d",&tamanho);
   
   Hash *h = criaHash(tamanho);

   
   int opcao = 1;
   while(opcao!=9){   
      printf("Selecione uma opção\n");
      printf("1 - Inserir\n");
      printf("2 - Remover\n"); 
      printf("3 - Buscar\n");
      printf("4 - Imprimir tabela hash\n");
      printf("9 - Sair\n");
      scanf("%d",&opcao);

     if(opcao==1){
        pessoa *p = cria_pessoa();
        int j = insere(h, p);
		printf("Posicao do item inserido: %d\n", j);   
     }else
     if(opcao==2){
        char nome[30];
        printf("Digite o nome do aluno: ");
        scanf("%s",nome);
        int k = remover(h, nome);
        printf("Posicao do item removido: %d\n", k);
     }else
     if(opcao==3){
        char nome[30];
        printf("Digite o nome do aluno: ");
        scanf("%s",nome);
        pessoa *p = busca_hash(h,nome);
        printf("Dado localizado: ");
        if(p!=NULL)
        	print_pessoa(p);
        else printf("Aluno nao encontrado!\n");
     } /*else
     if(opcao==4){
     	printf("\n");
     	imprime_tabela_hash(h);
     	printf("\n");
	 }*/
   }

   liberaHash(h);
}
