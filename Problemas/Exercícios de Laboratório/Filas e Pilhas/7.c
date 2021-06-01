#include <stdio.h>
#include <stdlib.h>


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



char peek(pilha *p){
   if(p->top!=NULL)
      return p->top->dado;
   else
      return '\0';
}

void print(pilha *p){
   pilhaItem *item = p->top;
   while(item!=NULL){
      printf("%c --- ",item->dado);
      item = item->next;
   }
   printf("\n\n");
}

int linguagem_L(char *s){
	pilha *p = criaPilha();
	int m = 0, n = 0;
	while(*s != 'w' && *s != '\0'){
		push(p, *s);
		s += 1;
		n++;
	}
	s += 1;
	while(m != n){
		if(p->top->dado == *s){
			pop(p);
			m++;
			if(m != n) s += 1;
		} else return 0;
	}
	return 1;
}

int main(){
    int i, n = 2;
    char palavra[50];
    fgets(palavra, 50, stdin);
    i = linguagem_L(palavra);
    if(i==1) printf("A palavra digitada pertence a linguagem L!\n");
    else printf("A palavra digitada pertence a linguagem L!\n");
}
