//https://leetcode.com/problems/distinct-subsequences/description/

#include<vector>
#include<iostream>
#include<stdio.h>
#include<cmath>
    using namespace std;

vector<vector<int> > f;

int numDistinct(string s, string t){
    s="." +s;
    t=","+ t;
    int m=s.length();
    int n=t.length();
    if(m<n){
        return 0;
    }
    f.resize(m+1);
    for(int i=0;i<=m;i++){
        f[i].resize(n+1);
    }
    for(int i=0;i<=m;i++){
        f[i][0]=1;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i>=j){
                f[i][j]=f[i-1][j];
                if(s[i]==t[j]){
                    f[i][j]+=f[i-1][j-1];
                }
                /*for(int i=1;i<m;i++){
                    for(int j=1;j<n;j++){
                        cout << f[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;*/
            }
        }
    }
    return f[m][n];


}


int main(){
    freopen("input.txt","r",stdin);
    string s,t;
    cin >> s >> t;
    cout << numDistinct(s,t);
    return 0;
}
