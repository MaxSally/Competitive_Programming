#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
    using namespace std;

vector< vector< pair<int,int> > > vec;
vector<int> cost;
int v,e;
priority_queue< pair<int,int> ,vector< pair<int,int> >, greater< pair<int,int> > > pq;

int main(){
    freopen("dijkstra.txt","r",stdin);
    cin >> v >> e;
    vec.resize(v);
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        vec[a].push_back(make_pair(c,b));
    }
    cost.resize(v);
    for(int i=1;i<v;i++){
        cost[i]=10000;
    }
    cost[0]=0;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        int a=pq.top().first; //cost
        int b=pq.top().second; //node
        pq.pop();
        for(int i=0;i<vec[b].size();i++){
            if(a+vec[b][i].first<cost[vec[b][i].second]){
                cost[vec[b][i].second]=a+vec[b][i].first;
                pq.push(make_pair(a+vec[b][i].first,vec[b][i].second));
            }

        }
    }
    for(int i=0;i<v;i++){
        cout << cost[i] << endl;
    }


    return 0;
}
