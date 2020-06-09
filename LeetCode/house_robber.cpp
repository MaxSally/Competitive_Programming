//https://leetcode.com/problems/house-robber/description/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
    using namespace std;

vector<vector<int> >dp;

/*int rob(vector<int> &nums){
    vector<int> cost;
    cost.resize(nums.size()+1);
    for(int i=0;i<nums.size();i++){
        cost[i+1]=nums[i];
    }
    int n=cost.size();
    int k= 0;
    for(int i=0;i<n;i++){
        k+=cost[i];
    }
    dp.resize(n+1);
    for(int i=0;i<=n;i++){
        dp[i].resize(k+1);
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=k;i++){
        dp[0][i]=0;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(cost[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],cost[i-1]+dp[i-2][j-cost[i-1]]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int maxN=0;
    for(int i=0;i<=k;i++){
        maxN=max(maxN,dp[n][i]);
        //cout << dp[n][i] << " ";
    }
    //cout << endl;
    return maxN;
}*/

int rob(vector<int> &nums){

    int n=nums.size();
    vector<int> cost;
    cost.resize(n);
    if(n>=1){
        cost[0]=nums[0];
        if(n>=2){
            cost[1]=max(nums[0],nums[1]);
            if(n>=3){
                cost[2]=max(nums[1],nums[0]+nums[2]);
            }
        }
    }
    for(int i=3;i<n;i++){
        cost[i]=max(cost[i-2],cost[i-3])+nums[i];
    }
    /*for(int i=0;i<n;i++){
        cout << cost[i] << " ";
    }*/
    return max(cost[n-1],cost[n-2]);
}

int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    vector<int> cost;
    cost.resize(n);
    for(int i=0;i<n;i++){
        cin >> cost[i];
    }
    cout << rob(cost);
    return 0;
}
