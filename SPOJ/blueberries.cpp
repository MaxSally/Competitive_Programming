//http://www.spoj.com/problems/RPLB/

#include<iostream>
#include<stdio.h>
#include<vector>
    using namespace std;

int n,k;
vector<vector<int> > dp;
vector<int> a;

int maxN(int c, int b){
    if(c>b){
        return c;
    }
    return b;
}

void dynamic(){
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(a[i-1]<=j){
                dp[i][j]=maxN(dp[i-1][j],a[i-1]+dp[i-2][j-a[i-1]]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

}


int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii=1;ii<=t;ii++){
        cin >> n >> k;
        a.clear();
        a.resize(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        dp.clear();
        dp.resize(n+1);
        for(int i=0;i<=n;i++){
            dp[i].resize(k+1,0);
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=k;i++){
            dp[0][i]=0;
        }
        for(int j=a[0];j<=k;j++){
            dp[1][j]=a[0];
        }
        dynamic();
        cout << "Scenario #" << ii << ": "<< dp[n][k]<< endl;
    }
    return 0;
}
