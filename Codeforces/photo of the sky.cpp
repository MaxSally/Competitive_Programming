//http://codeforces.com/contest/1013/problem/C

#include<bits/stdc++.h>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

const int inf = 1e9;

int a[200005];

int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n*2; i++){
        cin >> a[i];
    }
    sort(a, a + n*2);
    int cnt = 1;
    for(int i = 1; i < n*2; i++){
        if(a[i] == a[i - 1]){
            cnt++;
        }else{
            cnt = 1;
        }
        if(cnt >= n){
            cout << 0 << endl;
            return 0;
        }
    }
    cout <<(a[n - 1] - a[0])*(a[n*2 - 1]- a[n]) << endl;
    return 0;
}


