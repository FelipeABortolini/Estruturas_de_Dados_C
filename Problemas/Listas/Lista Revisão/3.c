#include<stdio.h>

int contem(int s1, int v1[s1], int s2, int v2[s2], int x){    // Custo | Vezes 
	int i, j;                                                 //  c1   |   1
	for (i=0; i<s1; i++){                                     //  c2   |   a  -> máx = s1
		if (v1[i] == x){                                      //  c3   |   a  -> máx = s1
			for (j=0; j<s2; j++){                             //  c4   |   b  -> máx = s1 * s2 
				if (v2[j] == x){                              //  c5   |   b  -> máx = s1 * s2 
					return 1;                                 //  c6   |   1
				}
			}
		}
	}
	return 0;                                                 //  c7   |   1
}

// C(s) = c1 + (c2 + c3)a + (c4 + c5)b + c6 + c7

int main(){
	int v1[] = {5,8,9,6,4};
	int v2[] = {12,16,14,19};
	int n = 6;
	printf("%d", contem((int) sizeof(v1) / sizeof(v1[0]), v1, (int) sizeof(v2) / sizeof(v2[0]), v2, n));
}


