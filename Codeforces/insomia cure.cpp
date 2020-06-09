//https://codeforces.com/problemset/problem/148/A

#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    int k, l, m , n, d;
    cin >> k >> l >> m >> n >> d;
    vector<bool> a;
    a.resize(d + 1, 0);
    int ans = 0;
    for(int i = 1; i <= d; i++){
        if(i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
            a[i] = 1;
        else
            ans++;
    }
    cout << d - ans;
    return 0;
}
