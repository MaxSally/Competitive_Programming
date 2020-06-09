//http://codeforces.com/contest/1005/problem/E1


#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include<string>
#include <map>
#include <queue>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

int n, m;
int const maxN = 200005;
int const maxN2 = 400005;
int a[maxN];
int b[maxN];
vector<ll> cntPre;
vector<ll> cntAf;
queue<int> q;

void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    b[0] = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == m){
            b[i] = b[i-1];
            q.push(i);
        }else if(a[i] > m){
            b[i] = b[i-1] + 1;
        }
        else{
            b[i] = b[i-1] - 1;
        }
        //cout << b[i] << " ";
    }
}

ll total(){
    ll res = 0;
    int pre = 0;
    while(!q.empty()){
        int ind = q.front();
        q.pop();
        cntPre.clear();
        cntAf.clear();
        cntPre.resize(n*2 + 5, 0);
        cntAf.resize(n*2 + 5, 0);
        for(int i = pre; i <= n; i++){
            if( i < ind){
                cntPre[b[i] + n]++;
            }else if (i >= ind){
                cntAf[b[i] + n]++;
            }
        }
        for(int i = 0; i <= 2*n; i++){
            //cout << cntPre[i] << " " << cntAf[i] << endl;
            res += (ll) cntPre[i]*((ll) cntAf[i]);
            res += (ll) cntPre[i]*cntAf[i + 1];
        }
        //cout << endl;
        pre = ind;
    }

    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    input();
    cout << total();
    return 0;
}
