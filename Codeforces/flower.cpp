//http://codeforces.com/problemset/problem/474/D

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
    using namespace std;

int n=100005;
int Num=1e9 +7;
long dp[100005];
int k;

void dynamics(){
    for(int i=1;i<=n;i++){
        if(i>=k){
            dp[i]=(dp[i-1]+dp[i-k]) % Num;
        }else{
            dp[i]=dp[i-1];
        }
    }
    for(int i=1;i<=n;i++){
        dp[i]=(dp[i]+dp[i-1]) % Num ;
    }

}

int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin >> t >> k;
    dp[0]=1;
    dynamics();
    for(int ii=0;ii<t;ii++){
        int a,b;
        cin >> a >> b;
        cout << (dp[b] - dp[a-1] + Num ) % Num << endl;
    }




    return 0;
}
