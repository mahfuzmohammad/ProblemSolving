//In the name of Allah, most Gracious, most Compassionate
#include <bits/stdc++.h>

using namespace std;

#define _TEXT_SIZE 110

char	s1[_TEXT_SIZE],
		s2[_TEXT_SIZE],
		virus[_TEXT_SIZE],
		ans[_TEXT_SIZE];

int		F[_TEXT_SIZE], //values of failur function of virus
		dp[_TEXT_SIZE][_TEXT_SIZE][_TEXT_SIZE],
		s1size, s2size, virusSize, ans_i = 0;

void calc_failure_fuction() {
    //everything is 1 indexed
    int k, psize = virusSize;
    F[1] = 0; F[0] = 0;

    for(int i = 2; i <= psize; i++) {
        k = F[i - 1];
        while(true) {
            if(virus[k] == virus[i - 1]) {
                F[i] = k + 1;
                break;
            }

            if(k == 0) {F[i] = 0; break;}
            k = F[k];
        }
    }
}

int f(int i, int j, int k) {

	if (k >= virusSize) return -1000;
	if (i >= s1size || j >= s2size) return 0;

	if (dp[i][j][k] != -1) return dp[i][j][k];

	int down = f(i + 1, j, k);
	int right = f(i, j + 1, k);
	int ret = max(right, down);

	if (s1[i] == s2[j]) {
		int tk = k;
		while (tk > 0 && s1[i] != virus[tk])
			tk = F[tk];

		if (s1[i] == virus[tk]) {
			tk++;
		}

		ret = max(ret, f(i + 1, j + 1, tk) + 1);
	}

	dp[i][j][k] = ret;
	return ret;

}

void printAnswer (int i, int j, int k) { //path print

	if (k >= virusSize) return;
	if (i >= s1size || j >= s2size) return;

	int valInThisState = f(i, j, k);

	if (valInThisState == f(i + 1, j, k)) {
		printAnswer(i + 1, j, k);
		return;
	}

	if (valInThisState == f(i, j + 1, k)) {
		printAnswer(i, j + 1, k);
		return;
	}

	if (s1[i] == s2[j]) {
		int tk = k;
		while (tk > 0 && s1[i] != virus[tk])
			tk = F[tk];

		if (s1[i] == virus[tk]) {
			tk++;
		}

		if (valInThisState == f(i + 1, j + 1, tk) + 1) {
			ans[ans_i++] = s1[i];
			printAnswer(i + 1, j + 1, tk);
		}
	}

	return;

}

int main() {

	//freopen("in", "r", stdin);
	scanf("%s\n%s\n%s", s1, s2, virus);
	s1size = strlen(s1), s2size = strlen(s2),
	virusSize = strlen(virus);

	calc_failure_fuction();

	memset(dp, -1, sizeof dp);

	int f_ans = f(0, 0, 0);
	printAnswer(0, 0, 0);

	if (f_ans > 0)
		printf("%s\n", ans);
	else
		printf("0\n");

	return 0;
}