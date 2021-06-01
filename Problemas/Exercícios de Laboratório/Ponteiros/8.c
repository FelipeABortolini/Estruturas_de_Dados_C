#include <stdio.h>

void troca(int **a, int **b){
	int c;
	c = **a;
	**a = **b;
	**b = c;
}

int main(){
	int a = 1, b = 2, *pa = &a, *pb = &b;
	troca(&pa, &pb);
	printf("a: %d; b: %d\n", a, b);
}
