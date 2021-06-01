#include<stdio.h>
#include<stdlib.h>

int pesquisa_sequencial(int x, int* v, int n, int* comp){
	int i;
	for(i=0; i<n; i++){
		(*comp)++;
		if(v[i] == x){
			return i;
		}
	}
	return -1;
}

int pesquisa(int x, int* v, int inicio, int fim, int* comp){
	//verificar o numero do centro do vetor e compará-lo com x
	if(inicio > fim) return -1;
	int meio = (inicio + fim) / 2; //meio é o índice central do vetor
	(*comp)++;
	if(v[meio] == x) 
		return meio;
	else if(x < v[meio])
		return pesquisa(x, v, inicio, meio-1, comp);
	else
		return pesquisa(x, v, meio+1, fim, comp);
}

int main(){
	int posicao, n, vetor[10] = {1,2,3,4,5,6,7,8,9,10}, comp = 0;
	printf("Digite o numero a pesquisar: ");
	scanf("%d", &n);
	posicao = pesquisa(n, vetor, 0, 9, &comp);
	printf("Resultado da busca: %d\n", posicao);
	printf("Numero de comparacoes feitas: %d\n", comp);
	comp = 0;
	posicao = pesquisa_sequencial(n, vetor, 10, &comp);
	printf("Resultado da busca: %d\n", posicao);
	printf("Numero de comparacoes feitas: %d\n", comp);
}
