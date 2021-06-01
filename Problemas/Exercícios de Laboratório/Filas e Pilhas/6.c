#include <stdio.h>
#include <stdlib.h>


typedef struct lstItem{
   int dado;
   struct lstItem *next;
}pilhaItem;


typedef struct{
   pilhaItem *top;	
}pilha;



pilha *criaPilha(){
   pilha *p = malloc(sizeof(pilha));
   p->top = NULL;
   return p;
}

void *push(pilha *p, int dado){
   pilhaItem *novo = malloc(sizeof(pilhaItem));
   novo->dado = dado;
   novo->next = p->top; 
   p->top = novo;
}


void *pop(pilha *p){
   pilhaItem *item = p->top;
   if(item!=NULL)
      p->top = p->top->next;
}



int peek(pilha *p){
   if(p->top!=NULL)
      return p->top->dado;
   else
      return -1;
}

void print(pilha *p){
   pilhaItem *item = p->top;
   while(item!=NULL){
      printf("%d --- ",item->dado);
      item = item->next;
   }
   printf("\n\n");
}

int compara_pilhas(pilha *p1, pilha *p2){
	if(peek(p1)==-1 && peek(p2)==-1) return -1;
	while(peek(p1) != -1 || peek(p2) != -1){
		if(peek(p1) == peek(p2)){
			pop(p1);
			pop(p2);
		} else {
			while(peek(p1) != -1 || peek(p2) != -1){
				pop(p1);
				pop(p2);
			}
			return 0;
		}
	}
	return 1;
}

int main(){
   
   pilha *p1 = criaPilha(), *p2 = criaPilha();
   int opcao = 1, i, j; 

   while(opcao!=10){
      printf("1 - Empilhar na pilha 1\n");
      printf("2 - Desmpilhar da pilha 1\n");
      printf("3 - Consultar cabeça (peek) da pilha 1\n");
      printf("4 - Imprimir a pilha 1\n");
      printf("5 - Empilhar na pilha 2\n");
      printf("6 - Desmpilhar da pilha 2\n");
      printf("7 - Consultar cabeça (peek) da pilha 2\n");
      printf("8 - Imprimir a pilha 2\n");
      printf("9 - Comparar pilhas\n");
      printf("10 - Sair\n");
      printf("\nDigite uma opcao: ");
      scanf("%d",&opcao);
      
      if(opcao==1){
         printf("Digite um número inteiro: ");
         scanf("%d",&i);
         push(p1,i);
      }else
      if(opcao==2){
         pop(p1);
         printf("Item removido com sucesso");
      }else
      if(opcao==3)  {
         printf("%d\n",peek(p1));
      }else
      if(opcao==4)  {
         print(p1);
      }else 
	  if(opcao==5){
         printf("Digite um número inteiro: ");
         scanf("%d",&i);
         push(p2,i);
      }else
      if(opcao==6){
         pop(p2);
         printf("Item removido com sucesso");
      }else
      if(opcao==7)  {
         printf("%d\n",peek(p2));
      }else
      if(opcao==8)  {
         print(p2);
      }else
      if(opcao==9)  {
         j = compara_pilhas(p1, p2);
         if(j==0) printf("Pilhas diferentes!\n");
         else if(j==1) printf("Pilhas iguais!\n");
         else printf("Erro!\n");
      }
   }
}
