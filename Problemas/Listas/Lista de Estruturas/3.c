#include <stdio.h>
#include <string.h>
#define N 10

typedef struct{
	char rua[50];
	int num;
	char bairro[50];
	char cidade[50];
}Endereco;

typedef struct{
	char nome[50];
	float renda;
	char casa;
	Endereco end;
}Clientes;

int main(){
	Clientes c[N];
	int i, ch;
	float rendaTot = 0;
	int quant_casa_prop = 0;
	for(i=0; i<N; i++){
		printf("----DADOS DO %i CLIENTE----\n", i+1);
		
		printf("Nome: "); // NOME
		gets(c[i].nome);
		
		printf("Renda Mensal: "); // RENDA
		scanf("%f", &c[i].renda);
		
		while((ch = getchar()) != '\n' && ch != EOF); // LIMPEZA DE BUFFER
		
		printf("Possui casa propria? [S/N] "); // CASA PRÓPRIA?
		scanf("%c", &c[i].casa);
		while (c[i].casa != 'S' && c[i].casa != 'N'){
			printf("Erro! Digite novamente.\nPossui casa propria? [S/N] ");
			while((ch = getchar()) != '\n' && ch != EOF); // LIMPEZA DE BUFFER
			scanf("%c", &c[i].casa);
		}
		
		while ((ch = getchar()) != '\n' && ch != EOF); // LIMPEZA DE BUFFER
		
		printf("Rua: ");
		gets(c[i].end.rua);
		
		printf("Numero: ");
		scanf("%d", &c[i].end.num);
		
		while ((ch = getchar()) != '\n' && ch != EOF); // LIMPEZA DE BUFFER
		
		printf("Bairro: ");
		gets(c[i].end.bairro);
		
		printf("Cidade: ");
		gets(c[i].end.cidade);
		
		printf("\n");
	}
	printf("------LISTA------\n");
	for(i=0; i<N; i++){
		printf("%d: %s - R$%.2f - %c - %s - %s - %s - %d\n", i+1, c[i].nome, c[i].renda, c[i].casa, c[i].end.cidade, c[i].end.bairro, c[i].end.rua, c[i].end.num);
		rendaTot += c[i].renda;
		if (c[i].casa == 'S'){
			quant_casa_prop++;
		}
	}
	printf("\n");
	int j, n = 1, cont = 0, vet[N];
	for(i=0; i<N; i++){
		if(vet[i] != i){
			for(j=i+1; j<N; j++){
				if((strcmp(c[i].end.cidade, c[j].end.cidade) == 0) && (strcmp(c[i].end.bairro, c[j].end.bairro) == 0) && (strcmp(c[i].end.rua, c[j].end.rua) == 0)){
					if(cont == 0){
						printf("%s - ", c[i].nome);
					}
					printf("%s - ", c[j].nome);
					cont++;
					n++;
					vet[j] = j;
				}
			}
			cont = 0;
			if(n > 1){
				printf("moram na rua %s\n", c[i].end.rua);
			}
			n = 1;
		}
	}
	
	printf("\nA media de salarios e de R$%.2f\n", rendaTot/N);
	printf("O percentual de pessoas que possuem casa propria e %.2f\n", (quant_casa_prop/(float)N)*100);
}
