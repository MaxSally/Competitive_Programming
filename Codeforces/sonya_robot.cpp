//http://codeforces.com/contest/1004/problem/C

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include<string>
#include <set>
#include <map>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

int n;
map<int, int> m;
vector<int> v;
vector<int> visited;

void input(){
    cin >> n;
    visited.resize(100005, 0);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
        if(m.find(a) == m.end()){
            m[a] = 1;
        }else{
            m[a]++;
        }
    }
}

ll total(){
    ll cnt = 0;
    for(int i = 0; i < n - 1; i++){
        int a = v[i];
        if(m[a] == 1){
            m.erase(a);
        }else{
            m[a]--;
        }
        if(visited[a])
            continue;
        visited[a] = 1;
        cnt += (ll) m.size();
        //cout <<i << " " << cnt << endl;
    }
    return cnt;
}

int main(){
    freopen("input.txt","r",stdin);
    input();
    cout << total();
    return 0;
}
