#include "blu3202.h"
#include <stdio.h>
#include <math.h>

void quadrados(int n){
	if(n!=0)
		printf("%d;", (int)sqrt(n));
	if(n>1)
		quadrados(n - ((int)sqrt(n) * (int)sqrt(n)));
}
