//http://codeforces.com/contest/1009/problem/A


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[1005];
int c[1005];

 int main(){
    freopen("input.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    int i = 0;
    int j = 0;
    int cnt = 0;
    while(i < n && j < m){
        if(c[i] <= a[j]){
            i++;
            j++;
            cnt++;
        }else{
            i++;
        }
    }
    cout << cnt;
    return 0;
 }

