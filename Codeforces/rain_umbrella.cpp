//http://codeforces.com/contest/988/problem/F

#include<vector>
#include<algorithm>
#include<stdio.h>
#include<iostream>
    using namespace std;

vector<vector<int> > dp;
vector<bool> rain;
vector<pair<int,int> > umb;
vector<int> cost;
int a,n,m;

int const inf=1000*1000*1000;

void rain_umb(){
    for(int i=0;i<a;i++){
        for(int j=0;j<=m;j++){
            if(dp[i][j]==inf){
                continue;
            }
            if(!rain[i]){
                dp[i+1][m]=min(dp[i+1][m],dp[i][j]);
            }
            if(j<m){
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+cost[j]);
            }
            if(umb[i].first!=inf){
                dp[i+1][umb[i].second]=min(dp[i+1][umb[i].second], dp[i][j]+umb[i].first);
            }
        }
    }
    int ans=inf;
    for(int i=0;i<=m;i++){
        ans=min(ans,dp[a][i]);
    }
    if(ans==inf){
        ans=-1;
    }
    cout << ans;
}


int main(){
    freopen("input.txt","r",stdin);
    cin >> a >> n >> m;
    rain.resize(a+1,false);
    dp.resize(a+1);
    for(int i=0;i<=a;i++){
        dp[i].resize(m+1,inf);
    }
    umb.resize(a+1,make_pair(inf,-1));
    cost.resize(m);
    //dp[0][0]=0;
    dp[0][m]=0;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >>y;
        for(int j=x;j<y;j++){
            rain[j]=true;
        }
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >>y;
        cost[i]=y;
        umb[x]=min(umb[x],make_pair(y,i));
    }
    rain_umb();
    //cout << total_time();
    return 0;
}
