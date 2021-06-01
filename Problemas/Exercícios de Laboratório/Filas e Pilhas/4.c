#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define true 1
#define false 0

typedef int bool;

typedef struct e{
	char caractere;
	struct e *prev;
}Elemento;

typedef struct{
	Elemento *topo;
}Pilha;

Pilha* criaPilha(){
	Pilha *p = malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

void push(Pilha *p, char c){
	Elemento *novo = malloc(sizeof(Elemento));
	novo->caractere = c;
	novo->prev = p->topo;
	p->topo = novo;
}

void pop(Pilha *p){
	if(p->topo==NULL) printf("Pilha vazia!");
	else{
		Elemento *aux = p->topo;
		p->topo = p->topo->prev;
		free(aux);
	}
}

bool valida(char *s, int t){
	Pilha *P = criaPilha();
	int cont = 0;
	char a;
	bool o = true;
	while(cont<t){
		a = *(s+cont);
		switch(a){
			case(')'):
				printf(")");
				if(P->topo==NULL) o = false;
				else pop(P);
				cont++;
				break;
			case('('):
				printf("(");
				push(P, a);
				cont++;
				break;
		}
	}
	if(P->topo != NULL || o == false) return false;
	else return true;
}

int main(){
	char *string, x;
	string = malloc(sizeof(char));
	int n = 0;
	printf("Digite uma sequencia de parênteses qualquer:('e' para encerrar)\n");
	while(x != 'e'){
		scanf("%c", &x);
		if(x=='(' || x==')'){
			realloc(string, sizeof(char)*(n+2));
			*(string+n) = x;
			n++;
		}
	}
	bool i;
	i = valida(string, n);
	if(i == true) printf("\nSequencia de parenteses VALIDA!");
	else printf("\nSequencia de parenteses INVALIDA!");
}
