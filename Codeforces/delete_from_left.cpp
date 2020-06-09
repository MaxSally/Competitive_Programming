//http://codeforces.com/contest/1005/problem/B

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

int main(){
    freopen("input.txt","r",stdin);
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    ll i = 0;
    ll temp = min(s.length(), t.length());
    while(s[i] == t[i] && i < temp){
        i++;
    }
    cout << ((ll) s.length() + (ll) t.length() - i*2);
    return 0;
}
