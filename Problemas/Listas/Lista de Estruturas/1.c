#include <stdio.h>
#include <string.h>

struct aluno{
	char nome[50];
	float media;
};

int main(){
	struct aluno al[5];
	int i, indMaiorM, ch;
	float maiorM = 0.0;
	for (i=0; i<5; i++){
		printf("Digite o nome do aluno: ");
		fgets(al[i].nome, sizeof(al[i].nome), stdin);
		printf("Digite a media do aluno: ");
		scanf("%f", &al[i].media);
		while((ch = getchar()) != '\n' && ch != EOF);
		if (al[i].media > maiorM){
			indMaiorM = i;
			maiorM = al[i].media;
		}
	}
	printf("\nAluno com maior media: %s", al[indMaiorM].nome);
}
