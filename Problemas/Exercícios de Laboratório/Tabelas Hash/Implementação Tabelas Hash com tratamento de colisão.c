#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct aluno{  
   char nome[30];
   float n1, n2, n3;
} typedef Aluno;


struct lstItem{
   Aluno *dado;
   struct lstItem *next;
}typedef listaItem;


struct hash {
   int TABLE_SIZE;
   listaItem **itens; //os itens são um vetor de ponteiros
} typedef Hash;


/******************** Funções para lista encadeada ****************/

/* Criação da lista: retorna uma lista vazia */
listaItem *cria_lista(){
   return NULL;
}


void insere_no_fim(listaItem **lista, Aluno *dado){
   listaItem *novo = malloc(sizeof(listaItem));
   novo->dado = dado;
   novo->next = NULL;
  
   if(*lista==NULL){
      *lista = novo;
   } 
   else{
       listaItem *ultimo = *lista;
       while(ultimo->next!=NULL){
        ultimo = ultimo->next;        
       }
       ultimo->next = novo;
   }  
}

/*********************************************************************/



/**************** Funcoes para manipulacao da tabela Hash *******************/
Hash *criaHash(int TABLE_SIZE){
   Hash *h = malloc(sizeof(Hash));
   int i;
   h->TABLE_SIZE = TABLE_SIZE;
   h->itens = malloc(TABLE_SIZE*sizeof(listaItem));
   for (i=0;i<h->TABLE_SIZE;i++){  
      h->itens[i]= cria_lista();      
   }
   return h;
}



int gera_hash(char* s, int TABLE_SIZE){
   /*int i, hash = 0;
   int len_s = strlen(s);
   for (i=0;i<len_s;i++){
      hash  = hash + s[i];        
    }
    return hash%TABLE_SIZE;*/
    int i = 0;
	while(*s != '\0'){
		i += *s;
		s += 1;
	} return i % TABLE_SIZE;
}


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

/*
   Inserir um novo elemento na tabela hash.
*/
void insere(Hash *h, Aluno *a){
   if(h==NULL){ 
      printf("Não será possível inserir");
   }
   else{
      /* Implementar a insercao. Se a posicao estiver ocupada, exibir uma mensagem e não inserir. Do contrário, fazer a inserção e exibir uma mensagem informando a posicao em que o elemento foi inserido.
      */
      int hash = gera_hash(a->nome, h->TABLE_SIZE);
      insere_no_fim(&(h->itens[hash]), a);
      printf("Elemento inserido na posicao %d\n", hash);
   }   
}

/*
   Remover da tabela hash o elemento com a chave passada no parâmetro.
*/
void remover(Hash *h, char *chave){
   if(h==NULL){
      printf("Não será possível remover");
   }
   else{
     /* Implementar a remocao. Se a chave não existir na tabela, exibir uma mensagem informando que a chave nao foi encontrada. Do contrário, fazer a exclusao e informar a posicao do item que foi removido. */
		int hash = gera_hash(chave, h->TABLE_SIZE);
		if(h->itens[hash] == NULL) printf("Aluno não encontrado!\n");
		else{
			listaItem *n = h->itens[hash];
			listaItem *ant = h->itens[hash];
			while(strcmp(chave, n->dado->nome) != 0){
				ant = n;
				n = n->next;
			}
			ant->next = n->next;
			free(n->dado);
			free(n);
			printf("Aluno %s removido com sucesso!\n", chave);
		}
   }
}


/*
  Busca na tabela hash o elemento com a chave passada no parâmetro.
*/
Aluno *busca(Hash *h, char *nome){
	int hash = gera_hash(nome, h->TABLE_SIZE);
	listaItem *n = h->itens[hash];
	while(n != NULL && strcmp(nome, n->dado->nome) != 0){
		n = n->next;
	} 
	if(n != NULL) return n->dado;
	return NULL;
}


void enderecos(Hash *h){
   int i;
   for(i=0;i<h->TABLE_SIZE;i++){
      printf("%d ", i);
      if(h->itens[i]==NULL)
         printf(" NULL %p, %p\n",&(h->itens[i]),h->itens[i] );
      else
         printf(" not NULL %p, %p, %s\n", &(h->itens[i]),h->itens[i],h->itens[i]->dado->nome);  
   }
}

Aluno *cria_aluno(){
   Aluno *a = malloc(sizeof(Aluno));
   printf("Nome: ");
   scanf("%s",a->nome);
   printf("Nota 1: ");
   scanf("%f", &(a->n1));
   printf("Nota 2: ");
   scanf("%f", &(a->n2));
   printf("Nota 3: ");
   scanf("%f", &(a->n3));
   return a;
}

void print_aluno(Aluno *a){
   printf("%s: %f, %f, %f\n", a->nome, a->n1, a->n2, a->n3);
}

void imprime_tabela_hash(Hash *h){
	int i;
	for(i = 0; i<h->TABLE_SIZE; i++){
		if(h->itens[i] == NULL){
		} else {
			printf("POSICAO %d\n", i);
			while(h->itens[i] != NULL){
				print_aluno(h->itens[i]->dado);
				h->itens[i] = h->itens[i]->next;
			}
		}
	}
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
        Aluno *a = cria_aluno();
        insere(h, a);        
     }else
     if(opcao==2){
        char nome[30];
        printf("Digite o nome do aluno: ");
        scanf("%s",nome);
        remover(h, nome);
     }else
     if(opcao==3){
        char nome[30];
        printf("Digite o nome do aluno: ");
        scanf("%s",nome);
        Aluno *a = busca(h,nome);
        printf("Dado localizado: ");
        if(a!=NULL)
        	print_aluno(a);
        else printf("Aluno nao encontrado!\n");
     } else
     if(opcao==4){
     	printf("\n");
     	imprime_tabela_hash(h);
     	printf("\n");
	 }
   }

   liberaHash(h);
}
