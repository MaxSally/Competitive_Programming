//http://codeforces.com/contest/1004/problem/D

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

int n, s, maxN;
vector<int> v;
map<int, int> m;


void input(){
    maxN = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        maxN = max(maxN, a);
        if(m.find(a) == m.end())
            m[a] = 1;
        else
            m[a]++;
        v.push_back(a);
    }
}

void process(){
    map<int, int> :: iterator it;
    int cnt = 0;
    vector<int> ans;
    for(it = m.begin(); it != m.end(); it++){
        int a = it->first;
        int b = it->second;
        if(b + cnt == a*4)
            continue;
        if(a*4 - b - cnt == 1){
            ans.push_back(a);
            if(cnt)
                break;
        }else if(a*4 - b - cnt >= 2){
            ans.push_back(b);
            if(!cnt){
                ans.push_back(b);
            }
            break;
        }
    }
    s = ans[0] + ans[1] + maxN;
    //cout << ans[0] << ans[1] << maxN << endl;
    int sizen, sizem;
    sizen = (int) (s + sqrt(s*s - 4*n))/2;
    sizem = (int) (s - sqrt(s*s - 4*n))/2;
    cout << sizen << " " << sizem << endl;
}

int main(){
    freopen("input.txt","r",stdin);
    input();
    process();
    return 0;
}
