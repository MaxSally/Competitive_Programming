//http://codeforces.com/contest/1003/problem/A

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
    cin >> n;
    vector<int> a;
    a.resize(105, 0);
    for(int i = 0; i < n; i++){
        int b;
        cin >> b;
        a[b]++;
    }
    int maxN = 0;
    for(int i = 0; i < 105; i++){
        maxN = max(maxN, a[i]);
    }
    cout << maxN;
    return 0;
}
