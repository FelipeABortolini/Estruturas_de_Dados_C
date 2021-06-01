#include <stdio.h>
#include <stdlib.h>

int main(){
	char *vet;
	int tam = 1, i;
	printf("Digite a sequencia de caracteres sem espacos: ");
	do{
		if(tam==1){
			vet = malloc(sizeof(char)*tam);
			*(vet+tam-1) = getchar();
			//printf("%c", *(vet+tam-1));
			tam++;	
		}
		else {
			realloc(vet, sizeof(char)*tam);
			*(vet+tam-1) = getchar();
			//printf("%c", *(vet+tam-1));
			tam++;
		}
	} while(*(vet+tam-2) != ' ' && *(vet+tam-2) != '\n' && *(vet+tam-2) != '\0');
	for(i=0; i<tam-2; i++){
		if(*(vet+i)=='A' || *(vet+i)=='E' || *(vet+i)=='I' || *(vet+i)=='O' || *(vet+i)=='U' || *(vet+i)=='a' || *(vet+i)=='e' || *(vet+i)=='i' || *(vet+i)=='o' || *(vet+i)=='u'){
			*(vet+i) = 'X';
		}
	}
	printf("String resultante: ");
	for(i=0; i<tam-2; i++){
		printf("%c", *(vet+i));
	}
}
