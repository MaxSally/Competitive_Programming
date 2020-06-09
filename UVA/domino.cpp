//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2499

#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
    using namespace std;

int parents[100000];
int parents1[100000];
bool visited[100000];
vector<vector<int> > graph;
int n,m;

void BFS(int x){
    queue<int> q;
    q.push(x);
    visited[x]=1;
    while(!q.empty()){
        int a=q.front();
        q.pop();
        for(int i=0;i<graph[i].size();i++){
            int b=graph[a][i];
            if(visited[b]==0){
                visited[b]=1;
                q.push(b);
            }
        }
    }
}

int findSet(int u){
    while(u!=parents[u]){
        u=findSet(parents[u]);
    }
    return u;
}

void unionSetSingle(int a,int b){
    int a1=findSet(a);
    if(b!=a1){
        /*for(int i=0;i<=n;i++){
            visited[i]=0;
        }
        visited[a]=1;
        visited[a1]=1;
        BFS(b);
        visited[a]=0;
        visited[a1]=0;
        for(int i=1;i<=n;i++){
            if(visited[i]){
                parents[i]=b;
            }
        }*/
        int b1=findSet(b);
        if(parents1[b1]!=b1){
            parents[b1]=a1;
        }else{
            parents[b]=a1;
        }

    }else{
        parents1[a1]=b;
    }
}
/*void unionSetDouble(int a,int b){
    int a1=findSet(a);
    int b1=findSet(b);
    if(a1!=b1){
        parents[b1]=a1;
    }
}

void DFS(int a){

    while(visited[a]==false){
        visited[a]=1;
        a=parents[a];
    }
}*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii=0;ii<t;ii++){
        cin >> n >> m;
        graph.clear();
        graph.resize(n+1);
        for(int i=0;i<=n;i++){
            parents[i]=i;
            parents1[i]=i;
        }
        for(int i=0;i<m;i++){
            int x,y;
            cin >> x >> y;
            graph[x].push_back(y);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<graph[i].size();j++){
                unionSetSingle(i,graph[i][j]);
            }
        }

        /*for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(graph[i][j]==1){
                    if(graph[i][j]==graph[j][i]){
                        unionSetDouble(i,j);
                    }else{
                        unionSetSingle(i,j);
                    }
                }
            }

        }*/
        int cnt=0;
        for(int i=1;i<=n;i++){
            //cout << i << " " << parents[i] << endl;
            if(parents[i]==i){
               cnt++;
            }
        }
        cout << cnt << endl;
    }
}
