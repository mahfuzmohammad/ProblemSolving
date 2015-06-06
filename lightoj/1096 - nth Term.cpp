//In the name of Allah, most Gracious, most Compassionate
/**
Algorithm: Matrix Exponetiation
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int matInit[4][4],
	matTemp[4][4];

void matMul (int a[4][4], int b[4][4], int d, int mod) {
    int mat[4][4];
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

int main () {

	//freopen("in.txt", "r", stdin);
	int t, a, b, c, n;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++) {
		scanf("%d %d %d %d", &n, &a, &b, &c);

		if(n <= 2) {
            printf("Case %d: %d\n", i, 0);
            continue;
		}

        memset(matInit, 0, sizeof matInit);
        memset(matTemp, 0, sizeof matTemp);

		matInit[0][0] = matTemp[0][0] = a;
		matInit[0][1] = matTemp[0][1] = 0;
		matInit[0][2] = matTemp[0][2] = b;
		matInit[0][3] = matTemp[0][3] = 1;
		matInit[1][0] = matTemp[1][0] = 1;
		matInit[2][1] = matTemp[2][1] = 1;
		matInit[3][3] = matTemp[3][3] = 1;

		matExp(n - 2, 4, MOD);

        printf("Case %d: %d\n", i, (matTemp[0][3] * c) % MOD);
	}

	return 0;
}
