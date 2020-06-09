//http://codeforces.com/contest/812/problem/C

#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

long long n,s,k,t,k1;
vector<long long> a,b;

bool compare(long long a, long long b){
    return a < b;
}

void nubi(){
    k1 = 0;
    k = 0;
    t = 0;
    b.resize(n+1);
    long long left, right;
    left = 1;
    right = n;
    while(true){
        //cout << "HERE";
        k = (long long) (right + left)/2;
        if(right < left){
            break;
        }
        b = a;
        for(int i = 1; i <= n; i++){
            b[i] = b[i] + i*k;
        }
        sort(b.begin() + 1,b.end(),compare);
        long long sum = 0;
        for(int i = 1; i <= k; i++){
            sum += b[i];
        }
        if(sum <= s){
            if(k1 < k){
                k1 = k;
                t = sum;
            }else if(k1 == k){
                t = min(t,sum);
            }
            left = k+1;
        }else{
            right = k-1;
        }



    }
    cout << k1 << " " << t;
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> s;
    a.resize(n+1);
    for(int i = 1 ; i <= n; i++){
        cin >> a[i];
    }
    nubi();
    return 0;
}
