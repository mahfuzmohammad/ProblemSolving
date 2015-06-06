//In the name of Allah, most Gracious, most Compassionate
/**
Algorithm: Matrix Exponetiation
*/
#include <bits/stdc++.h>

using namespace std;

int matInit[6][6],
	matTemp[6][6];

void matMul (int a[6][6], int b[6][6], int d, int mod) {
    int mat[6][6];
	for(int i = 0; i < d; i++) {
		for(int j = 0; j < d; j++) {
			int temp = 0;
			for(int k = 0; k < d; k++) {
				temp += ((a[i][k] * b[k][j]) % mod);
			}
			mat[i][j] = temp % mod;
		}
	}

	for(int i = 0; i < d; i++) {
        for(int j = 0; j < d; j++) {
            matTemp[i][j] = mat[i][j];
        }
	}
}

void matExp (int exp, int d, int mod) {
	if(exp < 2) return;

	matExp (exp >> 1, d, mod);
	matMul (matTemp, matTemp, d, mod);

	if(exp & 1) matMul (matInit, matTemp, d, mod);
}

void copyMatInit(int d) {
    for(int i = 0; i < d; i++) {
        for(int j = 0; j < d; j++) {
            matTemp[i][j] = matInit[i][j];
        }
    }
}

void printMatrix(int A[6][6], int d) {
    for(int i = 0; i < d; i++) {
        for(int j = 0; j < d; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main () {

	//freopen("in.txt", "r", stdin);
	int t, a1, b1, c1, a2, b2, c2, f0, f1, f2, g0, g1, g2, M, q, n;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++) {
		scanf("%d %d %d", &a1, &b1, &c1);
		scanf("%d %d %d", &a2, &b2, &c2);
		scanf("%d %d %d", &f0, &f1, &f2);
		scanf("%d %d %d", &g0, &g1, &g2);
		scanf("%d", &M);

		memset(matInit, 0, sizeof matInit);

		matInit[0][0] = a1; matInit[0][1] = b1; matInit[0][5] = c1;
		matInit[1][0] = 1;
		matInit[2][1] = 1;
		matInit[3][2] = c2; matInit[3][3] = a2; matInit[3][4] = b2;
		matInit[4][3] = 1;
		matInit[5][4] = 1;

		scanf("%d", &q);

        printf("Case %d:\n", i);
		for(int j = 0; j < q; j++) {
            scanf("%d", &n);
            switch(n) {
                case 0:
                    printf("%d %d\n", f0 % M, g0 % M);
                    break;
                case 1:
                    printf("%d %d\n", f1 % M, g1 % M);
                    break;
                case 2:
                    printf("%d %d\n", f2 % M, g2 % M);
                    break;
                default:
                    copyMatInit(6);
                    matExp(n - 2, 6, M);
                    printf("%d %d\n", (((matTemp[0][0] * f2) % M) + ((matTemp[0][1] * f1) % M) + ((matTemp[0][2] * f0) % M) + ((matTemp[0][3] * g2) % M) + ((matTemp[0][4] * g1) % M) + ((matTemp[0][5] * g0) % M)) % M,
                                      (((matTemp[3][0] * f2) % M) + ((matTemp[3][1] * f1) % M) + ((matTemp[3][2] * f0) % M) + ((matTemp[3][3] * g2) % M) + ((matTemp[3][4] * g1) % M) + ((matTemp[3][5] * g0) % M)) % M);
                    break;
            }

        }
	}

	return 0;
}
