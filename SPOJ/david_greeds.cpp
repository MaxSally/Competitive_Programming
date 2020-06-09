//http://www.spoj.com/problems/DAVIDG/

#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<iomanip>
    using namespace std;

vector<bool> visited;
vector<double> cost;
vector<vector<pair<int,int> > >graph;
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
vector<pair<int,int> > coordinate;

void prim(){
    pq.push(make_pair(0,0));
    cost[0]=0;
    while(pq.empty()==false){
        int a=pq.top().second;
        pq.pop();
        visited[a]=1;
        for(int i=0;i<graph[a].size();i++){
            if(visited[graph[a][i].second]==0 && graph[a][i].first<cost[graph[a][i].second]){
                cost[graph[a][i].second]=graph[a][i].first;
                pq.push(make_pair(cost[graph[a][i].second],graph[a][i].second));
            }
        }
    }

}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("david_greeds.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii=0;ii<t;ii++){
        int n,p;

        cin >> n >> p;
        coordinate.clear();
        graph.clear();
        graph.resize(n+5);
        visited.clear();
        visited.resize(n+5,0);
        cost.clear();
        cost.resize(n+5,1e9);
        for(int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            coordinate.push_back(make_pair(a,b));
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int c=ceil(p*sqrt((coordinate[i].first-coordinate[j].first)*(coordinate[i].first-coordinate[j].first)+(coordinate[i].second-coordinate[j].second)*(coordinate[i].second-coordinate[j].second)));
                graph[i].push_back(make_pair(c,j));
                graph[j].push_back(make_pair(c,i));
            }
        }
        prim();
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=cost[i];
        }


        cout << "Scenario #" << ii+1 << ": " << ans % 1000000007 << endl;



    }

    return 0;
}
