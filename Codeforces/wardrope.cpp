
//https://codeforces.com/contest/992/problem/C

#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

int x,k;
long long const modulo = 1000000007;

long long pow(long long a){
    if(a==0){
        return 1;
    }
    if(a==1){
        return 2;
    }
    long long b = (long long) a/2;
    long long c = a-b;

    return ((pow(b) % modulo) * (pow(c) % modulo)) % modulo;
}


int main(){
    freopen("input.txt","r",stdin);
    cin >> x >> k;
    if(x==0){
        cout << 0;
        return 0;
    }
    cout << (x*pow(k+1) - pow(k) + 1) % modulo;
    return 0;
}

