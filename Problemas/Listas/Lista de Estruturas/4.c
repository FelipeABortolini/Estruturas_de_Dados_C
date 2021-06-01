#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 5

typedef struct{
	int codigo;
	int localizacao[2];
	int energia;
}Robo;

inline void getDados(Robo r[N], int i){
	r[i].codigo = i+1;
	r[i].localizacao[0] = rand() % 10 + 1;
	r[i].localizacao[1] = rand() % 10 + 1;
	r[i].energia = rand() % 100;
}

int main(){
	Robo r[N];
	int i, j, k;
	srand(time(NULL));
	for(i=0; i<N; i++){
		getDados(r, i);
	}
	printf("--------------------- REPRESENTACAO GRAFICA ---------------------\n");
	
	int matriz[N][2];
	for(i=0; i<N; i++){
		matriz[i][0] = r[i].localizacao[0];
		matriz[i][1] = r[i].localizacao[1];
	}
	
	bool plotado;
	for(j=0; j<31; j++){
		for(i=0; i<61; i++){
			plotado = true;
			if(i == 0){
				printf(" ");
			}
			if(i % 6 == 0 && j != 0){
				printf("|");
			} else if((i % 6 == 3) && (j % 3 == 2)) {
				for(k=0; k<N; k++){
					if(r[k].localizacao[0] == (j+1)/3 && r[k].localizacao[1] == (i+3)/6){
						printf("%d", r[k].codigo);
						plotado = false;
					}
				} if (plotado) printf(" ");
			} else if(j % 3 == 0){
				printf("_");
			} else if(j % 3 != 0 && plotado){
				printf(" ");
			}
		}
		printf("\n");
	}
	
	printf("\n------------------------ LISTA DOS ROBOS ------------------------\n");
	for(i=0; i<N; i++){
		printf(" Robo: %d - Coordenadas(x,y): (%d,%d) - Energia(porcentagem): %d\n", i+1, r[i].localizacao[0], r[i].localizacao[1], r[i].energia);
	}
}
