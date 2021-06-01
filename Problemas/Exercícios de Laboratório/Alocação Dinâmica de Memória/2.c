#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i;
	float *v, media, soma = 0;
	
	printf("Quantidade de alunos: ");
	scanf("%d", &n);

	v = malloc(sizeof(float)*n);
	if(v == NULL){
		printf("Não há memória suficiente!");
		exit(EXIT_FAILURE);
	}
	for(i=0; i<n; i++){
		printf("Nota %do aluno: ", i+1);
		scanf("%f", v+i);
		soma += *(v+i);
	}
	media = soma/n;
	printf("\nBOLETIM DOS ALUNOS:\n\n");
	for(i=0; i<n; i++){
		printf("%do aluno: %.2f\n", i+1, *(v+i));
	}
	printf("\nMedia da turma: %.2f", media);
}
