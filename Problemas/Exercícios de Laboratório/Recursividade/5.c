#include <stdio.h>

int mdc(int maior, int menor){
	if(maior%menor==0)
		return menor;
	return mdc(menor, maior%menor);
}

int main(){
	int mai, men, r;
	printf("MDC - Digite os números em sequencia do maior para o menor: \n");
	scanf("%d %d", &mai, &men);
	r = mdc(mai, men);
	printf("Resultado do MDC entre %d e %d: %d", mai, men, r);
}
