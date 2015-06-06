//UVA 10336 - Rank the Languages.cpp

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> v;
int **temp;
int letters[26];

typedef struct {
    char ch;
    int rank;
} langContainer;

vector<langContainer> lang;
vector<langContainer> :: iterator it;

bool langSort(langContainer a, langContainer b){
    if(a.rank == b.rank) return (a.ch < b.ch);

    return (a.rank > b.rank);
}

void reset(int r, int c)
{
    v.clear();
    lang.clear();
    for(int i = 0; i < 26; i++){
        letters[i] = 0;
    }

    for(int i = 0; i < r; i++){
        delete [] temp[i];
    }

    delete [] temp;
}

void markState(char ch, int r, int c, int h, int w)
{
    if(r < 0 || c < 0 || r >= h || c >= w) return;
    if(temp[r][c] == 1) return;
    if(v[r][c] != ch) return;

    temp[r][c] = 1;

    markState(ch, r, c + 1, h, w);
    markState(ch, r, c - 1, h, w);
    markState(ch, r - 1, c, h, w);
    markState(ch, r + 1, c, h, w);
}

void process(int r, int c, int h, int w){
    if(r < 0 || c < 0 || r >= h || c >= w) return;
    if(temp[r][c] == 1) return;

    if(temp[r][c] == 0){
        if(letters[v[r][c] - 'a'] == 0){
            markState(v[r][c], r, c, h, w);
            langContainer lg;
            lg.ch = v[r][c];
            lg.rank = 1;
            lang.push_back(lg);
            letters[v[r][c] - 'a'] = lang.size();
        } else {
            lang[ letters[v[r][c] - 'a'] - 1].rank += 1;
            markState(v[r][c], r, c, h, w);
        }
    }

    process(r, c + 1, h, w);
    process(r, c - 1, h, w);
    process(r - 1, c, h, w);
    process(r + 1, c, h, w);
}

int main()
{
    int N, H, W;
    string str;

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> H >> W;
        temp = new int*[H];
        for(int j = 0; j < H; j++){
            temp[j] = new int[W];
        }

        for(int m = 0; m < H; m++){
            for(int n = 0; n < W; n++){
                temp[m][n] = 0;
            }
        }

        for(int j = 0; j < H; j++){
            cin >> str;
            v.push_back(str);
        }

        for(int m = 0; m < H; m++){
            for(int n = 0; n < W; n++){
                if(temp[m][n] == 0)
                    process(m, n, H, W);
            }
        }

        sort(lang.begin(), lang.end(), langSort);

        cout << "World #" << i << endl;

        langContainer langCon;

        for(it = lang.begin(); it < lang.end(); it++){
            langCon = *it;
            cout << langCon.ch << ": " << langCon.rank << endl;
        }

        reset(H, W);
    }

    return 0;
}
