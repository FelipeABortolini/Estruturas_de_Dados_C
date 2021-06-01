#include <stdio.h>

int s(int n, int m){
	if(m==1)
		return 1;
	if(n==1)
		return s(m-1, m-1);
	return n * s(n-1, m);
}

int SF(int n){
	return s(n,n);
}

int main(){
	int num;
	printf("Superfatorial de: ");
	scanf("%d", &num);
	printf("%d", SF(num));
}
