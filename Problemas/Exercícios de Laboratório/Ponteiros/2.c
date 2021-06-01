#include <stdio.h>

int main(){
	int a = 5, *a_ptr = &a;
	float b = 4.8, *b_ptr = &b;
	char c = 'f', *c_ptr = &c;
	
	printf("int antes: %d\n", a);
	printf("float antes: %.2f\n", b);
	printf("char antes: %c\n", c);
	
	*a_ptr = 9;
	*b_ptr = 7.4;
	*c_ptr = 'L';
	
	printf("\nint depois: %d\n", a);
	printf("float depois: %.2f\n", b);
	printf("char depois: %c\n", c);
}
