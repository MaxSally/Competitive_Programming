//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1783

#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<queue>
    using namespace std;

int n,m;
vector<vector<pair<int,int> > > graph;
vector<bool> visited;
vector<int> cost,path;

int MaxST(){
    priority_queue<pair<int,int>, vector<pair<int,int> >,  less<pair<int,int> > > pq;
    pq.push(make_pair(0,0));
    path[0]=0;
    while(!pq.empty()){
        int a=pq.top().second;
        pq.pop();
        visited[a]=1;
        for(int i=0;i<graph[a].size();i++){
            int v=graph[a][i].first;
            int w=graph[a][i].second;
            if(v>cost[w] && visited[w]==0){
                cost[w]=v;
                pq.push(make_pair(v,w));
                path[w]=a;
            }
        }
    }
    /*for(int i=0;i<n;i++){
        int a=path[i];
        for(int j=0;j<graph[i].size();j++){
            if(graph[i][j].second==a){
                cost[i]=max(cost[i],graph[i][j].first);
            }
        }
    }*/
    int ans=1e9;
    for(int i=0;i<n;i++){
        if(cost[i]!=0){
            ans=min(ans,cost[i]);
        }

    }
    return ans;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii=1;ii<=t;ii++){
        cin >> n >> m;
        if(n==1){
            int a,b,c;
            cin >> a >> b >> c;
            cout << "Case #" << ii << ": " << c << endl;
        }else{
            path.clear();
            graph.clear();
            visited.clear();
            cost.clear();
            graph.resize(n);
            visited.resize(n,0);
            cost.resize(n,0);
            path.resize(n);
            for(int i=0;i<m;i++){
                int a,b,c;
                cin >> a >> b >> c;
                graph[a].push_back(make_pair(c,b));
                graph[b].push_back(make_pair(c,a));
            }
            cout << "Case #" << ii << ": " << MaxST() << endl;
        }

    }
    return 0;
}
