#include <stdio.h>
long long int a, b, c, d, e, f;

int main() {
    long long int n, caseno = 0, cases;
    scanf("%lld", &cases);
    while( cases-- )
    {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        long long int fn[10005];
        fn[0]=a;
        fn[1]=b;
        fn[2]=c;
        fn[3]=d;
        fn[4]=e;
        fn[5]=f;
        for(int i=6;i<=n;i++)
          fn[i]=(fn[i-1] + fn[i-2] + fn[i-3] + fn[i-4] + fn[i-5] + fn[i-6])% 10000007;

        printf("Case %lld: %lld\n", ++caseno, fn[n]% 10000007);
    }
    return 0;
}
