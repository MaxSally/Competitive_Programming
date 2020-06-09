//http://codeforces.com/problemset/problem/607/B

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
    using namespace std;

int n;
int a[1000];
int dp[1000][1000];

int minN(int c, int b){
    if(c<b){
        return c;
    }
    return b;
}

int maxN(int c, int b){
    if(c>b){
        return c;
    }
    return b;
}

void dynamic(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

        }
    }
}


int main(){
    freopen("input.txt","r",stdin);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[j][i]=dp[j][i-1]+1;
            for(int k=j;k<i;k++){
                if(a[k]==a[i]){
                    dp[j][i]=minN(dp[j][i],dp[j][k-1]+maxN(dp[k+1][i-1],1));
                }
            }

        }
    }
    //dynamic();
    cout << dp[1][n];


    return 0;
}
