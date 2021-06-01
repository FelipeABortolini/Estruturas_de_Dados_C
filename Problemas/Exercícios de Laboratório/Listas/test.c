#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int elem;
	struct list *next;
}List;

List* criaLista(){
	return NULL;
}

List* addPrimElem(List* head, int valor){
	List* item = malloc(sizeof(List));
	item->elem = valor;
	item->next = head;
	head = item;
	return head;
}

void imprimeLista(List *head){
	List* item = head;
	while(item!=NULL){
		printf("%d ", item->elem);
		item = item->next;
	}
}

int numElem(List* head){
	if(head == NULL) return 0;
	return 1 + numElem(head->next);
}

int main(){
	int resp = 0;
	List* lista = criaLista();
	printf("Digite os elementos da lista de trás para frente, digite -1 para encerrar.\n");
	do{
		scanf("%d", &resp);
		if(resp!=-1){
			lista = addPrimElem(lista, resp);
		}
	} while(resp!=-1);
	imprimeLista(lista);
	int i = numElem(lista);
	printf("\nNumero de elementos da lista: %d", i);
}
