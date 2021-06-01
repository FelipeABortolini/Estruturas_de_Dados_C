#include <stdio.h>

int nFibo(int n){
	if(n==0) 
		return 0;
	else if(n==1) 
		return 1;
	else return (nFibo(n-1) + nFibo(n-2));
}

int main(){
	int num, nu;
	printf("Digite o numero do n-ésimo termo que deseja obter da sequencia de Fibonacci: ");
	scanf("%d", &num);
	nu = nFibo(num);
	printf("%d", nu);
}
