#include<stdio.h>
#include<math.h>

void diagonal(int s, int m[s][s]){          // Custo | Vezes 
	int i, j;                               //  c1   |   1
	for (i=0; i<s; i++){                    //  c2   |   s
		for (j=0; j<s; j++){                //  c3   |   s^2
			if (i == j){                    //  c4   |   s^2 
				printf("%d ", m[i][j]);     //  c5   |   s
			} else {                        //  c6   |   s^2-s
				printf("0 ");               //  c7   |   s^2-s
			}
		}
		printf("\n");                       //  c8   |   s
	}
}

// C(s) = c1 + (c2 + c5 + c8)s + (c3 + c4)s^2 + (c6 + c7)s^2-s

int main(){
	int matriz[3][3] = {{2,1,3},{4,5,4},{7,8,9}};
	int num = sqrt((int) sizeof(matriz) / sizeof(int));
	diagonal(num, matriz);
}
