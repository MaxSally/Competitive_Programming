//http://codeforces.com/contest/1008/problem/B

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

 int main(){
    freopen("input.txt","r",stdin);
    int n;
    bool flag = false;
    cin >> n;
    int cur = 1e9;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a <= cur && b <= cur)
            cur = max(a, b);
        else if(a <= cur && b > cur)
            cur = a;
        else if(a > cur && b <= cur)
            cur = b;
        else
            flag = true;
    }
    if(flag)
        cout << "NO";
    else
        cout << "YES";

 }

