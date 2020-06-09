//http://codeforces.com/contest/1013/problem/B

#include<bits/stdc++.h>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

const int inf = 1e9;
vector<pair<int,int> > a;

int main(){
    freopen("input.txt","r",stdin);
    int n, x;
    cin >> n >> x;
    a.resize(n);
    for(int i = 0; i < n ; i++){
        cin >> a[i].first;
        a[i].second = 0;
    }
    sort(a.begin(), a.end());
    for(int i = 1; i < n; i++){
        if(a[i].first == a[i - 1].first){
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        int b = a[i].first & x;
        if(b != a[i].first){
            a[i].first = b;
            a[i].second = 1;
        }
    }
    sort(a.begin(), a.end());
    /*for(int i = 0; i < n; i++){
        cout << a[i].first << " ";
    }
    cout << endl;*/
    int minN = inf;
    for(int i = 1; i < n; i++){
        if(a[i].first == a[i - 1].first){
            minN = min(minN,a[i].second + a[i - 1].second);
        }
    }
    if(minN != inf){
        cout << minN << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}
