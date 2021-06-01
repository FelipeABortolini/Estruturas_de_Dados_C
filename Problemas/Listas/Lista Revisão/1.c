#include<stdio.h>

int contem(int s, int v[s], int x){      // Custo | Vezes 
	int i;                               //  c1   |   1
	for (i=0; i<s; i++){                 //  c2   |   y
		if (v[i] == x){                  //  c3   |   y
			return 1;                    //  c4   |   1
		}
	}
	return 0;	                         //  c5   |   1
}

// y = índice em que o número procurado foi encontrado
// Pior Caso:
// C(s) = c1 + (c2 + c3)s + c4 + c5

int main(){
	int v[] = {5,8,9,6,4,12};
	int n = 2;
	printf("%d", contem((int) sizeof(v) / sizeof(v[0]), v, n));
}


