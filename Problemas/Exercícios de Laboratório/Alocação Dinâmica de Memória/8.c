#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, n = 0, tam = 1, *vet;
	printf("Preencha o vetor, digite zero para finalizar.\n");
	do {
		printf("Valor: ");
		scanf("%d", &n);
		if(n!=0){
			if(tam==1){
				vet = malloc(sizeof(int)*tam);
				*(vet+tam-1) = n;
				tam++;
			} else {
				realloc(vet, sizeof(int)*tam);
				*(vet+tam-1) = n;
				tam++;
			}
		}
	} while(n!=0);
	for(i=tam-2; i>=0; i--){
		printf("%d ", *(vet+i));
	}
}
