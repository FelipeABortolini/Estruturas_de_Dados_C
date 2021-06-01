#include<stdio.h>
#include<math.h>

void transposta(int s, int m[s][s]){        // Custo | Vezes 
	int i, j;                               //  c1   |   1
	for (i=0; i<s; i++){                    //  c2   |   s
		for (j=0; j<s; j++){                //  c3   |   s^2
			printf("%d ", m[j][i]);         //  c4   |   s^2
		}
		printf("\n");                       //  c5   |   s
	}
}

// C(s) = c1 + (c2 + c5)s + (c3 + c4)s^2

int main(){
	int matriz[2][2] = {{2,1},{4,5}};
	int num = sqrt((int) sizeof(matriz) / sizeof(int));
	transposta(num, matriz);
}
