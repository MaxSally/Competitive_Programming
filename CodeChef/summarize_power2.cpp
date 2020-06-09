//http://codeforces.com/contest/1005/problem/C

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include<string>
#include <map>
#include <queue>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

map<int, int> mp;
int n;
vector<ll> lis;

void pow(){
    lis.resize(35);
    lis[0]=1;
    for(int i=1;i<=34;i++){
        lis[i]=lis[i-1]*2;
    }
}

void input(){
    cin >> n;
    //cout << n << endl;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(mp.find(a) == mp.end())
            mp[a] = 1;
        else
            mp[a]++;
    }
}

void print(){
    map<int, int> :: iterator it, it1;
    for(it = mp.begin(); it != mp.end(); it++){
        cout << it -> first << " " << it -> second << endl;
    }
}

int total(){
    //int cnt = 0;
    map<int, int> :: iterator it, it1;
    for(it = mp.begin(); it != mp.end(); it++){
        int a = it -> first;
        if(it -> second >= 2 && binary_search(lis.begin(), lis.end(), (ll) a)){
            //cnt += it -> second;
            it -> second = 0;
            continue;
        }
        for(int i = 0; i < 33; i++){
            int c = (int) (lis[i] - (ll) a);
            //cout << c << endl;
            if(c <= 0)
                continue;
            it1 = mp.find(c);
            if(it1 != mp.end() && it1 != it){
                //cnt += it-> second;
                //cnt += it1 -> second;
                it -> second = 0;
                it1 -> second = 0;
            }
            //print();
            //cout <<c << " " << cnt << endl;
        }
    }
    int cnt = 0;
    for(it = mp.begin(); it != mp.end(); it++){
        cnt += it -> second;
    }
    return cnt;
}


int main(){
    freopen("input.txt", "r", stdin);
    input();
    pow();
    cout << total();
    return 0;
}

