//In the name of Allah, most Gracious, most Compassionate
/**
Algorithm: Matrix Exponetiation
*/
#include <bits/stdc++.h>

using namespace std;

int matInit[3][3],
	matTemp[3][3];

void matMul (int a[3][3], int b[3][3], int d, int mod) {
    int mat[3][3];
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
	int t, a, b, n, m, _m;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++) {
		scanf("%d %d %d %d", &a, &b, &n, &m);

		if(n == 0) {
            printf("Case %d: %d\n", i, a);
            continue;
		}

		if(n == 1) {
            printf("Case %d: %d\n", i, b);
            continue;
		}

		matInit[0][0] = matTemp[0][0] = 1;
		matInit[0][1] = matTemp[0][1] = 1;
		matInit[1][0] = matTemp[1][0] = 1;
		matInit[1][1] = matTemp[1][1] = 0;

		switch(m) {
            case 1:
                _m = 10;
                break;
            case 2:
                _m = 100;
                break;
            case 3:
                _m = 1000;
                break;
            case 4:
                _m = 10000;
                break;
            default:
                break;
		}

		matExp(n - 1, 2, _m);

        printf("Case %d: %d\n", i, (((matTemp[0][0] * b) % _m) + ((matTemp[0][1] * a) % _m)) % _m);
	}

	return 0;
}
