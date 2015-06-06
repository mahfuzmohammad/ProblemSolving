//UVA 11547 - AUTOMATIC ANSWER.cpp

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int T, n, ans;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        scanf("%d", &n);
        ans = ((n * 63) + 7492) * 5 - 498;
        ans /= 10;
        ans = fabs(ans);
        printf("%d\n", ans % 10);
    }

    return 0;
}
