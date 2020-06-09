//http://codeforces.com/contest/1000/problem/C

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

bool compare(pair<ll,ll> a, pair<ll,ll> b){
    return a.first < b.first;
}

bool compare1(ll a, ll b){
    return a < b;
}

int const lim = 200005;
int n;
vector<ll> cnt, ans, v;
vector<pair<ll,ll> > a;

int main(){
    freopen("input.txt","r",stdin);
    cin >> n;
    cnt.resize(n*2, 0);
    ans.resize(n + 1, 0);
    for(int i = 0; i < n; i++){
        ll left, right;
        cin >> left >> right;
        a.push_back(make_pair(left, right));
        v.push_back(left);
        v.push_back(right + 1);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end())-v.begin());
    for(int i = 0; i < a.size(); i++){
        int left = lower_bound(v.begin(),v.end(), a[i].first) - v.begin();
        int right = lower_bound(v.begin(),v.end(), a[i].second + 1) - v.begin();
        cnt[left]++;
        cnt[right]--;
    }
    for(int i = 1; i < 2*n; i++){
        cnt[i] += cnt[i-1];
    }
    for(int i = 1; i < 2*n; i++){
        ans[cnt[i-1]] += v[i] - v[i-1];
    }
    for(int i = 1; i < n+1; i++){
        cout << ans[i] << " ";
    }

    return 0;
}
