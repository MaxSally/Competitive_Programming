//http://www.spoj.com/problems/MMAXPER/

#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
    using namespace std;

int n;
vector<pair<int,int> > a;
int dp[1005][2];

int maxN(int c, int b){
    if(c>b){
        return c;
    }
    return b;
}

int abs(int c, int b){
    if(b>c){
        return b-c;
    }
    return c-b;
}

void dynamic(){
    for(int i=2;i<=n;i++){
        dp[i][0]=maxN(dp[i-1][0]+abs(a[i-1].first,a[i].first),dp[i-1][1]+abs(a[i-1].second,a[i].first))+a[i].second;
        dp[i][1]=maxN(dp[i-1][1]+abs(a[i-1].second,a[i].second),dp[i-1][0]+abs(a[i-1].first,a[i].second))+a[i].first;
    }
}

void print(){
    for(int i=1;i<=n;i++){
        cout << dp[i][0] << " " << dp[i][1] << endl;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n;
    a.push_back(make_pair(0,0));
    for(int i=1;i<=n;i++){
        int b,c;
        cin >> b >> c;
        a.push_back(make_pair(b,c));
    }
    dp[1][0]=a[1].second;               //0 nam ngang
    dp[1][1]=a[1].first;
    dynamic();
    cout << maxN(dp[n][1],dp[n][0]) << endl;
    return 0;
}
