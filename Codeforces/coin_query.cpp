//http://codeforces.com/contest/1003/problem/D

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include <string>
#include <set>
#include <map>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

bool compare(int a, int b){
    return a > b;
}

//vector<int> a;

int main(){
    freopen("input.txt","r",stdin);
    int n, q;
    cin >> n >> q;
    map<int,int> a;
    for(int i = 0; i < n ;i++){
        int b;
        cin >> b;
        if(a.find(b) != a.end()){
            a[b]++;
        }else{
            a[b] = 1;
        }
    }
    while(q--){
        int b;
        cin >> b;
        int cnt = 0;
        map<int,int> :: reverse_iterator it;
        for(it = a.rbegin(); it != a.rend(); it++){
            //cout << it->first <<" " << it -> second << endl;
            int c = (int) b/(it->first);
            if(c <= it->second){
                cnt += c;
                b -= c*(it->first);
            }else{
                cnt += it->second;
                b -= (it->second)*(it->first);
            }
            if(!b){
                break;
            }
        }
        if(!b)
            cout << cnt << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
