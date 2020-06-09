//http://codeforces.com/problemset/problem/729/C

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
using namespace std;

int const lim = 200005;
int n, k, s;
long long t, leftN, rightN;
int car[lim][2];
vector <int> gas_station;

bool compare(int a, int b){
    return a < b;
}

int findC(){
    long long mid;
    long long time;
    long long ans = -1;
    while(leftN <= rightN){
        mid = (leftN + rightN)/2;
        //cout << leftN  << " "<< mid << " " << rightN << endl;
        bool flag = false;
        long long cur = 0;
        time = 0;
        for(int i = 0; i <= k; i++){
            long long a = gas_station[i];
            long long s1 = a - cur;
            /*if(mid < s1){
                flag = true;
                break;
            }*/
            time += s1 + max(2*s1 - mid, 0LL);
            //cout <<"time " <<s1 << " " << time << endl;
            cur = a;
        }
        /*if(flag){
            leftN = mid + 1;
            continue;
        }*/
        if(time <= t){
            rightN = mid - 1;
            ans = mid;
        }else{
            leftN = mid + 1;
        }
        //cout << ans << endl;
    }
    if( ans == -1){
        return -1;
    }
    int res = 1e9;
    for(int i = 0; i < n; i++){
        if(car[i][1] >= ans){
            res = min(res, car[i][0]);
        }
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n >> k >> s >> t;
    leftN = -1e9;
    rightN = -1e9;
    for(int i = 0; i < n; i++){
        int c, v;

        cin >> c >> v;
        car[i][0] = c;
        car[i][1] = v;
        //leftN = min(leftN, (long long) v);
        rightN = max(rightN, (long long) v);
    }
    gas_station.resize(k+1);
    for(int i = 0; i < k; i++){
        cin >> gas_station[i];
    }
    gas_station[k] = s;
    sort(gas_station.begin(), gas_station.end(), compare);
    leftN = gas_station[0];
    for(int i = 1; i <= k; i++){
        leftN = max(leftN, (long long) gas_station[i] - gas_station[i-1]);
    }
    cout << findC();


    return 0;
}
