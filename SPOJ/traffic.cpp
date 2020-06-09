//http://www.spoj.com/problems/TRAFFICN/en/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
    using namespace std;

const int inf = 1e9;
#define MAX 10005
vector<int> costS, costT;
vector<vector<pair<int,int> > > vecS,vecT;



void makePath(int src , vector<int> &cost, vector<vector<pair<int,int> > > &vec){
    cost[src] = 0;
    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
        int node = pq.top().second;
        int costN= pq.top().first;
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
    //freopen("traffic.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin >> test;

    for(int ii=0;ii<test;ii++){

        int n,m,k,s,t,res;

        cin >> n >> m >> k >> s >>t;


        vecS = vector<vector<pair<int,int> > >(n+1,vector< pair<int,int> > ());
        vecT = vector<vector<pair<int,int> > >(n+1,vector< pair<int,int> > ());
        costS = vector<int> (MAX,inf);
        costT = vector<int> (MAX,inf);


        for(int i=0;i<m;i++){
            int a,b,c;
            cin >> a >> b >> c;
            vecS[a].push_back(make_pair(c,b));
            vecT[b].push_back(make_pair(c,a));
        }
        makePath(s,costS,vecS);
        makePath(t,costT,vecT);
        res=costS[t];

        for(int i=0;i<k;i++){
            int a,b,c;
            cin >> a >> b >> c;
            if(res>(costS[a]+c+costT[b])){
                res=costS[a]+c+costT[b];
            }
            if(res>(costS[b]+c+costT[a])){
                res=costS[b]+c+costT[a];
            }

        }
        if(res==inf){
            cout << -1 << endl;
        }else{
            cout << res << endl;
        }



    }
    return 0;
}
/*
for(int i=1;i<=n;i++){
    vec[i].clear();
}
vec.clear();
*/
