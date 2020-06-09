//www.spoj.com/problems/CSTREET/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
    using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair< int,int> > >pq;
vector<vector<pair<int,int> > > graph;
vector<bool> visited;
vector<int> cost;
int n,m;

void prim(){
    pq.push(make_pair(0,1));
    cost[1]=0;
    while(pq.empty()==false){
        int a=pq.top().second;
        visited[a]=1;
        pq.pop();
        for(int i=0;i<graph[a].size();i++){
            int b=graph[a][i].first; //weight
            int c=graph[a][i].second; //end node
            if(visited[c]==0 && b<cost[c]){
                cost[c]=b;
                pq.push(make_pair(b,c));
            }

        }
    }
}


int main(){
    freopen("csstreet.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii=0;ii<t;ii++){
        int p;
        cin >> p >> n >> m;
        graph.resize(n+5);
        cost.resize(n+5,1e9);
        for(int i=0;i<m;i++){
            int a,b,c;
            cin >> a >> b >> c;
            graph[a].push_back(make_pair(c,b));
            graph[b].push_back(make_pair(c,a));

        }
        visited.resize(n+5,0);
        prim();
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(cost[i]!=1e9){
                ans+=cost[i];
            }
        }
        cout << ans*p;
    }
    return 0;
}

