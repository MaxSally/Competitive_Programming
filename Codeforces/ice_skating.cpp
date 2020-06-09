//http://codeforces.com/problemset/problem/217/A

#include<vector>
#include<iostream>
#include<stdio.h>
#include<cmath>
    using namespace std;

vector<int> parents;
vector<pair<int,int> > point;
vector<bool> visited;


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
    }

}

int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    parents.resize(n);
    visited.resize(n,0);
    for(int i=0;i<n;i++){
        parents[i]=i;
    }
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        point.push_back(make_pair(a,b));
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(point[i].first==point[j].first || point[i].second==point[j].second){
                unionSet(i,j);
            }
        }
    }

    for(int i=0;i<n;i++){
        //cout << i << " " << temp << endl;
        visited[findSet(i)]=1;
    }
    //cout << endl;
    int ans=0;
    for(int i=0;i<n;i++){
        //cout << i<< " "<<visited[i] << endl;
        ans+=visited[i];
    }
    cout << ans-1;
    return 0;
}

