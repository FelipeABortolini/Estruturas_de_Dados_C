#include<stdio.h>

int contem(int s, int v[s]){     // Custo | Vezes 
	int i, j;                    //  c1   |   1
	for (i=0; i<s; i++){         //  c2   |   a  -> máx = s
		for (j=i+1; j<s; j++){   //  c3   |   b  -> máx = (s-1) + (s-2) + ... 1
			if (v[i] == v[j]){   //  c4   |   b  -> máx = (s-1) + (s-2) + ... 1
				return 1;        //  c5   |   1
			}
		}
	}
	return 0;                    //  c6   |   1
}

// C(s) = c1 + c2.a + (c3 + c4)b + c5 + c6

int main(){
	int v1[] = {5,8,9,96,4};
	printf("%d", contem((int) sizeof(v1) / sizeof(v1[0]), v1));
}


