#include<stdio.h>
#define N 10

struct clientes{
	char nome[50];
	float renda;
	char casa;
	
};

int main(){
	struct clientes c[N];
	int i, ch;
	float rendaTot = 0;
	int quant_casa_prop = 0;
	for(i=0; i<N; i++){
		printf("----DADOS DO %i CLIENTE----\n", i+1);
		printf("Nome: ");
		gets(c[i].nome);
		printf("Renda Mensal: ");
		scanf("%f", &c[i].renda);
		while((ch = getchar()) != '\n' && ch != EOF);
		printf("Possui casa propria? [S/N] ");
		scanf("%c", &c[i].casa);
		while (c[i].casa != 'S' && c[i].casa != 'N'){
			printf("Erro! Digite novamente.\nPossui casa propria? [S/N] ");
			while((ch = getchar()) != '\n' && ch != EOF);
			scanf("%c", &c[i].casa);
		}
		while ((ch = getchar()) != '\n' && ch != EOF);
		printf("\n");
	}
	printf("------LISTA------\n");
	for(i=0; i<N; i++){
		printf("%d: %s - R$%.2f - %c\n", i+1, c[i].nome, c[i].renda, c[i].casa);
		rendaTot += c[i].renda;
		if (c[i].casa == 'S'){
			quant_casa_prop++;
		}
	}
	printf("\nA media de salarios e de R$%.2f\n", rendaTot/N);
	printf("O percentual de pessoas que possuem casa propria e %.2f\n", (quant_casa_prop/(float)N)*100);
}
