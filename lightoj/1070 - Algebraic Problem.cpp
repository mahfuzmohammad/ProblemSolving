//In the name of Allah, most Gracious, most Compassionate
/**
Algorithm: Matrix Exponetiation
*/
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull matInit[3][3],
	matTemp[3][3];

void matMul (ull a[3][3], ull b[3][3], int d) {
    ull mat[3][3];
	for(int i = 0; i < d; i++) {
		for(int j = 0; j < d; j++) {
			ull temp = 0;
			for(int k = 0; k < d; k++) {
				temp += (a[i][k] * b[k][j]);
			}

			mat[i][j] = temp;
		}
	}

	for(int i = 0; i < d; i++) {
        for(int j = 0; j < d; j++) {
            matTemp[i][j] = mat[i][j];
        }
	}
}

void matExp (int exp, int d) {
	if(exp < 2) return;

	matExp (exp >> 1, d);
	matMul (matTemp, matTemp, d);

	if(exp & 1) matMul (matInit, matTemp, d);
}

void printMatrix(ull A[3][3], int d) {
    for(int i = 0; i < d; i++) {
        for(int j = 0; j < d; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main () {

	//freopen("in.txt", "r", stdin);
	int t, n;
	ull p, q;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++) {
		scanf("%llu %llu %d", &p, &q, &n);

		if(n == 0) {
            printf("Case %d: %d\n", i, 2);
            continue;
		}

		if(n == 1) {
            printf("Case %d: %d\n", i, p);
            continue;
		}

		matInit[0][0] = matTemp[0][0] = p;
		matInit[0][1] = matTemp[0][1] = -q;
		matInit[1][0] = matTemp[1][0] = 1;
		matInit[1][1] = matTemp[1][1] = 0;


		matExp(n - 1, 2);

        printf("Case %d: %llu\n", i, ((matTemp[0][0] * (ull)p) + (matTemp[0][1] * (ull)2L)));
	}

	return 0;
}

