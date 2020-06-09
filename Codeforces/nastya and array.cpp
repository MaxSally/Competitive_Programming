//https://codeforces.com/contest/992/problem/0

#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a==0)
            continue;
        s.insert(a);
    }
    cout << s.size();
    return 0;
}
