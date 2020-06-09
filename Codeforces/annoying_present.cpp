//http://codeforces.com/contest/1009/problem/C

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int m;
ll ans = 0;
ll n;

 int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    ll temp = (n - 2)*(n-1)/2;
    for(int i = 0; i < m; i++){
        ll x, d;
        cin >> x >> d;
        ans += n*x + d*temp;
    }
    double res = (double) ans/((double) n);
    cout << fixed << setprecision(9) << res;
    return 0;
 }

