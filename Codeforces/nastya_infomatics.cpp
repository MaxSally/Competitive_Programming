//https://codeforces.com/contest/992/problem/B

#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

long long gcd(long long a,long long b){
    if(a==0 || b==0){
        return 0;
    }
    if( a== b){
        return a;
    }
    if( a > b){
        return gcd(a - b, b);
    }
    return gcd(a, b - a);

}

int main(){
    freopen("input.txt","r",stdin);
    int l,r,x,y;
    cin >> l >> r >> x >> y;
    long long product = x*y;
    long long total = 0;
    for(int i = max(l,x); i <= min(r,y); i++){
        if(product % i == 0 ){
            total++;
        }
    }
    cout << total;
    return 0;
}

