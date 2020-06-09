//https://uva.onlinejudge.org/external/106/10608.pdf

#include<iostream>
#include<vector>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<sstream>
    using namespace std;

vector<int> parents;
vector<int> cnt;

int findSet(int u){
    return (parents[u]==u ? u : u = findSet(parents[u]));
}

int unionSet(int a,int b){
    int a1=findSet(a);
    int b1=findSet(b);
    if(a1!=b1){
        parents[b1]=a1;
        cnt[a1]+=cnt[b1];
    }
    return cnt[a1];
}

int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii=0;ii<t;ii++){
        int n,m;
        cin >> n >> m;
        parents.clear();
        parents.resize(n+1);
        cnt.clear();
        cnt.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parents[i]=i;
        }
        int ans=1;
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            int temp = unionSet(a,b);
            ans=max(ans,temp);
        }
        cout << ans << endl;
    }

    return 0;
}




