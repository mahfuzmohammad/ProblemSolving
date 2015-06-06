//In the name of Allah, most Gracious, most Compassionate
#include <bits/stdc++.h>

using namespace std;

int arr[10];
char str[100005];

int main() {

    for(int i = 1; i <= 4; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%s", str);
    int l = strlen(str);

    int ans = 0;

    for(int i = 0; i < l; i++) {
        ans += arr[(str[i] - '0')];
    }

    printf("%d\n", ans);

    return 0;
}
