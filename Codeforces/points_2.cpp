//http://codeforces.com/contest/988/problem/D

#include<vector>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<map>
    using namespace std;

int n;
vector<int> v;
int modu[100000][100000];

bool loga(int a){
    while(a!=0){
        if(a%2 ==0){
            a=a/2;
        }else{
            return 0;
        }
    }
    return 1;
}



int main(){
    freopen("input.txt","r",stdin);
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<100000;i++){
        for(int j=0;i<100000;i++){
            modu[i][j]=1e9;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int tot;
            if(v[i]<v[j]){
                tot=v[j]-v[i];
            }else{
                tot=v[i]-v[j];
            }
            int a1=tot / 100000;
            int a2=tot % 100000;
            if(modu[a1][a2]==1e9){
                modu[a1][a2]=loga(tot);
            }

        }
    }

    return 0;
}
