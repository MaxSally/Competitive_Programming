 //http://codeforces.com/contest/807/problem/C

#include <vector>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long x,y,p,q;
long long const inf = 1e9;


long long success_rate(){
    long long ans = -1;
    long long left = 0;
    long long right = (long long) inf;
    while(left <= right){
        //cout << left << " " << right << " " << ans <<endl;
        long long k = (long long) (left + right)/2;
        long long p1,q1;
        p1 = k * p;
        q1 = k * q;
        long long x1,y1;
        x1 = p1 - x;
        y1 = q1 - y;
        if(x1 >= 0 && x1 <= y1){
            ans = y1;
            //left = k + 1;
            right = k - 1;
        }else{
            left = k + 1;
            //right = k - 1;
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    while(t--){
        cin >> x >> y >> p >> q;
        cout << success_rate() << endl;
    }
    return 0;
}
