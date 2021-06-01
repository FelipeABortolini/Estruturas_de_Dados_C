#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
   char nome[30];
   float preco; 
} produto;


typedef struct lstItem{
   produto dado;
   struct lstItem *prev;
   struct lstItem *next;
} lstProduto;



/* Criação da lista: retorna uma lista vazia */
lstProduto *cria_lista(){
   return NULL;
}



/* 
   Imprime a lista.
   Esta função é um exemplo de como percorrer uma lista encadeada.
*/
void print(lstProduto *lista){
   /* "atual" é um ponteiro para o elemento da lista que está sendo examinado. Inicialmente, aponta para o primeiro elemento */
   lstProduto *atual = lista; 

   while(atual!=NULL){
      printf(">>Nome: %s; Preco: %f\n", (*atual).dado.nome, atual->dado.preco);
      atual = atual->next;
   }
}

/* 
   Imprime a lista invertida.
   Esta função é um exemplo de como percorrer uma lista duplamente encadeada de trás para frente.
*/
void print_inv(lstProduto *lista){
    /* "atual" é um ponteiro para o elemento da lista que está sendo examinado. Inicialmente, aponta para o primeiro elemento */
    lstProduto *atual = lista;
    while(atual->next!=NULL){
		atual = atual->next;	
    } 
	
    while(atual!=NULL){
        printf(">>Nome: %s; Preco: %f\n", (*atual).dado.nome, atual->dado.preco);
        atual = atual->prev;
    }
}



/* 
   Procura, em lstProduto, um elemento cujos dados sejam igual ao "dado" passado como parâmetro .
   Retorna um ponteiro para o elemento da lista que contém o referido dado.
*/
lstProduto *busca(lstProduto *lista, produto dado){
	if(lista==NULL || (strcmp((*lista).dado.nome, dado.nome) == 0 && (*lista).dado.preco == dado.preco)){
	   	return lista;
	}
	else return busca((*lista).next,dado);
}


/* 
   Insere um novo elemento no inicio na lista.
   Retorna um ponteiro para a cabeça da lista.
*/
lstProduto* insere_no_inicio(lstProduto *lista, produto dado){
    lstProduto* novo = malloc(sizeof(lstProduto));
    novo->dado = dado;
    novo->next = lista;
    novo->prev = NULL;
    if(lista!=NULL){
		lista->prev = novo;
    }
    lista = novo;
    return lista;
}

/* 
   VOID
   Insere um novo elemento no inicio na lista.
*/
void void_insere_no_inicio(lstProduto *lista, produto dado){ 
    lstProduto* novo = malloc(sizeof(lstProduto));
	novo->dado = lista->dado;
    novo->next = lista->next;
   	novo->prev = lista;
    lista->dado = dado;
    lista->prev = NULL;
    lista->next = novo;
}


/* 
   Insere um novo elemento no final na lista.
   Retorna um ponteiro para a cabeça da lista.

*/
lstProduto* insere_no_fim(lstProduto *lista, produto dado){
    lstProduto* novo = malloc(sizeof(lstProduto));
    novo->dado = dado;
    if(lista==NULL){
    	novo->dado = dado;
   		novo->next = NULL;
   		novo->prev = NULL;
		lista = novo;
    } else {
        lstProduto *ultimo = lista;
        while(ultimo->next!=NULL){
           ultimo = ultimo->next; 
        }
        ultimo->next = novo;
        novo->next = NULL;
        novo->prev = ultimo;
    }
    return lista;
}




/* 
   Inserção do produto passado no parâmetro "dado" após a posicao que armazena o produto passado no parâmero "posicao".
   Retorna um ponteiro para a cabeça da lista.
*/
lstProduto *insere_apos(lstProduto *lista, produto dado, produto posicao){
	lstProduto* p = lista;
	
	lstProduto* novo = malloc(sizeof(lstProduto));
	novo->dado = dado;
	novo->next = NULL;
	novo->prev = NULL;
	
	if(p==NULL){
		p = novo;
		return p;
	} else {
		while(p->next != NULL && (strcmp(p->dado.nome, posicao.nome) != 0 && p->dado.preco != posicao.preco)){
			p = p->next;
		}
		novo->next = p->next;
		novo->prev = p;
		p->next->prev = novo;
		p->next = novo;
	}
	return lista;
}



lstProduto *excluir_elemento(lstProduto *lista, produto dado){
	lstProduto* p = lista;
	lstProduto* q = lista->next;
	if(strcmp(p->dado.nome, dado.nome) == 0 && p->dado.preco == dado.preco){
		q->prev = NULL;
		lista = q;
		free(p);
		return lista;
	}
	while(q != NULL && ((strcmp(q->dado.nome, dado.nome) != 0 && q->dado.preco != dado.preco))){
		p = q;
		q = q->next;
	}
	if(q==NULL) return lista;
	if(strcmp(q->dado.nome, dado.nome) == 0 && q->dado.preco == dado.preco){
		p->next = q->next;
		q->next->prev = p;
		free(q);
	}
	return lista;
}



/* Execução das rotinas necessárias para ler os dados de um novo produto */
produto *novo_produto(){
   produto *novo = malloc(sizeof(produto));
   printf("Nome do produto: ");
   scanf("%s",((*novo).nome));
   printf("Preço: ");
   scanf("%f",&((*novo).preco));
   return novo;
}

int main(){

   lstProduto *lista = cria_lista();
   
   int opcao = 0;   

   while(opcao!=9){   
      /* Imprime o menu de opcoes */
      printf("1 - Inserir no início da lista\n"); 
      printf("2 - Inserir no meio da lista\n");
      printf("3 - Inserir no fim da lista\n");
      printf("4 - Excluir elemento da lista\n");
      printf("5 - Imprimir a lista\n");
      printf("6 - Pesquisar\n");
      printf("7 - Imprimir a lista invertida\n");
      printf("9 - Encerrar o programa\n");
      printf("\nDigite a opção desejada: ");
      scanf("%d",&opcao);
      printf("Opcao selecionada %d\n", opcao);

      if(opcao==1){
         produto *novo = novo_produto(); 
         //lista = insere_no_inicio(lista, *novo);
         if(lista==NULL){
         	lista = malloc(sizeof(lstProduto));
         	lista->dado = *novo;
         	lista->next = NULL;
         	lista->prev = NULL;
		 } else {
		 	void_insere_no_inicio(lista, *novo);
		 }
      }else 
      if(opcao==2){        
         produto *novo = novo_produto();          
         printf("Informe a posição que o novo elemento deve ocupar:\n");    
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
      	 printf("\n\n");
         print(lista);
         printf("\n\n");
         getchar();
      }else
      if(opcao==6){
         produto *p = novo_produto();          
         lstProduto *b = busca(lista,*p);
         if(b==NULL)
            printf("Produto não encontrado.\n"); 
         else
           printf("Produto encontrado.\n");  
         printf("\npressione qualquer tecla para continuar\n"  );
         getchar();
         getchar();
      }else
      if(opcao==7){
      	printf("\n\n");
      	print_inv(lista);
		printf("\n\n");
		getchar(); 	
	  }
   }
   
}
