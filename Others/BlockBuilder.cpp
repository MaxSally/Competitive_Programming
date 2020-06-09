#include <bits/stdc++.h>
//#include "csce310homework04part03.h"

using namespace std;
const int N = 100005;
int dp[N][2];

int footRace( vector<int> segments01 , vector<int> segments02 , vector<int> transitions01to02 , vector<int> transitions02to01 ){
    int n = (int)segments01.size();
    dp[0][0] = segments01[0];
    dp[0][1] = segments02[0];
    for(int i = 1; i < n; i++){
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + transitions02to01[i - 1]) + segments01[i];
        dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + transitions01to02[i - 1]) + segments02[i];
    }
    return min(dp[n - 1][0], dp[n - 1][1]);
}

void input(vector<int> &a, int n){
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
}


int main(){
    freopen("input.txt", "r", stdin);
    vector<int> segment01, segment02, trans1, trans2;
    int n; cin >> n;
    input(segment01, n);
    input(segment02, n);
    input(trans1, n - 1);
    input(trans2, n - 1);
    cout << footRace(segment01, segment02, trans1, trans2);
    return 0;
}

