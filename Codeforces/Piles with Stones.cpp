//http://codeforces.com/contest/1013/problem/0

#include<bits/stdc++.h>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

const int inf = 1e9;
const int N = 1005;
int a[N];

int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        sum += c;
    }
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        sum -= c;
    }

    if(sum >= 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}

