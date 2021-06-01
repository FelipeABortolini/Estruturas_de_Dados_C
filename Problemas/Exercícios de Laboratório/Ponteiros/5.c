#include <stdio.h>

int main(){
	int y, *p, x;
	y = 0;   // y recebe 4, y = 0;
	p = &y;  // p armazena o enderço de memória em que y está armazenado.
	x = *p;  // x recebe o valor que está no enderço de memória refernciado por p, que é o enderço de y, ou seja, x = 0;
	x = 4;   // x recebe 4, x = 4;
	(*p)++;  // O valor presente no endereço de memória que o ponteiro p referencia é incrementado em uma unidade, ou seja, y = 1;
	x--;     // x perde uma unidade, ou seja, x = 3;
	(*p) += x;  // O valor presente no endereço de memória que o ponteiro p referencia é incrementado do valor de x, ou seja, y = y + x = 1 + 3 = 4
	printf("y = %d\n", y);  // Imprime o valor de y que é 4;
}
