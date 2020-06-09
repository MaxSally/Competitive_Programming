//http://www.spoj.com/problems/MICEMAZE/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
    using namespace std;

vector<int> cost;
vector< vector< pair<int,int> > > vec;
priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;

void makePath(){
    while(!pq.empty()){
        int node=pq.top().second;
        int costN=pq.top().first;
        pq.pop();
        for(int i=0;i<vec[node].size();i++){
            if(costN+vec[node][i].first < cost[vec[node][i].second]){
                cost[vec[node][i].second]=costN+vec[node][i].first;
                pq.push(make_pair(cost[vec[node][i].second],vec[node][i].second));
            }
        }
    }

}


int main(){
    freopen("mice_maze.txt","r",stdin);
    int n,e,t,m;
    cin >> n >> e >> t >> m;
    vec.resize(n+1);
    cost.resize(n+1);
    for(int i=1;i<=n;i++){
        cost[i]=1000000000;
    }
    cost[e]=0;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        vec[b].push_back(make_pair(c,a));
    }
    pq.push(make_pair(0,e));
    makePath();
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(cost[i]<=t){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
