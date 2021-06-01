#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, x, i;
	printf("Digite um valor: ");
	scanf("%d", &n);
	int *v1, *v2;
	v1 = malloc(sizeof(int)*n);
	v2 = malloc(sizeof(int)*n);
	
	for(i=0; i<n; i++){
		printf("%do valor: ", i+1);
		scanf("%d", v1+i);
		*(v2+i) = *(v1+i)**(v1+i);
	}
	
	for(i=0; i<n; i++){
		printf("%d - %d\n", *(v1+i), *(v2+i));
	}
}
