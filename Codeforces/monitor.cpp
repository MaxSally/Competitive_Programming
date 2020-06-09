//http://codeforces.com/problemset/problem/16/C

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

int a, b, x, y;
const db epsilo = 1e-9;

int main(){
    freopen("input.txt","r",stdin);
    cin >> a >> b >> x >> y;
    int g = __gcd(x,y);
    x /= g;
    y /= g;
    a = min(a/x, b/y);
    cout << x*a << " " << y*a;
    return 0;
}
