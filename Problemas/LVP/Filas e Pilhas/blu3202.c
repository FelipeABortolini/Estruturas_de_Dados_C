#include<stdio.h>
#include<stdlib.h>
//#inlcude"blu3202.h"

typedef struct lstItem{
   char dado;
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


void *push(pilha *p, char dado){
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


int valida_cadeia(char *palavra){
	pilha *p = criaPilha();
	int m = 0, n = 0;
	while(*palavra != 'w' && *palavra != '\0'){
		push(p, *palavra);
		palavra += 1;
		n++;
	}
	palavra += 1;
	while(m != n){
		if(p->top->dado == *palavra){
			pop(p);
			m++;
			if(m != n) palavra += 1;
		} else return 0;
	}
	return 1;
}

int main(){
	int i = valida_cadeia("aaa");
	printf("%d", i);
}
