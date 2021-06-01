#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
   char nome[30];
   float preco; 
} produto;


typedef struct lstItem{
   produto dado;
   struct lstItem *next;
} lstProduto;



/* Cria��o da lista: retorna uma lista vazia */
lstProduto *cria_lista(){
   return NULL;
}



/* 
   Imprime a lista.
   Esta fun��o � um exemplo de como percorrer uma lista encadeada.
*/
void print(lstProduto *lista){
   /* "atual" � um ponteiro para o elemento da lista que est� sendo examinado. Inicialmente, aponta para o primeiro elemento */
   lstProduto *atual = lista; 

   while(atual!=NULL){
      printf(">>Nome: %s; Preco: %f\n", atual->dado.nome, atual->dado.preco);
      atual = atual->next;
   }
}



/* 
   Procura, em lstProduto, um elemento cujos dados sejam igual ao "dado" passado como par�metro .
   Retorna um ponteiro para o elemento da lista que cont�m o referido dado.
*/
lstProduto *busca(lstProduto *lista, produto dado){
	if(lista==NULL || (strcmp((*lista).dado.nome, dado.nome) == 0 && (*lista).dado.preco == dado.preco)){
	   	return lista;
	}
	else return busca((*lista).next,dado);
}


/* 
   Insere um novo elemento no inicio na lista.
   Retorna um ponteiro para a cabe�a da lista.
*/
lstProduto* insere_no_inicio(lstProduto *lista, produto dado){ 
   lstProduto* novo = malloc(sizeof(lstProduto));
   (*novo).dado = dado;
   (*novo).next = lista;
   lista = novo;
   return lista;
}

/* 
   VOID
   Insere um novo elemento no inicio na lista.
*/
/*void void_insere_no_inicio(lstProduto *lista, produto dado){ 
    lstProduto novo = (lstProduto) malloc(sizeof());
    novo->dado = dado;
    novo->next = NULL;
    if(lista!=NULL) novo->next = *lista;
    *lista = novo;
}/*

/* 
   Insere um novo elemento no final na lista.
   Retorna um ponteiro para a cabe�a da lista.

*/
lstProduto* insere_no_fim(lstProduto *lista, produto dado){
   lstProduto* novo = malloc(sizeof(lstProduto));
   novo->dado = dado;
   novo->next = NULL;
   if(lista==NULL){
      lista = novo;
   }else{
      lstProduto *ultimo = lista;
      while(ultimo->next!=NULL){
         ultimo = ultimo->next; 
      }
      ultimo->next = novo;
   }
   return lista;
}




/* 
   Inser��o do produto passado no par�metro "dado" ap�s a posicao que armazena o produto passado no par�mero "posicao".
   Retorna um ponteiro para a cabe�a da lista.
*/
lstProduto *insere_apos(lstProduto *lista, produto dado, produto posicao){
	lstProduto* p = lista;
	
	lstProduto* novo = malloc(sizeof(lstProduto));
	novo->dado = dado;
	novo->next = NULL;
	
	if(p==NULL){
		p = novo;
		return p;
	} else {
		while(p->next != NULL && (strcmp(p->dado.nome, posicao.nome) != 0 || p->dado.preco != posicao.preco)){
			p = p->next;
		}
		novo->next = p->next;
		p->next = novo;
	}
	return lista;
}



lstProduto *excluir_elemento(lstProduto *lista, produto dado){
	lstProduto* anterior = NULL;
	lstProduto* aExcluir = lista;
	while(aExcluir != NULL && ((strcmp(aExcluir->dado.nome, dado.nome) != 0 || aExcluir->dado.preco != dado.preco))){
		anterior = aExcluir;
		aExcluir = aExcluir->next;
	}
	if(anterior == NULL)
		lista = aExcluir->next;
	else if(strcmp(aExcluir->dado.nome, dado.nome) == 0 && aExcluir->dado.preco == dado.preco){
		anterior->next = aExcluir->next;
		free(aExcluir);
		aExcluir = NULL;
	}
	return lista;
}



/* Execu��o das rotinas necess�rias para ler os dados de um novo produto */
produto *novo_produto(){
   produto *novo = malloc(sizeof(produto));
   printf("Nome do produto: ");
   scanf("%s",((*novo).nome));
   printf("Pre�o: ");
   scanf("%f",&((*novo).preco));
   return novo;
}

int main(){

   lstProduto *lista = cria_lista();
   
   int opcao = 0;   

   while(opcao!=9){   
      /* Imprime o menu de opcoes */
      printf("1 - Inserir no in�cio da lista\n"); 
      printf("2 - Inserir no meio da lista\n");
      printf("3 - Inserir no fim da lista\n");
      printf("4 - Excluir elemento da lista\n");
      printf("5 - Imprimir a lista\n");
      printf("6 - Pesquisar\n");
      printf("9 - Encerrar o programa\n");
      printf("\nDigite a op��o desejada: ");
      scanf("%d",&opcao);
      printf("Opcao selecionada %d\n", opcao);

      if(opcao==1){
         produto *novo = novo_produto(); 
         lista = insere_no_inicio(lista, *novo);
         //void_insere_no_inicio(lista, *novo);
      }else 
      if(opcao==2){        
         produto *novo = novo_produto();          
         printf("Informe a posi��o que o novo elemento deve ocupar:\n");    
         produto *posicao = novo_produto();
         lista = insere_apos(lista, *novo, *posicao);
      }else
      if(opcao==3){
         produto *novo = novo_produto(); 
         lista = insere_no_fim(lista, *novo);
      }else
      if(opcao==4){
		 produto *novo = novo_produto();
		 lista = excluir_elemento(lista, *novo);
	  }else
      if(opcao==5){
         print(lista);
         printf("\n\n");
         getchar();
      }else
      if(opcao==6){
         produto *p = novo_produto();          
         lstProduto *b = busca(lista,*p);
         if(b==NULL)
            printf("Produto n�o encontrado.\n"); 
         else
           printf("Produto encontrado.\n");  
         printf("\npressione qualquer tecla para continuar\n"  );
         getchar();
         getchar();
      }    
   }
   
}
