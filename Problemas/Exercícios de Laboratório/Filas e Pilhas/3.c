#include<stdio.h>
#include<stdlib.h>

typedef struct l{
	int valor;
	struct l *next;
}Elemento;

typedef struct{
	Elemento *inicio;
	Elemento *fim;
}Fila;

Fila* criaFila(){
	Fila *fila = malloc(sizeof(Fila));
	fila->inicio = NULL;
	fila->fim = NULL;
	return fila;
}

void push(Fila *p, int v){
	Elemento *novo = malloc(sizeof(Elemento));
	novo->valor = v;
	novo->next = NULL;
	if(p->inicio == NULL) p->inicio = p->fim = novo;
	else{
		p->fim->next = novo;
		p->fim = novo;
	}
}

void pop(Fila *f){
   if(f->inicio==NULL){
      printf("Fila vazia.\n");
   }else{
      f->inicio = f->inicio->next;
      if(f->inicio==NULL) //se a fila ficou vazia
        f->fim = NULL;     
   }
}

void printFila(Fila *p){
	Elemento *aux = p->inicio;
	while(aux != NULL){
		printf("%d\n", aux->valor);
		aux = aux->next;
	}
}

/*void juntaFilas(Fila *f1, Fila *f2, Fila *f3){
	Elemento *aux1 = f1->inicio, *aux2 = f2->inicio;
	
	while(aux1 != NULL && aux2 != NULL){
		if(aux1->valor < aux2->valor){
			push(f3, aux1->valor);
			aux1 = aux1->next;
		} else if(aux2->valor < aux1->valor){
			push(f3, aux2->valor);
			aux2 = aux2->next;
		} else {
			push(f3, aux1->valor);
			push(f3, aux2->valor);
			aux1 = aux1->next;
			aux2 = aux2->next;
		}
	} 
	
	if(aux1 != NULL){
		while(aux1 != NULL){
			push(f3, aux1->valor);
			aux1 = aux1->next;
		}
	} else if(aux2 != NULL){
		while(aux2 != NULL){
			push(f3, aux2->valor);
			aux2 = aux2->next;
		}
	}
}*/

void juntaFilas(Fila *f1, Fila *f2, Fila *f3){
	while(peek(f1) != -1 || peek(f2) != -1){
		if((peek(f1) < peek(f2) || peek(f2) == -1) && peek(f1) != -1){
			push(f3, peek(f1));
			pop(f1);
		} else {
			push(f3, peek(f2));
			pop(f2);
		}
	}
}

int peek(Fila *f){
   if(f->inicio!=NULL)
      return f->inicio->valor;
   return -1;
}

int main(){
	Fila *F1 = criaFila(), *F2 = criaFila(), *F3 = criaFila();
	int i = 0;
	printf("Digite os elementos para a primiera fila em ordem crescente (-1 para encerrar):\n");
	while(i != -1){
		scanf("%d", &i);
		if(i!=-1) push(F1, i);
	}
	i = 0;
	printf("Digite os elementos para a segunda fila em ordem crescente (-1 para encerrar):\n");
	while(i != -1){
		scanf("%d", &i);
		if(i!=-1) push(F2, i);
	}
	juntaFilas(F1, F2, F3);
	printFila(F1);
	printf("---\n");
	printFila(F2);
	printf("---\n");
	printFila(F3);
}
