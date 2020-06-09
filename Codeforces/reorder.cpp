//http://codeforces.com/contest/1008/problem/C

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> a, b;

bool compare(int a, int b){
    return a > b;
}

void input(){
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    b = a;
}

int reorder(){
    sort(b.begin(), b.end(), compare);
    int i, j;
    i = 0;
    j = 1;
    if(b.size() == 1){
        return 0;
    }
    int cnt = 0;
    while(i < n && j < n){
        int x = b[i];
        int y = b[j];
        if(x > y){
            i++;
            j++;
            cnt++;
        }else{
            j++;
        }
    }
    return cnt;
}

 int main(){
    freopen("input.txt","r",stdin);
    input();
    cout << reorder();
    return 0;

 }

