//http://www.spoj.com/problems/TRVCOST/

#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>
#include<functional>
    using namespace std;

//vector< vector< pair<int,int> > > vec;
//vector<int> cost;

vector<pair<int,int> > vec[505];
vector<int> cost;

priority_queue < pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > process;

void makePath(){
    while(!process.empty()){
        int costN=process.top().first;
        int node=process.top().second;
        process.pop();
        for(int i=0;i<vec[node].size();i++){
            if(costN+vec[node][i].first<cost[vec[node][i].second]){
                cost[vec[node][i].second]=costN+vec[node][i].first;
                process.push(make_pair(cost[vec[node][i].second],vec[node][i].second));
            }
        }
    }
}

int main(){
    freopen("travelling_cost.txt","r",stdin);
    int n;
    cin >> n;
    cost = vector<int>(505, 1000000000);
    //vec.resize(n+10);
    //cost.resize(550,1000000000);
    for(int i=0;i<n;i++){
        int a,b,w;
        cin >> a >> b >>w;
        vec[a].push_back(make_pair(w,b));
        vec[b].push_back(make_pair(w,a));
    }
    int u,q;
    cin >> u >> q;
    cost[u]=0;
    process.push(make_pair(0,u));
    makePath();
    for(int i=0;i<q;i++){
        int v;
        cin >> v;

            if(cost[v]==1000000000){
                cout << "NO PATH" << endl;
            }else{
                cout << cost[v] << endl;
            }

    }


}
