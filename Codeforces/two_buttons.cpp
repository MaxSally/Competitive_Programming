//http://codeforces.com/contest/520/problem/B

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include <queue>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

int n, m;
int const lim = 1e9;

int solve(int a){
    if(a == n){
        return 0;
    }
    if(a < n){
        return solve(a+1) + 1;
    }
    if(!(a % 2)){
        return solve(a/2) + 1;
    }
    return solve((a+1)/2) + 2;

}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    cout << solve(m);

    return 0;
}
