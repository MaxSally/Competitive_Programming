//http://codeforces.com/contest/998/problem/B

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include <queue>
#include <string>
//#include <function>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

int n, b;
vector<int> a, sum;
priority_queue<int, vector<int>, greater<int> > pq;

int cutting(){
    int c = 0;
    for(int i = 1; i <= n; i++){
        int d = sum[i];
        if(c != d){
            continue;
        }
        pq.push(abs(a[i + 1] - a[i]));
    }
    int total = 0;
    int cnt = 0;
    while(pq.size() > 1){
        int d = pq.top();
        pq.pop();
        total += d;
        if(total > b){
            break;
        }else{
            cnt++;
        }
    }
    while(!pq.empty()){
        pq.pop();
    }
    return cnt;
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> b;
    a.resize(n + 2);
    sum.resize(n + 1);
    sum[0] = 0;
    a[n + 1] = 1000000000;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + (a[i] % 2? 1: -1);
    }
    /*for(int i = 1; i <= n; i++){
        cout << sum[i] << " ";
    }
    cout << endl;*/

    a[0] = 0;
    if( n % 2 || sum[n] != 0){
        cout << 0;
        return 0;
    }else{
        cout << cutting();
    }

    return 0;
}
