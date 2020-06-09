//http://codeforces.com/contest/1013/problem/E
#include<bits/stdc++.h>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

const int inf = 1e9;

int dp[5005][5005];

int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    vector<int> a;
    a.resize(n);
    for(int i = 0; i < 5005; i++){
        for(int j = 0; j < 5005; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i;j >= 0; j--){
            if(dp[i][j] == inf)
                continue;
            dp[]
        }
    }
    return 0;
}
