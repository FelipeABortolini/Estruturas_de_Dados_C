#include<stdio.h>
#include<stdlib.h>

void limpa_buffer(){
	int ch;
	while((ch=getchar()) != '\n' && ch != EOF);
}

typedef struct aviao{
	char nome[30];
	int identificador;
	char origem[4];
	char destino[4];
	struct aviao *next;
}Aviao;

typedef struct{
	Aviao *inicio;
	Aviao *fim;
}Fila;

Fila *criaFila(){
	Fila *f = malloc(sizeof(Fila));
	f->inicio = NULL;
	f->fim = NULL;
	return f;
}

Aviao *criaAviao(){
	Aviao *a = malloc(sizeof(Aviao));
	
	int id;
	
	printf("Digite o nome do aviao: ");
	limpa_buffer();
	fgets(a->nome, 30, stdin);
	
	printf("Digite o identificador do aviao: ");
	scanf("%d", &id);
	a->identificador = id;
	
	printf("Digite a origem do aviao: ");
	limpa_buffer();
	fgets(a->origem, 4, stdin);
	
	printf("Digite o destino do aviao: ");
	limpa_buffer();
	fgets(a->destino, 4, stdin);
	
	a->next = NULL;
	
	return a;
}

void push(Fila *f, Aviao *a){
	if(f->fim == NULL) f->inicio = a;
	else f->fim->next = a;
	f->fim = a;
}

void pop(Fila *f){
	if(f->inicio != NULL){
		Aviao *aux = f->inicio;
		f->inicio = f->inicio->next;
		free(aux);
		printf("Aviao autorizado para decolar!\n");
	} else {
		printf("Nao ha avioes para decolar!\n");
	}
}

int num_fila(Fila *f){
	if(f->inicio != NULL){
		Aviao *aux = f->inicio;
		int n = 1;
		while(aux->next != NULL){
			aux = aux->next;
			n++;
		}
		return n;
	} else return -1;
}

void print_avioes(Fila *f){
	if(f->inicio != NULL){
		Aviao *aux = f->inicio;
		int n = 1;
		printf("-------------LISTAGEM DE AVIOES NA ESPERA PARA DECOLAR-------------\n");
		while(n <= num_fila(f)){
			printf("----------------------------------\n");
			printf("%do AVIAO:\n", n);
			printf("Nome: %s", aux->nome);
			printf("Identificador: %d\n", aux->identificador);
			printf("Origem: %s\n", aux->origem);
			printf("Destino: %s\n", aux->destino);
			aux = aux->next;
			n++;
		}
	} else printf("Nao ha avioes para listar!\n");
}

void peek(Fila *f){
	if(f->inicio != NULL){
		printf("-------------PRIMEIRO DA FILA DE DECOLAGEM-------------\n");
		printf("Nome: %s", f->inicio->nome);
		printf("Identificador: %d\n", f->inicio->identificador);
		printf("Origem: %s\n", f->inicio->origem);
		printf("Destino: %s\n", f->inicio->destino);
	} else printf("Nao ha avioes na fila de espera!\n");
}

int main(){
	Fila *f = criaFila();
	int i = 1, j;
	while(i != 6){
		printf("1 - Listar o numero de avioes esperando para decolar;\n");
		printf("2 - Autorizar a decolagem do primeiro aviao na fila;\n");
		printf("3 - Adicionar um aviao na fila de espera;\n");
		printf("4 - Listar todos os avioes que estão na lista de espera;\n");
		printf("5 - Listar as caracteristicas do primeiro aviao da fila;\n");
		printf("6 - Sair;\n");
		
		scanf("%d", &i);
		
		if(i==1){
			printf("\n");
			j = num_fila(f);
			if(j != -1) printf("O numero de avioes esperando para decolar eh de %d\n", j);
			else printf("Nao ha avioes na fila de espera!\n");
			printf("\n");
		}else 
		if(i==2){
			printf("\n");
			pop(f);
			printf("\n");
		}else 
		if(i==3){
			printf("\n");
			Aviao *a = criaAviao();
			push(f, a);
			printf("\n");
		}else 
		if(i==4){
			printf("\n");
			print_avioes(f);
			printf("\n");
		}else 
		if(i==5){
			printf("\n");
			peek(f);
			printf("\n");
		}
	}	
}
