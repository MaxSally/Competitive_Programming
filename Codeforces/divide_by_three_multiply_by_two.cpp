//http://codeforces.com/problemset/problem/977/D

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

bool compare(pair<int, ll> a, pair<int, ll> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int n;
vector<pair<int,ll> > a;

int findTri(ll b){
    int cnt = 0;
    while(!(b % 3)){
        cnt++;
        b /= 3;
    }
    return cnt;
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n;
    for(int i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        int temp3 = findTri(temp);
        a.push_back(make_pair(temp3, temp));
    }
    sort(a.begin(), a.end(), compare);
    for(int i = 0; i < n; i++){
        cout << a[i].second << " ";
    }
    return 0;
}
