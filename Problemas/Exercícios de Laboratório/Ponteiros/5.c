#include <stdio.h>

int main(){
	int y, *p, x;
	y = 0;   // y recebe 4, y = 0;
	p = &y;  // p armazena o ender�o de mem�ria em que y est� armazenado.
	x = *p;  // x recebe o valor que est� no ender�o de mem�ria refernciado por p, que � o ender�o de y, ou seja, x = 0;
	x = 4;   // x recebe 4, x = 4;
	(*p)++;  // O valor presente no endere�o de mem�ria que o ponteiro p referencia � incrementado em uma unidade, ou seja, y = 1;
	x--;     // x perde uma unidade, ou seja, x = 3;
	(*p) += x;  // O valor presente no endere�o de mem�ria que o ponteiro p referencia � incrementado do valor de x, ou seja, y = y + x = 1 + 3 = 4
	printf("y = %d\n", y);  // Imprime o valor de y que � 4;
}
