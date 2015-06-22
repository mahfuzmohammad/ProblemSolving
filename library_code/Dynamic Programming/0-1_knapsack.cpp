#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> price, weight;
int array[10001][31];

int knapsack(int n, int w){
    if(n == -1 || w == 0) return 0;

    if(weight[n] > w)
        knapsack(n - 1, w);
    else {
        if(array[n][w] != -1) return array[n][w];
        else {
            array[n][w] = max(price[n] + knapsack(n - 1, w - weight[n]), knapsack(n - 1, w));
            return array[n][w];
        }
    }
}

void reset()
{
    price.clear();
    weight.clear();

    for(int i = 0; i < 10001; i++){
        for(int j = 0; j < 31; j++){
            array[i][j] = -1;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T, N, P, W, G, MW, ans;

    cin >> T;

    for(int i = 0; i < T; i++){
        reset();
        ans = 0;
        cin >> N;
        for(int j = 0; j < N; j++){
            cin >> P >> W;
            price.push_back(P);
            weight.push_back(W);
        }

        cin >> G;
        for(int j = 0; j < G; j++){
            cin >> MW;
            ans += knapsack(N - 1, MW);
        }

        cout << ans << endl;
    }

    return 0;
}
