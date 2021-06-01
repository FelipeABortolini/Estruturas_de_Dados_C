#include<stdio.h>

int main(){
	int a, b, *a_ptr = &a, *b_ptr = &b;
	printf("Enderço de a: %p - %ld\n", a_ptr, (long)a_ptr);
	printf("Endereço de b: %p - %ld\n", b_ptr, (long)b_ptr);
	
	printf("\nO maior enderco eh: ");
	if(a_ptr > b_ptr) printf("%p", a_ptr);
	else printf("%p", b_ptr);
	 
}
