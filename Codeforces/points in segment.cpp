//http://codeforces.com/contest/1015/problem/A

#include<bits/stdc++.h>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double
#define ngu cout <<"ngu" << endl;
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int inf = 1e9;

bool a[105];

int main(){
    io
    freopen("input.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    memset(a, false, sizeof a);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        for(int j = x; j <= y; j++){
            a[j] = 1;
        }
    }
    int cnt = 0;
    queue<int> q;
    for(int i = 1; i <= m; i++){
        if(!a[i]){
            cnt++;
            q.push(i);
        }
    }
    cout << cnt << endl;
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}

