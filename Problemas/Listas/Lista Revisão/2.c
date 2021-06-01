#include<stdio.h>

int contem(int s1, int v1[s1], int s2, int v2[s2], int x){    // Custo | Vezes 
	int i;                                                   //  c1   |   1
	for (i=0; i<s1; i++){                                    //  c2   |   a
		if (v1[i] == x){                                     //  c3   |   a
			return 1;                                        //  c4   |   1
		}
	}
	for (i=0; i<s2; i++){                                    //  c5   |   b
		if (v2[i] == x){                                     //  c6   |   b
			return 1;                                        //  c7   |   1
		}
	}
	return 0;	                                             //  c8   |   1
}

// a = índice em que o número procurado foi encontrado no vetor 1, caso não tenha encontrado a = s1;
// b = índice em que o número procurado foi encontrado no vetor 2, caso a != s1 então b = 0, caso a = s1 e o valor não for encontrado no vetor 2, b = s2;
// C(s) = c1 + (c2 + c3)a + c4 + (c5 + c6)b + c7 + c8

int main(){
	int v1[] = {5,8,9,6,4};
	int v2[] = {12,16,14,19};
	int n = 19;
	printf("%d", contem((int) sizeof(v1) / sizeof(v1[0]), v1, (int) sizeof(v2) / sizeof(v2[0]), v2, n));
}


