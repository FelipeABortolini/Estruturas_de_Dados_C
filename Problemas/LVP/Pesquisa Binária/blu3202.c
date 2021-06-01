#include<stdio.h>
#include<stdlib.h>

int pesquisa(int *v, int n, int x){
	int fim = n-1, inicio = 0, centro, soma = 0;
	while(inicio <= fim){
		centro = (inicio + fim)/2;
		if(v[centro] == x){
			soma += v[centro];
			return soma;
		}else if(v[centro] < x){
			soma += v[centro];
			inicio = centro + 1;
		}else{
			soma += v[centro];
			fim = centro - 1;
		}
	}
	return soma;
}

int main(){
	int n, soma, v[5] = {2,4,6,8,10};
	printf("Digite um numero para pesquisar: ");
	scanf("%d", &n);
	soma = pesquisa(v, 5, n);
	printf("%d\n", soma);
}
