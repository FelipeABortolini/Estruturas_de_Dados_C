#include <stdio.h>
#include <stdlib.h>

void vetor(float *vet, int num){
	int i;
	for(i=0; i<num; i++){
		printf("Nota %do aluno: ", i+1);
		scanf("%f", vet+i);
	}
}

int calc_media(float *vetor, int nu){
	int i;
	float soma = 0, media;
	for(i=0; i<nu; i++){
		soma += *(vetor+i);
	}
	media = soma/nu;
	return media;
}

int main(){
	int n, i;
	float *v, m;
	
	printf("Quantidade de alunos: ");
	scanf("%d", &n);
	v = malloc(sizeof(float)*n);
	
	vetor(v, n);
	
	m = calc_media(v, n);

	printf("\nBOLETIM DOS ALUNOS:\n\n");
	for(i=0; i<n; i++){
		printf("%do aluno: %.2f\n", i+1, *(v+i));
	}
	printf("\nMedia da turma: %.2f", m);
}
