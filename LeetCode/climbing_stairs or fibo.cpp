//https://leetcode.com/problems/climbing-stairs/description/

#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
    using namespace std;

vector<long long int> sum;

int climbStairs(int n) {
    sum.resize(n+1);
    sum[0]=1;
    sum[1]=1;
    for(int i=2;i<=n;i++){
        sum[i]=sum[i-1]+sum[i-2];
    }
    return sum[n];
}

int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin >>n;
    cout << climbStairs(n);
    return 0;
}
