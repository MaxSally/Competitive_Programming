//http://codeforces.com/contest/1003/problem/C

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double


int main(){
    freopen("input.txt","r",stdin);
    int n;
    db k;
    cin >> n >> k;
    vector<db> a;
    a.resize(n + 1);
    vector<db> b;
    b.resize(n + 1);
    b[0] = a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        b[i] = b[i - 1] + a[i];
    }
    db maxN = 0;
    for(int i = 0; i < n - k + 1; i++){
        for(int j = k; j <= n; j++){
            if( i + j > n)
                continue;
            maxN = max(maxN, (b[i + j] - b[i])/j);
        }
    }
    cout << fixed << setprecision(12) << maxN;
    return 0;
}
