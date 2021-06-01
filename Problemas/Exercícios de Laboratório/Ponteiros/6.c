#include <stdio.h>

void troca(float *a, float *b){
	float c;
	c = *a;
	*a = *b;
	*b = c;
}

int main(){
	float a = 5.8;
	float b = 6.9;
	troca(&a, &b);
	printf("a: %.2f\nb: %.2f", a, b);
}
