//https://leetcode.com/problems/minimum-path-sum/description/

#include<vector>
#include<iostream>
#include<stdio.h>
#include<cmath>
    using namespace std;

vector<vector<int> > sum;

int minPathSum(vector<vector<int> > &v){
    int m=v.size();
    int n=v[0].size();
    sum.resize(m);

    for(int i=0;i<m;i++){
        sum[i].resize(n);
    }
    sum[0][0]=v[0][0];

    for(int i=1;i<n;i++){
        sum[0][i]=v[0][i]+sum[0][i-1];
    }

    for(int i=1;i<m;i++){
        sum[i][0]=v[i][0]+sum[i-1][0];
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            sum[i][j]=min(sum[i][j-1],sum[i-1][j])+v[i][j];
        }
    }
    return sum[m-1][n-1];

}

int main(){
    freopen("input.txt","r",stdin);
    int m,n;
    cin >> m >> n;
    vector<vector<int> > v;
    v.resize(m);
    for(int i=0;i<m;i++){
        v[i].resize(n);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
        }
    }
    /*for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << minPathSum(v);


    return 0;
}
