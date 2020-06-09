//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1541

#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<iomanip>
#include<cmath>
#include<string.h>
    using namespace std;


vector<vector<pair<double,int> > > graph;
vector<bool> visited;
vector<double> cost;
bool edges[1000][1000];


int ans=0;
int n,m;

double sum(vector<double> cost){
    double ans=0;
    for(int i=1;i<cost.size();i++){
        if(cost[i]<1e9){
            ans+=double(cost[i]);
        }

    }
    return ans;
}

double prim(){
    priority_queue<pair<double,int>, vector<pair<double,int> >, greater<pair<double,int> > > pq;
    pq.push(make_pair(0,1));
    cost[1]=0;
    while(!pq.empty()){
        int a=pq.top().second;
        pq.pop();
        visited[a]=1;
        for(int i=0;i<graph[a].size();i++){
            double v=graph[a][i].first;
            int w=graph[a][i].second;
            if(visited[w]==0 && v<cost[w]){
                cost[w]=v;
                pq.push(make_pair(v,w));
            }
        }
    }
    return sum(cost);
}







int main(){
    freopen("input.txt","r",stdin);
    while(cin>> n){
        cost.clear();
        visited.clear();
        graph.clear();
        cost.resize(n+1,1e9);
        visited.resize(n+1,0);
        graph.resize(n+5);
        memset(edges,0,sizeof edges);
        vector<pair<int,int> > temp;
        temp.push_back(make_pair(0,0));
        for(int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            temp.push_back(make_pair(a,b));
        }
        cin >> m;
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            edges[a][b]=true;
            edges[b][a]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int a,b,a1,b1;
                a=temp[i].first;
                b=temp[i].second;
                a1=temp[j].first;
                b1=temp[j].second;
                double c;
                if(edges[i][j]==false){
                    c=sqrt(double((a-a1)*(a-a1)+(b-b1)*(b-b1)));

                }else{
                    c=0;
                }
                graph[i].push_back(make_pair(c,j));
                graph[j].push_back(make_pair(c,i));

            }
        }


        cout << fixed << setprecision(2) << prim() << endl;
    }

}
