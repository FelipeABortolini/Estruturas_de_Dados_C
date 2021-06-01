#include <stdio.h>

int palindromo(char *c, int n){
	if(n<=1)
		return 1;
	else if(*c != *(c+n-1))
		return 0;
	else return palindromo(c+1, n-2);
}

int main(){
	char *string = "abccba";
	printf("Palindromo? %d", palindromo(string, 6));
}
