//https://leetcode.com/problems/maximal-square/description/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
    using namespace std;

vector<vector<int> > f;

int maximalSquare(vector<vector<char> > &matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    f.resize(n);
    for(int i=0;i<n;i++){
        f[i].resize(m,0);
    }
    for(int i=0;i<n;i++){
        f[i][0]=1;
    }
    for(int i=0;i<m;i++){
        f[0][i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]=='1'){
                if(matrix[i-1][j]=='0' || matrix[i-1][j-1]=='0' || matrix[i][j-1]=='0'){
                    f[i][j]=1;
                }else{
                    f[i][j]=1+min(min(f[i-1][j],f[i-1][j-1]),f[i][j-1]);
                }
            }
        }
    }
    int maxN=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            maxN=max(maxN,f[i][j]);
        }
    }
    return maxN*maxN;
}



int main(){
    freopen("input.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    vector<vector<char> > v;
    v.resize(n);
    for(int i=0;i<n;i++){
        v[i].resize(m);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    cout << maximalSquare(v);
    return 0;
}
