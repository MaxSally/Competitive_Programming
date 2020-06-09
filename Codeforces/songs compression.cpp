//http://codeforces.com/contest/1015/problem/C

#include<bits/stdc++.h>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double
#define ngu cout <<"ngu" << endl;
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int inf = 1e9;



vector<int> a;

int main(){
    io
    freopen("input.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        int b, c;
        cin >> b >> c;
        cnt += (ll) b;
        a.push_back(b - c);
    }
    sort(a.begin(), a.end());
    int cntD = 0;
    for(int i = n - 1; i >= 0; i--){
        //cout << cnt << endl;
        if(cnt <= m){
            break;
        }
        cnt -= (ll) a[i];
        cntD++;
    }
    if(cnt > m){
        cout << -1;
    }else
        cout << cntD;
    return 0;
}

