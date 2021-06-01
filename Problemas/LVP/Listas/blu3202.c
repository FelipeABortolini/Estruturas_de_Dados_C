#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "blu3202.h"

typedef struct{
	char nome[30];
	int idade;
} pessoa;

typedef struct lstItem{
	pessoa dado;
	struct lstItem *next;
} lista;

pessoa* novo_dado(){
   //aloca memória para armazenar os dados de uma pessoa faz o ponteiro "p" apontar para a área de memória em que estes dados estão armazenados
   pessoa* p = malloc(sizeof(pessoa)); 
   printf("Nome: ");
   scanf("%s", p->nome);
   printf("Idade: ");
   scanf("%d",&(p->idade));
   return p;
}


/* Criação da lista: retorna uma lista vazia */
lista *cria_lista(){
   return NULL;
}



/* 
   Imprime a lista.
*/
void imprime_lista(lista *l){
   /* "atual" é um ponteiro para o elemento da lista que está sendo examinado. Inicialmente, aponta para o primeiro elemento */
   lista *atual = l; 

   while(atual!=NULL){
      printf("- Nome: %s; Idade: %d\n", (*atual).dado.nome, atual->dado.idade);
      atual = atual->next;
   }
}



/* 
   Insere um novo elemento no inicio na lista.
   Retorna um ponteiro para a cabeça da lista.
*/
lista* insere_no_inicio(lista *l, pessoa dado){ 
   lista* novo = malloc(sizeof(lista));
   (*novo).dado = dado;
   (*novo).next = l;
   l = novo;   
}


/* 
   Inverte a lista cujo primeiro elemento é apontado pelo ponteiro l.
   Retorna um ponteiro para o ínício da lista invertida.
*/

lista* inverte(lista *l){
	lista* a = NULL;
	lista* p = NULL;
	if(l != NULL){
		a = l;
		p = a->next;
	}
	lista* pp = NULL;
	if(p != NULL) pp = p->next;
	while(p!=NULL){
		if(a==l){
			a->next = NULL;
			p->next = a;
			a = p;
			p = pp;
			if(pp!=NULL) pp = pp->next;
		}
		else {
			p->next = a;
			a = p;
			p = pp;
			if(pp!=NULL) pp = pp->next;
		}
	}
	l = a;
	return l;
}


int main(){

   lista *l = cria_lista();
   
   int opcao = 0;   

   while(opcao!=9){   
      printf("1 - Inserir no início da lista\n"); 
      printf("2 - Imprimir a lista\n");
      printf("3 - Inverter a lista\n");
      printf("9 - Encerrar o programa\n");
      printf("\nDigite a opção desejada: ");
      scanf("%d",&opcao);
      printf("Opcao selecionada %d\n", opcao);

      if(opcao==1){
         pessoa *novo = novo_dado(); 
         l = insere_no_inicio(l, *novo);
      }else 
      if(opcao==2){
         printf("\n\n");
         imprime_lista(l);
         printf("\n\n"); 
         getchar();
      }else
	  if(opcao==3){
	  	l = inverte(l);
	  }  
   }
   return 0;   
}
