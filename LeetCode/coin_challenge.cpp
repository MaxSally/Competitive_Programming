//https://leetcode.com/problems/coin-change/description/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
    using namespace std;

vector<int>dp;

int coinChange(vector<int>& coins, int amount) {
    int n=coins.size();
    dp.resize(amount+1);
    for(int j=1;j<=amount;j++){
        int minN=1e9;
        for(int k=0;k<n;k++){
            if(coins[k]<=j){
                minN=min(minN,1+dp[j-coins[k]]);
            }
        }
        dp[j]=minN;
    }
    if(dp[amount]!=1e9){
        return dp[amount];
    }else{
        return -1;
    }

}

int main(){
    freopen("input.txt","r",stdin);
    int n,k;
    cin >> n >> k;
    vector<int> coins;
    coins.resize(n);
    for(int i=0;i<n;i++){
        cin >> coins[i];
    }
    cout << coinChange(coins,k);
    return 0;
}
