//https://codeforces.com/contest/828/problem/D

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include<string>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

int n, k;

int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> k;
    n--;
    int rot =(int) n/k;
    if(n % k == 1){
        cout << 1 + rot*2 << endl;
    }else if(n % k == 0){
        cout << rot*2 << endl;
    }else{
        cout << 2 + rot*2 << endl;
    }
    while(n){
        cout << max(n - k + 1, 1) << " " << n + 1 << endl;
        n--;
    }
    return 0;
}

