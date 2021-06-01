#include <stdio.h>
#include<stdbool.h>
#include<string.h>
#include <stdlib.h>
//#include "blu3202.h"

typedef struct{
	char nome[30];
	int idade;
} pessoa;


struct tree{
	pessoa *dado;
	struct tree *left, *right;
} typedef Tree;


Tree *create_tree(){
   return NULL;
}


Tree* inserir_nodo(Tree *t, pessoa *dado){
   if(t==NULL){
      t = malloc(sizeof(Tree));
      (*t).dado = dado;
      (*t).left = NULL;
      (*t).right = NULL; 
   }else{
      if(strcmp(dado->nome,t->dado->nome)<0)
         (*t).left = inserir_nodo((*t).left,dado);     
      else
         (*t).right = inserir_nodo((*t).right,dado); 
   } 
   return t;
}


/* imprimir o conteudo dos nodos percorrendo a arvore em pre-ordem*/
void imprimir_preorder(Tree *root){
	if(root != NULL){
		printf("%s;%d;", root->dado->nome, root->dado->idade);
		imprimir_preorder(root->left);
		imprimir_preorder(root->right);
	}
}


/* imprimir o conteudo dos nodos percorrendo a arvore em pos-ordem*/
void imprimir_postorder(Tree *root){
	if(root != NULL){
		imprimir_postorder(root->left);
		imprimir_postorder(root->right);
		printf("%s;%d;", root->dado->nome, root->dado->idade);
	}
}


/* imprimir o conteudo dos nodos percorrendo a arvore em-ordem (in-order)*/
void imprimir_inorder(Tree *root){
   if(root != NULL){
		imprimir_inorder(root->left);
		printf("%s;%d;", root->dado->nome, root->dado->idade);
		imprimir_inorder(root->right);
	}
}


/* Remover da arvore "t" o nodo "nodo" passado como parametro */
Tree* remover_nodo(Tree *t, Tree *nodo){
   //NÃO é necessário implementar esta função no laboratório virtual de programação da disciplina BLU3202
}


pessoa *cria_pessoa(){
   pessoa *a = malloc(sizeof(pessoa));
   printf("Nome: ");
   scanf("%s",a->nome);
   printf("Idade: ");
   scanf("%d", &(a->idade));
   return a;
}



/* 
   Imprime a arvore "t" na tela a partir da profundidade passada como parametro.
   Para imprimir a arvore a partir da raiz, informar profundidade zero.
*/
void mostra_arvore(Tree *t, int profundidade, char lado){
   int i;
   if (t != NULL){
      for (i = 0; i < profundidade*5; i++){
         if (i > profundidade*5 -5){
	    printf("-");
         } else {
	   printf(" ");
	}
      }
      printf(">%s - %d (%c)\n", t->dado->nome, t->dado->idade, lado);
      profundidade++;
      mostra_arvore(t->left, profundidade, 'L');
      mostra_arvore(t->right, profundidade, 'R');
   }
}


void main(){
  Tree *T = create_tree(); /* ponteiro para a raiz da arvore */
  pessoa *p;
  int option=0, x;
  char nome[30];
  while(option!=9){
    printf("Opções: \n <1> - Inserir \n <2> - Imprimir Preorder\n <3> - Imprimir Postorder\n <4> - Imprimir Inorder\n <5> - Mostrar árvore\n <9> - Sair");
    printf("\nDigite uma opção: ");
      scanf("%d", &option);
      switch(option){
        case 1: 
                p = cria_pessoa();
                T = inserir_nodo(T,p); 
        break;
        case 2: imprimir_preorder(T);        
                printf("\n");
        break;    
        case 3: imprimir_postorder(T);        
                printf("\n");
        break;
        case 4: imprimir_inorder(T);        
                printf("\n");
        break;
        
        case 5: mostra_arvore(T,0, 'T');        
                printf("\n"); 
        break;    
      }              
  }
   	

}
