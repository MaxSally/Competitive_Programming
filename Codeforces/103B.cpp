//http://codeforces.com/problemset/problem/103/B

#include<vector>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<stack>
    using namespace std;

vector<int> parents;
vector<pair<int,int> > point;
vector<bool> visited,visited1;
vector<vector<int> > graph;


int findSet(int u){
    while(u!=parents[u]){
        u=findSet(parents[u]);
    }
    return u;
}

void unionSet(int a,int b){
    int a1=findSet(a);
    int b1=findSet(b);
    parents[b1]=a1;
}

int DFS(int a){
    int cnt=1;
    visited1[a]=1;
    for(int i=0;i<graph[a].size();i++){
        if(!visited1[graph[a][i]]){
            cnt+=DFS(graph[a][i]);
        }
    }
    return cnt;

}

int main(){
    freopen("input.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    parents.resize(n+1);
    visited.resize(n+1,0);
    visited1.resize(n+1,0);
    graph.resize(n+1);
    /*for(int i=1;i<=n;i++){
        parents[i]=i;
    }*/

    /*for(int i=1;i<=n;i++){
        int temp=findSet(i);
        //cout << i << " " << temp << endl;
        visited[temp]=1;
    }
    //cout << endl;
    int ans=0;
    for(int i=1;i<=n;i++){
        //cout << i<< " "<<visited[i] << endl;
        ans+=visited[i];
    }*/
    if(m!=n){
        cout << "NO";
    }else{
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            //unionSet(a,b);
            graph[b].push_back(a);
            graph[a].push_back(b);
        }
        if(DFS(1)==n){
            cout << "FHTAGN!";
        }else{
            cout << "NO";
        }
    }







    return 0;
}


