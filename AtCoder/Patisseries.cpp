//https://abc100.contest.atcoder.jp/tasks/abc100_d

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include <queue>
#include <string>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

struct triple{
    ll a, b, c;
};

int n,m;
vector<triple> cake;

ll findCake(int k){
    priority_queue<ll, vector<ll>, less<ll> > pq;
    int c1, c2, c3;
    c3 = k % 2;
    k = k/2;
    c2 = k % 2;
    k = k/2;
    c1 = k;
    if (!c1){
        c1 = -1;
    }
    if (!c2){
        c2 = -1;
    }
    if (!c3){
        c3 = -1;
    }
    for (int i = 0; i < n; i++){
        ll a, b, c ;
        a = cake[i].a;
        b = cake[i].b;
        c = cake[i].c;
        pq.push(a*c1 + b*c2 + c*c3);
    }
    ll sum = 0;
    for(int i = 0; i < m; i++){
        sum += pq.top();
        pq.pop();
    }
    //cout << sum << endl;
    return sum;
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        triple temp;
        temp.a = a;
        temp.b = b;
        temp.c = c;
        cake.push_back(temp);
    }
    ll res = 0;
    for(int i = 0; i < 8; i++){
        res = max(res,findCake(i));
    }
    cout << res;
    return 0;
}
