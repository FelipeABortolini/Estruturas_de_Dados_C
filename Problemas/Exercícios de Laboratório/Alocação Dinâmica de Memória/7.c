#include <stdio.h>
#include <stdlib.h>

int **soma(int **mat1, int L1, int C1, int **mat2, int L2, int C2){
	if((L1 == L2) && (C1 == C2)){
		int **matSoma, i, j;
		
		matSoma = malloc(sizeof(int*)*L1);    // ALOCA플O PARA LINHAS (PONTEIROS QUE APONTAM PARA COLUNAS)
		for(i=0; i<L1; i++){
			*(matSoma+i) = malloc(sizeof(int)*C1);     // ALOCA플O PARA COLUNAS 
		}
		
		for(i=0; i<L1; i++){
			for(j=0; j<C1; j++){
				*(*(matSoma+i)+j) = *(*(mat1+i)+j) + *(*(mat2+i)+j);
			}
		}
		
		return matSoma;
	} else return NULL;
}

int **produto(int **mat1, int L1, int C1, int **mat2, int L2, int C2){
	if((C1 == L2)){
		int **matProd, i, j, k;
		
		matProd = malloc(sizeof(int*)*L1);    // ALOCA플O PARA LINHAS (PONTEIROS QUE APONTAM PARA COLUNAS)
		for(i=0; i<L1; i++){
			*(matProd+i) = malloc(sizeof(int)*C2);     // ALOCA플O PARA COLUNAS 
		}
		
		int soma;
		for(i=0; i<L1; i++){
			for(j=0; j<C2; j++){
				soma = 0;
				for(k=0; k<C1; k++){
					soma += *(*(mat1+i)+k) * *(*(mat2+k)+j);
				}
				*(*(matProd+i)+j) = soma;
			}
		}
		return matProd;
	} else return NULL;
}

int main(){
	int **m1, L1, C1, **m2, L2, C2 ,i, j;
	printf("Linhas 1a matriz: ");
	scanf("%d", &L1);
	printf("Colunas 1a matriz: ");
	scanf("%d", &C1);
	
	m1 = malloc(sizeof(int*)*L1);             // ALOCA플O PARA LINHAS (PONTEIROS QUE APONTAM PARA COLUNAS)
	for(i=0; i<L1; i++){
		*(m1+i) = malloc(sizeof(int)*C1);     // ALOCA플O PARA COLUNAS 
	}
	
	for(i=0; i<L1; i++){
		printf("Introduza os elementos da %da linha: ", i+1);
		for(j=0; j<C1; j++){
			scanf("%d", *(m1+i)+j);
		}
	}
	
	printf("\nLinhas 2a matriz: ");
	scanf("%d", &L2);
	printf("Colunas 2a matriz: ");
	scanf("%d", &C2);
	
	m2 = malloc(sizeof(int*)*L2);             // ALOCA플O PARA LINHAS (PONTEIROS QUE APONTAM PARA COLUNAS)
	for(i=0; i<L2; i++){
		*(m2+i) = malloc(sizeof(int)*C2);     // ALOCA플O PARA COLUNAS 
	}
	
	for(i=0; i<L2; i++){
		printf("Introduza os elementos da %da linha: ", i+1);
		for(j=0; j<C2; j++){
			scanf("%d", *(m2+i)+j);
		}
	}
	
	int **s;
	s = soma(m1, L1, C1, m2, L2, C2);
	printf("Resultado da soma:\n");
	if(s == NULL) printf("Nao definido.\n");
	else {
		for(i=0; i<L1; i++){
			printf("| ");
			for(j=0; j<C1; j++){
				printf("%d ", *(*(s+i)+j));
			}
			printf("|\n");
		}
	}
	
	int **p;
	p = produto(m1, L1, C1, m2, L2, C2);
	printf("Reultado do produto:\n");
	if(p == NULL) printf("Nao definido.\n");
	else {
		for(i=0; i<L1; i++){
			printf("| ");
			for(j=0; j<C2; j++){
				printf("%d ", *(*(p+i)+j));
			}
			printf("|\n");
		}
	}
	
	for(i=0; i<C1; i++){
		free(*(m1+i));      // LIBERA AS COLUNAS DA MATRIZ
		*(m1+i) = NULL;
	}
	free(m1);               // LIBERA AS LINHAS DA MATRIZ (VETOR DE PONTEIROS);
	m1 = NULL;
	
	for(i=0; i<C2; i++){
		free(*(m2+i));      // LIBERA AS COLUNAS DA MATRIZ
		*(m2+i) = NULL;
	}
	free(m2);               // LIBERA AS LINHAS DA MATRIZ (VETOR DE PONTEIROS);
	m2 = NULL;
	
	for(i=0; i<L2; i++){
		free(*(s+i));      // LIBERA AS COLUNAS DA MATRIZ
		*(s+i) = NULL;
	}
	free(s);               // LIBERA AS LINHAS DA MATRIZ (VETOR DE PONTEIROS);
	s = NULL;
	
	for(i=0; i<L1; i++){
		free(*(p+i));      // LIBERA AS COLUNAS DA MATRIZ
		*(p+i) = NULL;
	}
	free(p);               // LIBERA AS LINHAS DA MATRIZ (VETOR DE PONTEIROS);
	p = NULL;
}
