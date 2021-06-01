#include<stdio.h>

int contem(int s1, int v1[s1], int s2, int v2[s2]){    // Custo | Vezes 
	int i, j;                                          //  c1   |   1
	for (i=0; i<s1; i++){                              //  c2   |   a  -> máx = s1
		for (j=0; j<s2; j++){                          //  c3   |   b  -> máx = s1 * s2 
			if (v2[j] == v1[i]){                       //  c4   |   b  -> máx = s1 * s2 
				return 1;                              //  c5   |   1
			}
		}
	}
	return 0;                                          //  c6   |   1
}

// C(s) = c1 + c2.a + (c3 + c4)b + c5 + c6

int main(){
	int v1[] = {5,8,9,6,4};
	int v2[] = {12,16,14,19};
	printf("%d", contem((int) sizeof(v1) / sizeof(v1[0]), v1, (int) sizeof(v2) / sizeof(v2[0]), v2));
}


