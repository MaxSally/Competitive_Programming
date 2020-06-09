//https://leetcode.com/problems/palindrome-partitioning-ii/description/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
    using namespace std;

vector<vector<bool> > palin;
vector<int> total;

/*void print(){
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[i].size();j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}*/

int minCut(string s){
    //s=" "+s;
    int n=s.length();
    palin.resize(n+1);
    total.resize(n+1);
    for(int i=0;i<=n;i++){
        palin[i].resize(n+1);
    }
    for(int i=0;i<n;i++){
        palin[i][i]=1;
    }
    for(int l=2;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int j=i+l-1;
            if(l==2){
                if(s[i]==s[j]){
                    palin[i][j]=1;
                }else{
                    palin[i][j]=0;
                }
            }else{
                if(s[i]==s[j] && palin[i+1][j-1]){
                    palin[i][j]=1;
                }else{
                    palin[i][j]=0;
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        if(palin[0][i]){
            total[i]=0;
        }else{
            total[i]=1e9;
            for(int j=0;j<i;j++){
                if(palin[j+1][i] && 1+total[j]<total[i]){
                    total[i]=total[j]+1;
                }
            }
        }
    }
    return total[n-1];


}


int main(){
    freopen("input.txt","r",stdin);
    string s;
    cin >> s;
    cout << minCut(s);
    return 0;
}



