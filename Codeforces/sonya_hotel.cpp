//http://codeforces.com/contest/1004/problem/A

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include<string>
#include <set>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

int main(){
    freopen("input.txt","r",stdin);
    ll n, d;
    cin >> n >> d;
    vector<ll> v;
    v.resize(n);
    set<ll> s;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    if(n == 1){
        cout << 2;
        return 0;
    }
    for(int i = 0; i < n; i++){
        ll a = v[i];
        if(i == 0){
            s.insert(a - d);
            if(a + d <= v[i + 1] - d)
                s.insert(a + d);
            continue;
        }
        if(i == n -1){
            s.insert(a + d);
            if(a - d >= v[i - 1] + d)
                s.insert(a - d);
            continue;
        }
        if(a + d <= v[i + 1] - d)
            s.insert(a + d);
        if(a - d >= v[i - 1] + d)
            s.insert(a - d);

    }
    /*set<int> ::  iterator it;
    for(it = s.begin(); it != s.end(); it++)
        cout << *it << " ";
    cout << endl;*/
    cout << s.size();
    return 0;
}
