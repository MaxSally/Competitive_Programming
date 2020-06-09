//http://codeforces.com/problemset/problem/445/B

#include<vector>
#include<iostream>
#include<stdio.h>
#include<cmath>
    using namespace std;

vector<int> parents,cntV;


int findSet(int u){
    while(u!=parents[u]){
        u=findSet(parents[u]);
    }
    return u;
}

void unionSet(int a,int b){
    int a1=findSet(a);
    int b1=findSet(b);
    if(a1!=b1){
        parents[b1]=a1;
        cntV[a1]+=cntV[b1];
        cntV[b1]=1;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    parents.resize(n+1);
    for(int i=0;i<=n;i++){
        parents[i]=i;
    }
    cntV.resize(n+1,1);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        unionSet(a,b);
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=cntV[i]-1;
    }
    long long temp= (pow(2,ans));
    cout << temp;

    return 0;
}
